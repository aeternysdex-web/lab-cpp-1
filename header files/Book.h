#pragma once   
#include <string>

using namespace std;  

class Book {
private:                
    int id;
    string title;
    string author;

public:            
    Book(int id, string title, string author);

    int getId();
    string getTitle();
    string getAuthor();

    void printInfo();     
    void printShort();    
};
