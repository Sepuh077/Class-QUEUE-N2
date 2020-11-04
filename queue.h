#pragma once
#include <iostream>

template <class T>
class queue {
    struct node {
        T value;
        node* next;
    };
    node* first;
    int size;

public:
    queue() {
        size = 0;
        first = NULL;
    }

    queue(const queue<T>& a) {
        first = NULL;
        size = 0;
        node* b = a.first;
        for(int i = 1;i <= a.size; ++i) {
            push(b->value);
            b = b->next;
        }
    }

    bool empty() const {
        if(size == 0)
            return true;
        return false;
    }

    void push(T g) {
        if(empty()) {
            node* q = new node;
            q->value = g;
            q->next = first;
            first = q;
        }
        else {
            node* q = first;
            for(int i = 2;i <= size; ++i) {
                q = q->next;
            }
            node* p = new node;
            p->value = g;
            q->next = p;
            p->next = nullptr;
        }
        ++size;
    }

    void pop() {
        if(size != 0) {
            first = first->next;
            --size;
        }
    }

    T getFirst() {
        return first->value;
    }

    void clearQueue() {
        size = 0;
        first = NULL;
    }

    void print() {
        node* q = first;
        for(int i = 1;i <= size; ++i) {
            std::cout<<q->value<<" ";
            q = q->next;
        }
        std::cout<<std::endl;
    }

    ~queue() {
        size = 0;
        first = NULL;
    }
};
