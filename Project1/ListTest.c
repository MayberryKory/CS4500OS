#include "LinkedList.h"

/* Main function for testing */
int main() {
    list* myList = CreateList();
    if (myList == NULL) {
        printf("Failed to create list.\n");
        return 1;
    }

    AddToList(myList, "Hello");
    AddToList(myList, "World");
    AddToList(myList, "This is a test");

    PrintList(myList);

    char* removedItem = RemoveFromList(myList);
    printf("Removed item: %s\n", removedItem);
    free(removedItem); // Free the removed item's memory

    PrintList(myList);

    FlushList(myList);
    PrintList(myList);

    FreeList(&myList);
    if (myList == NULL) {
        printf("List successfully freed.\n");
    }

    return 0;
}