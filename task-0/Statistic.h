#ifndef TASK_0_STATISTIC_H
#define TASK_0_STATISTIC_H

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Statistic {
private:
    unordered_map<string, int> statMap;
    int wordNumber;
public:
    Statistic(){
        statMap = {};
        wordNumber = 0;
    }
    void add(const string& word);
    int getNumber() const;
    vector<pair<string, int>> sort() const;
};

#endif //TASK_0_STATISTIC_H
