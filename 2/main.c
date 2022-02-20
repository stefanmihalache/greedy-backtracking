#include <stdio.h>
#include <stdlib.h>

void rest(int n)
{
    int a[] = {150, 50, 30, 15, 5, 3, 1}, *b, i, c;
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

/*
    algoritmul ia de fiecare data cea mai mare bancnota mai mica de suma de bani
    daca am avea de exemplu 90 algoritmul ar produce solutia 50 30 5 5 deci 4 bancnote
    dar solutia optima evidenta este 3 bancnote de 30
*/

int main()
{
    int n;
    printf("Cititi suma de bani: ");
    scanf("%d", &n);

    rest(n);

    return 0;
}