#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store book data
typedef struct Book {
  char title[100];
  char author[50];
  char genre[50];
  int year;
  int available; // 1 if available, 0 if borrowed
} Book;

// Structure to store member data
typedef struct Member {
  char name[50];
  int id;
  int borrowed_books; // Number of books currently borrowed
  Book borrowed[2]; // Array to store borrowed book details
} Member;

// Global variables
Book books[100]; // Array to store books
Member members[100]; // Array to store members
int book_count = 0; // Number of books in the library
int member_count = 0; // Number of members

// Function prototypes
void add_book();
void add_member();
void issue_book();
void return_book();
void display_books_by_genre(char genre[]);


int main() {
  // Initialize the library and members
  book_count = 0;
  member_count = 0;
  int option;
  // Main program loop
  do {
    // Display menu options
    printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
    printf("1. Add Book\n");
    printf("2. Add Member\n");
    printf("3. Issue Book\n");
    printf("4. Return Book\n");
    printf("5. Display Books By Genre\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    // Handle user selection
    switch (option) {
      case 1:
        add_book();
        break;
      case 2:
        add_member();
        break;
      case 3:
        issue_book();
        break;
      case 4:
        return_book();
        break;
      case 5:
        {
          char genre[50];
          printf("Enter genre: ");
          scanf("%s", genre);
          display_books_by_genre(genre);
          break;
        }
      case 6:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid option! Please choose a valid option.\n");
    }
  } while (option != 6); // Continue until user chooses to exit

  return 0;
}

// Function to add a book
void add_book() {
  Book book;

  // Get book details
  printf("Enter book title: ");
  scanf("%s", book.title);
  printf("Enter book author: ");
  scanf("%s", book.author);
  printf("Enter book genre: ");
  scanf("%s", book.genre);
  printf("Enter book publication year: ");
  scanf("%d", &book.year);
  book.available = 1; // Book is available by default

  // Add book to the library
  books[book_count++] = book;

  printf("Book added successfully!\n");
}

// Function to add a member
void add_member() {
  Member member;

  // Get member details
  printf("Enter member name: ");
  scanf("%s", member.name);
  printf("Enter unique member ID: ");
  scanf("%d", &member.id);
  member.borrowed_books = 0; // Member starts with no borrowed books

  // Add member to the list
  members[member_count++] = member;

  printf("Member added successfully!\n");
}

// Function to issue a book to a member
void issue_book() {
  int book_id, member_id;

  // Get book ID
  printf("Enter book ID: ");
  scanf("%d", &book_id);

  // Check if book ID is valid
  if (book_id < 0 || book_id >= book_count) {
    printf("Invalid book ID!\n");
    return;
  }

  // Get member ID
  printf("Enter member ID: ");
  scanf("%d", &member_id);

  // Check if member ID is valid
  if (member_id < 0 || member_id >= member_count) {
    printf("Invalid member ID!\n");
    return;
  }

  // Check if book is available
  if (!books[book_id].available) {
    printf("Book is already borrowed!\n");
    return;
  }

  // Check if member has reached borrowing limit
  if (members[member_id].borrowed_books >= 2) {
    printf("Member has reached borrowing limit!\n");
    return;
  }

  // Issue book and update records
  books[book_id].available = 0;
  members[member_id].borrowed_books++;
  members[member_id].borrowed[members[member_id].borrowed_books - 1] = books[book_id];

  printf("Book issued successfully!\n");
}

// Function to return a borrowed book
void return_book() {
  int book_id, member_id;

  // Get book ID
  printf("Enter book ID: ");
  scanf("%d", &book_id);
}
void display_books_by_genre(char genre[]) {
  int found = 0;

  printf("\n--- Available Books in \"%s\" Genre ---\n", genre);

  // Loop through all books
  for (int i = 0; i < book_count; i++) {
    if (strcmp(books[i].genre, genre) == 0 && books[i].available) {
      // Found a matching book
      found = 1;

      // Display book details
      printf("Book ID: %d\n", i);
      printf("Title: %s\n", books[i].title);
      printf("Author: %s\n", books[i].author);
      printf("Year: %d\n\n", books[i].year);
    }
  }

  if (!found) {
    printf("No books available in this genre.\n");
  }
}
  // Check if