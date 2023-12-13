#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include"../inc/Graph1.h"
using namespace std;

int main()
{       
    Graph<int> test;
    test.addNode(5);
    test.addNode(4);
    test.addEdge(0,0);
    test.addEdge(0,1);
    Graph<int>::EdgeIterator it(0,test);
    it.next();
    it.deleteEdge();
    pair<int,int> p = it.getValue();
   
    
    return 0;

}