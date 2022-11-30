#include <stdio.h>

void primefactors(int a);

int main(void)
{
    int num;
    printf("Enter a number: \n");
    scanf("%i", &num);
    printf("prime factors:\n");
    primefactors(num);
}

void primefactors(int a)
{
    int j, count = 0;
    for (int i = 2; i < a; i++)
    {
        if(a%i == 0)
        {
            for(j = 2; j < i; j++)
            {
                if(i%j == 0)
                {
                    count++;
                }
            }
            if(count == 0)
            {
                printf("%i\n", i);
            }
            count = 0;
        }
        
    }
}