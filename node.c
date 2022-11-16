#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *adr; 
}
node;

int main(void)
{
    node *new = malloc(sizeof(node));
    new->data = 5;
    new->adr = NULL;
    printf("%i\n", new->data);
}