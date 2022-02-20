#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n=4,k=3,x[20];

void print()
{
    int i;
    for (i = 0; i < k; i++)
        printf("%d ", x[i]);
    printf("\n");
}

bool solutie(int i)
{
    return ++i==k;
}

bool ok(int i)
{
    for(int j=0;j<i;j++)
            if(x[j]>=x[i]) return false;
    return true;
}  

void back(int i)
{
    for(int j=0;j<n;j++)
    {
        x[i]=j+1;
        if(ok(i))
        {
            if(solutie(i))
                print();
            else back(i+1);
        }
    }
}

int main()
{
    back(0);
    return 0;
}