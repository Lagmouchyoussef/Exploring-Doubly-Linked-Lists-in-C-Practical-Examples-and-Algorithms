#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

// 1. delete_all_occurrences(Node *head, int val)

Node* delete_all_occurrences(Node* head, int val) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            Node* ptr = temp;
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(ptr);
        }
        temp = temp->next;
    }
    return head;
}

// 2. int is_palindrome(Node* head)

int is_palindrome(Node* head) {
    if (head == NULL) {
        return 1;
    }
    Node* pt1 = head;
    Node* pt2 = head;
    while (pt2->next != NULL) {
        pt2 = pt2->next;
    }
    while (pt1 != pt2 && pt1->prev != pt2) {
        if (pt1->data != pt2->data) {
            return 0;
        }
        pt1 = pt1->next;
        pt2 = pt2->prev;
    }
    return 1;
}

// 3. Node* reverse_list(Node* head)

Node* reverse_list(Node* head) {
    Node* temp = head;
    Node* ptr = NULL;
    while (temp != NULL) {
        ptr = temp->prev;
        temp->prev = temp->next;
        temp->next = ptr;
        temp = temp->prev;
    }
    if (ptr != NULL) {
        head = ptr->prev;
    }
    return head;
}

// 4. Node* merge_lists(Node* list1, Node* list2)

Node* merge_lists(Node* list1, Node* list2) {
    Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    list2->prev = temp;
    return list1;
}

int main() {
    // Creation of the doubly linked list
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->prev = head;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->prev = head->next;
    head->next->next->next = NULL;

    if (is_palindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    head = delete_all_occurrences(head, 2);
    Node* temp = head;
    printf("List after deleting all occurrences of 2: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    head = reverse_list(head);
    temp = head;
    printf("List after reversing: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    Node* list2 = (Node*)malloc(sizeof(Node));
    list2->data = 4;
    list2->next = (Node*)malloc(sizeof(Node));
    list2->next->data = 5;
    list2->next->prev = list2;
    list2->next->next = NULL;

    head = merge_lists(head, list2);
    temp = head;
    printf("List after merging: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}