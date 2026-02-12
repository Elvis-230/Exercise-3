#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int numAssignments;
    double* scores;

    Student(const std::string& n = "", int num = 0);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
    
    void print() const;
    double getAverage() const;
};

struct StudentNode {
    Student student;
    StudentNode* next;
    
    StudentNode(const Student& s) : student(s), next(nullptr) {}
};

#endif
