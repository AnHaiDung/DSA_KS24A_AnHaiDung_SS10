#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* insert(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void print(Node* head){
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(void) {
    int n;
    int value;
    Node* head = NULL;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("phan tu %d: ", i + 1);
        scanf("%d", &value);
        head = insert(head, value);
    }
    print(head);
    return 0;
}