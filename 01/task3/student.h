#ifndef LIBRARY_H
#define LIBRARY_H

struct Grades
{
    private:

    short unsigned EAI;
    short unsigned geometry;
    short unsigned english;
    short unsigned OOP;
    short unsigned DIS;

    public:
    
    void setGrades();

    void printGrades();
};

struct Student {
    private:
    
    char* name;
    char EGN[10];
    unsigned facultyNum;
    Grades gradeList;

    public:

    ~Student();

    void deleteStudent();

    Student& operator = (const Student &otherBook);

    void printStudent();

    friend class Group; 
};

struct Group {
    private:

    unsigned size = 0;
    unsigned capacity = 0;
    Student * studentList;

    public:

    ~Group();

    void addStudent();

    void getSize();

    void printGroup();
};
#endif