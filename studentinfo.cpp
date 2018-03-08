//
// Created by G Carl Evans on 3/4/18.
//

#include "studentinfo.h"

std::ostream & operator<<(std::ostream& output_stream, const StudentRecord &record) {
    return output_stream << record.name_ << " " << record.grade_;
}

std::istream & operator>>(std::istream& input_stream, StudentRecord& record) {
    std::string name;
    int grade;
    input_stream >> name >> grade;

    if(!input_stream) {
        return input_stream;
    } else if (name == "") {
        input_stream.setstate(std::ios::failbit);
        return input_stream;
    }
    record.name_ = name;
    record.grade_ = grade;

    return input_stream;
}

std::string StudentRecord::getName() const {
    return name_;
}

void StudentRecord::setName(const std::string &new_name) {
    name_ = new_name;
}

int StudentRecord::getGrade() const {
    return grade_;
}

void StudentRecord::setGrade(int new_grade) {
    grade_ = new_grade;
}

StudentRecord::StudentRecord(const std::string &new_name, int new_grade) :
        name_(new_name), grade_(new_grade)
{

}

bool StudentRecord::valid() const {
    if(name_ == "") {
        return false;
    }
    return true;
}
