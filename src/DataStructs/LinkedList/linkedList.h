#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
class linkedList{
    protected:
        int itemCount {0};
    public:
        linkedList();
       ~linkedList();
        virtual void Prepend(T data) = 0;
        virtual void Append(T data) = 0;
        void Remove(T data){
            while(Contains(data)) RemoveFirst(data);
        };
        virtual void RemoveFirst(T data) = 0;
        virtual void Print(std::ostream& out = std::cout) const = 0;
        virtual bool Contains(const T data) const = 0;
        int Count() const {
            return itemCount;
        };
        friend std::ostream& operator << (std::ostream& out, const linkedList & list){
            Print(out);
            return out;
        };
};

#endif