#include "Statistic.h"

void Statistic::adding(const string& word) {
    word_number++;
    stat_map[word]++;
}

int Statistic::get_number() const {
    return word_number;
}

static bool comp(const pair<string, int>& v1, const pair<string, int>& v2) {
    return v1.second > v2.second;
}

vector<pair<string, int>> Statistic::sorting() const {
    vector<pair<string, int>> sorted = {};                                  //создали
    sorted.resize(stat_map.size());                                //задали размер
    copy(stat_map.begin(), stat_map.end(), sorted.begin()); //внесли элементы
    sort(sorted.begin(), sorted.end(), comp);                     //отсортировали
    return sorted;                                                          //вернули
}