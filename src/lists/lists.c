/**
 * @file lists.c
 * @brief Implementation of a singly linked list to manage a list of Person structures.
 * 
 * This file contains functions to perform various operations on a singly linked list,
 * such as insertion, deletion, searching, and printing. Each node in the list contains
 * a Person structure as its data.
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
 * Pointer to a string representing the name of the person.
 * @var Person::age
 * Integer representing the age of the person.
 * @var Person::gender
 * Character representing the gender of the person ('M' for male, 'F' for female, etc.).
 */

/**
 * @struct Node
 * @brief Represents a node in the singly linked list.
 * 
 * @var Node::data
 * A Person structure containing the data for the node.
 * @var Node::next
 * Pointer to the next node in the list.
 */

/**
 * @brief Inserts a new node with the given data at the beginning of the list.
 * 
 * @param head Pointer to the head of the list.
 * @param data The Person data to insert.
 * @return 0 on success, -1 on memory allocation failure.
 */
int insertAtBeginning(Node **head, Person data);

/**
 * @brief Inserts a new node with the given data at the end of the list.
 * 
 * @param head Pointer to the head of the list.
 * @param data The Person data to insert.
 * @return 0 on success, -1 on memory allocation failure.
 */
int insertAtEnd(Node **head, Person data);

/**
 * @brief Inserts a new node with the given data at the specified position in the list.
 * 
 * @param head Pointer to the head of the list.
 * @param data The Person data to insert.
 * @param position The position (0-based index) to insert the new node.
 * @return 0 on success, -1 on memory allocation failure or invalid position.
 */
int insertAtPosition(Node **head, Person data, int position);

/**
 * @brief Deletes the first node with the specified name from the list.
 * 
 * @param head Pointer to the head of the list.
 * @param name The name of the person to delete.
 * @return 0 on success, -1 if the name is not found.
 */
int deleteName(Node **head, char *name);

/**
 * @brief Deletes the first node in the list.
 * 
 * @param head Pointer to the head of the list.
 * @return 0 on success, -1 if the list is empty.
 */
int deleteAtBeginning(Node **head);

/**
 * @brief Deletes the last node in the list.
 * 
 * @param head Pointer to the head of the list.
 * @return 0 on success, -1 if the list is empty.
 */
int deleteAtEnd(Node **head);

/**
 * @brief Deletes the node at the specified position in the list.
 * 
 * @param head Pointer to the head of the list.
 * @param position The position (0-based index) of the node to delete.
 * @return 0 on success, -1 if the position is invalid or the list is empty.
 */
int deleteAtPosition(Node **head, int position);

/**
 * @brief Searches for a node with the specified name in the list.
 * 
 * @param head Pointer to the head of the list.
 * @param name The name of the person to search for.
 * @return Pointer to the node containing the name, or NULL if not found.
 */
Node *searchName(Node *head, char *name);

/**
 * @brief Prints the entire list to the standard output.
 * 
    }
 * @param head Pointer to the head of the list.
 */
void printList(Node *head);
    //we create the node
/**e *)malloc(sizeof(Node));
 * @brief Prints the data of the node at the specified position in the list.ocation failed
    newNode->data = data;
 * 
 * @param head Pointer to the head of the list.
 * @param position The position (0-based index) of the node to print.n
 */
void printNodeAtPosition(Node *head, int position);
    Node *current = *head;
/**
 * @brief Clears the entire list, freeing all allocated memory.
 *  NULL && i < position; i++) {
 * @param head Pointer to the head of the list.evious = current;
 * @return 0 on success, -1 if the list is already empty.
 */
int clearList(Node **head);

/**revious->next = newNode;
 * @brief Main function to demonstrate the usage of the linked list functions.
 * 
 * Creates a list of Person structures, performs various operations such as insertion,
 * deletion, and printing, and demonstrates the functionality of the linked list.nt deleteName(Node **head, char *name) {
 * 
 * @return 0 on successful execution.
 */
int main();
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