#include "gtest/gtest.h"
#include "../Writer.h"
const vector<string> CSV_WORD = {"word", "Frequency", "PercentFrequency"};

TEST(Writer, text) {
Writer writer("text.csv");
writer.open();

Statistic statistic;

statistic.add("second");
statistic.add("fourth");
statistic.add("third");
statistic.add("first");
statistic.add("fourth");
statistic.add("fourth");
statistic.add("second");
statistic.add("third");
statistic.add("third");
statistic.add("fourth");

int wordsAmount = statistic.getAmountOfWords();
vector<pair<string, int>> sortedList = statistic.sort();

writer.writing(CSV_WORD, ';');

//выводим отсортированный список
for (int k = 0; k < sortedList.size(); k++) {
const pair<string, int>& wordInfo = sortedList[k];

string word = wordInfo.first;
int frequency = wordInfo.second;
double percentFrequency = (double)wordInfo.second / wordsAmount * 100;

vector<string> allWordsInfo = {word, to_string(frequency), to_string(percentFrequency)};
writer.writing(allWordsInfo, ';');
}

writer.close();

ifstream test_file("text.csv");
string line;

getline(test_file, line);
ASSERT_EQ(line, "word;Frequency;PercentFrequency;");

getline(test_file, line);
ASSERT_EQ(line, "fourth;4;40.000000;");
getline(test_file, line);
ASSERT_EQ(line, "third;3;30.000000;");
getline(test_file, line);
ASSERT_EQ(line, "second;2;20.000000;");
getline(test_file, line);
ASSERT_EQ(line, "first;1;10.000000;");

getline(test_file, line);
ASSERT_EQ(line, "");
ASSERT_TRUE(test_file.eof());
}
