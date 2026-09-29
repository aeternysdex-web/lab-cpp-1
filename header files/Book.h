#pragma once            // защита: чтобы файл не подключился дважды

#include <string>

// В заголовочных файлах нельзя писать "using namespace std;" (Sonar это запрещает),
// поэтому здесь пишем std::string. В .cpp-файлах using namespace std можно.

// Класс Book — одна книга (издание). Хранит id, название и автора.
class Book {
private:                // поля: снаружи (из main) напрямую их не трогаем
    int id;
    std::string title;
    std::string author;

public:                 // методы: их можно вызывать снаружи

    // Конструктор — вызывается при создании книги:
    // Book b(1, "Война и мир", "Л.Н. Толстой");
    //
    // const std::string& — "передать строку без копирования и не менять её".
    // Sonar требует именно так: копировать длинные строки дорого.
    // Имена параметров (bookId, bookTitle...) отличаются от имён полей,
    // чтобы не было "затенения" (когда два разных имени выглядят одинаково).
    Book(int bookId, const std::string& bookTitle, const std::string& bookAuthor);

    // Методы, которые возвращают значения полей.
    // const в конце — "этот метод только читает, объект не меняет".
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;

    // Вывод на экран
    void printInfo() const;     // полная информация
    void printShort() const;    // одна короткая строка для списка
};
