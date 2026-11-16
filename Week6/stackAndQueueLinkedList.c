#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} *NODE;

NODE front = NULL, rear = NULL, top = NULL;

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

NODE push(NODE first, int ele){
    NODE temp = getNode();
    if(temp == NULL){
        return first;
    }
    temp->data = ele;
    temp->link = first;
    printf("Added %d\n", ele);
    return temp;
}

void display(NODE first){
    if(first == NULL){
        printf("List is empty\n");
        return;
    }
    NODE temp = first;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void dequeue(){
    if(front == NULL){
        printf("List Underflow\n");
        return;
    }
    if(front->link == NULL){
        printf("Deleted %d\n", front->data);
        freeNode(front);
        front = NULL;
        rear = NULL;
        return;
    }
    NODE temp = front;
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    NODE temp2 = temp->link;
    temp->link = NULL;
    rear = temp;
    printf("Deleted %d\n", temp2->data);
    freeNode(temp2);
}

NODE pop(){
    if(top == NULL){
        printf("List Underflow\n");
        return NULL;
    }
    NODE temp = top->link;
    printf("Deleted %d\n", top->data);
    freeNode(top);
    top = temp;
    return top;
}

void freeAll(NODE head) {
    NODE temp;
    while(head != NULL) {
        temp = head;
        head = head->link;
        freeNode(temp);
    }
}

int main() {
    int choice, ele;

    while(1) {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display Stack\n");
        printf("4.Enqueue\n");
        printf("5.Dequeue\n");
        printf("6.Display Queue\n");
        printf("7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                top = push(top, ele);
                break;
            case 2:
                top = pop();
                break;
            case 3:
                printf("Stack elements: ");
                display(top);
                break;
            case 4:
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                front = push(front, ele);
                if(front->link == NULL) {
                    rear = front;
                }
                break;
            case 5:
                dequeue();
                break;
            case 6:
                printf("Queue elements: ");
                display(front);
                break;
            case 7:
                freeAll(top);
                freeAll(front);
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
