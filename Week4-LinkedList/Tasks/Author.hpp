//
// Created by 35988 on 12/29/2024.
//

#ifndef WEEK4_LINKEDLIST_TASK_AUTHOR_HPP
#define WEEK4_LINKEDLIST_TASK_AUTHOR_HPP

#include<algorithm>
#include<fstream>
#include <cstdint>
#include<cstring>

#include "Book.hpp"

class Author {
    static const size_t NAME_SIZE = 30;
public:
    Author() : name(), book_cnt(), books(nullptr) {}
    Author(const Author& other);
    Author& operator=(const Author& other);
    ~Author();

    void deserialize(std::ifstream& in);
    friend std::ofstream& operator<<(std::ofstream& out, const Author& author);
    friend bool operator>(const Author& lhs, const Author& rhs);
    friend bool operator>(const Author& lhs, char c);
private:
    void copy(const Author& other);
private:
    char name[NAME_SIZE+1];
    uint32_t book_cnt; //32-bit integer type
    Book* books;

};

Author::Author(const Author& other){
    copy(other);
}
Author& Author::operator=(const Author &other) {
    if(this!=&other){
        delete[] books;
        copy(other);
    }
    return *this;
}
Author::~Author() {
    delete[] books;
}
void Author::deserialize(std::ifstream &in) {
    in.read(name, NAME_SIZE);
    name[NAME_SIZE] = '\0';
    in.read(reinterpret_cast<char *>(&book_cnt), sizeof(unit32_t));
    books = new Book[book_cnt];
    for (unit32t i = 0; i < book_cnt; ++i) {
        books[i].deserialize(in);
    }
}
void Author::copy(const Author &other) {
    strcpy_s(name, NAME_SIZE+1, other.name);
    book_cnt = other.book_cnt;
    books = new Book[book_cnt];
    for(size_t i = 0; i<book_cnt;++i){
        books[i] = other.books[i];
    }
}
std::ofstream& operator<<(std::ofstream& out, const Author& author) {
    out << author.name << ' ' << author.book_cnt << std::endl;
    for (size_t i = 0; i < author.book_cnt; ++i)
        out << author.books[i] << std::endl;

    return out;
}

bool operator>(const Author& lhs, const Author& rhs) {
    return std::strcmp(lhs.name, rhs.name) == 1;
}

bool operator>(const Author& lhs, char c) {
    return lhs.name[0] > c;
}
#endif //WEEK4_LINKEDLIST_TASK_AUTHOR_HPP
