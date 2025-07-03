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

Node* deleteNode(Node* head,int value) {
    while(head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while(current != NULL && current->next != NULL) {
        if(current->next->data == value) {
            Node*temp = current->next;
            current->next = current->next->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;

}

void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(void) {
    int n;
    int value;
    int num;
    Node* head = NULL;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("phan tu %d: ", i + 1);
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("nhap value muon xoa");
    scanf("%d", &num);
    head = deleteNode(head, num);
    print(head);
    return 0;
}