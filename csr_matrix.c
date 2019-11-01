#include "csr_matrix.h"
#include <stdlib.h>

void csr_create(sparse_matrix_t **csr_matrix, 
		double **matrix,
		const int length, const int width)
{
	*csr_matrix = malloc(sizeof(sparse_matrix_t));

	if(csr_matrix)
	{
		(*csr_matrix)->nnz = 0;
		(*csr_matrix)->n = length;
		(*csr_matrix)->l = width;

		(*csr_matrix)->vals = malloc( sizeof(double) 
				* width * length);
		(*csr_matrix)->cols = malloc(sizeof(unsigned int) 
				* width * length);
		(*csr_matrix)->rows = malloc(sizeof(unsigned int) 
				* length + 1);
		(*csr_matrix)->rows[0] = 0;
		size_t size = 0;
		for(int i = 0; i < length; i++) 
		{
			for(int j = 0; j < width; j++)
			{
				if(matrix[i][j] != 0)
				{
					(*csr_matrix)->cols[size] = j;
					(*csr_matrix)->vals[size] =
						matrix[i][j];
					size++;
					(*csr_matrix)->nnz += 1;
				}
			}
			(*csr_matrix)->rows[i] = size;
		}
		(*csr_matrix)-> vals = 
			realloc((*csr_matrix)->vals, sizeof(double) * size);
		(*csr_matrix)->cols = 
			realloc((*csr_matrix)->cols, sizeof(unsigned int) * size);
		(*csr_matrix)->rows = 
			realloc((*csr_matrix)->rows, sizeof(unsigned int) * size);
	}

}
