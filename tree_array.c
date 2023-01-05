#include <stdio.h>

void parent(int node, int tree[], int size);
void children(int node, int tree[], int size);

int main(void)
{
    int size, choice;
    printf("Enter size of node: \n");
    scanf("%d", &size);
    int tree[size];
    printf("Enter tree node values: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &tree[i]);
    }
    do
    {
        if (choice)
        {
            int node;
            int option;
            printf("Enter your choice:\n1.Finding parent\n2.Finding children\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                printf("Whose parent you want to find? \n");
                scanf("%d", &node);
                parent(node, tree, size);
                break;
            case 2:
                printf("Whose children you want to find? \n");
                scanf("%d", &node);
                children(node, tree, size);
                break;
            default:
                printf("Invalid choice\n");
            }
        }
        printf("Do you want to perform operations (y/n)?: \n");
        scanf("%d", &choice);
    } while (choice);
}

void parent(int node, int tree[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tree[i] == node)
        {
            if (i % 2 == 0)
                printf("parent: %d\n", tree[(node - 2) / 2]);
            else
                printf("parent: %d\n", tree[(node - 1) / 2]);
        }
    }
}

void children(int node, int tree[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tree[i] == node)
        {
            printf("left child:%d\nright child:%d\n", tree[2 * i + 1], tree[2 * i + 2]);
        }
    }
}
