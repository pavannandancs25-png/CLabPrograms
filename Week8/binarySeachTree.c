#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
    struct btree * prev;
    int data;
    struct btree * next;
} * node;

node getNode(){
    node x = malloc(sizeof(struct btree));
    if(x == NULL){
        return NULL;
    }
    return x;
}

node insert(node head, int ele){

    if(head == NULL){
        node temp = getNode();
        temp->data = ele;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }

    if(head->data < ele){
        head->prev = insert(head->prev,ele);
    } else {
        head->next = insert(head->next,ele);
    }
    return head;
}

void displayPreorder(node head){
    if(head == NULL){
        printf("Tree is empty\n");
        return;
    }
    printf("%d ",head->data);
    if(head->prev != NULL){
        displayPreorder(head->prev);
    } if(head->next != NULL){
        displayPreorder(head->next);
    }

}

void displayInorder(node head){
    if(head == NULL){
        printf("Tree is empty\n");
        return;
    }
    if(head->prev != NULL){
        displayInorder(head->prev);
    }
    printf("%d ",head->data);
    if(head->next != NULL){
        displayInorder(head->next);
    }

}

void displayPostorder(node head){
    if(head == NULL){
        printf("Tree is empty\n");
        return;
    }
    if(head->prev != NULL){
        displayPostorder(head->prev);
    }
    if(head->next != NULL){
        displayPostorder(head->next);
    }
    printf("%d ",head->data);

}

void freeTree(node head){
    if(head == NULL){
        printf("Tree is empty\n");
        return;
    }
    if(head->prev != NULL){
        freeTree(head->prev);
    }
    if(head->next != NULL){
        freeTree(head->next);
    }
    free(head);

}

int main(void){
    int choice, ele;
    node head = NULL;

    while(1){
        printf("\n== Options ==\n");
        printf("1.Insert\n");
        printf("2.Traverse Preorder\n");
        printf("3.Traverse Inorder\n");
        printf("4.Traverse Postorder\n");
        printf("5.Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1 :
                printf("Enter the element to insert : ");
                scanf("%d",&ele);
                head = insert(head,ele);
                break;
            case 2:
                displayPreorder(head);
                break;
            case 3:
                displayInorder(head);
                break;
            case 4 :
                displayPostorder(head);
                break;
            case 5:
                freeTree(head);
                return 0;
            default : printf("Invalid Choice\n");
        }
    }
}
