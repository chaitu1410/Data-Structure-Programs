#include<stdio.h>
#define MAX 10
#define MAX_TOP (MAX - 1)

typedef struct CSIPs{
    int cs;
    int ip;
} CSIP;

CSIP Stack[MAX];
int top = -1;
int overflow, underflow;

CSIP input()
{
    CSIP ele;
    printf("Enter Current CS and IP(Space Separated) : ");
    scanf("%d%d", &ele.cs, &ele.ip);
    return ele;
}

void printCSIP(CSIP ele)
{
    printf("(CS: %d, IP: %d)\n",ele.cs, ele.ip);
}

void push()
{
    if(top == MAX_TOP)
    {
        printf("STACK OVERFLOW\n");
        overflow = 1;
        return;
    }
    overflow=0;
    Stack[++top] = input();
}

CSIP pop()
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW\n");
        underflow=1;
        return;
    }
    underflow=0;
    return Stack[top--];
}

void status()
{
    printf("\nHere's Your Call Stack: \n");
    if(underflow){
        printf("Empty...\n");
    }
    for(int i = top; i >= 0; i--)
    {
        printCSIP(Stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    CSIP csip;

    printf("Hello Processor!\n");
    do
    {
        printf("\nWhat Do You want to Do? : \n");
        printf("1. Call a Function\n");
        printf("2. Return From a Function\n");
        printf("3. Print Call Stack\n");
        printf("4. Execute Other Instruction\n");
        printf("5. Exit\n>>> ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            push();
            break;

        case 2:
            csip = pop();
            if(!underflow)
            {
                printf("\nGo To This Address: ");
                printCSIP(csip);
            }
            break;

        case 3:
            status();
            break;

        case 4:
            printf("\nInstruction Executed\n");
            break;

        case 5:
            printf("\nBye...\n");
            return 0;
        default:
            printf("\nMake valid choice...\n");
        }

    }
    while(1);
}
