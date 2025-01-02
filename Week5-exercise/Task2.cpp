//
// Created by 35988 on 12/30/2024.
//
#include<iostream>
#include "HelperFuncs.hpp"
/*
	Напишете функция, която пренарежда свързан списък по зададен начин в линейно време.

	Представяме списъка като:
	`L0 → L1 → … → Ln - 1 → Ln`

	Пренареждаме елементите му по следния начин:
	`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`
*/

template <typename T>
void reorder_list(Node<T>* left){
    Node<T>* right = get_middle_node(left);

    //split the list
    Node<T>* mid = right;
    right = right->next;
    mid->next = nullptr;

    reverse_list(right);

    while(right){
        Node<T>* left_next = left->next;
        Node<T>* right_next = right->next;

        left->next = right;
        right->next = left_next;

        left = left_next;
        right = right_next;
    }
}

int main () {
    Node<int>* head = create_list({1,2,3,4,5});
    print(head);

    reorder_list(head);
    print(head);

    delete_list(head);

    return 0;
}