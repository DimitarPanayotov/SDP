//
// Created by 35988 on 10/17/2024.
//
#include<iostream>
#include<string>
#include<stack>
std::string reverseStr(std::string expression){
    std::stack<char> reversedStr;
    std::string result="";
    for(int i=0;i<expression.length();i++){
        reversedStr.push(expression[i]);
    }
    while(!reversedStr.empty()){
        result.push_back((reversedStr.top()));
        reversedStr.pop();
    }
    return result;
}
//int main () {
//    std::string expression;
//    getline(std::cin, expression);
//    std::cout<<reverseStr(expression);
//}