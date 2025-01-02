//
// Created by 35988 on 1/2/2025.
//
/*
	Даден е списък с `n` елемента.

	Да се дефинира функция `shuffle()`, която получава адреса на първия елемент на списъка.

	Функцията да пренарежда възлите на списъка така, че *елементите от втората половина на
	списъка да се преместят в началото на списъка, но в обратен ред*

	(при списъци с нечетен брой елементи считаме средния елемент за принадлежащ
	към втората половина на списъка).
*/

#include "HelperFuncs.hpp"

template<typename T>
void reorder(Node<T>*& list){
    Node<T>* middle = get_middle_node(list);
    split_before(list, middle);

    Node<T>* curr = middle;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = list;
    list = middle;
}
int main() {
    Node<int>* list = create_list({ 1,2,3,4,5 });
    reorder(list);
    print(list);

    return 0;
}
