#include "LinkedList.hpp"

//Big 4
template <typename T>
inline LinkedList<T>::LinkedList(const std::initializer_list<T>& values)
        : LinkedList()
{
        for(const T& val : values)
            push_back(val);
}
template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T> &other)
        : LinkedList()
{
            copy(other);
}
template <typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    if(this!=other){
        free();
        copy(other);
    }
    return *this;
}
template <typename T>
inline LinkedList<T>::~LinkedList() {
    free();
}

//Reading elements
template<typename T>
inline const T& LinkedList<T>::at(size_t pos) const {
    if(empty() || pos>=sz) {
        throw std::invalid_argument("Invalid index");
    }
    if(pos == sz-1){
        return tail->data;
    }
    const node* it = head;
    for(size_t i=0;i<pos;++i){
        it=it->next;
    }
    return it->data;
}
template<typename T>
inline const T& LinkedList<T>::front() const {
    return at(0);
}

template<typename T>
inline const T& LinkedList<T>::back() const {
    return at(sz - 1);
}

//Adding elements
template <typename T>
inline void LinkedList<T>::push_at_pos(size_t pos, const T& val){
    if(pos>sz){
        throw std::invalid_argument("Invalid index");
    }
    if(pos==0){
        head = new node(val, head);
        if(sz == 0){
            tail = head;
        }
    }
    else if(pos == sz){
        tail->next = new node(val);
        tail = tail->next;
    }else{
        node* it = head;
        for(size_t i=0;i<pos-1;i++){
            it=it->next;

            it->next = new node(val, it->next);
        }
    }
    ++sz;
}
template<typename T>
inline void LinkedList<T>::push_front(const T& val) {
    push_at_pos(0, val);
}
template<typename T>
inline void LinkedList<T>::push_back(const T& val) {
    push_at_pos(sz, val);
}

//Removing element
template<typename T>
inline T LinkedList<T>::pop_at_pos(size_t pos) {
    if(empty() || pos>=sz){
        throw std::invalid_argument("Invalid index");
    }
    node* to_delete = head;
    if(pos == 0){
        head=head->next;
        if(head == nullptr){
            tail = nullptr;
        }
    }else{
        node* it = head;
        for(size_t i=0;i<pos-1;++i){
            it = it->next;
        }

        to_delete = it->next;
        it->next = to_delete->next;
        if(it->next==nullptr){
            tail = it;
        }
    }
    --sz;
    T stored_data = to_delete->data;
    delete to_delete;
    return stored_data;
}
template<typename T>
inline T LinkedList<T>::pop_front() {
    return pop_at_pos(0);
}
template<typename T>
inline T LinkedList<T>::pop_back() {
    return pop_at_pos(sz - 1);
}

template <typename T>
inline void LinkedList<T>::reverse() {
    if(sz<2){
        return;
    }
    node* curr=head;
    node* prev=nullptr;
    node* next=nullptr;
    tail=head;

    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
}


template<typename T>
inline void LinkedList<T>::to_set() {
    node* slow = head;
    node* fast = nullptr;

    while (slow && slow->next) {
        fast = slow;
        while (fast->next) {
            if (slow->data == fast->next->data) {
                node* to_delete = fast->next;
                fast->next = to_delete->next;
                --sz;
                delete to_delete;
            }
            else {
                fast = fast->next;
            }
        }
        slow = slow->next;
    }
    tail = slow;
}
template<typename T>
inline void LinkedList<T>::filter(bool(*f)(const T&)) {
    node* curr = head;
    node* prev = nullptr;

    while (curr) {
        if (!f(curr->data)) {
            node* to_delete = curr;
            curr = curr->next;

            if(prev)
                prev->next = curr;

            if (to_delete == head)
                head = curr;

            --sz;
            delete to_delete;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    tail = prev;
}

template<typename T>
inline void LinkedList<T>::map(void(*f)(T&)) {
    node* curr = head;

    while (curr) {
        f(curr->data);
        curr = curr->next;
    }
}


template <typename T>
inline void LinkedList<T>::copy(const LinkedList<T> &other) {
    node dummy;
    node* it = &dummy;
    node* curr = other.head;
    while(curr){
        it->next = new node(curr->data);
        it=it->next;
        curr=curr->next;
    }
    head = dummy.next;
    tail = head ? it : nullptr;
    sz=other.sz;
}

template<typename T>
inline void LinkedList<T>::free() {
    node* it = head;
    node* to_delete = nullptr;

    while (it) {
        to_delete = it;
        it = it->next;
        delete to_delete;
    }

    tail = head = nullptr;
    sz = 0;
}