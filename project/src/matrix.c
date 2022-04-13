#include "matrix.h"

Matrix* create_matrix_from_file(const char* path_file) {
    if (path_file != NULL) {
        FILE* file_with_matrix = fopen(path_file, "r");
        size_t rows;
        size_t cols;
        fscanf(file_with_matrix, "%zu%zu", &rows, &cols);

        Matrix* matrix = malloc(sizeof(Matrix) + rows * cols * sizeof(double));

        matrix->rows = rows;
        matrix->cols = cols;
        for (size_t i = 0; i < matrix->rows * matrix->cols; ++i) {
            fscanf(file_with_matrix, "%lf", &matrix->array[i]);
        }

        fclose(file_with_matrix);
        return matrix;
    }

    return NULL;
}

Matrix* create_matrix(size_t rows, size_t cols) {
    if (rows > 0 && cols > 0) {
        Matrix* matrix = malloc(sizeof(Matrix) + rows * cols * sizeof(double));

        matrix->rows = rows;
        matrix->cols = cols;
        for (size_t i = 0; i < matrix->rows * matrix->cols; ++i) {
            matrix->array[i] = 0;
        }

        return matrix;
    }
    return NULL;
}

void free_matrix(Matrix* matrix) {
    if (matrix != NULL) {
        free(matrix);
    }
}

int get_rows(const Matrix* matrix, size_t* rows) {
    if (matrix != NULL && rows != NULL) {
        *rows = matrix->rows;

        return 0;
    }

    return -1;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (matrix != NULL && cols != NULL) {
        *cols = matrix->cols;

        return 0;
    }

    return -1;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (matrix != NULL && val != NULL) {
        *val = matrix->array[row * matrix->cols + col];

        return 0;
    }

    return -1;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (matrix != NULL) {
        matrix->array[row * matrix->cols + col] = val;

        return 0;
    }

    return -1;
}

Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (matrix != NULL) {
        Matrix* multiplied_matrix = create_matrix(matrix->rows, matrix->cols);

        for (size_t i = 0; i < matrix->rows * matrix->cols; ++i) {
            multiplied_matrix->array[i] = matrix->array[i] * val;
        }

        return multiplied_matrix;
    }

    return NULL;
}

Matrix* transp(const Matrix* matrix) {
    if (matrix != NULL) {
        Matrix* transposed_matrix = create_matrix(matrix->cols, matrix->rows);

        for (size_t i = 0; i < matrix->cols; ++i) {
            for (size_t j = 0; j < matrix->rows; ++j) {
                transposed_matrix->array[i * matrix->rows + j] = matrix->array[j * matrix->cols + i];
            }
        }

        return transposed_matrix;
    }

    return NULL;
}

Matrix* sum(const Matrix* l, const Matrix* r) {
    if (l != NULL && r != NULL && l->rows == r->rows && l->cols == r->cols) {
        Matrix* sum_of_matrices = create_matrix(r->rows, r->cols);

        for (size_t i = 0; i < r->rows * r->cols; ++i) {
            sum_of_matrices->array[i] = r->array[i] + l->array[i];
        }

        return sum_of_matrices;
    }

    return NULL;
}

Matrix* sub(const Matrix* l, const Matrix* r) {
    if (l != NULL && r != NULL && l->rows == r->rows && l->cols == r->cols) {
        Matrix* sub_of_matrices = create_matrix(r->rows, r->cols);

        for (size_t i = 0; i < r->rows * r->cols; ++i) {
            sub_of_matrices->array[i] = l->array[i] - r->array[i];
        }

        return sub_of_matrices;
    }

    return NULL;
}

Matrix* mul(const Matrix* l, const Matrix* r) {
    if (l != NULL && r != NULL && l->cols == r->rows) {
        Matrix* multiple_of_matrices = create_matrix(l->rows, r->cols);

        for (size_t i = 0; i < l->rows; ++i) {
            for (size_t j = 0; j < r->cols; ++j) {
                for (size_t k = 0; k < l->cols; ++k) {
                    multiple_of_matrices->array[i * r->cols + j] += l->array[i * l->cols + k] *
                                                                  r->array[k * r->cols + j];
                }
            }
        }

        return multiple_of_matrices;
    }

    return NULL;
}

Matrix* create_smaller_size_matrix(const Matrix* matrix, size_t row_to_skip, size_t col_to_skip) {
    Matrix* smaller_matrix = create_matrix(matrix->rows - 1, matrix->cols - 1);

    size_t i = 0;
    size_t diff_of_rows = 0;
    while (i < smaller_matrix->rows) {
        if (i == row_to_skip) {
            ++diff_of_rows;
        }
        size_t j = 0;
        size_t diff_of_cols = 0;
        while (j < smaller_matrix->cols) {
            if (j == col_to_skip) {
                ++diff_of_cols;
            }
            smaller_matrix->array[i * smaller_matrix->cols + j] = matrix->array[(i + diff_of_rows) *
                                                                            matrix->cols + j + diff_of_cols];
            ++j;
        }
        ++i;
    }

    return smaller_matrix;
}

double det_counting(const Matrix* matrix, size_t rows) {
    if (matrix->rows == 1) {
        return matrix->array[0];
    }

    if (matrix->rows == 2) {
        return matrix->array[0] * matrix->array[3] - matrix->array[1] * matrix->array[2];
    }

    double val = 0;
    int sign = 1;
    for (size_t i = 0; i < rows; ++i) {
        Matrix* smaller_matrix = create_smaller_size_matrix(matrix, 0, i);

        val += sign * matrix->array[i] * det_counting(smaller_matrix, rows - 1);
        sign *= -1;

        free_matrix(smaller_matrix);
    }

    return val;
}

int det(const Matrix* matrix, double* val) {
    if (matrix != NULL  && val != NULL && matrix->rows == matrix->cols) {
        *val = det_counting(matrix, matrix->rows);

        return 0;
    }

    return -1;
}

Matrix* adj(const Matrix* matrix) {
    if (matrix != NULL && matrix->rows == matrix->cols) {
        Matrix* transposed_matrix = transp(matrix);
        Matrix* adj_matrix = create_matrix(transposed_matrix->rows, transposed_matrix->cols);

        for (size_t i = 0; i < adj_matrix->rows; ++i) {
            for (size_t j = 0; j < adj_matrix->cols; ++j) {
                Matrix* smaller_matrix = create_smaller_size_matrix(transposed_matrix, i, j);

                int sign = 1;
                if ((i + j) % 2 != 0) {
                    sign *= -1;
                }
                adj_matrix->array[i * adj_matrix->rows + j] = sign *
                                                            det_counting(smaller_matrix,
                                                                         smaller_matrix->rows);

                free_matrix(smaller_matrix);
            }
        }
        free_matrix(transposed_matrix);

        return adj_matrix;
    }

    return NULL;
}

Matrix* inv(const Matrix* matrix) {
    if (matrix != NULL && matrix->rows == matrix->cols) {
        double val = det_counting(matrix, matrix->rows);
        if (val == 0) {
            return NULL;
        }

        if (matrix->rows == 1) {
            Matrix* inv_matrix = create_matrix(1, 1);
            inv_matrix->array[0] = 1 / matrix->array[0];
            return inv_matrix;
        }

        Matrix* adj_matrix = adj(matrix);
        val = 1.0 / val;

        Matrix* inv_matrix = mul_scalar(adj_matrix, val);
        free_matrix(adj_matrix);

        return inv_matrix;
    }

    return NULL;
}
