#include <algorithm>
#include <iostream>
#include "BitArray.h"

BitArray::BitArray(int numBits, unsigned long value) {
    
    //считаем количество блоков
    int amountOfBlocks = (numBits + BLOCK_SIZE - 1) / BLOCK_SIZE;

    this->numBits = numBits;
    //задаём вектор
    arrayOfBlocks.resize(amountOfBlocks);
    arrayOfBlocks[0] = value;
}

BitArray::BitArray(const BitArray &b) {
    arrayOfBlocks = b.arrayOfBlocks;
    numBits = b.numBits;
}

BitArray &BitArray::operator=(const BitArray &b) {
    arrayOfBlocks = b.arrayOfBlocks;
    numBits = b.numBits;
    return *this;
}

void BitArray::swap(BitArray &b) {
    BitArray j = *this;
    *this = b;
    b = j;
}


void BitArray::resize(int newNumBits, bool value) {
    if (newNumBits < 0) {
        throw ExceptionThrow("Amount of bits can not be negative");
    }

    unsigned long block = 0;
    if (value) block = FULL_BLOCK;

    if (newNumBits >= numBits) {
        int amountOfFullBlocks = numBits / BLOCK_SIZE;
        int amountOfRemBits = numBits % BLOCK_SIZE;

        arrayOfBlocks[amountOfFullBlocks] |= (block >> amountOfRemBits);
        numBits += BLOCK_SIZE - amountOfRemBits;

        int amountOfBlocksToAdd = (newNumBits + BLOCK_SIZE - 1) / BLOCK_SIZE - (numBits / BLOCK_SIZE);

        while (amountOfBlocksToAdd) {
            arrayOfBlocks.push_back(block);
            amountOfBlocksToAdd--;
        }


        numBits = newNumBits;
    } else {
        int amountOfBlocksToDelete = arrayOfBlocks.size() - ((numBits - newNumBits) / BLOCK_SIZE) - 1;
        while (amountOfBlocksToDelete) {
            arrayOfBlocks.pop_back();
            amountOfBlocksToDelete--;
        }

        numBits = newNumBits;
    }
}

string BitArray::toString() const {
    string number;
    int amountOfBlocks = (numBits) / BLOCK_SIZE;

    for (int i = 0; i < amountOfBlocks; i++) {
        for (int shift = BLOCK_SIZE - 1; shift >= 0; shift--) {
            if ((arrayOfBlocks[i] >> shift) & 1) {
                number += "1";
            } else {
                number += "0";
            }
        }
    }

    //для последнего блока
    for (int shift = BLOCK_SIZE - 1; shift > BLOCK_SIZE - 1 - (numBits) % BLOCK_SIZE; shift--) {
        if ((arrayOfBlocks[amountOfBlocks] >> shift) & 1) {
            number += "1";
        } else {
            number += "0";
        }
    }

    return number;
}

void BitArray::clear() {
    arrayOfBlocks.clear();
    numBits = 0;
}

void BitArray::pushBack(bool bit) {
    if (numBits % BLOCK_SIZE) {
        arrayOfBlocks[arrayOfBlocks.size() - 1] |= (bit << (BLOCK_SIZE - numBits % BLOCK_SIZE - 1));
    } else {
        arrayOfBlocks.push_back(0 | (bit << (BLOCK_SIZE - 1)));
    }
    numBits++;
}

BitArray& BitArray::operator&=(const BitArray &b) {
    if (numBits != b.numBits) {
        throw ExceptionThrow("Arrays have different size for &");
    }

    for (int i = 0; i <  arrayOfBlocks.size(); i++) {
        arrayOfBlocks[i] &= b.arrayOfBlocks[i];
    }

    return *this;
}

BitArray& BitArray::operator|=(const BitArray &b) {
    if (numBits != b.numBits) {
        throw ExceptionThrow("Arrays have different size for |");
    }

    for (int i = 0; i <  arrayOfBlocks.size(); i++) {
        arrayOfBlocks[i] |= b.arrayOfBlocks[i];
    }

    return *this;
}

BitArray& BitArray::operator^=(const BitArray &b) {
    if (numBits != b.numBits) {
        throw ExceptionThrow("Arrays have different size for ^");
    }

    for (int i = 0; i <  arrayOfBlocks.size(); i++) {
        arrayOfBlocks[i] ^= b.arrayOfBlocks[i];
    }

    return *this;
}

BitArray &BitArray::operator<<=(int n) {
    if (n < 0) {
        throw ExceptionThrow("n less then zero");
    }

    if (n >= numBits) {
        this->reset();
        return *this;
    }

    int shiftedBlock = n / BLOCK_SIZE;
    int shift = n % BLOCK_SIZE;

    for (int i = 0; i < arrayOfBlocks.size() - shiftedBlock; i++) {
        arrayOfBlocks[i] = (arrayOfBlocks[shiftedBlock + i] << shift) | (arrayOfBlocks[shiftedBlock + i + 1] >> (BLOCK_SIZE - shift));
    }
    arrayOfBlocks[arrayOfBlocks.size() - shiftedBlock] << (BLOCK_SIZE - shift);
    for (int i = arrayOfBlocks.size() - shiftedBlock; i < arrayOfBlocks.size(); i++) {
        arrayOfBlocks[i] &= 0;
    }

    return *this;
}

