#ifndef TASK_0_FILEREADER_H
#define TASK_0_FILEREADER_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileReader {
private:
    ifstream file;
    string filename;
public:
    FileReader(string filename) {
        this->filename = filename;
    }
    void open();
    void close();
    void reset();

    bool is_next();
    string get_next();
};

#endif //TASK_0_FILEREADER_H