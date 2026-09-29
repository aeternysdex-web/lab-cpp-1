#pragma once           

#include <string>

class Book {
private:                
    int id;
    std::string title;
    std::string author;
public:                
    Book(int bookId, const std::string& bookTitle, const std::string& bookAuthor);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;

    void printInfo() const;     
    void printShort() const;    
};
