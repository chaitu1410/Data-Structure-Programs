#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
} Node;

Node* Head = NULL;

Node* createNode(){
    return (Node*) malloc(sizeof(Node));
}

void insert(int o){
    Node *n = createNode();
    n->data = o;
    n->next = NULL;
    n->prev = NULL;

    if(Head != NULL){
        Node* t = Head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = n;
        n->prev = t;
    }else{
        Head = n;
    }
}

void removeElement(){
    if(Head->next != NULL){
        Node *t = Head;
        while(t->next->next != NULL){
            t = t->next;
        }
        printf("\n\n%d removed.\n", t->next->data);
        free(t->next);
        t->next = NULL;
    }else if(Head != NULL){
        printf("\n\n%d removed.\n", Head->data);
        free(Head);
        Head = NULL;
    }
    else{
        printf("\n\nLinked List is empty.\n");
    }
}


void print(){
    printf("\n\nLinked List Elements : \n");
    if(Head != NULL){
        Node *t = Head;
        while(t != NULL){
            printf("%d ", t->data);
            t = t->next;
        }
    }else{
        printf("\n\nLinked List is empty.\n");
    }
}

void printReverse(){
    printf("\n\nLinked List Elements In Reverse Order : \n");
    if(Head != NULL){
        Node *t = Head;
        while(t->next != NULL){
            t = t->next;
        }
        while(t != NULL){
            printf("%d ", t->data);
            t = t->prev;
        }
    }else{
        printf("\n\nLinked List is empty.\n");
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    print();
    printReverse();
    printf("\n\n\n");
}
