//
// Created by 35988 on 12/29/2024.
//
#ifndef WEEK4_LINKEDLIST_IMPLEMENTATION_LINKEDLIST_HPP
#define WEEK4_LINKEDLIST_IMPLEMENTATION_LINKEDLIST_HPP

#include <initializer_list>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct node {
        T data;
        node* next;
        node(const T& data = T(), node* next =nullptr) :
        data(data) ,  next(next) {};
    };
public:
    LinkedList() : head(nullptr), tail(nullptr), sz(0) {};

    LinkedList(const std::initializer_list<T>& values);
    LinkedList(const LinkedList<T>& other);
    LinkedList<T>& operator=(const LinkedList<T>& other);
    ~LinkedList();

    //Iterator
    class iterator;
    iterator begin();
    iterator end() const;

    //Reading element
    const T& front() const;
    const T& back() const;
    const T& at(size_t pos) const;

    //Information funcs
    bool empty() const {
        return sz==0;
    }
    size_t size () const {
        return sz;
    }

    //Adding elements
    void push_front(const T& val);
    void push_back(const T& val);
    void push_at_pos(size_t pos, const T& val);


    //Removing elements
    T pop_front();
    T pop_back();
    T pop_at_pos(size_t pos);

    //Algorythms
    void reverse();
    void to_set();

    void filter (bool (* f)(const T&));
    void map(void (* f)(T&));

private:
    void copy(const LinkedList<T>& other);
    void free();

    node* head;
    node* tail;
    size_t sz;
};

#include "LinkedList.inl"
#endif //WEEK4_LINKEDLIST_IMPLEMENTATION_LINKEDLIST_HPP
