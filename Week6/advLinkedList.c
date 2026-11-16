#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} *NODE;





NODE getNode() {
    NODE head = (NODE)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    return head;
}

void freeNode(NODE n) {
    if (n == NULL) {
        printf("Node is already free\n");
        return;
    }
    free(n);
}

NODE insertEnd(NODE head, int data) {
    NODE newNode = getNode();
    if (newNode == NULL) return head;

    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) {
        return newNode;
    }

    NODE temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return head;
}

void displayList(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }

}

NODE sortList(NODE head) {
    if (head == NULL || head->link == NULL) {
        return head;
    }
    NODE i, j;
    int temp;

    for (i = head; i->link != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

NODE reverseList(NODE head) {
    NODE prev = NULL;
    NODE current = head;
    NODE next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}

NODE concatenateLists(NODE head1, NODE head2) {
    NODE newHead = NULL;
    NODE temp = head1;

    while (temp != NULL) {
        newHead = insertEnd(newHead, temp->data);
        temp = temp->link;
    }

    temp = head2;
    while (temp != NULL) {
        newHead = insertEnd(newHead, temp->data);
        temp = temp->link;
    }

    return newHead;
}


NODE freeList(NODE head) {
    NODE temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        freeNode(temp);
    }
    return NULL;
}

int main() {
    NODE list1 = NULL;
    NODE list2 = NULL;
    NODE concatList = NULL;
    int choice, data, listChoice;

    while (1) {
        printf("1.Insert to List 1\n");
        printf("2.Insert to List 2\n");
        printf("3.Display Lists\n");
        printf("4.Sort a List\n");
        printf("5.Reverse a List\n");
        printf("6.Concatenate List 1 and List 2\n");
        printf("7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into List 1: ");
                scanf("%d", &data);
                list1 = insertEnd(list1, data);
                printf("Added %d to List 1\n", data);
                break;

            case 2:
                printf("Enter data to insert into List 2: ");
                scanf("%d", &data);
                list2 = insertEnd(list2, data);
                printf("Added %d to List 2\n", data);
                break;

            case 3:
                printf("List 1: ");
                displayList(list1);
                printf("\nList 2: ");
                displayList(list2);
                if (concatList != NULL) {
                    printf("Concatenated List: ");
                    displayList(concatList);
                }
                break;

            case 4:
                printf("Which list do you want to sort? (1 or 2): ");
                scanf("%d", &listChoice);
                if (listChoice == 1) {
                    list1 = sortList(list1);
                    printf("List 1 sorted.\n");
                } else if (listChoice == 2) {
                    list2 = sortList(list2);
                    printf("List 2 sorted\n");
                } else {
                    printf("Invalid list\n");
                }
                break;

            case 5:
                printf("Which list do you want to reverse? (1 or 2): ");
                scanf("%d", &listChoice);
                if (listChoice == 1) {
                    list1 = reverseList(list1);
                    printf("List 1 reversed\n");
                } else if (listChoice == 2) {
                    list2 = reverseList(list2);
                    printf("List 2 reversed\n");
                } else {
                    printf("Invalid list\n");
                }
                break;

            case 6:
                if (concatList != NULL) {
                    concatList = freeList(concatList);
                }
                concatList = concatenateLists(list1, list2);
                printf("Lists concatenated\n");
                break;

            case 7:
                list1 = freeList(list1);
                list2 = freeList(list2);
                if (concatList != NULL) {
                    concatList = freeList(concatList);
                }
                printf("Exiting program\n Memory freed\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
