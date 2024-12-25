//
// Created by 35988 on 12/24/2024.
//
#include<iostream>
#include<queue>
#include<stack>

using std::queue;
using std::stack;

template <typename T>
void flip_first_k(queue<T>& q, int k){
    stack<T> s;
    //We need the first k element which we will add to a stack
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }

    //Now we need to return them to thr queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    //Lastly, we have the move the remaining size-k elements to the back of thr queue
    int size = q.size() - k;
    for(int i=0;i<size;i++){
        q.push(q.front());
        q.pop();
    }
}
void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}
int main () {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    flip_first_k(q, 3);
    print_queue(q);
}
