#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

void print(int a[N][N])
{
    FILE *f;
    if ((f = fopen("output.txt", "wt")) == NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            fprintf(f, "%d ", a[i][j]);
            if ((j + 1) % 3 == 0 && j != N - 1)
                fprintf(f, "| ");
        }
        fprintf(f, "\n");
        if ((i + 1) % 3 == 0 && i != N - 1)
        {
            for (k = 0; k < 21; k++)
                fprintf(f, "-");
            fprintf(f, "\n");
        }
    }
    fclose(f);
}

bool ok(int a[N][N], int l, int c, int k)
{
    int j, i;
    for (j = 0; j < N; j++)
        if (a[l][j] == k)
            return false;

    for (i = 0; i < N; i++)
        if (a[i][c] == k)
            return false;

    int startRow = l - l % 3;
    int startCol = c - c % 3;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (a[i + startRow][j + startCol] == k)
                return false;
    return true;
}

int Sudoku(int a[N][N], int l, int c)
{

    if (c == N)
    {
        l++;
        c = 0;
    }

    if (l == N)
        return 1;

    if (a[l][c] > 0)
        return Sudoku(a, l, c + 1);

    for (int k = 1; k <= N; k++)
    {
        if (ok(a, l, c, k))
        {
            a[l][c] = k;

            if (Sudoku(a, l, c + 1))
                return 1;
        }

        a[l][c] = 0;
    }

    return 0;
}

int main()
{
    int a[N][N], i, j;
    FILE *f;
    if ((f = fopen("input.txt", "rt")) == NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            fscanf(f, "%d", &a[i][j]);
    fclose(f);

    if (Sudoku(a, 0, 0))
        print(a);

    return 0;
}