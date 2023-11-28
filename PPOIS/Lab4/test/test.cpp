#include <gtest/gtest.h>
#include <sstream>
#include "../inc/Graph.h"
#include <string>

TEST(GRAPH_Test, empty)
{
  Graph<int> test(0);
  EXPECT_TRUE(test.isEmpty());
}

TEST(GRAPH_Test, Node)
{
  Graph<int> test(1);
  test.addNode();
  EXPECT_EQ(2, test.getNumberOfNode());
  test.deleteNode(1);
  EXPECT_EQ(1, test.getNumberOfNode());
}

TEST(GRAPH_Test, Edge)
{
  Graph<int> test(3);
  EXPECT_EQ(0, test.getNumberOfEdge());
  test.addEdge(0, 1, 1);
  EXPECT_EQ(1, test.getValue(0, 1));
  test.setValue(0, 1, 2);
  EXPECT_EQ(2, test.getValue(0, 1));
  EXPECT_EQ(1, test.getNumberOfEdge());
  test.deleteEdge(0, 1);
  EXPECT_EQ(0, test.getNumberOfEdge());
}

TEST(GRAPH_Test, iterator)
{
  Graph<int> test(3);
  std::vector<std::vector<int>>::iterator it = test.begin();
  it++;
  test.deleteNode(it);
  EXPECT_EQ(test.getNumberOfNode(), 2);
  std::vector<int>::iterator it1 = test.begin(0);
  it1++;
  test.addEdge(it1, 1);
  EXPECT_EQ(test.getNumberOfEdge(), 1);
  test.setValue(it1, 2);
  EXPECT_EQ(test.getValue(it1), 2);
}

TEST(GRAPH_Test, operators)
{
  Graph<int> test1(3);
  Graph<int> test2(3);
  EXPECT_TRUE(test1 == test2);
  test2.deleteNode(2);
  EXPECT_TRUE(test1 != test2);
  test1.addEdge(0, 1, 1);
  std::ostringstream oss;
  oss << test1;
  std::string s = "0 -> 1 value: 1\n";
  EXPECT_TRUE(oss.str() == s);
}

TEST(GRAPH_Test, NodeAdjacentIterator)
{
  Graph<int> test(4);
  test.addEdge(0, 1, 1);
  test.addEdge(0, 2, 1);
  test.addEdge(1, 2, 1);
  Graph<int>::NodeAdjacentIterator it(0, test);
  it.next();
  EXPECT_TRUE(test.getNumberOfNode() == 4);
  test.deleteNode(it.getCurrent());
  EXPECT_TRUE(test.getNumberOfNode() == 3);
  it.back();
  test.deleteNode(it.getCurrent());
  EXPECT_TRUE(test.getNumberOfNode() == 2);

}