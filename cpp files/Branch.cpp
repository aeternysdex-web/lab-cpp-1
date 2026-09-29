#include "Branch.h"
#include <iostream>

using namespace std;

Branch::Branch(const string& branchName, int branchCapacity)
    : name(branchName), capacity(branchCapacity) {
}

// Добавить книгу в филиал
bool Branch::addBook(const Book& book) {
    if (isFull()) {
        return false;               // места нет
    }
    catalog.push_back(book);        // push_back — добавить в конец списка
    return true;
}

// Удалить книгу по id
bool Branch::removeBookById(int id) {
    // size_t — тип для размеров и номеров в vector (целое число без минуса)
    for (size_t i = 0; i < catalog.size(); ++i) {   // ++i — то же самое, что i++
        if (catalog[i].getId() == id) {
            catalog.erase(catalog.begin() + i);     // erase — удалить элемент с номером i
            return true;
        }
    }
    return false;                   // такой книги нет
}

// Найти книгу по id. Возвращает адрес книги (указатель) или nullptr.
const Book* Branch::findBookById(int id) const {
    // Цикл "для каждой книги из каталога":
    // const Book& book — берём саму книгу (без копии), менять её нельзя.
    for (const Book& book : catalog) {
        if (book.getId() == id) {
            return &book;           // & перед именем — "взять адрес"
        }
    }
    return nullptr;
}

// Филиал полон, если книг >= вместимости.
// size() возвращает size_t, а capacity у нас int, поэтому приводим через static_cast<int>.
bool Branch::isFull() const {
    return static_cast<int>(catalog.size()) >= capacity;
}

string Branch::getName() const {
    return name;
}

int Branch::getCapacity() const {
    return capacity;
}

int Branch::getBooksCount() const {
    return static_cast<int>(catalog.size());
}

// Показать филиал и все его книги
void Branch::printCatalog() const {
    cout << "=== Филиал \"" << name << "\" (книг: " << catalog.size()
         << "/" << capacity << ") ===\n";
    if (catalog.empty()) {
        cout << "  В филиале нет книг.\n";
    }
    for (const Book& book : catalog) {
        book.printShort();
    }
}

// Одна строка про филиал
void Branch::printShort() const {
    cout << name << " (книг: " << catalog.size() << "/" << capacity << ")\n";
}
