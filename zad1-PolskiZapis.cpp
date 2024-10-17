//
// Created by 35988 on 10/17/2024.
//
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
//RPN-Reversed Polish notation
bool isDigit(char c){
    return c>='0' && c<='9';
}

int calculateRPN(std::string rpn){
    std::stack<int> elements;
    int tempNum=0;
    for(int i=0;i<rpn.length();i++) {
        if (isDigit(rpn[i])) {
            tempNum = tempNum * 10 + rpn[i] - '0';
        } else if (rpn[i] == ' ') {
            if (tempNum != 0) {
                elements.push(tempNum);
                tempNum = 0;
            }
        } else if (rpn[i] == '+') {
            int first, second;
            second = elements.top();
            elements.pop();
            first = elements.top();
            elements.pop();
            elements.push(first + second);
        } else if (rpn[i] == '-') {
            int first, second;
            second = elements.top();
            elements.pop();
            first = elements.top();
            elements.pop();
            elements.push(first - second);
        } else if (rpn[i] == '*') {
            int first, second;
            second = elements.top();
            elements.pop();
            first = elements.top();
            elements.pop();
            elements.push(first * second);
        } else if (rpn[i] == '/') {
            int first, second;
            second = elements.top();
            elements.pop();
            first = elements.top();
            elements.pop();
            elements.push(first / second);
        } else if (rpn[i] == '^') {
            int first, second;
            second = elements.top();
            elements.pop();
            first = elements.top();
            elements.pop();
            elements.push(pow(first, second));
        }
    }
    return elements.top();
}
//int main() {
//    std::string rpn;
//   getline(std::cin, rpn);
//   std::cout<<calculateRPN(rpn);
//}