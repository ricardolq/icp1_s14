#include <stdio.h>

typedef struct {
    char * name;
    int age;
    char gender;
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

//Node *head = NULL;

void insertOrdered(Node **head, Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || strcmp((*head)->data.name, data.name) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL && strcmp(current->next->data.name, data.name) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertAtBeginning(Node **head, Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(Node **head, char *name) {
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void deleteAtPosition(Node **head, int position) {
    if (*head == NULL || position < 0) {
        return;
    }

    Node *current = *head;

    if (position == 0) {
        *head = current->next;
        free(current);
        return;
    }

    Node *previous = NULL;
    for (int i = 0; current != NULL && i < position; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;
    free(current);
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d, Gender: %c\n", current->data.name, current->data.age, current->data.gender);
        current = current->next;
    }
}