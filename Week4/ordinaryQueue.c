#include <stdio.h>
#define MAX 5

void insert(int queue[], int *front,int *rear, int ele) {
    if(*rear == MAX-1) {
        printf("Queue Overflow\n");
        return;
    }

    queue[++(*rear)] = ele;
    printf("Element %d added to the queue\n",ele);
}

void delete(int queue[], int *front,int *rear) {
    if(*front > *rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Removed Element %d from the stack\n",queue[(*front)++]);
    if(*front > *rear) {
        *front = 0;
        *rear = -1;
    }
}

void display(int queue[], int front, int rear) {
    if(front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    for(int i = front; i <= rear; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}


int main () {
    int queue[MAX],front=0,rear=-1,choice,ele;

    while (1) {
        printf("== Options ==\n");
        printf("1.Inset\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1 :
                int ele;
                printf("Enter the element to insert : ");
                scanf("%d",&ele);
                insert(queue,&front,&rear,ele);
                break;
            case 2:
                delete(queue,&front,&rear);
                break;
            case 3:
                display(queue,front,rear);
                printf("\n");
                break;
            case 4:return 0;
            default : printf("Invalid Choice\n");
        }

    }

    return 0;
}
