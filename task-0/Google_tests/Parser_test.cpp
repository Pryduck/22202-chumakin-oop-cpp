#include "gtest/gtest.h"
#include "../Parser.h"
using namespace std;

TEST(Parser, simpleText) {
Parser parser;

string simpleText = "We gonna rapapap tonight";
bool sense = false;
  
vector<string> words = parser.parse(simpleText, sense);

ASSERT_EQ(words, vector<string>({"we", "gonna", "rapapap", "tonight"}));
}


TEST(Parser, caseSensitive) {
Parser parser;

string caseSensitive = "We we are duper Duper";
bool sense = true;
  
vector<string> words = parser.parse(caseSensitive, sense);

ASSERT_EQ(words, vector<string>({"We", "we", "are", "duper", "Duper"}));
}



TEST(Parser, strangeText) {
Parser parser;

string strangeText = "We$$$are**the@Champions";
bool sense = false;
  
vector<string> words = parser.parse(strangeText, sense);

ASSERT_EQ(words, vector<string>({"we", "are", "the", "champions"}));
}


TEST(Parser, noText) {
Parser parser;

string noText;
bool sense = false;
  
vector<string> words = parser.parse(noText, sense);

ASSERT_EQ(words.size(), 0);
}