BitArray &BitArray::operator>>=(int n) {
    if (n < 0) {
        throw ExceptionThrow("n less then zero");
    }

    if (n >= numBits) {
        this->reset();
        return *this;
    }

    int shiftedBlock = n / BLOCK_SIZE;
    int shift = n % BLOCK_SIZE;

    for (int i = arrayOfBlocks.size() - 1; i >= shiftedBlock + 1; i--) {
        arrayOfBlocks[i] = (arrayOfBlocks[i - shiftedBlock] << shift) | (arrayOfBlocks[i - 1 - shiftedBlock] >> (BLOCK_SIZE - shift));
    }
    arrayOfBlocks[shiftedBlock] = (arrayOfBlocks[shiftedBlock] >> shift) | 0;

    for (int i = 0; i < shiftedBlock; i++) {
        arrayOfBlocks[i] &= 0;
    }

    return *this;
}

BitArray BitArray::operator<<(int n) const {
    if (n < 0) {
        throw ExceptionThrow("value of left shift < 0");
    }

    BitArray shiftedArray(*this);
    shiftedArray <<= n;
    return shiftedArray;
}

BitArray BitArray::operator>>(int n) const {
    if (n < 0) {
        throw ExceptionThrow("value of right shift < 0");
    }

    BitArray shiftedArray(*this);
    shiftedArray >>= n;
    return shiftedArray;
}

BitArray &BitArray::set(int n, bool val) {
    if (n >= numBits - 1) {
        this->resize(n + 1, false);
    }
    int amountOfBlocks = n / BLOCK_SIZE;
    int shift = BLOCK_SIZE - n % BLOCK_SIZE - 1;
    arrayOfBlocks[amountOfBlocks] |= (val << shift);
    return *this;
}

BitArray &BitArray::set() {
    for (int i = 0; i <= arrayOfBlocks.size(); i++) {
        arrayOfBlocks[i] = 0;
    }
    return *this;
}

BitArray &BitArray::reset(int n) {
    this->set(n, false);
    return *this;
}

BitArray &BitArray::reset() {
    for (unsigned long i : arrayOfBlocks) {
        i = 0;
    }
    return *this;
}

bool BitArray::any() const {
    for (unsigned long i : arrayOfBlocks) {
        if (i ^ 0) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    for (unsigned long i : arrayOfBlocks) {
        if (i ^ 0) {
            return false;
        }
    }
    return true;
}

BitArray BitArray::operator~() const {
    BitArray inversion(*this);
    for (int i = 0; i < arrayOfBlocks.size(); i++) {
        inversion.arrayOfBlocks[i] = arrayOfBlocks[i] ^ (unsigned long)FULL_BLOCK;
    }
    return inversion;
}

int BitArray::count() const {
    int count = 0;
    //пробегаем по массиву
    for (unsigned long i : arrayOfBlocks) {
        //пробегаем внутри блоков
        for (int shift = 0; shift < BLOCK_SIZE; shift++) {
            if ((i >> shift) & 1) {
                count++;
            }
        }
    }
    return count;
}

int BitArray::size() const {
    return numBits;
}

bool BitArray::empty() const {
    return numBits == 0;
}


BitArray::Bit BitArray::operator[](int i) const{
    if (i >= numBits) {
        throw ExceptionThrow("i is out of range");
    }
    return BitArray::Bit(*this, i);
}


BitArray::Bit &BitArray::Bit::operator=(bool value) {
    (bitArray).set(index, value);
    return *this;
}

BitArray::Bit::Bit(const BitArray& bitArray, int index) : bitArray(const_cast<BitArray &>(bitArray)) {
    this->bitArray = bitArray;
    this->index = index;
}


BitArray::Bit::operator bool() {
    if (index >= bitArray.numBits) {
        return false;
    }
    int block = index / BLOCK_SIZE;
    int shift = BLOCK_SIZE - index % BLOCK_SIZE - 1;
    return ((bitArray.arrayOfBlocks[block] >> shift) & 1);
}

bool operator==(const BitArray & a, const BitArray & b) {
    //сразу проверим размеры
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const BitArray & a, const BitArray & b) {
    //сразу проверим размеры
    if (a.size() != b.size()) {
        return true;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return true;
        }
    }
    return false;
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    BitArray result(b1);
    result &= b2;
    return result;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    BitArray result(b1);
    result |= b2;
    return result;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    BitArray result(b1);
    result ^= b2;
    return result;
}
