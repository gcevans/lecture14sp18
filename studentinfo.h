//
// Created by G Carl Evans on 3/4/18.
//

#ifndef LECTURE14_STUFRNYINFO_H
#define LECTURE14_STUFRNYINFO_H

#include <istream>
#include <ostream>
#include <string>
#include <vector>

struct StudentRecord {
private:
    std::string name_;
    int grade_;
public:
    explicit StudentRecord(const std::string &new_name = "", int new_grade = 0);
    std::string getName() const;
    void setName(const std::string &new_name);
    int getGrade() const;
    void setGrade(int new_grade);
    bool valid() const;

    friend std::ostream & operator<<(std::ostream& output_stream, const StudentRecord &record);
    friend std::istream & operator>>(std::istream& input_stream, StudentRecord &record);
};



#endif //LECTURE14_STUFRNYINFO_H
