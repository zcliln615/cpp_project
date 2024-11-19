#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 50
float *Matrix_p_buff[Max] = {NULL};
int Matrix_p_buff_index = 0;
float *Matrix_create(size_t row, size_t col);
void Matrix_free(float *mat);
void Martrix_free_all();
float *Matrix_mul(float *mat1, size_t row1, size_t col1, float *mat2, size_t row2, size_t col2);
void Matrix_printf(float *mat, size_t row, size_t col);

int main()
{
    // 初始化随机数种子
    srand(time(NULL));

    // 测试生成随机数矩阵
    size_t square = 1000;
    size_t row1 = square, col1 = square;
    size_t row2 = square, col2 = square;
    float *mat1 = NULL;
    mat1 = Matrix_create(row1, col1);
    float *mat2 = NULL;
    mat2 = Matrix_create(row2, col2);
    float *result = NULL;
    result = Matrix_mul(mat1, row1, col1, mat2, row2, col2);

    // 打印矩阵
    // Matrix_printf(mat1, row1, col1);
    // printf("\n");
    // Matrix_printf(mat2, row2, col2);
    // printf("\n");
    // Matrix_printf(result, row1, col2);

    // 释放矩阵
    Martrix_free_all();
    return 0;
}

/// @brief 生成一个row行col列的矩阵，并填充随机数
/// @param row 矩阵的行数
/// @param col 矩阵的列数
/// @return
float *Matrix_create(size_t row, size_t col)
{
    size_t n = row * col;
    float *vec1 = (float *)malloc(n * sizeof(float));
    if (vec1 == NULL)
        fprintf(stderr, "Memory allocation failed.\n");
    else
    {
        Matrix_p_buff[Matrix_p_buff_index++] = vec1;
        for (size_t i = 0; i < n; i++)
        {
            vec1[i] = (int)rand() % 10; // 生成0到10之间的随机整数
        }
    }
    return vec1;
}

/// @brief 矩阵释放
/// @param mat 矩阵指针
void Matrix_free(float *mat)
{
    free(mat);
}

/// @brief 释放当前所申请的所有矩阵
void Martrix_free_all()
{
    for (int i = 0; i < Matrix_p_buff_index; i++)
        free(Matrix_p_buff[i]);
    Matrix_p_buff_index = 0;
}

float *Matrix_mul(float *mat1, size_t row1, size_t col1, float *mat2, size_t row2, size_t col2)
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

void Matrix_printf(float *mat, size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%.0f ", mat[i * col + j]);
        }
        printf("\n");
    }
}