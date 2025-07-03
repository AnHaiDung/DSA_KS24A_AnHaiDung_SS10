#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* insert(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* newNode(Node* head, int value) {
    Node* newNode = insert(head, value);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
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
    int num;
    Node* head = NULL;
    Node* tail = NULL;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("phan tu %d: ", i + 1);
        scanf("%d", &value);
        head = newNode(head, value);
    }
    printf("nhap so muon them");
    scanf("%d", &num);
    head = newNode(head, num);
    print(head);
    return 0;
}