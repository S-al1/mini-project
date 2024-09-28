#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

char titles[MAX_BOOKS][50];
char authors[MAX_BOOKS][50];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("book title: ");
        scanf(" %[^\n]", titles[bookCount]);
        printf("author : ");
        scanf(" %[^\n]", authors[bookCount]);
        printf("book price : ");
        scanf("%f", &prices[bookCount]);
        printf("Quantity in stock : ");
        scanf("%d", &quantities[bookCount]);
        bookCount++;
        printf("book added successfully !\n");
    } else {
        printf("stock is full.\n");
    }
}
void displayBooks() {
    if (bookCount == 0) {
        printf("no book available.\n");
        return;
    }
    printf("\nbook available :\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s, author: %s, Prix: %.2f, Quantity: %d\n",
               titles[i], authors[i], prices[i], quantities[i]);
    }
}

void updateQuantity() {
    char title[50];
    printf("Title of book to update : ");
    scanf(" %[^\n]", title);
   
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("new quantity : ");
            scanf("%d", &quantities[i]);
            printf("Quantity updated successfully !\n");
            return;
        }
    }
    printf("book not found.\n");
}
void deleteBook() {
    char title[50];
    printf("Title of the book to be deleted : ");
    scanf(" %[^\n]", title);
   
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            bookCount--;
            printf("book deleted successfully !\n");
            return;
        }
    }
    printf("book not found.\n");
}

void totalBooks() {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += quantities[i];
    }
    printf("total number of books in stock : %d\n", total);
}
int main() {
    int choice;
    do {
        printf("\nMenu :\n");
        printf("1. add a book\n");
        printf("2. display all books\n");
        printf("3. update quantity\n");
         printf("4. delete book\n");
        printf("5. total of books in stock\n");
        printf("6. Quit\n");
        printf("Choose an option : ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: updateQuantity(); break;
            case 4: deleteBook(); break;
            case 5: totalBooks(); break;
            case 6: printf("Au revoir !\n"); break;
            default: printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 6);
  
   
    return 0;
 }
