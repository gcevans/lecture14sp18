#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

void addGrade(map<string, int>&gradebook);
void findGrade(map<string, int>&gradebook);
void printGrades(map<string, int>gradebook);

int main() {

    map<string,int> gradebook;

    while(true) {
        string input;
        cout << "Enter command: ";
        cin >> input;

        if(input == "exit") {
            return 0;
        } else if (input == "add") {
            addGrade(gradebook);
        } else if (input == "print") {
            printGrades(gradebook);
        } else if (input == "find") {
            findGrade(gradebook);
        }
    }
    return -1;
}

void addGrade(map<string, int> &gradebook) {
    cout << "What it the student and grade? ";
    string name;
    int grade;
    cin >> name >> grade;
    gradebook[name] = grade;
}

void printGrades(map<string, int>gradebook){
    cout << "Current Grades" << endl;
    for(auto record : gradebook) {
        cout << record.first << " : " << record.second << endl;
    }
}

void findGrade(map<string, int>&gradebook) {
    cout << "What is the student's name? ";
    string student_name;
    cin >> student_name;
    auto record = gradebook.find(student_name);
    if (record != gradebook.end()) {
        cout << student_name << " had a " << record->second << endl;
    } else {
        cout << "Could not find " << student_name << endl;
    }
}
