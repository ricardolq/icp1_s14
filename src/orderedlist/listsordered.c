/**
 * @file listsordered.c
 * @brief Implementation of an ordered linked list with various operations.
 *
 * This file contains the implementation of an ordered linked list that stores
 * `Person` structures. It provides functions for inserting, deleting, searching,
 * and printing nodes in the list.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @struct Person
 * @brief Represents a person with a name, age, and gender.
 *
 * @var Person::name
 * The name of the person (dynamically allocated string).
 * @var Person::age
 * The age of the person.
 * @var Person::gender
 * The gender of the person ('M' for male, 'F' for female, etc.).
 */

/**
 * @struct Node
 * @brief Represents a node in the linked list.
 *
 * @var Node::data
 * The data stored in the node (a `Person` structure).
 * @var Node::next
 * Pointer to the next node in the list.
 */

/**
 * @brief Inserts a new node in the list in an ordered manner based on the name.
 *
 * @param head Pointer to the head of the list.
 * @param data The `Person` data to insert.
 * @return 0 on success, -1 on memory allocation failure.
 */

/**
 * @brief Inserts a new node at the beginning of the list.
 *
 * @param head Pointer to the head of the list.
 * @param data The `Person` data to insert.
 * @return 0 on success, -1 on memory allocation failure.
 */

/**
 * @brief Inserts a new node at the end of the list.
 *
 * @param head Pointer to the head of the list.
 * @param data The `Person` data to insert.
 * @return 0 on success, -1 on memory allocation failure.
 */

/**
 * @brief Inserts a new node at a specific position in the list.
 *
 * @param head Pointer to the head of the list.
 * @param data The `Person` data to insert.
 * @param position The position (0-based index) to insert the node.
 * @return 0 on success, -1 on memory allocation failure or invalid position.
 */

/**
 * @brief Deletes a node from the list by name.
 *
 * @param head Pointer to the head of the list.
 * @param name The name of the person to delete.
 * @return 0 on success, -1 if the name is not found.
 */

/**
 * @brief Deletes the first node in the list.
 *
 * @param head Pointer to the head of the list.
 * @return 0 on success, -1 if the list is empty.
 */

/**
 * @brief Deletes the last node in the list.
 *
 * @param head Pointer to the head of the list.
 * @return 0 on success, -1 if the list is empty.
 */

/**
 * @brief Deletes a node at a specific position in the list.
 *
 * @param head Pointer to the head of the list.
 * @param position The position (0-based index) of the node to delete.
 * @return 0 on success, -1 if the position is invalid or the list is empty.
 */

/**
 * @brief Searches for a node in the list by name.
 *
 * @param head Pointer to the head of the list.

 * @param name The name of the person to search for.
 * @return Pointer to the node if found, NULL otherwise.
 */

/**
 * @brief Searches for a node in an ordered list by name.
 *
typedef struct {
 * @param head Pointer to the head of the list.
 * @param name The name of the person to search for.
 * @return Pointer to the node if found, NULL otherwise.
 */

/**
 * @brief Prints all nodes in the list.
 *
 * @param head Pointer to the head of the list.
 */

/**
 * @brief Prints the node at a specific position in the list.
 *
 * @param head Pointer to the head of the list.
 * @param position The position (0-based index) of the node to print.
 */

/**
 * @brief Clears the entire list, freeing all allocated memory.
 *
 * @param head Pointer to the head of the list.
 * @return 0 on success, -1 if the list is already empty.
 */

/**
 * @brief Main function to demonstrate the functionality of the ordered linked list.
 *
 * Creates a list of `Person` objects, performs various insertions, and prints the list.
 *
 * @return 0 on successful execution.
 */
    char * name;
    int age;
    char gender;
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;


