typedef struct {
	int n/*number of rows*/,
	    nnz /*total values*/,
	    l/*number of columns*/;
	int *rows /*size is n*/;
	int *cols;
	double *vals /*rows values*/;
} sparse_matrix_t;

void csr_create(sparse_matrix_t **csr_matrix, 
		double **matrix,
		const int length, const int width);
