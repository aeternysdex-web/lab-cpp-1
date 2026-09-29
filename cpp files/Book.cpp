#include "Book.h"
#include <iostream>

using namespace std;  

Book::Book(int bookId, const string& bookTitle, const string& bookAuthor)
    : id(bookId), title(bookTitle), author(bookAuthor) {
}

int Book::getId() const {
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

void Book::printInfo() const {
    cout << "ID: " << id << "\n";
    cout << "Название: " << title << "\n";
    cout << "Автор: " << author << "\n";
}

void Book::printShort() const {
    cout << "  ID " << id << ": \"" << title << "\", " << author << "\n";
}
