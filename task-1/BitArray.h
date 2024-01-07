#ifndef TASK_1_BITARRAY_H
#define TASK_1_BITARRAY_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "ExceptionThrow.h"
using namespace std;

#define BLOCK_SIZE 32 //размер блока = 32 бит
#define FULL_BLOCK 0xffffffff // 8*4 = 32 "1"
class BitArray {
private:
    vector<unsigned long> arrayOfBlocks;
    int numBits;

    class Bit {
    private:
        BitArray &bitArray;
        int index;

    public:
        //конструктор
        Bit(const BitArray &bitArray, int index);

        //оператор присваивания индексу значения
        Bit &operator=(bool value);
        operator bool();
    };

public:
    //создает пустой массив, резервирующий память размером типа
    BitArray() = default;

    //деструктор
    ~BitArray() = default;

    //Конструирует массив, хранящий заданное количество бит.
    //Первые sizeof(long) бит можно инициализровать с помощью параметра value.
    explicit BitArray(int numBits, unsigned long value = 0);

    // Копировать конструктор
    BitArray(const BitArray &b);

    //Обменивает значения двух битовых массивов.
    void swap(BitArray &b);

    // Присваивает битовый массив другому
    BitArray &operator=(const BitArray &b);

    //Изменяет размер массива. В случае расширения, новые элементы
    //инициализируются значением value.
    void resize(int newNumBits, bool value = false);

    // Очищает массив
    void clear();

    //Добавляет новый бит в конец массива. В случае необходимости
    //происходит перераспределение памяти.
    void pushBack(bool bit);

    //побитовое и с проверкой размеров
    BitArray &operator&=(const BitArray &b);

    //побитовое или с проверкой размеров
    BitArray &operator|=(const BitArray &b);

    //побитовое исключающее или с проверкой размеров
    BitArray &operator^=(const BitArray &b);

    //Побитовый сдвиг влево, изменяет исходный массив
    BitArray &operator<<=(int n);

    //Побитовый сдвиг вправо, изменяет исходный массив
    BitArray &operator>>=(int n);

    //Побитовый сдвиг влево, создание нового объекта
    BitArray operator<<(int n) const;

    //Побитовый сдвиг вправо, создание нового объекта
    BitArray operator>>(int n) const;

    //Устанавливает бит с индексом n значение val.
    BitArray &set(int n, bool val = true);

    // заполняет массив истиной
    BitArray &set();

    //Устанавливает бит с индексом n в значение false.
    BitArray &reset(int n);

    // заполняет массив ложью
    BitArray &reset();

    // true, если есть бит = 1
    bool any() const;

    // true, если все биты массива - 0.
    bool none() const;

    // Битовая инверсия
    BitArray operator~() const;

    // Возвращает количество единичных битов
    int count() const;

    //Возвращает значение бита по индексу i
    BitArray::Bit operator[](int i) const;

    // возвращает размер массива в битах
    int size() const;

    // true, если массив пустой
    bool empty() const;

    //Возвращает строковое представление массива.
    string toString() const;

};
    // возвращает значение true, если массивы равны
    bool operator==(const BitArray &a, const BitArray &b);
    // возвращает значение true, если массивы не равны
    bool operator!=(const BitArray &a, const BitArray &b);

    //побитовое и, возвращает новый объект
    BitArray operator&(const BitArray& b1, const BitArray& b2);
    //побитовое или, возвращает новый объект
    BitArray operator|(const BitArray& b1, const BitArray& b2);
    //побитовое исключающее или, возвращает новый объект
    BitArray operator^(const BitArray& b1, const BitArray& b2);


#endif //TASK_1_BITARRAY_H
