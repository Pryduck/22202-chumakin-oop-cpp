#ifndef TASK_0_STATISTIC_H
#define TASK_0_STATISTIC_H

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Statistic {
private:
    unordered_map<string, int> stat_map;
    int word_number;
public:
    Statistic(){
        stat_map = {};
        word_number = 0;
    }
    void adding(const string& word);
    int get_number() const;
    vector<pair<string, int>> sorting() const;
};

#endif //TASK_0_STATISTIC_H
