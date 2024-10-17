//
// Created by 35988 on 10/17/2024.
//
#include<iostream>
#include<stack>
#include<vector>
bool find132pattern(std::vector<int> arr){
    std::stack<int>  helper;
    int min=-2147483648;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]<min){
            return true;
        }
        while(!helper.empty() && arr[i]>helper.top()){
            min=helper.top();
            helper.pop();
        }
        helper.push(arr[i]);
    }
    return false;
}
int main () {
    std::vector<int> arr= {1,3,2,4};
    std::cout<<std::boolalpha<<find132pattern(arr);
}