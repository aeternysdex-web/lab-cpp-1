#pragma once

#include <string>
#include <vector>
#include "Book.h"       // филиал хранит книги, поэтому подключаем Book

// Класс Branch — один филиал библиотеки.
// Хранит название, вместимость и список книг (каталог).
class Branch {
private:
    std::string name;
    int capacity;               // максимум книг в филиале
    std::vector<Book> catalog;  // vector — список, в котором лежат объекты Book

public:
    Branch(const std::string& branchName, int branchCapacity);

    // Работа с книгами
    bool addBook(const Book& book);     // false, если филиал переполнен
    bool removeBookById(int id);        // true, если книгу нашли и удалили

    // const Book* — "указатель на книгу, которую нельзя менять".
    // Указатель — это адрес книги внутри каталога.
    // Если книги с таким id нет — вернёт nullptr ("ничего").
    const Book* findBookById(int id) const;

    bool isFull() const;                // true, если книг уже столько же, сколько вместимость

    // Методы, которые возвращают значения полей
    std::string getName() const;
    int getCapacity() const;
    int getBooksCount() const;

    // Вывод на экран
    void printCatalog() const;  // название филиала и все его книги
    void printShort() const;    // одна строка про филиал
};
