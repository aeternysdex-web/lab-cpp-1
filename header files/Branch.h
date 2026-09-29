#pragma once

#include <string>
#include <vector>
#include "Book.h"     

using namespace std;

class Branch {
private:
    string name;
    int capacity;           
    vector<Book> catalog;  

public:
    Branch(string name, int capacity);

    bool addBook(Book book);     
    bool removeBookById(int id);   
    Book* findBookById(int id);    
    bool isFull();

    string getName();
    int getCapacity();
    int getBooksCount();

    void printCatalog();    
    void printShort();      
};
