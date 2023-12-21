#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include"../inc/Graph.h"
using namespace std;

int main()
{       
    Graph<int> test;
    test.addNode(5,1);
    test.addNode(5,2);
    test.addNode(3,3);
    test.addEdge(0,1);
    test.addEdge(0,2);
    test.addEdge(2,1);
    Graph<int> test1;
    test1.addNode(5,2);
    test1.addNode(5,1);
    test1.addNode(3,3);
    test1.addEdge(1,0);
    test1.addEdge(1,2);
    test1.addEdge(2,0);
    if(test== test1)
    cout<<"true";
    else
    cout<<"false";
    
    return 0;

}