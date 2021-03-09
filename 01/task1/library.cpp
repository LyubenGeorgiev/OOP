#include <iostream>
#include <cstring>
#include "library.h"


void Book::deleteBook() {
    delete[] title;
    delete[] author;
}

Book::~Book() {
    delete[] title;
    delete[] author;
}

Book& Book::operator=(const Book &otherBook) {
    delete[] this->title;
    delete[] this->author;

    this->title = new char[strlen(otherBook.title) + 1]();
    strcpy(this->title, otherBook.title);
    this->author = new char[strlen(otherBook.author) + 1]();
    strcpy(this->author, otherBook.author);
    this->ISBN = otherBook.ISBN;
    
    return *this;
}

void Book::printBook() {
    std::cout << this->title << " by " << this->author << " and number " << this->ISBN << '\n';
}

Library::~Library() {
    delete[] books;
}

void Library::addBook() {
    size += 1;
    if (size > capacity) {
        ++capacity;
        Book * booksTemp = new(std::nothrow) Book[size];
        for (int i = 0; i < size - 1; ++i) {
            booksTemp[i] = books[i];
        }

        char title[100];
        char author[100];
        int ISBN;
        
        std::cin >> title;
        std::cin >> author;
        std::cin >> ISBN;

        title[0] = toupper(title[0]);

        booksTemp[size-1].title = new(std::nothrow) char[strlen(title)+1]();
        strcpy(booksTemp[size-1].title, title);
        booksTemp[size-1].author = new(std::nothrow) char[strlen(author)+1]();
        strcpy(booksTemp[size-1].author, author);
        booksTemp[size-1].ISBN = ISBN;

        delete[] books;
        this->books = booksTemp;
    }
    else {
        char title[100];
        char author[100];
        int ISBN;
        
        std::cin >> title;
        std::cin >> author;
        std::cin >> ISBN;

        title[0] = toupper(title[0]);

        books[size-1].title = new(std::nothrow) char[strlen(title)+1]();
        strcpy(books[size-1].title, title);
        books[size-1].author = new(std::nothrow) char[strlen(author)+1]();
        strcpy(books[size-1].author, author);
        books[size-1].ISBN = ISBN;
    }
}

void Library::deleteBook() {
    int number;
    std::cout << "Enter ISBN of the book you wanna remove: ";
    std::cin >> number;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (books[i].ISBN == number) index = i;
    }
    if (index == -1) return;

    for (; index < size - 1; ++index) {
        books[index] = books[index+1];
    }
    books[index].deleteBook();

    --size;
}

void Library::getSize() {
    std::cout << this->size << '\n';
}

void Library::printLibrary() {
    for (int i = 0; i < size; ++i) {
        books[i].printBook();
    }
}