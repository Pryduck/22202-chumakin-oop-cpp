#ifndef TASK_0_PARSER_H
#define TASK_0_PARSER_H

#include <vector>
#include <string>
using namespace std;

class Parser {
public:
    bool CaseSensitive;
    vector<string> parsing(const string& line);
};

#endif //TASK_0_PARSER_H
