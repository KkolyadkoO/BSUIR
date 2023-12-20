#include <gtest/gtest.h>
#include "../inc/Graph.h"
#include <string>

TEST(GRAPH_Test, empty)
{
  Graph<int> test;
  EXPECT_TRUE(test.isEmpty());
}

TEST(GRAPH_Test, Node)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  EXPECT_EQ(2, test.getNumberOfNode());
  test.deleteNode(1);
  EXPECT_EQ(1, test.getNumberOfNode());
}

TEST(GRAPH_Test, Edge)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  EXPECT_EQ(0, test.getNumberOfEdge());
  test.addEdge(0, 1);
  EXPECT_EQ(4, test.getValue(1));
  EXPECT_EQ(1, test.getNumberOfEdge());
  test.deleteEdge(0, 1);
  EXPECT_EQ(0, test.getNumberOfEdge());
}

TEST(GRAPH_Test, AdjacentIterator)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  test.addNode(3);
  test.addEdge(0,2);
  test.addEdge(0,1);
  Graph<int>::NodeAdjacentIterator it(0,test);
  it.begin();
  EXPECT_TRUE(it.getCurrent() == 4);
  it.next();
  EXPECT_TRUE(it.getCurrent() == 3);
  it.back();
  EXPECT_TRUE(it.getCurrent() == 4);
  it+1;
  EXPECT_TRUE(it.getCurrent() == 3);
  it-1;
  EXPECT_TRUE(it.getCurrent() == 4);
}

TEST(GRAPH_Test, operators)
{
  Graph<int> test1;
  Graph<int> test2;
  test1.addNode(5);
  test1.addNode(4);
  test1.addNode(3);
  test2.addNode(5);
  test2.addNode(4);
  test2.addNode(3);
  EXPECT_TRUE(test1 == test2);
  test2.deleteNode(2);
  EXPECT_TRUE(test1 != test2);
  test1.addEdge(0, 1);
  std::ostringstream oss;
  oss << test1;
  std::string s = "0 -> 1\n";
  EXPECT_TRUE(oss.str() == s);
}

TEST(GRAPH_Test, NodeIteratorConst)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  test.addNode(3);
  test.addEdge(0,2);
  test.addEdge(0,1);
  Graph<int>::NodeIteratorConst it(test);
  it.begin();
  EXPECT_TRUE(it.getCurrent().getValue() == 5);
  it.next();
  EXPECT_TRUE(it.getCurrent().getValue() == 4);
  it.back();
  EXPECT_TRUE(it.getCurrent().getValue() == 5);
  it+2;
  EXPECT_TRUE(it.getCurrent().getValue() == 3);
  it-1;
  EXPECT_TRUE(it.getCurrent().getValue() == 4);
}
TEST(GRAPH_Test, NodeIterator)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  test.addNode(3);
  test.addEdge(0,2);
  test.addEdge(0,1);
  Graph<int>::NodeIterator it(test);
  it.begin();
  EXPECT_TRUE(it.getCurrent().getValue() == 5);
  it.next();
  EXPECT_TRUE(it.getCurrent().getValue() == 4);
  it.back();
  EXPECT_TRUE(it.getCurrent().getValue() == 5);
  it+2;
  EXPECT_TRUE(it.getCurrent().getValue() == 3);
  it-1;
  EXPECT_TRUE(it.getCurrent().getValue() == 4);
  it.deleteNode();
  EXPECT_TRUE(test.getNumberOfNode() == 2);
  it.setValue(2);
  EXPECT_TRUE(it.getCurrent().getValue() == 2);

}
TEST(GRAPH_Test, RNodeIterator)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  test.addNode(3);
  Graph<int>::ReverseNodeIterator it(test);
  it.begin();
  EXPECT_TRUE(it.getCurrent().getValue() == 3);
}

TEST(GRAPH_Test, AdjacentEdgeIteratorConst)
{
  Graph<int> test;
  test.addNode(5);
  test.addNode(4);
  test.addNode(3);
  test.addEdge(0,1);
  test.addEdge(0,2);
  Graph<int>::AdjacentEdgeIteratorConst it(0, test);
  EXPECT_TRUE(it.hasNext());
  EXPECT_FALSE(it.hasPrev());
  it.next();
  std::pair<int,int> p(5,3); 
  EXPECT_TRUE(it.getValue() == p);
  it.back();
  std::pair<int,int> p1(5,4); 
  EXPECT_TRUE(it.getValue() == p1);
}
