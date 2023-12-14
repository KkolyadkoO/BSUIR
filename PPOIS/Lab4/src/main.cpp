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
    test.addNode(5);
    test.addNode(4);
    test.addEdge(0,0);
    test.addEdge(0,1);
    cout << test;
    
    
    return 0;

}