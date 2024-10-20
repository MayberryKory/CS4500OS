#ifndef Linked_List_Header
#define Linked_List_Header

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


/*functions*/
list* CreateList();
int AddToList(list* ll, char *item);
char* RemoveFromList(list *ll);
void PrintList(list *ll);
void FlushList(list *ll);
void FreeList(list **ll);

#endif