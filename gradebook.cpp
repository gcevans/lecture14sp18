//
// Created by G Carl Evans on 3/7/18.
//
#include <fstream>
#include <iostream>
#include "gradebook.h"

void Gradebook::addGrade(std::string name, int score){
    gradebook_[name]=StudentRecord(name,score);
}

void Gradebook::addGrade(StudentRecord record){
    gradebook_[record.getName()]=record;
}

std::ostream & operator<<(std::ostream& output_stream, const Gradebook &gradebook) {
    for(auto record : gradebook.gradebook_) {
        std::cout << record.second << std::endl;
    }
    return output_stream;
}

StudentRecord Gradebook::findRecord(std::string student) const {
    auto record = gradebook_.find(student);
    if(record == gradebook_.end()) {
        return StudentRecord("");
    }
    return record->second;
}

bool Gradebook::saveToFile(std::string filename) const {
    std::ofstream savefile(filename);

    if(!savefile) {
        return false;
    }

    for(auto record : gradebook_) {
        savefile << record.second << std::endl;
    }

    savefile.close();
    return true;
}

Gradebook::Gradebook(std::string filename) {
    std::ifstream gradebook_file(filename);

    if(!gradebook_file) {
        return;
    }

    while(gradebook_file) {
        StudentRecord new_record;
        gradebook_file >> new_record;
        if(gradebook_file.fail()) {
            continue;
        }
        gradebook_[new_record.getName()] = new_record;
    }

    gradebook_file.close();

}
