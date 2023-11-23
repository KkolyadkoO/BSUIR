#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include"../inc/Graph.h"
using namespace std;

int main()
{       
    Graph<int> a(1);
    a.deleteNode(0);
    cout << a.getNumberOfNode()<< endl;
    // vector<int>::iterator it = a.begin(0);
    // it++;

    // a.deleteEdge(it);
    // cout << a.getNumberOfEdge()<< endl;
    // cout << a.getEdgeDegree(0,1)<< endl;
    
    
    return 0;

}