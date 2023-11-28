#pragma once
#include <iostream>
#include <vector>
#include <iterator>

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
    Graph(int n) : matrix(n, NodeList(n, T())), numberOfNode(n - 1) {}

    /**
     * @brief add node
     *
     */
    void addNode()
    {
        numberOfNode++;
        for (auto &node : matrix)
        {
            node.push_back(T());
        }
        matrix.push_back(NodeList(numberOfNode + 1, T()));
    }
    /**
     * @brief add Edge with number of nodes
     *
     * @param from first node
     * @param to second node
     * @param value value
     */
    void addEdge(int from, int to, const T &value)
    {
        if (!isEdge(from, to))
        {
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
    void addEdge(EdgeIterator it, const T &value)
    {
        if (*it == T())
        {
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
    void setValue(int from, int to, const T &value)
    {
        isNode(from);
        isNode(to);
        if (isEdge(from, to))
        {
            matrix[from][to] = value;
        }
    }

    /**
     * @brief Set the Value object with edge iterator
     *
     * @param it edge iterator
     * @param value value
     */
    void setValue(EdgeIterator it, const T &value)
    {
        if (*it != T())
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
    int getEdgeDegree(int from, int to)
    {
        return isEdge(from, to) ? 1 : 0;
    }

    /**
     * @brief delete node with number
     *
     * @param nodeNum number of node
     */
    void deleteNode(int nodeNum)
    {
        isNode(nodeNum);
        int numberOfEdgeInThisNode = 0;
        for (const auto &node : matrix)
        {
            if (node[nodeNum] != T())
                numberOfEdgeInThisNode++;
        }

        numberOfEdge -= numberOfEdgeInThisNode;
        numberOfEdge -= getNodeDegree(nodeNum);

        matrix.erase(matrix.begin() + nodeNum);
        for (auto &node : matrix)
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
    void deleteNode(NodeIterator it)
    {
        int number = it - matrix.begin();

        int numberOfEdgeInThisNode = 0;
        for (const auto &node : matrix)
        {
            if (node[number] != T())
                numberOfEdgeInThisNode++;
        }
        numberOfEdge -= numberOfEdgeInThisNode;
        numberOfEdge -= getNodeDegree(number);

        matrix.erase(it);
        for (auto &node : matrix)
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
    void deleteEdge(EdgeIterator it)
    {
        *it = T();
        numberOfEdge--;
    }

    /**
     * @brief delete edge with number of node
     *
     * @param from first node
     * @param to second node
     */
    void deleteEdge(int from, int to)
    {
        matrix[from][to] = T();
        numberOfEdge--;
    }

    /**
     * @brief Get the Number Of Edge object
     *
     * @return int
     */
    int getNumberOfEdge()
    {
        return numberOfEdge;
    }
    /**
     * @brief Get the Number Of Node object
     *
     * @return int
     */
    int getNumberOfNode() const
    {
        return numberOfNode + 1;
    }
    /**
     * @brief Get the Node Degree object
     *
     * @param nodeNum number of node
     * @return int degree
     */
    int getNodeDegree(int nodeNum)
    {
        isNode(nodeNum);
        int degree = 0;
        for (const auto &value : matrix[nodeNum])
        {
            if (value != T())
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
    T &getValue(EdgeIterator it) const
    {
        return *it;
    }

    /**
     * @brief Get the Value object
     *
     * @param from first node
     * @param to second node
     * @return T& value
     */
    T &getValue(int from, int to)
    {
        isNode(from);
        isNode(to);
        if (!isEdge(from, to))
        {
            throw std::invalid_argument("no such edge");
        }
        return matrix[from][to];
    }
    /**
     * @brief Get the Value Without Exeption object
     *
     * @param from first node
     * @param to second node
     * @return T& value
     */
    T &getValueWithoutExeption(int from, int to)
    {
        isNode(from);
        isNode(to);

        return matrix[from][to];
    }
    /**
     * @brief nodeIterator begin
     *
     * @return NodeIterator
     */
    NodeIterator begin() { return matrix.begin(); }
    /**
     * @brief nodeIterator end
     *
     * @return NodeIterator
     */
    NodeIterator end() { return matrix.end(); }

    /**
     * @brief edge iterator begin
     *
     * @param node number of node
     * @return EdgeIterator
     */
    EdgeIterator begin(int node)
    {
        isNode(node);
        return matrix[node].begin();
    }
    /**
     * @brief edge iterator end
     *
     * @param node number of node
     * @return EdgeIterator
     */
    EdgeIterator end(int node)
    {
        isNode(node);
        return matrix[node].end();
    }

    /**
     * @brief node revesre iterator begin
     *
     * @return ReverseNodeIterator
     */
    ReverseNodeIterator rbegin() { return matrix.rbegin(); }
    /**
     * @brief node revesre iterator end
     *
     * @return ReverseNodeIterator
     */
    ReverseNodeIterator rend() { return matrix.rend(); }

    /**
     * @brief edge revesre iterator begin
     *
     * @param node number of node
     * @return ReverseEdgeIterator
     */
    ReverseEdgeIterator rbegin(int node) { return matrix[node].rbegin(); }
    /**
     * @brief edge revesre iterator end
     *
     * @param node number of node
     * @return ReverseEdgeIterator
     */
    ReverseEdgeIterator rend(int node) { return matrix[node].rend(); }

    /**
     * @brief check is empty matrix
     *
     * @return true
     * @return false
     */
    bool isEmpty()
    {
        return matrix.empty();
    }
    /**
     * @brief clear matrix
     *
     */
    void clear()
    {
        matrix.clear();
        numberOfEdge = 0;
        numberOfNode = -1;
    }

    /**
     * @brief operator ==
     *
     * @param graph graph
     * @return true
     * @return false
     */
    bool operator==(const Graph &graph)
    {
        if (this->numberOfNode != graph.numberOfNode || this->numberOfEdge != graph.numberOfEdge)
            return false;
        for (size_t i = 0; i < numberOfNode + 1; i++)
        {
            for (size_t j = 0; j < numberOfNode + 1; j++)
            {
                if (this->matrix[i][j] != graph.matrix[i][j])
                    return false;
            }
        }
        return true;
    }
    /**
     * @brief operator !=
     *
     * @param graph graph
     * @return true
     * @return false
     */
    bool operator!=(const Graph &graph)
    {
        if (this->numberOfNode != graph.numberOfNode || this->numberOfEdge != graph.numberOfEdge)
            return true;
        for (size_t i = 0; i < numberOfNode + 1; i++)
        {
            for (size_t j = 0; j < numberOfNode + 1; j++)
            {
                if (this->matrix[i][j] != graph.matrix[i][j])
                    return true;
            }
        }
        return false;
    }

    class NodeAdjacentIterator
    {
    private:
        NodeIterator current;
        std::vector<NodeIterator> adjacentNode;
        int position = 0;

    public:
        /**
         * @brief Construct a new Node Adjacent Iterator object
         *
         * @param nodeNum number of node
         * @param graph graph
         */
        NodeAdjacentIterator(int nodeNum, Graph &graph)
        {
            adjacentNode.push_back(graph.begin() + nodeNum);
            for (int i = 0; i < graph.getNumberOfNode(); i++)
            {
                if (graph.getValueWithoutExeption(nodeNum, i) != T())
                {
                    adjacentNode.push_back(graph.begin() + i);
                }
            }
            current = adjacentNode[0];
        }

        /**
         * @brief set current on first node
         *
         */
        void begin()
        {
            current = adjacentNode[0];
        }

        /**
         * @brief set current on next node
         *
         */
        void next()
        {
            position++;
            if (position > adjacentNode.size() - 1)
                throw std::out_of_range("no such node");

            current = adjacentNode[position];
        }
        /**
         * @brief set current on previous node
         *
         */
        void back()
        {
            position--;
            if (position < 0)
                throw std::out_of_range("no such node");

            current = adjacentNode[position];
        }

        /**
         * @brief operator +
         *
         * @param n number of nodes
         * @details set current on +n nodes
         */
        void operator+(int n)
        {
            position += n;
            if (position > adjacentNode.size() - 1)
                throw std::out_of_range("no such node");
            current = adjacentNode[position];
        }
        /**
         * @brief operator -
         *
         * @param n number of nodes
         * @details set current on -n nodes
         */
        void operator-(int n)
        {
            position -= n;
            if (position < 0)
                throw std::out_of_range("no such node");
            current = adjacentNode[position];
        }

        /**
         * @brief Get the Current iterator
         *
         * @return NodeIterator
         */
        NodeIterator getCurrent()
        {
            return current;
        }
    };

    /**
     * @brief get begin of adjancent iterator
     *
     * @param n number of node
     * @return NodeAdjacentIterator
     */
    NodeAdjacentIterator beginAdjancent(int n)
    {
        NodeAdjacentIterator res(n, *this);
        return res;
    }

private:
    /**
     * @brief check is node in matrix
     *
     * @param nodeNum number of node
     */
    void isNode(int nodeNum) const
    {
        if (nodeNum < 0 || nodeNum > numberOfNode)
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
    bool isEdge(int from, int to) const
    {
        return matrix[from][to] != T();
    }
};
/**
 * @brief operator <<
 * 
 * @param os 
 * @param graph 
 * @return std::ostream& 
 */
template <typename Temp>
std::ostream &operator<<(std::ostream &os, Graph<Temp> &graph)
{
    for (size_t i = 0; i < graph.getNumberOfNode(); i++)
    {
        for (size_t j = 0; j < graph.getNumberOfNode(); j++)
        {
            if (graph.getValueWithoutExeption(i, j) != Temp())
            {
                os << i << " -> " << j << " value: " << graph.getValue(i, j) << "\n";
            }
        }
    }

    return os;
}
