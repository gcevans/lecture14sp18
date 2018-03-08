#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include "gradebook.h"
#include "studentinfo.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

void addGrade(Gradebook &gradebook);
void findGrade(Gradebook &gradebook);
void saveGradebook(const Gradebook &gradebook);

int main() {
    Gradebook gradebook;

    while(true) {
        string input;
        cout << "Enter command: ";
        cin >> input;
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if(input == "exit") {
            return 0;
        } else if (input == "add") {
            addGrade(gradebook);
        } else if (input == "print") {
            cout << gradebook;
        } else if (input == "find") {
            findGrade(gradebook);
        } else if (input == "save") {
            saveGradebook(gradebook);
        } else if (input == "read") {
            std::string filename;
            cout << "What filename to load from? ";
            cin >> filename;
            gradebook = Gradebook(filename);
            if(gradebook.size() == 0) {
                cout << "Empty Gradebook" << endl;
            }
        }
    }
    return -1;
}

void addGrade(Gradebook &gradebook) {
    cout << "What it the student and grade? ";
    StudentRecord input_student;
    cin >> input_student;
    gradebook.addGrade(input_student);
}

void findGrade(Gradebook &gradebook) {
    cout << "What is the student's name? ";
    string student_name;
    cin >> student_name;
    auto record = gradebook.findRecord(student_name);
    if (record.valid()) {
        cout << student_name << " had a " << record.getGrade()<< endl;
    } else {
        cout << "Could not find " << student_name << endl;
    }
}

void saveGradebook(const Gradebook &gradebook) {
    std::string filename;
    cout << "What filename to save to? ";
    cin >> filename;
    if(gradebook.saveToFile(filename)) {
        cout << "Gradebook saved" << endl;
    } else {
        cout << "Could not save to " << filename << endl;
    }
}
