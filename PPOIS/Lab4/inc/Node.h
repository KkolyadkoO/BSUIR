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
    /**
     * @brief Construct a new Node object
     * 
     * @param name_ name
     * @param value_ value
     */
    Node(std::string name_, T value_ = T()): value(value_), name(name_){}
    /**
     * @brief Construct a new Node object without name
     * 
     * @param value_ value
     */
    Node( T value_ = T()): value(value_){}

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
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName() const{
        return name;
    }

    /**
     * @brief operator ==
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool operator==(const Node &node){
        return node.value == value && node.name == name ? true : false;
    }
    /**
     * @brief operator !=
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool operator!=(const Node &node){
        return node.value == value && node.name == name ? false : true;
    }
    /**
     * @brief Set the Name object
     * 
     * @param name_ 
     */
    void setName(std::string name_){
        name = name_;
    }


};