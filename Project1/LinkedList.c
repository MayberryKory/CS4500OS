/* Declaring all the structs */
typedef struct Node node;

struct Node
{
    char *item;
    node *next
};

typedef struct List
{
    node *head
} list;

/* Allocate space for a new list and set its head to NULL
Returns the created list if successful, NULL otherwise */
list* CreateList();

/* Allocates a new node and copies the string from the item to this node
use malloc, strlen, and strcpy Adds this new node to end of list ll, returns 0 if successful, 
non- zero otherwise */
int AddToList(list* ll , char *item );

/* Removes the head of the list ll (and move the head of ll
to the next node in the list), extracts the string stored in the head,
and returns a pointer to this string. Also free the removed head node */
char* RemoveFromList(list *ll );

/* Prints every string in each node of the list ll. 
with a newline character at the end of each string*/
void PrintList(list *ll);

/* Flushes (clears) the entire list and re-initializes the list
The passed pointer ll should still point to a valid empty list when this 
function returns. Any memory allocated to store nodes in the list should be freed*/
void FlushList(list *ll);

/* De-allocates all of the data for the list. Ensure all memory allocated
for the list *ll is freed, including any allocated strings and the list ll itself*/
void FreeList(list **ll);