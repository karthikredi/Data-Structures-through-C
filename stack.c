#include <stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty();
int isfull();
void peek();
void pop();
void push();

int main()
{
    int x, choice;
    do
    {
        printf("Enter your choice\n1.PUSH\n2.POP\n3.PEEK\n");
        scanf("%i", &choice);
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
        printf("Do you want to perform any operations?\n");
        scanf("%i", &x);
    }while(x);
    return 0;
}

int isempty()
{
   if(top == -1)
      return 1;
   else
      return 0;
}
int isfull()
{
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}
void peek()
{
   printf("%i\n", stack[top]);
}
void pop()
{
   int data;
   if(!isempty())
   {
      data = stack[top];
      top = top - 1;  
      printf("%i\n", data);
   }
   else
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}
void push()
{
    int data;
   if(!isfull())
   {
        printf("Enter data value:\n");
        scanf("%i", &data);
        top = top + 1;   
        stack[top] = data;
   }
   else
   {
      printf("Could not insert data, Stack is full.\n");
   }
}