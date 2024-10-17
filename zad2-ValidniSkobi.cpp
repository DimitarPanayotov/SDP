//
// Created by 35988 on 10/17/2024.
//
#include<iostream>
#include<string>
#include<stack>
bool isValid(std::string expression){
    std::stack<char> symbols;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='('){
            symbols.push(expression[i]);
        }
        if(expression[i]==')' ){
            if(symbols.empty()){
                return false;
            }
            symbols.pop();
        }
    }
    return symbols.empty();
}
//int main () {
//    std::string expression;
//    getline(std::cin, expression);
//    std::cout<<std::boolalpha<<isValid(expression);
//}