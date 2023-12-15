#include "gtest/gtest.h"
#include "../Parser.h"
using namespace std;

TEST(Parser, simple_text) {
Parser parser;

string simple_text = "We gonna rapapap tonight";
bool sense = false;
  
vector<string> words = parser.parse(simple_text, sense);

ASSERT_EQ(words, vector<string>({"we", "gonna", "rapapap", "tonight"}));
}


TEST(Parser, caseSensitive) {
Parser parser;

string caseSensitive = "We we are duper Duper";
bool sense = true;
  
vector<string> words = parser.parse(caseSensitive, sense);

ASSERT_EQ(words, vector<string>({"We", "we", "are", "duper", "Duper"}));
}



TEST(Parser, strange_text) {
Parser parser;

string simple_text = "We$$$are**the@Champions";
bool sense = false;
  
vector<string> words = parser.parse(simple_text);

ASSERT_EQ(words, vector<string>({"we", "are", "the", "champions"}));
}


TEST(Parser, no_text) {
Parser parser;

string no_text;
bool sense = false;
  
vector<string> words = parser.parse(no_text, sense);

ASSERT_EQ(words.size(), 0);
}
