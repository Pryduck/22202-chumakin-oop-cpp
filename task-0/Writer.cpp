#include "Writer.h"

void Writer::open() {
    file.open(filename);
}

void Writer::close() {
    file.close();
}

void Writer::writing(const vector<string>& text, char separator) {
    for (int i = 0; i <= text.size() - 1; i++) {
        file << text[i] << separator;
    }
    file << '\n';
}
