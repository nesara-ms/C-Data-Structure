#include <stdio.h>

#define MAX 10

char stack[MAX][50];

int top = -1;

// 1. PUSH - Visit a new webpage

void push()
{
    if (top == MAX - 1)
    {
        printf("History is full!\n");
    }
    else
    {
        top++;

        printf("Enter webpage name: ");
        scanf("%s", stack[top]);

        printf("Webpage added successfully!\n");
    }
}

// 2. POP - Navigate back
void pop()
{
    if (top == -1)
    {
        printf("No previous webpage available!\n");
    }
    else
    {
        printf("Going back from: %s\n", stack[top]);
        top--;

        if (top == -1)
            printf("No webpage available!\n");
        else
            printf("Current webpage: %s\n", stack[top]);
    }
}

// 3. PEEK - Display current webpage
void peek()
{
    if (top == -1)
    {
        printf("No webpage available!\n");
    }
    else
    {
        printf("Current webpage: %s\n", stack[top]);
    }
}

// 4. DISPLAY - Display complete history
void display()
{
    int i;

    if (top == -1)
    {
        printf("History is empty!\n");
    }
    else
    {
        printf("Browsing History:\n");

        for (i = 0; i <= top; i++)
        {
            printf("%s\n", stack[i]);
        }
    }
}

// 5. CLEAR - Clear browsing history
void clear()
{
    top = -1;
    printf("Browsing history cleared!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Browser History Management ---\n");
        printf("1. Visit webpage (PUSH)\n");
        printf("2. Go back (POP)\n");
        printf("3. Current webpage (PEEK)\n");
        printf("4. Display history\n");
        printf("5. Clear history\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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

            case 4:
                display();
                break;

            case 5:
                clear();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

