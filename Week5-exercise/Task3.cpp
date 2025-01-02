//
// Created by 35988 on 1/2/2025.
//
/* Даден е едносвързан списък и число х.

Пренаредете списъка така, че всички елементи със стойност по-малка от х да са преди елементите със стойност по-голяма от х.

Трябва да се запази относителния ред на елементите в двете половини.
 */
#include "HelperFuncs.hpp"
#include<iostream>

void reorder_list(Node<int>* head, int x){
    Node<int> dummy(0, head);
    Node<int>* curr = &dummy;

    Node<int> dummy_l;
    Node<int>* larger = &dummy_l;

    while(curr && curr->next){
        if(curr->next->data >= x){
            larger->next = curr->next;
            curr->next = curr->next->next;
            larger = larger->next;
        }else{
            curr = curr->next;
        }
    }
    if(dummy.next == nullptr){
        dummy.next = dummy_l.next;
    }else{
        curr->next = dummy_l.next;
    }

    head = dummy.next;
}
int main () {
    Node<int>* list = create_list({ 1,3,6,2,2,5 });
    reorder_list(list, 3);
    print(list);

    return 0;
}
