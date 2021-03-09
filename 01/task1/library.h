#ifndef LIBRARY_H
#define LIBRARY_H

struct Book {
    private:
    
    char* title;
    char* author;
    int ISBN;

    public:

    ~Book();

    void deleteBook();

    Book& operator = (const Book &otherBook);

    void printBook();

    friend class Library; 
};

struct Library {
    private:

    unsigned size = 0;
    unsigned capacity = 0;
    Book * books;

    public:

    ~Library();

    void addBook();

    void deleteBook();

    void getSize();

    void printLibrary();
};
#endif