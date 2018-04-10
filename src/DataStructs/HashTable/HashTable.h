#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <bitset>
#include <iostream>
#include <limits>

template<typename T>
class HashTable{
    public:
        HashTable(int size = 5000)
        : _size {size}
        {
            table = new std::list<T>[_size];
        };
       ~HashTable(){
            delete [] table;
        };
        void Add(T value){
            if(hashFunction == nullptr) std::cout << "hi";

            int hash = hashFunction(value) % _size;
            table[hash].push_front(value);
            ++count;
        };
        void Remove(T value){
            if(hashFunction == nullptr) return;

            int hash = hashFunction(value) % _size;
            table[hash].remove(value);
            --count;
        };
        int Count(){
            return count;
        };
        int hashFunction(const T& val){
            int bytes {sizeof(T)};

            int ints {bytes / sizeof(int)};
            int* intArray {(int*)(&val)};

            int extraBytes {size % sizeof(int)};
            char* byteArray {(char*)(&val) + bytes - extraBytes};//char is defined with size of one byte

            int hash {std::numeric_limits<int>::max()};
            for(short int i {0}; i < ints; ++i){
                hash ^= intArray[i]; //hash = hash XOR intArray[i]
            }
            for(short int i{0}; i < extraBytes; ++i){//If i == 0 we won't go in anyways
                hash ^= (int)byteArray[i];
            }
            return hash;
        };
    private:
        int _size;
        int count {0};
        std::list<T>* table;
};

#endif