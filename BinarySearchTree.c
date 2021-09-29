#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
 struct node *left;
 int data;
 struct node *right;
} Node;

Node *root = NULL;

Node* queue[20];

int front = -1;
int rear = -1;

void enqueue(Node *n)
{
    if(rear == -1)
    {
        front++;
        rear++;
    }else{
        rear++;
    }

    queue[rear] = n;
    //printf("\nenqueue %d", queue[rear]->data);
}

Node* dequeue()
{
    Node *q;
    if(front == -1)
    {
        return NULL;
    }
    q = queue[front];
    front++;
    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
    //printf("\ndequeue %d", q->data);
    return q;
}


Node* Search(int key)
{
 Node *t = root;

 while(t != NULL)
 {
     if(key == t->data)
        return t;
     else if(key < t->data)
        t = t->left;
     else
        t = t->right;
     }
     return NULL;
}

Node* Insert(Node *p,int key)
{
 Node *t = NULL;

 if(p == NULL)
 {
     t = (Node *)malloc(sizeof(Node));
     t->data = key;
     t->left = t->right = NULL;
     return t;
 }
 if(key < p->data)
    p->left = Insert(p->left, key);
 else if(key > p->data)
    p->right = Insert(p->right, key);
 return p;
}

int Height(Node *p)
{
  int x,y;
  if(p == NULL)return 0;
  x = Height(p->left);
  y = Height(p->right);
  return x > y ? x+1 : y+1;
}

Node* InorderPredecessor(Node *p)
{
 while(p && p->right != NULL)
 p = p->right;
 return p;
}

Node* InorderSuccessor(Node *p)
{
 while(p && p->left != NULL)
    p = p->left;

 return p;
}

Node* Delete(Node *p,int key)
{
 Node *q;

 if(p == NULL)
    return NULL;
 if(p->left == NULL && p->right == NULL)
 {
     if(p == root)
        root = NULL;
     free(p);
     return NULL;
 }

 if(key < p->data)
    p->left = Delete(p->left, key);
 else if(key > p->data)
    p->right = Delete(p->right, key);
 else
 {
     if(Height(p->left) > Height(p->right))
     {
         q = InorderPredecessor(p->left);
         p->data = q->data;
         p->left = Delete(p->left, q->data);
     }
    else
     {
         q = InorderSuccessor(p->right);
         p->data = q->data;
         p->right = Delete(p->right, q->data);
     }
 }
 return p;
}
void Preorder(Node *p)
{
 if(p)
 {
     printf("%d ", p->data);
     Preorder(p->left);
     Preorder(p->right);
 }
}

void Inorder(Node *p)
{
 if(p)
 {
     Inorder(p->left);
     printf("%d ", p->data);
     Inorder(p->right);
 }
}

void Postorder(Node *p)
{
 if(p)
 {
     Postorder(p->left);
     Postorder(p->right);
     printf("%d ", p->data);
 }
}

void Levelorder(Node *p)
{
 Node *temp = NULL;
 temp = p;
 while(temp != NULL)
 {
     //printf("\nbefore enqueue");
     printf("%d ", temp->data);
     if(temp->left != NULL)
        enqueue(temp->left);

     if(temp->right != NULL)
        enqueue(temp->right);
    //printf("\nafter enqueue");

    temp = dequeue();
    //printf("\nafter dequeue");
 }
}

int main()
{
 Node *temp;
 int choice, d, k;

 do{
    printf("\nEnter your choice : ");
    printf("\n1. Insert Element");
    printf("\n2. Delete Element");
    printf("\n3. Search Element");
    printf("\n4. Pre-order Traversal");
    printf("\n5. In-order Traversal");
    printf("\n6. Post-order Traversal");
    printf("\n7. Level-order Traversal");
    printf("\n8. Exit");
    printf("\n>>>");
    scanf("%d", &choice);

    switch(choice){
        case 1 : {
            printf("\nEnter element to insert : ");
            scanf("%d", &d);
            if(root == NULL)
                root = Insert(root,d);
            Insert(root,d);
            break;
        }

        case 2 : {
            printf("\nEnter element to delete : ");
            scanf("%d", &d);
            temp = Delete(root,d);
            if(temp != NULL)
                printf("Element %d is deleted\n", d);
            else
                printf("Element is not found\n");
            temp = NULL;
            break;
        }

        case 3 : {
            printf("\nEnter element to search : ");
            scanf("%d", &d);
            temp = Search(d);
            if(temp != NULL)
                printf("Element %d is found\n", temp->data);
            else
                printf("Element is not found\n");
            temp = NULL;
            break;
        }

        case 4 : {
            printf("\nPreorder : ");
            Preorder(root);
            break;
        }

        case 5 : {
            printf("\nInorder : ");
            Inorder(root);
            break;
        }

        case 6 : {
            printf("\nPostorder : ");
            Postorder(root);
            break;
        }
        case 7 : {
            printf("\nLevel Order : ");
            Levelorder(root);
            break;
        }

        case 8 : {
            printf("\nBye Bye");
            break;
        }

        default : {
            printf("\nEnter valid choice");
        }
    }
 }
 while(choice != 8);


 return 0;
}
