#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n = 3, x[20];

void print()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

bool solution(int k)
{
    return ++k == n;
}

bool ok(int k)
{
    for (int i = 0; i < k; i++)
        if (x[i] == x[k])
            return false;
    return true;
}

void back(int k)
{

    for (int i = 1; i <= n; i++)
    {
        x[k] = i;
        if (ok(k))
            if (solution(k))
                print();
            else
                back(k + 1);
    }
}

int main()
{

    back(0);
    return 0;
}