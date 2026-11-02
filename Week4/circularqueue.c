#include <stdio.h>
#define MAX 5

void insert(int queue[], int *front,int *rear,int *count, int ele) {
    if(*count == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    (*rear) = (*rear + 1) % MAX;
    queue[*rear] = ele;
    (*count)++;
    printf("Element %d added to the queue\n",ele);
}

void delete(int queue[], int *front,int *rear,int *count) {
    if(*count == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Removed Element %d from the stack\n",queue[(*front)]);
    (*front) = (*front + 1) % MAX;
    (*count)--;
}

void display(int queue[], int front, int rear,int count) {
    if(count == 0) {
        printf("Queue is Empty\n");
        return;
    }
    for(int i = front; i < front + count; i++) {
        printf("%d ",queue[i % MAX]);
    }
    printf("\n");
}


int main () {
    int queue[MAX],front=0,rear=-1,choice,ele,count=0;

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
                insert(queue,&front,&rear,&count,ele);
                break;
            case 2:
                delete(queue,&front,&rear,&count);
                break;
            case 3:
                display(queue,front,rear,count);
                printf("\n");
                break;
            case 4:return 0;
            default : printf("Invalid Choice\n");
        }

    }

    return 0;
}
