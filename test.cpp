#include "Student.h"
#include <iostream>
#include <cassert>
#include <cmath>

int pass = 0, total = 0;

void test(const std::string& name, bool condition) {
    total++;
    if (condition) {
        pass++;
        std::cout << "[PASS] " << name << std::endl;
    } else {
        std::cout << "[FAIL] " << name << std::endl;
    }
}

// Test 1: Zero assignments
void test1() {
    std::cout << "\nTest 1: Zero Assignments" << std::endl;
    Student s("John", 0);
    test("  Scores is null", s.scores == nullptr);
    test("  Average is 0", s.getAverage() == 0.0);
}

// Test 2: Copy constructor
void test2() {
    std::cout << "\nTest 2: Copy Constructor (Deep Copy)" << std::endl;
    Student s1("Alice", 2);
    s1.scores[0] = 80.0;
    s1.scores[1] = 90.0;
    
    Student s2(s1);
    test("  Name copied", s2.name == "Alice");
    test("  Scores copied", s2.scores[0] == 80.0 && s2.scores[1] == 90.0);
    
    s1.scores[0] = 50.0;
    test("  Deep copy (independent)", s2.scores[0] == 80.0);
}

// Test 3: Assignment operator
void test3() {
    std::cout << "\nTest 3: Assignment Operator (Deep Copy)" << std::endl;
    Student s1("Bob", 2);
    s1.scores[0] = 70.0;
    s1.scores[1] = 75.0;
    
    Student s2("Temp", 1);
    s2 = s1;
    
    test("  Name assigned", s2.name == "Bob");
    test("  Scores assigned", s2.scores[0] == 70.0);
    
    s1.scores[0] = 60.0;
    test("  Deep copy (independent)", s2.scores[0] == 70.0);
}

// Test 4: Average calculation
void test4() {
    std::cout << "\nTest 4: Average Calculation" << std::endl;
    Student s("Carol", 3);
    s.scores[0] = 80.0;
    s.scores[1] = 90.0;
    s.scores[2] = 100.0;
    
    double expected = 90.0;
    test("  Average correct", std::abs(s.getAverage() - expected) < 0.01);
}

// Test 5: Linked list operations
void test5() {
    std::cout << "\nTest 5: Linked List (Single Node)" << std::endl;
    Student s("Dave", 1);
    s.scores[0] = 85.0;
    
    StudentNode* node = new StudentNode(s);
    test("  Node created", node != nullptr);
    test("  Node name correct", node->student.name == "Dave");
    test("  Next is null", node->next == nullptr);
    
    delete node;
}

// Test 6: Linked list multiple nodes
void test6() {
    std::cout << "\nTest 6: Linked List (Multiple Nodes)" << std::endl;
    
    Student s1("Eve", 1);
    Student s2("Frank", 1);
    
    StudentNode* head = new StudentNode(s1);
    head->next = new StudentNode(s2);
    
    test("  First node correct", head->student.name == "Eve");
    test("  Second node correct", head->next->student.name == "Frank");
    test("  End marker correct", head->next->next == nullptr);
    
    delete head->next;
    delete head;
}

// Test 7: Boundary values
void test7() {
    std::cout << "\nTest 7: Boundary Score Values" << std::endl;
    Student s("George", 3);
    s.scores[0] = 0.0;
    s.scores[1] = 100.0;
    s.scores[2] = 50.0;
    
    test("  Min score (0) works", s.scores[0] == 0.0);
    test("  Max score (100) works", s.scores[1] == 100.0);
    double avg = (0.0 + 100.0 + 50.0) / 3.0;
    test("  Average with boundaries correct", std::abs(s.getAverage() - avg) < 0.01);
}

int main() {
    std::cout << "===== EDGE CASE TESTS =====" << std::endl;
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    
    std::cout << "\n===== RESULTS =====" << std::endl;
    std::cout << "Passed: " << pass << "/" << total << std::endl;
    
    return (pass == total) ? 0 : 1;
}
