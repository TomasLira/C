#include <stdlib.h>
#include <stdio.h>

int *create_matrix(int cols, int rows)
{
    int *ptr = malloc((rows * cols) * sizeof(int));
    return ptr;
}

int *fill_matrix(int *mat, int cols, int rows)
{

    printf("Fill the values in the matrix!\n");

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i * rows + j]);
        }
    }
}

int *multipplying_two_matrices(int *mat1, int *mat2, int rows1, int cols1, int rows2, int cols2, int *rows3, int *cols3)
{

    if (cols1 != rows2)
        return 0;
    int *mat3 = create_matrix(rows1, cols2);

    *rows3 = rows1;
    *cols3 = cols2;

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            mat3[i * (*rows3) + j] = 0;

            for (int k = 0; k < rows2; k++)
            {
                mat3[i * (*rows3) + j] += mat1[i * rows1 + k] * mat2[k * rows2 + j];
            }
        }
    }

    return mat3;
}

void identity_matrix(int *mat, int rows, int cols)
{

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j)
                mat[i * rows + j] = 1;
            else
                mat[i * rows + j] = 0;
        }
    }
}

void find_transpose_matrix(int *mat, int rows, int cols)
{

    int *tmp = mat;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            tmp[i * rows + j] = mat[j * rows + i];
        }
    }

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            mat[i * rows + j] = tmp[i * rows + j];
        }
    }
}

int print_matrix(int *mat, int cols, int rows)
{

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%d\t", mat[i * rows + j]);
        }
        printf("\n");
    }
}

// Only works for  square matrices! ;(
int main()
{

    int cols1 = 3, rows1 = 3;
    int cols2 = 3, rows2 = 3;
    int cols3 = 0, rows3 = 0;

    printf("The first matrix:\n");

    int *mat1 = create_matrix(cols1, rows1);
    fill_matrix(mat1, cols1, rows1);
    print_matrix(mat1, cols1, rows1);

    printf("\nThe second matrix:\n");

    int *mat2 = create_matrix(cols2, rows2);
    fill_matrix(mat2, cols2, rows2);
    print_matrix(mat2, cols2, rows2);

    printf("Multiplying both of our matrices:\n");
    int *mat3 = multipplying_two_matrices(mat1, mat2, rows1, cols1, rows2, cols2, &rows3, &cols3);
    print_matrix(mat3, rows3, cols3);

    printf("\n");

    find_transpose_matrix(mat3, rows3, cols3);
    print_matrix(mat3, rows3, cols3);

    return 0;
}