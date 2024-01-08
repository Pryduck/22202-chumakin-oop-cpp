#include "gtest/gtest.h"
#include "../BitArray.h"

//отдельно запись.........................................................................
TEST (BitArray, ind) {
    BitArray array(10, 0);

    array[0] = true;
    array[3] = true;
    array[7] = true;
    array[9] = true;

    ASSERT_EQ(array.toString(), "1001000101");
    ~array;
}


TEST (BitArray, build) {
    BitArray array(8, 5);

    ASSERT_EQ("10100000", array.toString());
    ~array;
}

//основные тесты..........................................................

TEST(BitArray, General) {
    BitArray a(100, 0x10101);

    ASSERT_TRUE(a.any());
    ASSERT_FALSE(a.none());
    ASSERT_EQ(a.size(), 100);
    ASSERT_FALSE(a.empty());
    ASSERT_EQ(a.count(), 3);
    ~a;
}


TEST (BitArray, Swap) {
    BitArray a1(100, 5);
    BitArray a2(110, 7);

    BitArray aCopy1(a1);
    BitArray aCopy2(a2);

    a1.swap(a2);
    ASSERT_EQ(a1, aCopy2);
    ASSERT_EQ(a2, aCopy1);
    ~a1;
    ~a2;
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

    a1[1] = true;
    a1[3] = true;
    a1[5] = true;
    a1[7] = true;

    a2.set();
    a1 &= a2;
    ASSERT_EQ("01010101", a1.toString());
    ~a1;
    ~a2;
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
    ~a1;
    ~a2;

}


TEST (BitArray, XOR) {
    BitArray a1(8, 0);
    BitArray a2(8, 0);
    
    a1[1] = true;
    a1[3] = true;
    a1[5] = true;
    a1[7] = true;
    
    a1 ^= a2;
    ASSERT_EQ("01010101", a1.toString());
    
    
    a2.set();
    a1 ^= a2;
    ASSERT_EQ("10101010", a1.toString());
    ~a1;
    ~a2;
}


TEST(BitArray, Resize) {
    BitArray a(100, 0x111);
    
    a.resize(110);
    ASSERT_EQ(a.size(), 110);
    ASSERT_EQ(a.count(), 3);
    ~a;
}


TEST (BitArray, Inverse) {
    BitArray a1(8, 0);
    
    a1[1] = true;
    a1[3] = true;
    a1[5] = true;
    a1[7] = true;
    
    a1 = ~a1;
    ASSERT_EQ("10101010", a1.toString());
    ~a1;
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
    ~array;
}


TEST (BitArray, RightShift) {
    BitArray array(5, 1);
    array >>= 2;
    string str = "00100";
    ASSERT_EQ(str, array.toString());
    ~array;
}


TEST (BitArray, LeftShift) {
    BitArray array(5, 0);
    array[4] = true;
    array <<= 2;
    string str = "00100";
    ASSERT_EQ(str, array.toString());
    ~array;
}


TEST (BitArray, RightShiftCopy) {
    BitArray array(5, 1);
    ASSERT_EQ("00100", (array>>2).toString());
    ~array;
}


TEST (BitArray, LeftShiftCopy) {
    BitArray array(5, 0);
    array[4] = true;
    ASSERT_EQ("00100", (array<<2).toString());
    ~array;
}


//(не)равенство...................................................................

TEST (BitArray, Equality) {
    BitArray a1(100, 0x111);
    BitArray a2(100, 0x111);
    
    ASSERT_TRUE(a1 == a2);
    ASSERT_FALSE(a1 != a2);
    ~a1;
    ~a2;
}

TEST (BitArray, Inequality) {
    BitArray a1(100, 0x111);
    BitArray a2(100, 0x101);
    
    ASSERT_TRUE(a1 != a2);
    ASSERT_FALSE(a1 == a2);
    ~a1;
    ~a2;
}


TEST(BitArray, clear) {
    BitArray a(20, 0x111);

    a.clear();
    ASSERT_EQ(a.size(), 0);
    ~a;
}

