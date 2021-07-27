#include<stdio.h>
#define MAX 5
int Queue[MAX] = {NULL};
int front = -1, rear = -1;

int isEmpty(){
    if(front == -1)
        return 1;
    return 0;
}

int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    return 0;
}

void enqueue(int o){
    if(isFull()){
        printf("Queue overflow...\n");
        return;
    }
    if(rear == -1){
        front++;
        Queue[++rear] = o;
    }else{
        Queue[++rear] = o;
    }
    printf("%d Inserted\n", o);
}

void dequeue(){
    if(isEmpty()){
        printf("Queue underflow...\n");
        return;
    }
    if(rear == front){
        printf("%d removed\n", Queue[front]);
        front = -1;
        rear=  -1;
    }else{
        printf("%d removed\n", Queue[front]);
        front++;
    }
}

void status(){
    printf("\nQueue:\n");
    for(int i = front; i <= rear; i++){
        printf(" %d", Queue[i]);
    }
    printf("\n");
}

int main()
{
    int c, element;

    do{
        printf("\nEnter your choice : \n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Status\n");
        printf("4. Exit\n");
        printf(">>> ");
        scanf("%d", &c);
        switch(c){
        case 1:
            printf("\nEnter Element : ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            status();
            break;
        case 4:
            printf("\nBye Bye\n\n");
            break;
        default:
            printf("\nEnter Valid Choice\n");
        }
    }while(c != 4);
}
