#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE * prev;
    int data;
    struct NODE* next;
}* node;

node getNode(){
    node n = malloc(sizeof(struct NODE));
    if(n == NULL){
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    return n;
}

void freeNode(node n){
    if(n == NULL){
        printf("Memory Already Freed\n");
        return;
    }
    free(n);
}

node insertFront(node front, int ele){
    node n = getNode();
    if(n == NULL){
        return NULL;
    }
    n->data = ele;
    n->prev = NULL;
    n->next = front;
    printf("Inserted %d\n",ele);
    if(front != NULL){
        front->prev = n;
    }
    return n;
}

node delNodeByPos(node front, int pos){
    if(pos < 1){
        printf("Invalid Position\n");
        return NULL;
    }
    if(front == NULL){
        printf("UnderFlow \n");
        return NULL;
    }
    if(front->next == NULL){
        printf("Deleted %d from the list",front->data);
        freeNode(front);
        return NULL;
    }
    int count = 1;
    node temp = front;
    while(temp->next != NULL && count < pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    printf("Deleted %d from the list\n",temp->data);
    freeNode(temp);
    return front;
}

void display(node front){
    if(front == NULL){
        printf("List is empty\n");
    }
    node temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main () {
    int choice,ele,pos;
    node front = NULL;

    while (1) {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1 :
                printf("Enter the element to insert : ");
                scanf("%d",&ele);
                front = insertFront(front,ele);
                break;
            case 2:
                printf("Enter the position to delete : ");
                scanf("%d",&pos);
                front = delNodeByPos(front,pos);
                break;
            case 3:
                display(front);
                break;
            case 4:
                pos = 1;
                while(front != NULL) {
                    front = delNodeByPos(front,pos);
                    pos++;
                }
                return 0;
            default : printf("Invalid Choice\n");
        }

    }

    return 0;
}
