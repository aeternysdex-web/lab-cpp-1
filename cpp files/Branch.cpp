#include "Branch.h"
#include <iostream>

using namespace std;

Branch::Branch(const string& branchName, int branchCapacity)
    : name(branchName), capacity(branchCapacity) {
}

bool Branch::addBook(const Book& book) {
    if (isFull()) {
        return false;               
    }
    catalog.push_back(book);     
    return true;
}

bool Branch::removeBookById(int id) {
    for (size_t i = 0; i < catalog.size(); ++i) {  
        if (catalog[i].getId() == id) {
            catalog.erase(catalog.begin() + i);    
            return true;
        }
    }
    return false;                   
}

const Book* Branch::findBookById(int id) const {
    for (const Book& book : catalog) {
        if (book.getId() == id) {
            return &book;           
        }
    }
    return nullptr;
}

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

void Branch::printShort() const {
    cout << name << " (книг: " << catalog.size() << "/" << capacity << ")\n";
}
