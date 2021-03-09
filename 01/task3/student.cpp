#include <iostream>
#include <cstring>
#include "student.h"

/*
Да се състави програма, която съхранява в масив следните данни за група студенти:

име (собствено бащино фамилно, символен низ с точен размер)
ЕГН (символен низ с точен размер)
факултетен номер (6 цифри)
оценките по 5 дисциплини (оценката да бъде структура съдържаща предмет и оценка)
и извършва следните операции, избирани от меню:

добавя към масив данните на нов студент. При въвеждането да се коригира първата буква от всяко име 
(собствено бащино фамилно) да е главна без значение как е въведена от потребителя.
извежда на екрана имената (собствено и фамилно) и успеха на студентите, родени през м. Март
извежда на екрана имената (собствено и фамилно) на студента с най-висок среден успех
*/

void Grades::setGrades() {
    unsigned short grades[5];

    std::cout << "English: ";
    std::cin >> grades[0];
    std::cout << "Geometry: ";
    std::cin >> grades[1];
    std::cout << "EAI: ";
    std::cin >> grades[2];
    std::cout << "OOP: ";
    std::cin >> grades[3];
    std::cout << "DIS: ";
    std::cin >> grades[4];

    for (int i = 0; i < 5; ++i) {
        if (grades[i] < 2 || grades[i] > 6) grades[i] = 2;
    }

    this->EAI = grades[0];
    this->geometry = grades[1];
    this->english = grades[2];
    this->OOP = grades[3];
    this->DIS = grades[4];
}

Grades& Grades::operator=(const Grades &otherGrades) {
    this->EAI = otherGrades.EAI;
    this->OOP = otherGrades.OOP;
    this->DIS = otherGrades.DIS;
    this->geometry = otherGrades.geometry;
    this->english = otherGrades.english;
    
    return *this;
}

void Grades::printGrades() {
    std::cout << "Grades: \nEnglish " << this->english <<
                "\nGeometry " << this->geometry <<
                "\nEAI " << this->EAI <<
                "\nOOP " << this->OOP <<
                "\nDIS " << this->DIS << '\n';
}

void Student::deleteStudent() {
    delete[] name;
}

Student::~Student() {
    delete[] name;
}

Student& Student::operator=(const Student &otherBook) {
    delete[] this->name;

    this->name = new char[strlen(otherBook.name) + 1]();
    strcpy(this->name, otherBook.name);
    strcpy(this->EGN, otherBook.EGN);
    this->facultyNum = otherBook.facultyNum;
    
    return *this;
}

void Student::printStudent() {
    std::cout << this->name << " with EGN " << this->EGN << 
                " and faculty number " << this->facultyNum << '\n';
    this->gradeList.printGrades();
}

Group::~Group() {
    delete[] studentList;
}

void Group::addStudent() {
    size += 1;
    if (size > capacity) {
        ++capacity;
        Student * tempStudentList = new(std::nothrow) Student[size];
        for (int i = 0; i < size - 1; ++i) {
            tempStudentList[i] = studentList[i];
        }

        char name[200];
        char EGN[10];
        int facultyNumber;
        
        std::cin >> name;
        std::cin >> EGN;
        std::cin >> facultyNumber;

        name[0] = toupper(name[0]);

        tempStudentList[size-1].name = new(std::nothrow) char[strlen(name)+1]();
        strcpy(tempStudentList[size-1].name, name);
        strcpy(tempStudentList[size-1].EGN, EGN);
        tempStudentList[size-1].facultyNum = facultyNumber;

        delete[] studentList;
        this->studentList = tempStudentList;
    }
    else {
        char name[200];
        char EGN[10];
        int facultyNumber;
        
        std::cin >> name;
        std::cin >> EGN;
        std::cin >> facultyNumber;

        name[0] = toupper(name[0]);

        studentList[size-1].name = new(std::nothrow) char[strlen(name)+1]();
        strcpy(studentList[size-1].name, name);
        strcpy(studentList[size-1].EGN, EGN);
        studentList[size-1].facultyNum = facultyNumber;
    }
}

void Group::getSize() {
    std::cout << this->size << '\n';
}

void Group::printGroup() {
    for (int i = 0; i < size; ++i) {
        studentList[i].printStudent();
    }
}