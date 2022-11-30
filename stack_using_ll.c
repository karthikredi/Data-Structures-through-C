#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}
node;

node *top = NULL;

void push(int value);
int pop();
void display();

int main(void)
{
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) 
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("Popped element is :%d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
}

void push(int value) {
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = value;
    if (top == NULL) {
        newnode->next = NULL;
    } else {
        newnode->next = top;
    }
    top = newnode;
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
        return 0;
    } else {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        for (node *temp = top; temp != NULL; temp = temp->next)
        {
            printf("%i\t", temp->data);
        }
        printf("\n");
    }
}