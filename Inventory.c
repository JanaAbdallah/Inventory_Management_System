#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inventory.h"

int ItemExists(const Node *head, int id) {
    const Node *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return 1;
        }
        current = current->next;
    }
    return 0; 
}

void AddItem(Node **head) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter item ID: ");
    scanf("%d", &newNode->id);

    if (ItemExists(*head, newNode->id)) {
        printf("Item with ID %d already exists.\n", newNode->id);
        free(newNode);
        return;
    }

    printf("Enter item name: ");
    scanf("%s", newNode->name);
    printf("Enter item quantity: ");
    scanf("%d", &newNode->quantity);

    newNode->next = *head;
    *head = newNode;
    printf("Item added successfully.\n");
}

void DisplayItems(const Node *head) {
    if (head == NULL) {
        printf("No items in inventory.\n");
        return;
    }

    const Node *current = head;
    printf("Inventory:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d\n", current->id, current->name, current->quantity);
        current = current->next;
    }
}

void SearchItemByName(const Node *head, const char *name) {
    const Node *current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Item found - ID: %d, Name: %s, Quantity: %d\n", current->id, current->name, current->quantity);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Item with name '%s' not found.\n", name);
    }
}

void SearchItemByID(const Node *head, int id) {
    const Node *current = head;
    int found = 0;
    while (current != NULL) {
        if (current->id == id) {
            printf("Item found - ID: %d, Name: %s, Quantity: %d\n", current->id, current->name, current->quantity);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}