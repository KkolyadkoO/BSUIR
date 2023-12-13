#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

template <typename T>
class Node{
private:
    T value;
    std::string name;
public:
    Node(std::string name_, T value_ = T()): value(value_), name(name_){}
    Node( T value_ = T()): value(value_){}

    T getValue(){
        return value;
    }

    void setValue(T value_){
        value = value_;
    }

    std::string getName(){
        return name;
    }

    bool operator==(const Node &node){
        return node.value == value && node.name == name ? true : false;
    }
    bool operator!=(const Node &node){
        return node.value == value && node.name == name ? false : true;
    }

    void setName(std::string name_){
        name = name_;
    }


};