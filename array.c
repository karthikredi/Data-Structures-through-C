#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("Enter size of an array:\n");
    scanf("%i", &n);
    int *arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element value:\n");
        scanf("%i", &arr[i]);
    }
    printf("Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", arr[i]);
    }
}