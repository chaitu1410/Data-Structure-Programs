#include<stdio.h>
#include<stdlib.h>

typedef struct node{
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

    if(Head != NULL){
        Node* t = Head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = n;
        printf("\n%d inserted.\n", o);
    }else{
        Head = n;
        printf("\n%d inserted.\n", o);
    }
}

void insertAt(int at, int o){
    Node *n = createNode();
    n->data = o;
    n->next = NULL;
    int c = 1;
    if(at == 1){
        n->next = Head;
        Head = n;
        printf("\n%d inserted.\n", o);
    }else{
        Node* t = Head;
        while((c+1) != at){
            if(t==NULL){
                break;
            }
            t=t->next;
            c++;
        }
        if(t != NULL){
            n->next = t->next;
            t->next = n;
            printf("\n%d inserted.\n", o);
        }else{
            printf("\nLinked List index out of bound.\n");
        }
    }
}

void removeElement(){
    if(Head->next != NULL){
        Node *t = Head;
        while(t->next->next != NULL){
            t = t->next;
        }
        printf("\n%d removed.\n", t->next->data);
        free(t->next);
        t->next = NULL;
    }else if(Head != NULL){
        printf("\n%d removed.\n", Head->data);
        free(Head);
        Head = NULL;
    }
    else{
        printf("\nLinked List is empty.\n");
    }
}

void removeAt(int at){
    int c = 1;
    if(at == 1 && Head != NULL){
        Node *t = Head;
        Head = Head->next;
        free(t);
    }else if(Head != NULL){
        Node* t = Head;
        while((c+1) != at){
            if(t==NULL){
                break;
            }
            t=t->next;
            c++;
        }
        if(t != NULL && t->next != NULL){
            Node *p = t->next;
            t->next = t->next->next;
            printf("\n%d removed.\n", p->data);
            free(p);
        }else{
            printf("\nLinked List index out of bound.\n");
        }
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
        printf("\nLinked List is empty.");
    }
    printf("\n");
}

int main()
{
    insert(43);
    insert(234);
    insert(64);
    insertAt(2,23);
    insertAt(5,65);
    insertAt(9,22);
    print();
    removeElement();
    removeAt(3);
    removeAt(9);
    print();
    printf("\n\n\n");
}
