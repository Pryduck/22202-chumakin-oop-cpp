#ifndef TASK_0_WRITER_H
#define TASK_0_WRITER_H

#include <fstream>
#include <string>
#include <vector>
#include "Statistic.h"
using namespace std;

class Writer {
private:
    ofstream file;
    string filename;
public:
    Writer(string filename){
        this->filename = filename;
    }
    //функция открытия файла
    void open();
    //функция закрытия файла
    void close();
    //функция записи строки с разделителем
    void write(const vector<string>& text, char separator);
};

#endif //TASK_0_WRITER_H
