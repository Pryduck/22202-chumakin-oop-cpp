#include "Parser.h"

vector<string> Parser::parse(const string& line, bool caseSensitive) {
    vector<string> words = {};
    string word;

    int cutLen = 0;
    for (int i = 0; i < line.size(); i++) {
        const char& symbol = line[i];

        if (isalnum(symbol)) {
            if (caseSensitive)
                word += (symbol);
            else
                word += tolower(symbol);
            curLen++;
        }

        if (!isalnum(symbol)) {
            if (curLen != 0) {
                words.push_back(word);
                curLen = 0;
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
