#include <stdlib.h>
#include <stdio.h>

int     ft_strlen(int *str);
int     ft_strlen2(int **str);
int     ft_vector_dot_product(int **vector_A, int **vector_B, int n_max, int j, int k);
int     *ft_line_dot_product(int **vector_A, int **vector_B, int n_max, int j_max, int k);
int     **ft_matrix_dot_product(int **vector_A, int **vector_B, int n_max, int j_max, int k_max);

int     main(int argc, char **argv)
{
    int     m = 0;


    // INIT MAT_A
    int     **mat_A = malloc(sizeof(int*) * 3);
	while (m < 3)
	{
		mat_A[m] = malloc(sizeof(int) * 3);
		m++;
	}
    mat_A[m] = NULL;
    mat_A[0][0] = 1; 	mat_A[0][1] = 1;    mat_A[0][2] = 1;
    mat_A[1][0] = 1;    mat_A[1][1] = 1;    mat_A[1][2] = 1;
    mat_A[2][0] = 1;    mat_A[2][1] = 1;    mat_A[2][2] = 1;
    m = 0;

    // INIT MAT_B
    int     **mat_B = malloc(sizeof(int*) * 3);
	while (m < 3)
	{
		mat_B[m] = malloc(sizeof(int) * 3);
		m++;
	}
    mat_B[m] = NULL;
    mat_B[0][0] = 1; 	mat_B[0][1] = 1;    mat_B[0][2] = 1;
    mat_B[1][0] = 1;    mat_B[1][1] = 1;    mat_B[1][2] = 1;
    mat_B[2][0] = 1;    mat_B[2][1] = 1;    mat_B[2][2] = 1;
    m = 0;

    //PRINT MATRICES

    int	i = 0;
	int	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%d ", mat_A[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

    printf("\n");

    i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%d ", mat_B[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

    printf("\n");

    //DOT PRODUCT BETWEEN VECTORS
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 0, 0));
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 1, 0));
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 2, 0));
    printf("\n");
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 0, 1));
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 1, 1));
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 2, 1));
    printf("\n");
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 0, 2));
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 1, 2));
    printf("%d ", ft_vector_dot_product(mat_A, mat_A, 3, 2, 2));

    printf("\n");
    printf("\n");
    //DOT PRODUCT LINE BY LINE
    int *line1 = ft_line_dot_product(mat_A, mat_A, 3, 3, 2);
	j = 0;
    while (j < 3)
    {
        printf("%d ", line1[j]);
        j++;
    }
    printf("\n");
    printf("\n");
    //MATRIX DOT PRODUCT
    int **matrix = ft_matrix_dot_product(mat_A, mat_A, 3, 3, 3);
    i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

    free(line1);
    free(matrix);
    free(mat_A);
    free(mat_B);
}