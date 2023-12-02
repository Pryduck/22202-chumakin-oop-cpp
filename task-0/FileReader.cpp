#include "FileReader.h"

void FileReader::open() {
    file.open(filename);
}

void FileReader::close() {
    file.close();
}

bool FileReader::is_next() {
    return !file.eof();
}

string FileReader::get_next() {
    if (file.eof()) return "";
    string next;
    getline(file, next);
    return next;
}

void FileReader::reset() {
    file.seekg(ios_base::beg);
}