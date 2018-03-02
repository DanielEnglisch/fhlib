#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <bitset>
#include <iostream>
#include <limits>

typedef std::bitset<8> BYTE;

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
            BYTE* byteArray = (BYTE*)(&val);
            int size = sizeof(T);
            int* intArray = (int*)byteArray;
            int intSize = size / sizeof(int);
            int extraBytes = size % sizeof(int);
            int hash = std::numeric_limits<int>::max();
            for(int i = 0; i < intSize; i++){
                hash ^= intArray[i];//hash = hash XOR intArray[i]
            }
            if(extraBytes > 0){
                for(int i = 0; i < extraBytes; i++){
                    BYTE* lastByteOfHash = ((BYTE*)(&(hash))) + sizeof(int) - 1;
                    *lastByteOfHash = *lastByteOfHash ^ byteArray[intSize * sizeof(int) + i];
                }
            }
            return hash;
        };
    private:
        int _size;
        int count {0};
        std::list<T>* table;
};

#endif