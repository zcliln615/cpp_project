#include <stdio.h>

typedef struct _Matrix
{
    size_t rows;
    size_t cols;
    float *data;
} Matrix;

Matrix *Matrix_create(size_t rows, size_t cols);
Matrix *matmul_plain(float *mat1, size_t row1, size_t col1, float *mat2, size_t row2, size_t col2);

int main()
{
    return 0;
}

Matrix *Matrix_create(size_t rows, size_t cols)
{
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    if (mat == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (float *)malloc(rows * cols * sizeof(float));
    if (mat->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        free(mat);
        return NULL;
    }

    for (size_t i = 0; i < rows * cols; i++)
    {
        mat->data[i] = (int)rand() % 10; // 生成0到10之间的随机整数
    }

    return mat;
}

Matrix *matmul_plain(float *mat1, size_t row1, size_t col1, float *mat2, size_t row2, size_t col2)
{
    if (mat1 == NULL || mat2 == NULL)
        fprintf(stderr, "Matrix is NULL.\n");
    if (col1 != row2) // 矩阵乘法的条件,用col1或者row2当作迭代数
        fprintf(stderr, "Matrix dimensions do not match\n");
    float *result = Matrix_create(row1, col2);

    for (size_t i = 0; i < row1; i++)
    {
        for (size_t j = 0; j < col2; j++)
        {
            result[i * col2 + j] = 0;
            for (size_t k = 0; k < col1; k++)
            {
                result[i * col2 + j] += mat1[i * col1 + k] * mat2[k * col2 + j];
            }
        }
    }
    return result;
}