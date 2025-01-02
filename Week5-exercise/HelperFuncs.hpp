//
// Created by 35988 on 12/30/2024.
//

#ifndef WEEK5_EXERCISE_HELPERFUNCS_HPP
#define WEEK5_EXERCISE_HELPERFUNCS_HPP
#include<iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data = T(), Node* next = nullptr ) // = T() means it defaults to the default type of T
        : data(data), next(next) {}
};

template <typename T>
Node<T>* create_list(const std::initializer_list<T>& values){
    Node<T> dummy;
    Node<T>* curr = &dummy;
    for (const T& val : values){
        curr->next = new Node<T>(val);
        curr=curr->next;
    }
    return dummy.next;
}

template <typename T>
void delete_list(Node<T>*& list) {
    Node<T>* curr = list;
    while(curr){
        Node<T>* to_delete = curr;
        curr = curr->next;
        delete to_delete;
    }
    list = nullptr;
}

template <typename T>
void print(Node<T>* list){
    while(list){
        std::cout<<list->data<<" ";
        list=list->next;
    }
    std::cout<<std::endl;
}

template <typename T>
Node<T>* get_middle_node(Node<T>* head){
    Node<T>* slow = head;
    Node<T>* fast = head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

template <typename T>
void reverse_list(Node<T>* head){
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;

    while(curr){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

template <typename T>
void split_before(Node<T>* list, Node<T>* const position){
    if(!list) return;
    while(list && list->next){
        if(list->next == position){
            list->next = nullptr;
            return;
        }
        list = list->next;
    }
}
#endif //WEEK5_EXERCISE_HELPERFUNCS_HPP
