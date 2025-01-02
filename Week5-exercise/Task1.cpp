//
// Created by 35988 on 12/30/2024.
//
/*
	Да се напише функция, която проверява дали свързан списък е палиндром.
*/
#include "HelperFuncs.hpp"

bool is_palindrome(Node<int>* left){
    Node<int>* right = get_middle_node(left);
    reverse_list(right);
    while(right){
        if(right->data!=left->data){
            return false;
        }
        right=right->next;
        left=left->next;
    }
    return true;
}
int main(){
    Node<int>* list = create_list({1,2,2,1});
    std::cout<<is_palindrome(list);
    delete_list(list);
    return 0;
}
