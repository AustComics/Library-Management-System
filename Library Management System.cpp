#include <iostream>
#include <vector>
#include <string>

// Class representing a Book entity
class Book {
public:
    std::string title;
    std::string author;
    int year;
    bool available;

    Book(std::string title, std::string author, int year) : title(title), author(author), year(year), available(true) {}

    // Method to mark the book as borrowed
    void borrowBook() {
        available = false;
    }

    // Method to mark the book as returned
    void returnBook() {
        available = true;
    }
};

// Class representing a Library User entity
class LibraryUser {
public:
    std::string name;
    std::vector<Book*> borrowedBooks;

    LibraryUser(std::string name) : name(name) {}

    // Method to borrow a book
    void borrowBook(Book* book) {
        if (book->available) {
            book->borrowBook();
            borrowedBooks.push_back(book);
            std::cout << name << " borrowed " << book->title << std::endl;
        } else {
            std::cout << "Book is not available for borrowing" << std::endl;
        }
    }

    // Method to return a book
    void returnBook(Book* book) {
        book->returnBook();
        borrowedBooks.erase(std::return(borrowedBooks.begin(), borrowedBooks.end(), book), borrowedBooks.end());
        std::cout << name << " returned " << book->title << std::endl;
    }
};

int main() {
    // Creating some sample books
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);
    Book book3("1984", "George Orwell", 1949);

    // Creating some sample library users
    LibraryUser user1("Alice");
    LibraryUser user2("Bob");

    // Testing borrowing and returning books
    user1.borrowBook(&book1);
    user2.borrowBook(&book1);
    user1.returnBook(&book1);
    user2.borrowBook(&book1);

    return 0;
}

