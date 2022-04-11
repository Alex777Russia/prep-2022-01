#include "matrix.h"

Matrix* create_matrix_from_file(const char* path_file) {
    if (path_file == NULL) {
        return NULL;
    }

    Matrix* matrix = malloc(sizeof(Matrix));

    FILE *file_with_matrix = fopen(path_file, "r");
    fscanf(file_with_matrix, "%zu %zu\n", &matrix->rows, &matrix->cols);

    for (int i = 0; i < matrix->rows * matrix->cols; ++i) {
        fscanf(file_with_matrix, "%lf ", &matrix->array[i]);
    }

    fclose(file_with_matrix);
    return matrix;
}

Matrix* create_matrix(size_t rows, size_t cols) {
    // if (rows <= 0 || cols <= 0) {
    //     return NULL;
    // }

    Matrix* matrix = malloc(sizeof(Matrix));

    matrix->rows = rows;
    matrix->cols = cols;

    for (int i = 0; i < matrix->rows * matrix->cols; ++i) {
        matrix->array[i] = 0;
    }

    return matrix;
}

void free_matrix(Matrix* matrix) {
    if (matrix != NULL) {
        free(matrix);
    }
}

int get_rows(const Matrix* matrix, size_t* rows) {
    if (matrix == NULL) {
        return -1;
    }

    *rows = matrix->rows;
    return 0;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (matrix == NULL) {
        return -1;
    }

    *cols = matrix->cols;
    return 0;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (matrix == NULL || val == NULL) {                           // || row <= 0 || col <= 0)
        return -1;
    }

    *val = matrix->array[row * matrix->cols + col];
    return 0;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (matrix == NULL && row == 0 && col == 0) {
        return -1;
    }

    matrix->array[row * matrix->cols + col] = val;
    return 0;
}

Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (matrix == NULL) {
        return NULL;
    }

    Matrix* mul_scalar_matrix = create_matrix(matrix->rows, matrix->cols);

    for (int i = 0; i < matrix->rows * matrix->cols; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            mul_scalar_matrix->array[i] = matrix->array[i] * val;
        }
    }
    return mul_scalar_matrix;
}

Matrix* transp(const Matrix* matrix) {
    if (matrix == NULL) {
        return NULL;
    }

    Matrix* transposed_matrix = create_matrix(matrix->rows, matrix->cols);

    for(int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            transposed_matrix->array[i * matrix->rows + j] = matrix->array[j * matrix->rows + i];
        }
    }
    return transposed_matrix;
}

Matrix* sum(const Matrix* l, const Matrix* r) {
    if (l == NULL || r == NULL || l->rows == r->rows || l->cols == r->cols) {
        return NULL;
    }

    Matrix* sum_of_matrix = create_matrix(l->rows, l->cols);

    for (int i = 0; i < r->rows * r->cols; ++i) {
        sum_of_matrix->array[i] = l->array[i] + r->array[i];
    }
    return sum_of_matrix;
}

Matrix* sub(const Matrix* l, const Matrix* r) {
    if (l == NULL || r == NULL || l->rows == r->rows || l->cols == r->cols) {
        return NULL;
    }

    Matrix* sub_of_matrix = create_matrix(l->rows, l->cols);

    for (int i = 0; i < l->rows; ++i) {
        sub_of_matrix->array[i] = l->array[i] - r->array[i];
    }
    return sub_of_matrix;
}

Matrix* mul(const Matrix* l, const Matrix* r) {
    if (l == NULL || r == NULL || l->rows == r->cols) {
        return NULL;
    }

    Matrix* multiply_matrix = create_matrix(l->cols, l->rows);

    for (size_t i = 0; i < l->rows; ++i) {
        for (size_t j = 0; j < r->cols; ++j) {
            for (size_t k = 0; k < l->cols; ++k) {
                multiply_matrix->array[i * l->cols + j] += l->array[i * l->cols + k] * r->array[k * r->cols + j];
            }
        }
    }
    return multiply_matrix;
}

Matrix* create_minor(const Matrix* matrix, size_t col_to_skip) {
    Matrix* minor_matrix = create_matrix(matrix->rows, matrix->cols);

    for(size_t i = 0; i < matrix->rows - 1; ++i) {
        size_t j = 0;
        size_t diff_of_col = 0;
        while (j < matrix->cols - 1) {
            if (j != col_to_skip) {
                minor_matrix->array[i * matrix->cols + j] = matrix->array[(i + 1) * matrix->cols + j + diff_of_col];
                ++j;
            } else {
                ++diff_of_col;
            }
        }
    }
    return minor_matrix;
}

int det(const Matrix* matrix, double* val) {
    if (matrix == NULL || val == NULL || (matrix->rows != matrix->cols)) {
        return -1;
    }

    if (matrix->rows == 1) {
        *val = matrix->array[0];
        return 0;
    }

    if(matrix->rows == 2) {
        *val = matrix->array[0] * matrix->array[3] - matrix->array[1] * matrix->array[2];
        return 0;
    }

    *val = 0;
    int sign = 1;

    for (size_t i = 0; i < matrix->rows; ++i) {
        Matrix* minor_matrix = create_minor(matrix, i);

        *val += sign * matrix->array[i] * det(minor_matrix, val);
        sign *= -1;

        free_matrix(minor_matrix);
    }

    return 0;
}

Matrix* adj(const Matrix* matrix) {
    if (matrix == NULL || matrix->rows != matrix->cols) {
        return NULL;
    }

    Matrix* adj_matrix = create_matrix(matrix->rows, matrix->cols);

    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j) {
            Matrix* minor_matrix = create_minor(matrix, i);

            double value = 0;
            adj_matrix->array[i * matrix->rows + j] = det(minor_matrix, &value);

            free_matrix(minor_matrix);
        }
    }

    transp(adj_matrix);
    return adj_matrix;
}

Matrix* inv(const Matrix* matrix) {
    if (matrix == NULL || matrix->rows == matrix->cols) {
        return NULL;
    }

    Matrix* adj_matrix = adj(matrix);

    double determinant = 0;
    det(matrix, &determinant);
    determinant = 1.00 / determinant;

    Matrix* inv_matrix = mul_scalar(adj_matrix, determinant);
    free_matrix(adj_matrix);

    return inv_matrix;
}