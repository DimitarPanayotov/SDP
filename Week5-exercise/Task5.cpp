//
// Created by 35988 on 1/2/2025.
//
/*
	Да се напише функция, която обръща всяка група от `k` елемента в свързан списък.

	Ако `k` не е делител на броя на елементите в списъка, последната група от елементи
	да остане непроменена.

	Не трябва да променяте стойностите на елементите, можете да работите само с указатели.
*/

#include "HelperFuncs.hpp"

template <typename T>
void reverse_k_groups(Node<T>*& list, size_t k){
    Node<T>* begin = list;
    Node<T>* end = list;
    size_t count = 0;

    while(end && count + 1 < k){
        end = end->next;
        count++;
    }

    if(!end) return;

    reverse_k_groups(end->next, k);
    Node<T>* rest = end->next;
    split_before(begin,end->next);
    end = begin;

    reverse_list(begin);
    list = begin;
    end->next = rest;
}

int main() {
    Node<int>* list = create_list({ 1,2,3,4,5,6,7 });
    reverse_k_groups(list, 2);
    print(list);

    return 0;
}