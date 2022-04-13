#include "matrix.h"

int main(void) {
    Matrix* array = create_matrix_from_file("D:\\WorkPrograms\\C++\\making-hw-3\\Kal.txt");
    for (size_t i = 0; i < array->rows * array->cols; ++i) {
        printf("%lf ", array->array[i]);
    }
    printf("\n\n\n");
    Matrix* array1 = inv(array);
    for (size_t i = 0; i < array1->rows * array1->cols; ++i) {
        printf("%lf ", array1->array[i]);
    }
}
