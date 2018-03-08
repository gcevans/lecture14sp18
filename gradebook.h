//
// Created by G Carl Evans on 3/7/18.
//

#ifndef LECTURE14_GRADEBOOK_H
#define LECTURE14_GRADEBOOK_H
#include <map>
#include <string>
#include "studentinfo.h"

class Gradebook {
    std::map<std::string,StudentRecord> gradebook_;
public:
    Gradebook()= default;
    explicit Gradebook(std::string filename);

    void addGrade(std::string name, int score);
    void addGrade(StudentRecord record);
    StudentRecord findRecord(std::string student) const;
    bool saveToFile(std::string filename) const;
    unsigned long size() const { return gradebook_.size();};

    friend std::ostream & operator<<(std::ostream& output_stream, const Gradebook &gradeboook);
};


#endif //LECTURE14_GRADEBOOK_H