int insertOrdered(Node **head, Person data);
int insertAtBeginning(Node **head, Person data);
int insertAtEnd(Node **head, Person data);
int insertAtPosition(Node **head, Person data, int position);
int deleteName(Node **head, char *name);
int deleteAtBeginning(Node **head);
int deleteAtEnd(Node **head);
int deleteAtPosition(Node **head, int position);
Node *searchName(Node *head, char *name);
Node *searchNameOrdered(Node *head, char *name);
void printList(Node *head);
void printNodeAtPosition(Node *head, int position);
int clearList(Node **head);

int insertOrdered(Node **head, Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // Memory allocation failed
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
    return 0; // Success
}

int insertAtBeginning(Node **head, Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // Memory allocation failed
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return 0; // Success
}

int insertAtEnd(Node **head, Person data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // Memory allocation failed
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
    return 0; // Success
}

int insertAtPosition(Node **head, Person data, int position) {
    if (position < 0) {
        return -1; // Invalid position
    }

    if (position == 0) {
        insertAtBeginning(head, data);
        return 0; // Success
    }

    //we create the node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // Memory allocation failed
    newNode->data = data;
    newNode->next = NULL;

    //we find the position
    Node *current = *head;
    Node *previous = NULL;
    int i;
    for (i = 0; current != NULL && i < position; i++) {
        previous = current;
        current = current->next;
    }
    newNode->next = current;
    previous->next = newNode;
    return 0; // Success
}

int deleteName(Node **head, char *name) {
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
            return 0; // Success
        }
        previous = current;
        current = current->next;
    }
    return -1; // Name not found
}

int deleteAtBeginning(Node **head) {
    if (*head == NULL) {
        return -1; // List is empty
    }

    Node *current = *head;
    *head = current->next;
    free(current->data.name); // Free the name field
    free(current);
    return 0; // Success
}

int deleteAtEnd(Node **head) {
    if (*head == NULL) {
        return -1; // List is empty
    }

    Node *current = *head;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head = NULL;
    } else {
        previous->next = NULL;
    }

    free(current);
    return 0; // Success
}

int deleteAtPosition(Node **head, int position) {
    if (*head == NULL || position < 0) {
        return -1; // List is empty or invalid position
    }

    if (position == 0) {
        deleteAtBeginning(head);
        return 0; // Success
    }

    Node *current = *head;
    Node *previous = NULL;
    for (int i = 0; current != NULL && i < position; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return -1; // Position out of bounds
    }

    previous->next = current->next;
    free(current);
    return 0; // Success
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d, Gender: %c\n", current->data.name, current->data.age, current->data.gender);
        current = current->next;
    }
}

void printNodeAtPosition(Node *head, int position) {
    if (head == NULL || position < 0) {
        return;
    }

    Node *current = head;
    for (int i = 0; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current != NULL) {
        printf("Name: %s, Age: %d, Gender: %c\n", current->data.name, current->data.age, current->data.gender);
    }
}

int clearList(Node **head) {
    if (*head == NULL) {
        return -1; // List is empty
    }
    while (*head != NULL) {
        deleteAtBeginning(head);
    }
    return 0; // Success
}

Node* searchName(Node *head, char *name) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Name not found
}

Node* searchNameOrdered(Node *head, char *name) {
    Node *current = head;
    while (current != NULL && strcmp(current->data.name, name) < 0) {
        current = current->next;
    }
    if (current != NULL && strcmp(current->data.name, name) == 0) {
        return current;
    }
    return NULL; // Name not found
}

int main() {
    Node *head = NULL;
    Person p1 = {"Alice", 25, 'F'};
    Person p2 = {"Bob", 30, 'M'};
    Person p3 = {"Charlie", 35, 'M'};
    Person p4 = {"David", 40, 'M'};
    Person p5 = {"Eve", 45, 'F'};

    insertAtEnd(&head, p1);
    insertAtEnd(&head, p2); 
    insertAtEnd(&head, p3);
    printList(head);

    insertAtPosition(&head, p4, 3);
    insertAtPosition(&head, p5, 3);
    printf("Second round\n");

    printList(head);

    return 0;
}