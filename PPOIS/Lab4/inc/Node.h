#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

template <typename T>
class Node{
private:
    T value = T();
    int uniqueName;
public:

    /**
     * @brief Construct a new Node object without name
     * 
     * @param value_ value
     */
    Node( int uniqueName_, T value_ = T()): value(value_), uniqueName(uniqueName_){}
    Node(T value_ = T()): value(value_){}

    int getUniqueName(){
        return uniqueName;
    }
    /**
     * @brief Get the Value object
     * 
     * @return T 
     */
    T getValue() const{
        return value;
    }

    /**
     * @brief Set the Value object
     * 
     * @param value_ 
     */
    void setValue(T value_){
        value = value_;
    }



    /**
     * @brief operator ==
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool operator==(const Node &node){
        return node.value == value && node.uniqueName == uniqueName;
    }
    /**
     * @brief operator !=
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool operator!=(const Node &node){
        return !operator==(node);
    }



};