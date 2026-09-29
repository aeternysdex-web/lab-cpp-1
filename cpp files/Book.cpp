#include "Book.h"
#include <iostream>

using namespace std;    // в .cpp это разрешено, поэтому можно писать просто string

// Book::Book — "конструктор класса Book".
// После двоеточия — список инициализации: поле(значение).
// Например, id(bookId) значит: в поле id положить значение параметра bookId.
// Это то же самое, что this->id = bookId; в теле, только правильнее для Sonar.
Book::Book(int bookId, const string& bookTitle, const string& bookAuthor)
    : id(bookId), title(bookTitle), author(bookAuthor) {
}

// Book::getId — "метод getId класса Book". Просто возвращает поле.
int Book::getId() const {
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

// Полная информация о книге
void Book::printInfo() const {
    cout << "ID: " << id << "\n";
    cout << "Название: " << title << "\n";
    cout << "Автор: " << author << "\n";
}

// Короткая строка для списка
void Book::printShort() const {
    cout << "  ID " << id << ": \"" << title << "\", " << author << "\n";
}
