Synopsis:

The provided C code implements a simple Library Management System (LMS) allowing users to manage books and members. Here's how it works:

Data Structures: The system utilizes two main data structures: Book and Member, representing books and members of the library, respectively.

Menu-Driven Interface: Upon execution, users are presented with a menu-driven interface offering various options:

Adding a book
Adding a member
Issuing a book to a member
Returning a borrowed book
Displaying available books by genre
Exiting the program
Functionality:

Adding Book/Member: Users can input details such as title, author, genre, and publication year to add a book, and name and ID to add a member.
Issuing and Returning Books: Books can be issued to members, with checks for availability and borrowing limits. Books can also be returned to the library.
Displaying Books by Genre: Users can view available books based on a specified genre.
Global Variables: The program maintains global arrays to store book and member data, along with counters to track the number of books and members.

Input Validation: The system includes basic input validation, such as checking for valid book and member IDs.

Usage Limitation: Members are limited to borrowing two books at a time.

This system provides essential functionality for managing a library's resources, allowing for the addition, issuance, and return of books, along with genre-based 
book viewing. However, it lacks advanced features like search functionalities, data persistence, and more robust input validation.
