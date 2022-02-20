#include <stdio.h>
#include <stdlib.h>

void rest(int n)
{
    int a[] = {100, 50, 10, 5, 1}, *b, i, c;
    c = sizeof(a) / sizeof(a[0]);
    b = (int *)calloc(c, sizeof(int));

    for (i = 0; i < c; i++)
        while (n >= a[i])
        {
            b[i]++;
            n -= a[i];
        }
    printf("Restul:\n");
    for (i = 0; i < c; i++)
        if (b[i])
            printf("%d bancnote de %d\n", b[i], a[i]);
    free(b);
}

int main()
{
    int n;
    printf("Cititi suma de bani: ");
    scanf("%d", &n);

    rest(n);

    return 0;
}