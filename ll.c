#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *adr;
}
node;

node *head = NULL;

int isempty(node *);
void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_begin();
void delete_middle();
void delete_end();
void transverse();

int main()
{
    int choice, c;
    do
    {
        if(isempty(head))
        {
            create();
        }
        else
        {
            printf("Operations of Linked list\n1.Insertion\n2.Deletion\n3.Traversal\nEnter your choice\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("Insertion types\n1.Insertion @ the begining\n2.Insertion in the middle\n3.Insertion @ the end\n");
                    int insert_choice;
                    printf("Enter your choice\n");
                    scanf("%d", &insert_choice);
                    switch(insert_choice)
                    {
                        case 1:
                            insert_begin();
                            break;
                        case 2:
                            insert_middle();
                            break;
                        case 3:
                            insert_end();
                            break;
                        default:
                            printf("Entered insertion choice is wrong\n");
                    }
                    break;
                case 2:
                    printf("Deletion types\n1.Deletion from the begining\n2.Deletion from the middle\n3.Deletion from the end\n");
                    int delete_choice;
                    printf("Enter your choice\n");
                    scanf("%d", &delete_choice);
                    switch(delete_choice)
                    {
                        case 1:
                            delete_begin();
                            break;
                        case 2:
                            delete_middle();
                            break;
                        case 3:
                            delete_end();
                            break;
                        default:
                            printf("Entered insertion choice is wrong\n");
                    }
                    break;
                case 3:
                    transverse();
                    break;
                default:
                    printf("entered choice is wrong");
            }
        }
        printf("Do you want to perform operations? any number for Yes and zero for No.\n");
        scanf("%i", &c);
    }while(c);
}

int isempty(node *head)
{
    if(head == NULL)
    {
        return 1;
    }
    return 0;
}
void create()
{
    node *prev, *temp;
    int n;
    printf("Enter number of nodes: \n");
    scanf("%i", &n);
    for(int i = 0; i < n; i++)
    {
        temp = malloc(sizeof(struct node));
        printf("Enter Data value: \n");
        scanf("%i", &temp->data);
        temp->adr = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            prev->adr = temp;
        }
        prev = temp;
    }
}

void insert_begin()
{
    node *prev;
    prev = malloc(sizeof(head));
    int x;
    printf("Enter data value: \n");
    scanf("%i", &x);
    prev->data = head->data;
    prev->adr = head->adr;
    head->data = x;
    head->adr = prev;
}

void insert_middle()
{
    node *new;
    new = malloc(sizeof(head));
    int x, y, i = 0;
    printf("Enter after which node you want to insert a new node: \n");
    scanf("%i", &y);
    printf("Enter data value: \n");
    scanf("%i", &x);
    new->data = x;
    new->adr = NULL;
    for(node *temp = head; temp != NULL; temp = temp->adr)
    {
        if(i == (y - 1))
        {
            new->adr = temp->adr;
            temp->adr = new;
            break;
        }
        i++;
    }
}

void insert_end()
{
    node *new;
    new = malloc(sizeof(head));
    int x;
    printf("Enter data value: \n");
    scanf("%i", &x);
    for(node *temp = head; temp != NULL; temp = temp->adr)
    {
        if(temp->adr == NULL)
        {
            new->data = x;
            temp->adr = new;
            new->adr = NULL;
            break;
        }
    }
}

void delete_begin()
{
    head = head->adr;
}

void delete_middle()
{
    node *prev = NULL;
    prev = malloc(sizeof(head));
    int y, i = 1;
    printf("Enter the node you want to delete: \n");
    scanf("%i", &y);
    for(node *temp = head; temp != NULL; temp = temp->adr)
    {
        if(i != y)
        {
            prev = temp;
        }
        else
        {
            prev->adr = temp->adr;
            free(temp);
            break;
        }
        i++;
    }
}

void delete_end()
{
    for(node *temp = head; temp != NULL; temp = temp->adr)
    {
        if(temp->adr->adr == NULL)
        {
            temp->adr = NULL;
        }
    }
}

void transverse()
{
    printf("Transverse\n");
    for(node *temp = head; temp != NULL; temp = temp->adr)
    {
        printf("%i\n", temp->data);
    }
}