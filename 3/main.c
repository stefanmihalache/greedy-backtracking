#include <stdio.h>
#include <stdlib.h>


int n = 6, a[] = {1, 2, 3}, m = (sizeof(a)/sizeof(a[0])), x[20];

void print()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
}


int solution(int k)
{
    return ++k == n;
}

void back(int k)
{  

    for (int i = 0; i < m; i++)
    {
        x[k] = a[i];

        if (solution(k))
            print();
        else back(k+1);
            
    }
}

int main()
{   
    back(0);
    return 0;
}