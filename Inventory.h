#ifndef INVENTORY_H
#define INVENTORY_H

#define ITEM_NAME_LENGTH 50

typedef struct Node {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
    struct Node *next;
} Node;

void AddItem(Node **head);
void DisplayItems(const Node *head);
void SearchItemByName(const Node *head, const char *name);
void SearchItemByID(const Node *head, int id);
int  ItemExists(const Node *head, int id); // Function to check if item exists

#endif