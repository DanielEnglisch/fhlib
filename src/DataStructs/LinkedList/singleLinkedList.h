#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "./linkedList.h"

template<typename T>
class singleLinkedList final : public linkedList<T> {
    class Node{
        Node(T val)
        : value{val}
        { };
        T value;
        Node* nxt {nullptr};
    };
    public:
        singleLinkedList() = default;
       ~singleLinkedList(){
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
            head = n;
            if(tail == nullptr) tail = head;
            linkedList<T>::itemCount++;
        };
        virtual void Append(T data) override{
            Node* n = new Node(data);
            tail->nxt = n;
            tail = n;
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
                Node* prev;
                do{
                    if(tmp->value == data) break;
                    prev = tmp;
                    tmp = tmp->nxt;
                } while (tmp != nullptr);
                if(tmp == head){
                    head = tmp->nxt;
                }
                else if(tail == tmp){
                    tail = prev;
                    prev->nxt = nullptr;
                }
                else{
                    prev->nxt = tmp->nxt;
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