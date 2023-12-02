#include "gtest/gtest.h"
#include "../Parser.h"
using namespace std;
TEST(Parser, simple_text) {
Parser parser;

string simple_text = "We gonna rapapap tonight";
vector<string> words = parser.parsing(simple_text);

ASSERT_EQ(words, vector<string>({"we", "gonna", "rapapap", "tonight"}));
}

TEST(Parser, strange_text) {
Parser parser;

string simple_text = "We$$$are**the@Champions";
vector<string> words = parser.parsing(simple_text);

ASSERT_EQ(words, vector<string>({"we", "are", "the", "champions"}));
}

TEST(Parser, no_text) {
Parser parser;

string no_text;
vector<string> words = parser.parsing(no_text);

ASSERT_EQ(words.size(), 0);
}
