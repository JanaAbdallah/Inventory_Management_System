#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inventory.h"

int main() {
    Node *inventoryHead = NULL;
    int choice;
    char searchName[ITEM_NAME_LENGTH];
    int searchID;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item by Name\n");
        printf("4. Search Item by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddItem(&inventoryHead);
                break;
            case 2:
                DisplayItems(inventoryHead);
                break;
            case 3:
                printf("Enter item name to search: ");
                scanf("%s", searchName);
                SearchItemByName(inventoryHead, searchName);
                break;
            case 4:
                printf("Enter item ID to search: ");
                scanf("%d", &searchID);
                SearchItemByID(inventoryHead, searchID);
                break;
            case 5:
                printf("Exiting...\n");
        
                while (inventoryHead != NULL) {
                    Node *temp = inventoryHead;
                    inventoryHead = inventoryHead->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}