#include "gtest/gtest.h"
#include "../Writer.h"
const vector<string> CSV_WORD = {"word", "Frequency", "Percent_Frequency"};

TEST(Writer, text) {
Writer writer("text.csv");
writer.open();

Statistic statistic;

statistic.adding("second");
statistic.adding("fourth");
statistic.adding("third");
statistic.adding("first");
statistic.adding("fourth");
statistic.adding("fourth");
statistic.adding("second");
statistic.adding("third");
statistic.adding("third");
statistic.adding("fourth");

int words_number = statistic.get_number();
vector<pair<string, int>> sorted_list = statistic.sorting();

writer.writing(CSV_WORD, ',');

//выводим отсортированный список
for (int k = 0; k < sorted_list.size(); k++) {
const pair<string, int>& word_info = sorted_list[k];

string word = word_info.first;
int frequency = word_info.second;
double percent_frequency = (double)word_info.second / words_number * 100;

vector<string> all_words_info = {word, to_string(frequency), to_string(percent_frequency)};
writer.writing(all_words_info, ',');
}

writer.close();

ifstream test_file("text.csv");
string line;

getline(test_file, line);
ASSERT_EQ(line, "word,Frequency,Percent_Frequency,");
//ASSERT_FALSE(test_file.eof());

getline(test_file, line);
ASSERT_EQ(line, "fourth,4,40.000000,");
getline(test_file, line);
ASSERT_EQ(line, "third,3,30.000000,");
getline(test_file, line);
ASSERT_EQ(line, "second,2,20.000000,");
getline(test_file, line);
ASSERT_EQ(line, "first,1,10.000000,");

getline(test_file, line);
ASSERT_EQ(line, "");
ASSERT_TRUE(test_file.eof());
}
