#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structs */
typedef struct Node {
    char *item;
    struct Node *next;
} node;

typedef struct List {
    node *head;
} list;

/* Allocate space for a new list and set its head to NULL */
list* CreateList() {
    list* newList = (list*) malloc(sizeof(list));
    if (newList == NULL) {
        return NULL; // Memory allocation failed
    }
    newList->head = NULL; // Initialize head to NULL
    return newList;
}

/* Allocates a new node and copies the string from the item to this node */
int AddToList(list* ll, char *item) {
    if (ll == NULL || item == NULL) {
        return -1; // Invalid list or item
    }

    // Allocate memory for the new node
    node *newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        return -1; // Memory allocation failed
    }

    // Allocate memory for the item and copy the string
    newNode->item = (char*) malloc(strlen(item) + 1);
    if (newNode->item == NULL) {
        free(newNode);
        return -1; // Memory allocation failed
    }
    strcpy(newNode->item, item);

    newNode->next = NULL;

    // Add the new node to the end of the list
    if (ll->head == NULL) {
        ll->head = newNode; // If list is empty, new node becomes the head
    } else {
        node *current = ll->head;
        while (current->next != NULL) {
            current = current->next; // Traverse to the end of the list
        }
        current->next = newNode; // Add the new node at the end
    }
    return 0; // Success
}

/* Removes the head of the list and returns a pointer to the item */
char* RemoveFromList(list *ll) {
    if (ll == NULL || ll->head == NULL) {
        return NULL; // List is empty or invalid
    }

    node *oldHead = ll->head;
    char *item = oldHead->item;

    ll->head = oldHead->next; // Move the head to the next node
    free(oldHead); // Free the memory for the removed node

    return item; // Return the item of the removed node
}

/* Prints every string in each node of the list */
void PrintList(list *ll) {
    if (ll == NULL || ll->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *current = ll->head;
    while (current != NULL) {
        printf("%s\n", current->item);
        current = current->next; // Move to the next node
    }
}

/* Flushes (clears) the entire list */
void FlushList(list *ll) {
    if (ll == NULL) {
        return; // Invalid list
    }

    node *current = ll->head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp->item); // Free the allocated string
        free(temp); // Free the node
    }

    ll->head = NULL; // Reinitialize the list to empty
}

/* De-allocates all of the data for the list */
void FreeList(list **ll) {
    if (ll == NULL || *ll == NULL) {
        return; // Invalid list
    }

    FlushList(*ll); // Clear all nodes

    free(*ll); // Free the list structure itself
    *ll = NULL; // Set the pointer to NULL
}


