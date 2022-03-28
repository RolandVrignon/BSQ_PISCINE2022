/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:56:13 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/20 12:56:25 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     ft_strlen(int *str);
int     ft_strlen2(int **str);


int     ft_vector_dot_product(int **vector_A, int **vector_B, int n_max, int j, int k)
{
    int     product;
    int     i;

    i = 0;
    product = 0;
    while (i < n_max)
    {
        product = product + vector_B[i][j] * vector_A[k][i];
        i++;
    }
    return (product);
}

int     *ft_line_dot_product(int **vector_A, int **vector_B, int n_max, int j_max, int k)
{
    int j = 0;
    int *vector_out = malloc(sizeof(int) * j_max);

    while (j < j_max)
    {
        vector_out[j] = ft_vector_dot_product(vector_A, vector_B, n_max, j, k);
        j++;
    }
    return (vector_out);
}

int     **ft_matrix_dot_product(int **vector_A, int **vector_B, int n_max, int j_max, int k_max)
{
    int k = 0;
    int **matrix_out = malloc(sizeof(int*) * k_max);

    while (k < k_max)
    {
        matrix_out[k] = ft_line_dot_product(vector_A, vector_B, n_max, j_max, k);
        k++;
    }
    matrix_out[k] = NULL;
    return (matrix_out);
}

char    ft_itoa(int *nb)
{

}