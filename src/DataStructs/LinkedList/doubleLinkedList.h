#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "./linkedList.h"

template<typename T>
class doubleLinkedList final : public linkedList<T>{
    class Node{
        Node(T val)
        : value {val}
        { };
        T value;
        Node* nxt {nullptr};
        Node* prev {nullptr};
    };
    public:
        doubleLinkedList() = default;
       ~doubleLinkedList(){
            Node* tmp {head};
            while(head != nullptr){
                tmp = head;
                head = head->nxt;
                delete tmp;
            }
        };
        virtual void Prepend(T data) override{
            Node* n = new Node(data);
            n->nxt = head;
            if(head != nullptr) head->prev = n;
            head = n;
            if(tail == nullptr) tail = head;
            linkedList<T>::itemCount++;
        };
        virtual void Append(T data) override{
            Node* n = new Node(data);
            if(tail != nullptr)tail->nxt = n;
            n->prev = tail;
            if(head == nullptr) head = tail;
            linkedList<T>::itemCount++;
        };
        virtual void RemoveFirst(T data) override{
            if(!Contains(data)) return;
            Node* tmp {head};
            if(tmp == nullptr) return;

            if(tmp->nxt == nullptr){
                delete tmp;
                head = tail = nullptr;
            }
            else{
                do{
                    if(tmp->value == data) break;
                    tmp = tmp->nxt;
                } while(tmp != nullptr);
                if(tmp == head){
                    head = head->nxt;
                    head->prev = nullptr;
                }
                else if(tmp == tail){
                    tail = tail->prev;
                    tail->nxt = nullptr;
                }
                else{
                    tmp->prev->nxt = tmp->nxt;
                    tmp->nxt->prev = tmp->prev;
                }
                delete tmp;
            }
            linkedList<T>::itemCount--;
        };
        virtual void Print(std::ostream& out) const override{
            Node* cur {head};
            while(cur != nullptr){
                out << cur->value;
                cur = cur->nxt;
            }
        };
        virtual bool Contains(T data) const override{
            Node* cur {head};
            while(cur != nullptr && cur->value != data) cur = cur->nxt;
            if(cur == nullptr) return false;
            return true;
        };
    private:
        Node* head {nullptr};
        Node* tail {nullptr};
};

#endif