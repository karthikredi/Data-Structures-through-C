#include <stdio.h>

int Prime(int a);

int main(void)
{
    int num;
    printf("Enter a number: \n");
    scanf("%i", &num);
    if (Prime(num))
    {
        printf("Prime\n");
        return 0;
    }
    printf("Not Prime");
}

int Prime(int a)
{
    for (int i = 2; i < a; i++)
    {
        if (a%i == 0)
        {
            return 0;
        }
    }
    return 1;
}