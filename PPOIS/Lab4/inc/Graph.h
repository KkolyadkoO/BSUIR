#pragma once
#include<iostream>
#include<vector>
#include<iterator>

template <typename T>

class Graph
{
public:
    typedef std::vector<T> NodeList;
    typedef std::vector<NodeList> Matrix;
    typedef typename Matrix::iterator NodeIterator;
    typedef typename NodeList::iterator EdgeIterator;
    typedef typename Matrix::reverse_iterator ReverseNodeIterator;
    typedef typename NodeList::reverse_iterator ReverseEdgeIterator;
private:
    Matrix matrix;
    int numberOfNode = 0;
    int numberOfEdge = 0;
public:
    /**
     * @brief Construct a new Graph object
     * 
     * @param n number of nodes
     */
    Graph(int n):matrix(n,NodeList(n,T())),numberOfNode(n-1){}
    void addNode(){
        numberOfNode++;
        for(auto& node : matrix){
            node.push_back(T());
        }
        matrix.push_back(NodeList(numberOfNode+1,T()));
    }
    /**
     * @brief add Edge with number of nodes
     * 
     * @param from first node
     * @param to second node
     * @param value value
     */
    void addEdge(int from, int to, const T& value){
        if(!isEdge(from,to)){
        isNode(from);
        isNode(to);
        numberOfEdge++;
        matrix[from][to] = value;
        }
        else
        {
            throw std::invalid_argument("edge alredy exists");
        }
    }

    /**
     * @brief add edge with iterator
     * 
     * @param it iterator
     * @param value value
     */
    void addEdge(EdgeIterator it, const T& value){
        if(*it==T()){
        numberOfEdge++;
        *it = value;
        }
        else
        {
            throw std::invalid_argument("edge alredy exists");
        }
    }

    /**
     * @brief Set the Value object with number of nodes
     * 
     * @param from first node
     * @param to second node
     * @param value value
     */
    void setValue(int from, int to, const T& value){
        if(isEdge(from,to)){
        isNode(from);
        isNode(to);
        matrix[from][to] = value;
        }
    }

    /**
     * @brief Set the Value object with edge iterator
     * 
     * @param it edge iterator
     * @param value value
     */
    void setValue(EdgeIterator it, const T& value){
        if(*it!=T())
        *it = value;
        else
            throw std::invalid_argument("no such edge");
    }

    /**
     * @brief Get the Edge Degree object
     * 
     * @param from first node
     * @param to second node
     * @return int degree
     */
    int getEdgeDegree(int from, int to){
        return isEdge(from, to) ? 1 : 0;
    }

    /**
     * @brief delete node with number
     * 
     * @param nodeNum number of node
     */
    void deleteNode(int nodeNum){
        isNode(nodeNum);
        matrix.erase(matrix.begin() + nodeNum);
        for (auto& node : matrix)
        {
            node.erase(node.begin() + nodeNum);
        }
        numberOfNode--;
    }
    /**
     * @brief delete node with iterator
     * 
     * @param it node iterator
     */
    void deleteNode(NodeIterator it){
        int number = it - matrix.begin();
        matrix.erase(it);
        for (auto& node : matrix)
        {
            node.erase(node.begin() + number);
        }
        numberOfNode--;
    }

    /**
     * @brief delete edge with iterator
     * 
     * @param it edge iterator
     */
    void deleteEdge(EdgeIterator it){
        *it = T();
        numberOfEdge--;
    }

    /**
     * @brief delete edge with number of node
     * 
     * @param from first node
     * @param to second node
     */
    void deleteEdge(int from, int to){
        matrix[from][to] = T();
        numberOfEdge--;
    }

    /**
     * @brief Get the Number Of Edge object
     * 
     * @return int 
     */
    int getNumberOfEdge(){
        return numberOfEdge;
    }
    /**
     * @brief Get the Number Of Node object
     * 
     * @return int 
     */
    int getNumberOfNode(){
        return numberOfNode+1;
    }
    /**
     * @brief Get the Node Degree object
     * 
     * @param nodeNum number of node
     * @return int degree
     */
    int getNodeDegree(int nodeNum){
        isNode(nodeNum);
        int degree = 0;
        for(const auto& value : matrix[nodeNum])
        {
            if(value != T())
                degree++;
        }
        return degree;
    }

    /**
     * @brief Get the Value object
     * 
     * @param it edge iterator
     * @return T& value
     */
    T& getValue(EdgeIterator it){
        return *it;
    }

    /**
     * @brief Get the Value object
     * 
     * @param from first node
     * @param to second node
     * @return T& value
     */
    T& getValue(int from, int to){
        isNode(from);
        isNode(to);
        if(!isEdge(from,to))
        {
            throw std::invalid_argument("no such edge");
        }
        return matrix[from][to];
    }

    /**
     * @brief nodeIterator begin
     * 
     * @return NodeIterator 
     */
    NodeIterator begin()  {return matrix.begin();}
    /**
     * @brief nodeIterator end
     * 
     * @return NodeIterator 
     */
    NodeIterator end()  {return matrix.end();}

    /**
     * @brief edge iterator begin
     * 
     * @param node number of node
     * @return EdgeIterator 
     */
    EdgeIterator begin(int node)  {return matrix[node].begin();}
    /**
     * @brief edge iterator end
     * 
     * @param node number of node
     * @return EdgeIterator 
     */
    EdgeIterator end(int node)  {return matrix[node].end();}

    /**
     * @brief node revesre iterator begin
     * 
     * @return ReverseNodeIterator 
     */
    ReverseNodeIterator rbegin() {return matrix.rbegin();}
    /**
     * @brief node revesre iterator end
     * 
     * @return ReverseNodeIterator 
     */
    ReverseNodeIterator rend() {return matrix.rend();}

    /**
     * @brief edge revesre iterator begin
     * 
     * @param node number of node
     * @return ReverseEdgeIterator 
     */
    ReverseEdgeIterator rbegin(int node) {return matrix[node].rbegin();}
    /**
     * @brief edge revesre iterator end
     * 
     * @param node number of node
     * @return ReverseEdgeIterator 
     */
    ReverseEdgeIterator rend(int node) {return matrix[node].rend();}

    /**
     * @brief check is empty matrix
     * 
     * @return true 
     * @return false 
     */
    bool isEmpty(){
        return matrix.empty();
    }
    /**
     * @brief clear matrix
     * 
     */
    void clear(){
        matrix.clear();
    }

    private:
    /**
     * @brief check is node in matrix
     * 
     * @param nodeNum number of node
     */
    void isNode(int nodeNum){
        if(nodeNum<0 || nodeNum > numberOfNode )
        {
            throw std::out_of_range("no such node");
        }
    }
    /**
     * @brief check is edge in graph
     * 
     * @param from first node
     * @param to second node
     * @return true 
     * @return false 
     */
    bool isEdge(int from, int to){
        return matrix[from][to] != T();
    }
};