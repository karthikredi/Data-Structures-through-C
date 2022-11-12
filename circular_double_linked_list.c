#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}
node;

node *head = NULL, *tail = NULL;

int isempty(node *);
void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_begin();
void delete_middle();
void delete_end();
void transverse();
void transverse_backward();

int main(void)
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
            printf("Operations of Circual linked list\n1.Insertion\n2.Deletion\n3.Traversal\nEnter your choice\n");
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
                    printf("Traversal types\n1.Forward direction\n2.Backward direction\nEnter your choice\n");
                    int traversal_choice;
                    scanf("%i", &traversal_choice);
                    switch(traversal_choice)
                    {
                        case 1:
                            transverse();
                            break;
                        case 2:
                            transverse_backward();
                            break;
                        default:
                            printf("entered choice is wrong");
                    }
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
    int x, y;
    node *temp, *current = NULL;
    printf("Enter number of nodes: \n");
    scanf("%i", &y);
    while(y)
    {
        printf("Enter data value: \n");
        scanf("%i", &x);
        temp = malloc(sizeof(node));
        temp->data = x;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            current->next = temp;
            temp->prev = current;
        }
        current = temp;
        y--;

    }
    for(node *temp = head; temp != NULL; temp = temp->next)
    {
        if(temp->next == NULL)
        {
            tail = temp;
            break;
        }
    }
    tail->next = head;
    head->prev = tail;
}

void insert_begin()
{
    int x;
    printf("Inserting before head\nEnter data value:\n");
    scanf("%i", &x);
    node *new;
    new = malloc(sizeof(node));
    new->data = head->data;
    new->next = head->next;
    new->prev = head;
    head->data = x;
    head->next = new;
    new->next->prev = new;
    
}

void insert_middle()
{
    int x, y, i = 1;
    printf("Inserting in the middle\nEnter data value:\n");
    scanf("%i", &x);
    printf("Enter after which node you want to insert:\n");
    scanf("%i", &y);
    node *new;
    new = malloc(sizeof(node));
    new->data = x;
    for(node *temp = head; temp != NULL; temp = temp->next)
    {
        if(i == y)
        {
            temp->next->prev = new;
            new->next = temp->next;
            new->prev = temp;
            temp->next = new;
            break;
        }
        i++;
    }
}

void insert_end()
{
    int x;
    printf("Inserting after tail\nEnter data value:\n");
    scanf("%i", &x);
    node *new;
    new = malloc(sizeof(node));
    new->data = tail->data;
    new->prev = tail->prev;
    tail->prev->next = new;
    tail->data = x;
    tail->prev = new;
    new->next = tail;
}

void delete_begin()
{
    printf("Deletion at the start\n");
    node *temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
}

void delete_middle()
{
    int y, i = 1;
    printf("Deletion in the middle\nEnter node value:\n");
    scanf("%i", &y);
    for(node *temp = head; temp != NULL; temp = temp->next)
    {
        if(i == y)
        {
            node *new = temp->next;
            new->prev = temp->prev;
            temp->prev->next = new;
            free(temp);
            break;
        }
        i++;
    }
    
}

void delete_end()
{
    printf("Deletion at the end\n");
    node *temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    free(temp);
}

void transverse()
{
    printf("Transverse\n");
    for(node *temp = head; temp != NULL; temp = temp->next)
    {
        printf("%i\n", temp->data);
        if(temp == tail)
        {
            break;
        }
    }
}

void transverse_backward()
{
    printf("Transerve Backwards: \n");
    for(node *temp = tail; temp != NULL; temp = temp->prev)
    {
        printf("%i\n", temp->data);
        if(temp == head)
        {
            break;
        }
    }
}