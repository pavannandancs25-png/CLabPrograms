#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} *NODE;

NODE getNode() {
    NODE head = (NODE)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    return head;
}

void freeNode(NODE n) {
    if(n == NULL) {
        printf("Node is already free\n");
        return;
    }
    free(n);
}

NODE insertFront(NODE front,int ele){
    NODE temp = getNode();
    if(temp == NULL){
        return front;
    }
    temp->data=ele;
    temp->link=front;
    printf("Added %d to the front",ele);
    return temp;
}

NODE insertRear(NODE front,int ele){
    NODE temp = getNode();
    if(temp == NULL){
        return NULL;
    }
    temp->data=ele;
    temp->link=NULL;
    NODE temp2 = front;
    if(temp2 == NULL){
        printf("Added %d to the rear",ele);
        return temp;
    }
    while(temp2->link != NULL){
        temp2=temp2->link;
    }
    temp2->link=temp;
    printf("Added %d to the rear",ele);
    return front;
}

NODE insertAtPos(NODE front,int ele,int pos){
    if(pos < 0) {
        printf("Invalid Position\n");
        return front;
    }
    if(pos == 0){
        return insertFront(front,ele);
    }

    int count = 0;
    NODE temp2 = front;
    while(temp2 != NULL && count < pos-1){
        temp2=temp2->link;
        count++;
    }
    if(temp2 == NULL) {
        printf("Position Out of Bounds\n");
        return front;
    }
    NODE temp = getNode();
    if(temp == NULL) return front;
    temp->data=ele;
    temp->link=temp2->link;
    temp2->link=temp;
    printf("Added %d to the position %d",ele,pos);
    return front;
}

void display(NODE front){
    if(front == NULL){
        return;
    }
    NODE temp = front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

NODE deleteAtFront(NODE front){
    if(front == NULL){
        printf("List Underflow\n");
        return NULL;
    }
    NODE temp=front->link;
    printf("Deleted %d at the position front",front->data);
    freeNode(front);
    return temp;
}

NODE deleteAtRear(NODE front){
    if(front == NULL){
        printf("List Underflow\n");
        return NULL;
    }
    if(front->link == NULL){
        printf("Deleted %d at the position rear",front->data);
        freeNode(front);
        return NULL;
    }
    NODE temp=front;
    while(temp->link->link != NULL){
        temp=temp->link;
    }
    NODE temp2 = temp->link;
    temp->link = NULL;
    printf("Deleted %d at the position rear",temp2->data);
    freeNode(temp2);
    return front;
}


NODE deleteAtPos(NODE front,int pos){
    if(front == NULL){
        printf("List Underflow\n");
        return NULL;
    }
    if(pos < 0) {
        printf("Invalid Position\n");
        return front;
    }
    if(pos == 0){
        return deleteAtFront(front);
    }

    NODE temp=front;
    int count=0;
    while(temp != NULL && count<pos-1){
        temp=temp->link;
        count++;
    }
    if(temp == NULL || temp->link == NULL) {
        printf("Position out of bounds\n");
    }
    NODE temp2 = temp->link;
    temp->link = temp2->link;
    printf("Deleted %d at the position %d",temp2->data,pos);
    freeNode(temp2);
    return front;
}

int main () {
    int choice,ele,pos;
    NODE front = NULL;

    while (1) {
        printf("== Options ==\n");
        printf("1.Inset At Front\n");
        printf("2.Inset At Rear\n");
        printf("3.Inset At Pos\n");
        printf("4.Delete At Front\n");
        printf("5.Delete At Rear\n");
        printf("6.Delete At Pos\n");
        printf("7.Display\n");
        printf("8.Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1 :
                printf("Enter the element to insert : ");
                scanf("%d",&ele);
                front = insertFront(front,ele);
                break;
            case 2:
                printf("Enter the element to insert : ");
                scanf("%d",&ele);
                front = insertRear(front,ele);
                break;
            case 3:
                printf("Enter the element to insert : ");
                scanf("%d",&ele);
                printf("Enter the position to insert : ");
                scanf("%d",&pos);
                front = insertAtPos(front,ele,pos);
                break;
            case 4 :
                front = deleteAtFront(front);
                break;
            case 5:
                front = deleteAtRear(front);
                break;
            case 6:
                printf("Enter the position to insert : ");
                scanf("%d",&pos);
                front = deleteAtPos(front,pos);
                break;
            case 7:
                display(front);
                break;
            case 8:
                while(front != NULL) {
                    front = deleteAtFront(front);
                }
                return 0;
            default : printf("Invalid Choice\n");
        }

    }

    return 0;
}

