#include <stdio.h>

#define Max 50
float *Matrix_p_buff[Max] = {NULL};
int Matrix_p_buff_index = 0;
float *Matrix_create(size_t row, size_t col);
void Matrix_free(float *mat);
void Martrix_free_all();
float *Matrix_mul(float *mat1, size_t row1, size_t col1, float *mat2, size_t row2, size_t col2);

int main()
{

    return 0;
}

/// @brief 生成一个row行col列的矩阵
/// @param row 矩阵的行数
/// @param col 矩阵的列数
/// @return
float *Matrix_create(size_t row, size_t col)
{
    size_t n = row * col;
    float *vec1 = (float *)malloc(n * sizeof(float));
    if (vec1 == NULL)
        sprintf(stderr, "Memory allocation failed.\n");
    else
        Matrix_p_buff[Matrix_p_buff_index++] = vec1;
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
        sprintf(stderr, "Matrix is NULL.\n");
    if (col1 != row2) // 矩阵乘法的条件,用col1或者row2当作迭代数
        sprintf(stderr, "Matrix dimensions do not match\n");
    float *result = Matrix_create(row1, col2);//哈哈哈
}

//测试同步
//测试同步