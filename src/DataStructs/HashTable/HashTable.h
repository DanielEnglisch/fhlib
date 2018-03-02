#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <iostream>

template<typename T>
class HashTable{
    public:
        HashTable(int (*fkt)(const T&), int size = 5000)
        : _size {size}
        , hashFunction {fkt}
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
    private:
        int _size;
        int count {0};
        std::list<T>* table;
        int (*hashFunction)(const T&);
};

#endif