#include <gtest/gtest.h>
#include <sstream>
#include "../inc/Graph.h"


TEST(GRAPH_Test, empty)
{
  Graph<int> test(0);
  EXPECT_TRUE(test.isEmpty());
}

TEST(GRAPH_Test, Node)
{
  Graph<int> test(1);
  test.addNode();
  EXPECT_EQ(2,test.getNumberOfNode());
  test.deleteNode(1);
  EXPECT_EQ(1,test.getNumberOfNode());
}

TEST(GRAPH_Test, Edge)
{
  Graph<int> test(3);
  EXPECT_EQ(0,test.getNumberOfEdge());
  test.addEdge(0,1,1);
  EXPECT_EQ(1,test.getValue(0,1));
  test.setValue(0,1,2);
  EXPECT_EQ(2,test.getValue(0,1));
  EXPECT_EQ(1,test.getNumberOfEdge());
  test.deleteEdge(0,1);
  EXPECT_EQ(0,test.getNumberOfEdge());
}

TEST(GRAPH_Test, iterator)
{
  Graph<int> test(3);
  std::vector<std::vector<int>>::iterator it = test.begin();
  it++;
  test.deleteNode(it);
  EXPECT_EQ(test.getNumberOfNode(),2);
  std::vector<int>::iterator it1 = test.begin(0);
  it1++;
  test.addEdge(it1,1);
  EXPECT_EQ(test.getNumberOfEdge(),1);
  test.setValue(it1,2);
  EXPECT_EQ(test.getValue(it1),2);
}