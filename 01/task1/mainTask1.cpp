#include "library.h"

int main()
{
    Library myBooks;

    for (int i = 0; i < 3; ++i) {
        myBooks.addBook();
        myBooks.printLibrary();
    }

    myBooks.deleteBook();
    myBooks.deleteBook();
    myBooks.deleteBook();

    for (int i = 0; i < 3; ++i) {
        myBooks.addBook();
        myBooks.printLibrary();
    }

    return 0;
}