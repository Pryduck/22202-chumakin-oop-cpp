#include "gtest/gtest.h"
#include "../BitArray.h"
const int ARRAY_SIZE = 100;

//основные тесты..........................................................

TEST(BitArray, General) {
    BitArray a(ARRAY_SIZE, 0x10101);

    ASSERT_TRUE(a.any());
    ASSERT_FALSE(a.none());
    ASSERT_EQ(a.size(), ARRAY_SIZE);
    ASSERT_FALSE(a.empty());
    ASSERT_EQ(a.count(), 3);
}


TEST (BitArray, Swap) {
    BitArray a1(ARRAY_SIZE, 5);
    BitArray a2(ARRAY_SIZE + 10, 7);

    BitArray aCopy1(a1);
    BitArray aCopy2(a2);

    a1.swap(a2);
    ASSERT_EQ(a1, aCopy2);
    ASSERT_EQ(a2, aCopy1);
}

//операторы.....................................................................


TEST (BitArray, AND) {
BitArray a1(8, 0);
BitArray a2(8, 0);

a1[1] = true;
a1[3] = true;
a1[5] = true;
a1[7] = true;

a1 &= a2;
ASSERT_EQ("00000000", a1.toString());

a2.set();
a1 &= a2;
ASSERT_EQ("01010101", a1.toString());

}


TEST (BitArray, OR) {
BitArray a1(8, 0);
BitArray a2(8, 0);

a1[1] = true;
a1[3] = true;
a1[5] = true;
a1[7] = true;

a1 |= a2;
ASSERT_EQ("01010101", a1.toString());

a2.set();
a1 |= a2;
ASSERT_EQ("11111111", a1.toString());

}


TEST (BitArray, XOR) {
BitArray a1(8, 0);
BitArray a2(8, 0);

a1[1] = true;
a1[3] = true;
a1[5] = true;
a1[7] = true;

a1 |= a2;
ASSERT_EQ("01010101", a1.toString());

a2.set();
a1 |= a2;
ASSERT_EQ("10101010", a1.toString());

}


TEST(BitArray, Resize) {
BitArray a(20, 0x111);

a.resize(30);
ASSERT_EQ(a.size(), 30);
ASSERT_EQ(a.count(), 3);
}


TEST (BitArray, Inverse) {
BitArray a1(8, 0);

a1[1] = true;
a1[3] = true;
a1[5] = true;
a1[7] = true;

a1 = ~a1;
ASSERT_EQ("10101010", a1.toString());
}

//исключения...............................................................

TEST (BitArray, Except) {
BitArray a1(10, 0);
BitArray a2(20, 0);
BitArray array(10, 0);

ASSERT_THROW(a1 &= a2, ExceptionThrow);
ASSERT_THROW(a1 |= a2, ExceptionThrow);
ASSERT_THROW(a1 ^= a2, ExceptionThrow);
ASSERT_THROW(a1 & a2, ExceptionThrow);
ASSERT_THROW(a1 | a2, ExceptionThrow);
ASSERT_THROW(a1 ^ a2, ExceptionThrow);

ASSERT_THROW(array.resize(-1), ExceptionThrow);

~a1;
~a2;
~array;
}

//сдвиги......................................................................

TEST(BitArray, PushBack) {
BitArray array(10, 1);
array.pushBack(true);
ASSERT_EQ("10000000001", array.toString());
}


TEST (BitArray, RightShift) {
BitArray array(5, 1);
array >>= 2;
string str = "00100";
ASSERT_EQ(str, array.toString());
}


TEST (BitArray, LeftShift) {
BitArray array(5, 0);
array[4] = true;
array <<= 2;
string str = "00100";
ASSERT_EQ(str, array.toString());
}


TEST (BitArray, RightShiftCopy) {
BitArray array(5, 1);
ASSERT_EQ("00100", (array>>2).toString());
}


TEST (BitArray, LeftShiftCopy) {
BitArray array(5, 0);
array[4] = true;
ASSERT_EQ("00100", (array<<2).toString());
}


//(не)равенство...................................................................

TEST (BitArray, Equality) {
BitArray a1(10, 5);
BitArray a2(10, 5);

ASSERT_TRUE(a1 == a2);
ASSERT_FALSE(a1 != a2);
}

TEST (BitArray, Inequality) {
BitArray a1(10, 5);
BitArray a2(10, 6);

ASSERT_TRUE(a1 != a2);
ASSERT_FALSE(a1 != a2);
}


TEST(BitArray, clear) {
    BitArray a(20, 0x111);

    a.clear();
    ASSERT_EQ(a.size(), 0);
}

//индексы.........................................................................
TEST (BitArray, ind) {
BitArray array(6, 37); //100101

bool a = array[2];
bool b = array[3];

ASSERT_EQ(true, b);
ASSERT_EQ(false, a);

array[1] = true;
bool c = array[1];
ASSERT_EQ(true, c);
}
