#include "Branch.h"
#include <iostream>

using namespace std;

Branch::Branch(string name, int capacity) {
    this->name = name;
    this->capacity = capacity;
}

bool Branch::addBook(Book book) {
    if (isFull()) {
        return false;             
    }
    catalog.push_back(book);       
    return true;
}

bool Branch::removeBookById(int id) {
    int count = catalog.size();    
    for (int i = 0; i < count; i++) {
        if (catalog[i].getId() == id) {
            catalog.erase(catalog.begin() + i);  
            return true;
        }
    }
    return false;                 
}

Book* Branch::findBookById(int id) {
    int count = catalog.size();
    for (int i = 0; i < count; i++) {
        if (catalog[i].getId() == id) {
            return &catalog[i];   
        }
    }
    return nullptr;
}

bool Branch::isFull() {
    int count = catalog.size();
    return count >= capacity;
}

string Branch::getName() {
    return name;
}

int Branch::getCapacity() {
    return capacity;
}

int Branch::getBooksCount() {
    int count = catalog.size();
    return count;
}

void Branch::printCatalog() {
    cout << "=== Филиал \"" << name << "\" (книг: " << catalog.size()
        << "/" << capacity << ") ===\n";
    if (catalog.empty()) {
        cout << "  В филиале нет книг.\n";
    }
    int count = catalog.size();
    for (int i = 0; i < count; i++) {
        catalog[i].printShort();
    }
}

void Branch::printShort() {
    cout << name << " (книг: " << catalog.size() << "/" << capacity << ")\n";
}
