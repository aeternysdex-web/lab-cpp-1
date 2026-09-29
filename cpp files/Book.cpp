#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(int id, string title, string author) {
    this->id = id;
    this->title = title;
    this->author = author;
}

int Book::getId() {
    return id;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

void Book::printInfo() {
    cout << "ID: " << id << "\n";
    cout << "Название: " << title << "\n";
    cout << "Автор: " << author << "\n";
}

void Book::printShort() {
    cout << "  ID " << id << ": \"" << title << "\", " << author << "\n";
}
