#include "gtest/gtest.h"
#include "../FileReader.h"
using namespace std;

TEST(FileReader, poem) {
ofstream test_file("poem.txt");
test_file << "Remember, remember the fifth of November,\nGunpowder treason and plot,\nI see no reason why gunpowder treason\nShould ever be forgot";
test_file.close();
FileReader fileReader("poem.txt");
fileReader.open();

ASSERT_EQ(fileReader.getNext(), "Remember, remember the fifth of November,");
ASSERT_EQ(fileReader.getNext(), "Gunpowder treason and plot,");
ASSERT_TRUE(fileReader.isNext());
ASSERT_EQ(fileReader.getNext(), "I see no reason why gunpowder treason");
ASSERT_EQ(fileReader.getNext(), "Should ever be forgot");
ASSERT_FALSE(fileReader.isNext());
}

TEST(FileReader,NoWords) {
std::ofstream test_file("NoWords.txt");
test_file.close();
FileReader fileReader("NoWords.txt");
fileReader.open();

ASSERT_EQ(fileReader.getNext(), "");
ASSERT_FALSE(fileReader.isNext());
}
