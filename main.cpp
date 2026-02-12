#include "Student.h"
#include <iostream>

int main() {
    std::cout << "===== Student Linked List =====" << std::endl;

    int n;
    std::cout << "How many students? ";
    std::cin >> n;

    StudentNode* head = nullptr;

    // Add students to linked list
    for (int i = 0; i < n; ++i) {
        std::cout << "\nStudent " << (i + 1) << ":" << std::endl;
        
        std::string name;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        
        int numAssign;
        std::cout << "Number of assignments: ";
        std::cin >> numAssign;
        
        Student student(name, numAssign);
        
        for (int j = 0; j < numAssign; ++j) {
            std::cout << "Score " << (j + 1) << ": ";
            std::cin >> student.scores[j];
        }
        
        // Add to linked list
        StudentNode* newNode = new StudentNode(student);
        if (head == nullptr) {
            head = newNode;
        } else {
            StudentNode* current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
    }

    // Print all students
    std::cout << "\n===== All Students =====" << std::endl;
    StudentNode* current = head;
    while (current != nullptr) {
        current->student.print();
        current = current->next;
    }

    // Cleanup
    current = head;
    while (current != nullptr) {
        StudentNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
