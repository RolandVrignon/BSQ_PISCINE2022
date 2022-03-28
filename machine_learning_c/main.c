#include <stdio.h>
#include <stdlib.h>

int     **ft_matrix_dot_product(int **vector_A, int **vector_B, int n_max, int j_max, int k_max);
int     ft_strlen(int *str);
int     ft_strlen2(int **str);
int     ft_tablen(int **tab);

int main(int argc, char **argv)
{
    int     m = 0;

    // INIT MAT_A
    int     **mat_A = malloc(sizeof(int*) * 3);
	while (m < 4)
	{
		mat_A[m] = malloc(sizeof(int) * 4);
		m++;
	}
    mat_A[m] = NULL;
    mat_A[0][0] = 1; 	mat_A[0][1] = 0;    mat_A[0][2] = 1;
    mat_A[1][0] = 0;    mat_A[1][1] = 1;    mat_A[1][2] = 0;
    mat_A[2][0] = 1;    mat_A[2][1] = 1;    mat_A[2][2] = 1;
    m = 0;

    // INIT MAT_B
    int     **mat_B = malloc(sizeof(int**) * 3);
	while (m < 3)
	{
		mat_B[m] = malloc(sizeof(int*) * 3);
		m++;
	}
    mat_B[m] = NULL;
    mat_B[0][0] = 0; 	mat_B[0][1] = 1;    mat_B[0][2] = 0;
    mat_B[1][0] = 1;    mat_B[1][1] = 1;    mat_B[1][2] = 1;
    mat_B[2][0] = 0;    mat_B[2][1] = 1;    mat_B[2][2] = 1;
    m = 0;

    printf("len : %d \n", ft_tablen(mat_B));
    printf("strlen2 : %d \n", ft_strlen2(mat_B));
    printf("strlen : %d \n", ft_strlen(mat_B[0]));

    //MATRIX DOT PRODUCT
    int **matrix = ft_matrix_dot_product(mat_A, mat_B, 3, 3, 3);
    int i = 0;
	int j = 0;
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


    free(matrix);
    free(mat_A);
    free(mat_B);
    
    return (0);
}
