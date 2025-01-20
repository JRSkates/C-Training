#include <stdio.h>
#include <stdlib.h>
// A linked list is a set of dynamically allocated nodes, 
// arranged in such a way that each node contains one value and one pointer. 
// The pointer always points to the next member of the list. 
// If the pointer is NULL, then it is the last node in the list.

// A linked list is held using a local pointer variable 
// which points to the first item of the list. 
// If that pointer is also NULL, then the list is considered to be empty.

//     ------------------------------              ------------------------------
//     |              |             |            \ |              |             |
//     |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
//     |              |             |            / |              |             |
//     ------------------------------              ------------------------------

struct Node {
    int data;  // Stores the data of the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function implementations
void insert_at_beginning(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    new_node->data = new_data; // Set the data field
    new_node->next = *head;    // Link the new node to the current head
    *head = new_node;          // Update the head pointer to the new node
}
// Allocate memory for the new node using malloc.
// Initialize the data field with new_data.
// Set the next pointer of the new node to the current head of the list.
// Update the head pointer (*head) to point to the new node.

void insert_at_end(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    new_node->data = new_data; // Set the data field
    new_node->next = NULL;    // Set the next pointer to NULL

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node
    struct Node* last = *head;
    while (last->next!= NULL) {
        last = last->next;
    }

    // Insert the new node at the end
    last->next = new_node;
}
// Allocate memory for the new node using malloc
// Initialize the data field with new_data.
// Move through the list to find the last node
// Insert the new node at the end of the list



void delete_node(struct Node** head, int key) {
    struct Node* temp = *head;  // Temporary pointer to traverse the list
    struct Node* prev = NULL;  // Keeps track of the previous node

    // Case 1: If the head node contains the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Update the head pointer
        free(temp);         // Free the memory of the old head
        return;
    }

    // Case 2: Traverse the list to find the key
    while (temp != NULL && temp->data != key) {
        prev = temp;        // Store the current node
        temp = temp->next;  // Move to the next node
    }

    // Case 3: Key not found
    if (temp == NULL) {
        printf("Key not found in the list\n");  // Key not found
        return;
    }

    // Case 4: Key found, delete the node
    prev->next = temp->next; // Unlink the node from the list
    free(temp);              // Free the memory of the deleted node
}
// Handle the special case where the key is in the head node.
// Traverse the list to locate the node with the key.
// If the node is found, unlink it from the list and free its memory.
// If the key is not found, do nothing.



void print_list(struct Node* head) {
    struct Node* temp = head;  // Temporary pointer to traverse the list
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;           // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}
// Start from the head and traverse the list using a temporary pointer.
// Print the data of each node followed by an arrow (->).
// Stop when the pointer reaches NULL.



int search(struct Node* head, int key) {
    struct Node* temp = head;  // Temporary pointer to traverse the list
    while (temp != NULL) {
        if (temp->data == key) // Check if the current node contains the key
            return 1;          // Key found
        temp = temp->next;     // Move to the next node
    }
    return 0; // Key not found
}
// Traverse the list from the head to the end.
// If a node contains the key, return 1 (found).
// If the end of the list is reached without finding the key, return 0.



void free_list(struct Node** head) {
    struct Node* temp;

    while (*head != NULL) {
        temp = *head;         // Store the current node
        *head = (*head)->next; // Move the head to the next node
        free(temp);           // Free the memory of the current node
    }
}
// Start from the head of the list.
// Use a temporary pointer to store the current node.
// Move the head pointer to the next node.
// Free the memory of the current node.
// Repeat until the list is empty.



int main() {
    struct Node* head = NULL;

    // Insert nodes
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_end(&head, 40);

    // Print list
    printf("Linked List: ");
    print_list(head);

    // Search for a value
    int key = 20;
    printf("Search for %d: %s\n", key, search(head, key) ? "Found" : "Not Found");

    // Delete a node
    delete_node(&head, 50);
    delete_node(&head, 40);
    printf("After deletion: ");
    print_list(head);
    delete_node(&head, 20);
    printf("After deletion: ");
    print_list(head);


    // Free the entire list
    free_list(&head);
    printf("Linked List Freed\n");

    return 0;
}
