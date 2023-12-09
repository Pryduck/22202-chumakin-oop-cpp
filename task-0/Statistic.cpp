#include "Statistic.h"

void Statistic::add(const string& word) {
    word_number++;
    statMap[word]++;
}

int Statistic::getNumber() const {
    return wordNumber;
}

static bool comp(const pair<string, int>& v1, const pair<string, int>& v2) {
    return v1.second > v2.second;
}

vector<pair<string, int>> Statistic::sort() const {
    vector<pair<string, int>> sorted = {};                                  //создали
    sorted.resize(statMap.size());                                         //задали размер
    copy(statMap.begin(), statMap.end(), sorted.begin());                 //внесли элементы
    sort(sorted.begin(), sorted.end(), comp);                               //отсортировали
    return sorted;                                                          //вернули
}
