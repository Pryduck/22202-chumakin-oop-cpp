#include "Parser.h"

vector<string> Parser::parsing(const string& line, bool CaseSensitive) {
    vector<string> words = {};
    string word;

    int cur_len = 0;
    for (int i = 0; i < line.size(); i++) {
        const char& symbol = line[i];

        if (isalnum(symbol)) {
            if (CaseSensitive)
                word += (symbol);
            else
                word += tolower(symbol);
            cur_len++;
        }

        if (!isalnum(symbol)) {
            if (cur_len != 0) {
                words.push_back(word);
                cur_len = 0;
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
