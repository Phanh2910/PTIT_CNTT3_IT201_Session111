#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node *head) {
    if (head==NULL) { return;}
    Node *current = head;
    int i=1;
    printf("NULL ->");
    while (current != NULL) {
        if (current->next == NULL) {
            printf(" %d -> NULL", current->data);
            break;
        }
        printf("%d <->", current->data);
        i++;
        current = current->next;
    }
}
Node *deleteHead(Node *head) {
    if (head==NULL) { return NULL; }
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 1; i <= 5; i++) {
        Node *node = createNode(i);
        if (head==NULL) {
            head = tail = node;
        }else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    printList(head);
    printf("\n");
    head = deleteHead(head);
    printList(head);
    return 0;
}