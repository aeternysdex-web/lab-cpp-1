#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Branch.h"

using namespace std;

// Ввод целого числа с подсказкой
int readInt(string prompt) {
    cout << prompt;
    int number;
    cin >> number;
    cin.ignore(1000, '\n');     // убираем из ввода Enter, чтобы он не мешал следующему getline
    return number;
}

// Ввод целой строки (с пробелами) с подсказкой
string readLine(string prompt) {
    cout << prompt;
    string line;
    getline(cin, line);
    return line;
}

// Показать пронумерованный список филиалов.
// Знак & в vector<Branch>& значит: "работаем с самим списком, а не с его копией".
void printBranches(vector<Branch>& branches) {
    int count = branches.size();
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        branches[i].printShort();
    }
}

// Найти книгу по id во всех филиалах.
// Возвращает указатель на книгу (или nullptr, если не нашли).
// Через branchIndex (тоже с &) возвращает номер филиала, где книга лежит (или -1).
Book* findBook(vector<Branch>& branches, int id, int& branchIndex) {
    int count = branches.size();
    for (int i = 0; i < count; i++) {
        Book* book = branches[i].findBookById(id);
        if (book != nullptr) {          // нашли
            branchIndex = i;
            return book;
        }
    }
    branchIndex = -1;                   // не нашли
    return nullptr;
}

// Показать все филиалы и книги в них
void showBranches(vector<Branch>& branches) {
    int count = branches.size();
    for (int i = 0; i < count; i++) {
        branches[i].printCatalog();
    }
}

// Показать подробную информацию о книге
void showBookInfo(vector<Branch>& branches) {
    showBranches(branches);
    int id = readInt("Введите ID книги: ");
    int branchIndex;
    Book* book = findBook(branches, id, branchIndex);
    if (book == nullptr) {
        cout << "Книга с таким ID не найдена.\n";
        return;
    }
    book->printInfo();      // -> используется, когда работаем через указатель (вместо точки)
}

// Добавить книгу в выбранный филиал
void addBook(vector<Branch>& branches, int& nextId) {
    string title = readLine("Название книги: ");
    string author = readLine("Автор: ");
    cout << "В какой филиал добавить?\n";
    printBranches(branches);
    int choice = readInt("Номер филиала: ");

    int count = branches.size();
    if (choice < 1 || choice > count) {
        cout << "Некорректный номер.\n";
        return;
    }
    int index = choice - 1;     // в списке нумерация с 0, а пользователь вводит с 1

    if (branches[index].isFull()) {
        cout << "Филиал \"" << branches[index].getName() << "\" переполнен.\n";
        return;
    }

    branches[index].addBook(Book(nextId, title, author));
    cout << "Книга добавлена с ID " << nextId << ".\n";
    nextId++;
}

// Удалить книгу по id
void deleteBook(vector<Branch>& branches) {
    showBranches(branches);
    int id = readInt("Введите ID книги для удаления: ");
    int branchIndex;
    Book* book = findBook(branches, id, branchIndex);
    if (book == nullptr) {
        cout << "Книга с таким ID не найдена.\n";
        return;
    }
    cout << "Книга \"" << book->getTitle() << "\" удалена.\n";
    branches[branchIndex].removeBookById(id);
}

// Меню
void printMenu() {
    cout << "\n========== Сеть библиотек ==========\n";
    cout << "1. Показать филиалы и книги в них\n";
    cout << "2. Информация о книге\n";
    cout << "3. Добавить книгу\n";
    cout << "4. Удалить книгу\n";
    cout << "0. Выход\n";
    cout << "=====================================\n";
}

int main() {
    // Создаём два филиала
    vector<Branch> branches;
    branches.push_back(Branch("Филиал №1", 5));
    branches.push_back(Branch("Филиал №2", 5));

    // Тестовые книги. nextId — id, который получит следующая книга.
    int nextId = 1;
    branches[0].addBook(Book(nextId, "Война и мир", "Л.Н. Толстой"));
    nextId++;
    branches[0].addBook(Book(nextId, "Мастер и Маргарита", "М.А. Булгаков"));
    nextId++;
    branches[1].addBook(Book(nextId, "Евгений Онегин", "А.С. Пушкин"));
    nextId++;
    cout << "Загружены тестовые данные: 2 филиала.\n";

    // Главный цикл: показываем меню, пока не выберут 0
    int choice;
    do {
        printMenu();
        choice = readInt("Выберите пункт меню: ");
        switch (choice) {
        case 1:
            showBranches(branches);
            break;
        case 2:
            showBookInfo(branches);
            break;
        case 3:
            addBook(branches, nextId);
            break;
        case 4:
            deleteBook(branches);
            break;
        case 0:
            cout << "Завершение работы.\n";
            break;
        default:
            cout << "Такого пункта меню нет.\n";
        }
    } while (choice != 0);

    return 0;
}
