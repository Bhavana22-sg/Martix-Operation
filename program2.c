#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int result[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int result[MAX][MAX],
                    int r1, int c1, int c2)
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[MAX][MAX],
                     int result[MAX][MAX],
                     int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX];
    int result[MAX][MAX];
    int transpose[MAX][MAX];

    int r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");

    printf("\nEnter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r2, c2);

    printf("\nChoose an operation:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose of A\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (r1 == r2 && c1 == c2)
            {
                addMatrix(A, B, result, r1, c1);

                printf("\nMatrix A + Matrix B:\n");
                displayMatrix(result, r1, c1);
            }
            else
            {
                printf("\nAddition is not possible.\n");
                printf("Both matrices must have the same dimensions.\n");
            }
            break;

        case 2:
            if (c1 == r2)
            {
                multiplyMatrix(A, B, result, r1, c1, c2);

                printf("\nMatrix A x Matrix B:\n");
                displayMatrix(result, r1, c2);
            }
            else
            {
                printf("\nMultiplication is not possible.\n");
                printf("Columns of A must equal rows of B.\n");
            }
            break;

        case 3:
            transposeMatrix(A, transpose, r1, c1);

            printf("\nTranspose of Matrix A:\n");
            displayMatrix(transpose, c1, r1);
            break;

        case 4:
            printf("\nProgram ended.\n");
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}
