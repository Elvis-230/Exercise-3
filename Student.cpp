#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(const std::string& n, int num)
    : name(n), numAssignments(num), scores(nullptr) {
    if (num > 0) {
        scores = new double[num];
        for (int i = 0; i < num; ++i)
            scores[i] = 0.0;
    }
}

Student::Student(const Student& other)
    : name(other.name), numAssignments(other.numAssignments), scores(nullptr) {
    if (other.numAssignments > 0 && other.scores != nullptr) {
        scores = new double[other.numAssignments];
        for (int i = 0; i < other.numAssignments; ++i)
            scores[i] = other.scores[i];
    }
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] scores;
        name = other.name;
        numAssignments = other.numAssignments;
        scores = nullptr;
        
        if (other.numAssignments > 0 && other.scores != nullptr) {
            scores = new double[other.numAssignments];
            for (int i = 0; i < other.numAssignments; ++i)
                scores[i] = other.scores[i];
        }
    }
    return *this;
}

Student::~Student() {
    delete[] scores;
}

void Student::print() const {
    std::cout << "Name: " << name << ", Assignments: " << numAssignments;
    if (numAssignments > 0 && scores != nullptr) {
        std::cout << ", Average: " << std::fixed << std::setprecision(2) << getAverage();
    }
    std::cout << std::endl;
}

double Student::getAverage() const {
    if (numAssignments <= 0 || scores == nullptr)
        return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < numAssignments; ++i)
        sum += scores[i];
    return sum / numAssignments;
}
