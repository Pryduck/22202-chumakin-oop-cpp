#include "lib/googlemock/include/gmock/gmock.h"
#include "lib/googletest/include/gtest/gtest.h"
#include "../FileReader.h"
using namespace std;

TEST(FileReader, poem) {
ofstream test_file("poem.txt");
test_file << "Remember, remember the fifth of November,\nGunpowder treason and plot,\nI see no reason why gunpowder treason\nShould ever be forgot";
test_file.close();
FileReader fileReader("poem.txt");
fileReader.open();

ASSERT_EQ(fileReader.get_next(), "Remember, remember the fifth of November,");
ASSERT_EQ(fileReader.get_next(), "Gunpowder treason and plot,");
ASSERT_TRUE(fileReader.is_next());
ASSERT_EQ(fileReader.get_next(), "I see no reason why gunpowder treason");
ASSERT_EQ(fileReader.get_next(), "Should ever be forgot");
ASSERT_FALSE(fileReader.is_next());
}

TEST(FileReader,no_words) {
std::ofstream test_file("no_words.txt");
test_file.close();
FileReader fileReader("no_words.txt");
fileReader.open();

ASSERT_EQ(fileReader.get_next(), "");
ASSERT_FALSE(fileReader.is_next());
}