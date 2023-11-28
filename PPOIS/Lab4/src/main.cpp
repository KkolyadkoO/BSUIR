#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include"../inc/Graph.h"
using namespace std;

int main()
{       
    Graph<int> test(4);
   test.addEdge(0,1,1);
   test.addEdge(0,2,1);
   test.addEdge(1,2,1);

   Graph<int>::NodeAdjacentIterator it(0,test);
   it.next();
   cout<<test.getNumberOfNode();
   test.deleteNode(it.getCurrent());
   cout<<test.getNumberOfNode();

    
    return 0;

}