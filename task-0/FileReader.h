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
    //функция открытия файла
    void open();
    //функция закрытия файла
    void close();
    
    //функция обнуления указателя чтения
    void reset();
    
    //проверка наличия строки
    bool isNext();
    //взятие следующей строки
    string getNext();
};

#endif //TASK_0_FILEREADER_H
