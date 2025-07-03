#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void findNode(Node* head) {
    int len=0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    int mid = len/2;
    temp = head;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main(void) {
    int n;
    int value;
    Node* head = NULL;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu: ");
        scanf("%d", &value);
        head = insert(head, value);
    }
    print(head);
    printf("\n");
    printf("mid node: ");
    findNode(head);
    return 0;
}