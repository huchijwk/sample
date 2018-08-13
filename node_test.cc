// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_FALSE(node == nullptr);
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

  static void InsertPreviousTest() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertPreviousNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_EQ(node1->GetPreviousNode(), node2);
    ASSERT_EQ(node2->GetNextNode(), node1);
    delete node1;
    delete node2;
  }

  static void MulitpleInsertPreviousTest() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertPreviousNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_EQ(node1->GetPreviousNode(), node2);
    ASSERT_EQ(node2->GetNextNode(), node1);
    Node *node3 = node2->InsertPreviousNode('C');
    ASSERT_FALSE(node3 == nullptr);
    ASSERT_EQ(node2->GetPreviousNode(), node3);
    ASSERT_EQ(node3->GetNextNode(), node2);
    ASSERT_EQ(node1->GetPreviousNode(), node2);
    ASSERT_EQ(node2->GetNextNode(), node1);
    Node *node4 = node2->InsertPreviousNode('D');
    ASSERT_FALSE(node4 == nullptr);
    ASSERT_EQ(node4->GetPreviousNode(), node3);
    ASSERT_EQ(node3->GetNextNode(), node4);
    ASSERT_EQ(node4->GetNextNode(), node2);
    ASSERT_EQ(node2->GetPreviousNode(), node4);
    
    delete node1;
    delete node2;
    delete node3;
    delete node4;
  }

  static void InsertNextTest() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_EQ(node1->GetNextNode(), node2);
    ASSERT_EQ(node2->GetPreviousNode(), node1);
    delete node1;
    delete node2;
  }

  static void MulitpleInsertNextTest() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_EQ(node1->GetNextNode(), node2);
    ASSERT_EQ(node2->GetPreviousNode(), node1);
    Node *node3 = node2->InsertNextNode('C');
    ASSERT_FALSE(node3 == nullptr);
    ASSERT_EQ(node2->GetNextNode(), node3);
    ASSERT_EQ(node3->GetPreviousNode(), node2);
    ASSERT_EQ(node1->GetNextNode(), node2);
    ASSERT_EQ(node2->GetPreviousNode(), node1);
    Node *node4 = node2->InsertNextNode('D');
    ASSERT_FALSE(node4 == nullptr);
    ASSERT_EQ(node4->GetPreviousNode(), node2);
    ASSERT_EQ(node2->GetNextNode(), node4);
    ASSERT_EQ(node4->GetNextNode(), node3);
    ASSERT_EQ(node3->GetPreviousNode(), node4);

    delete node1;
    delete node2;
    delete node3;
  }

  static void GetPreviousTest() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_EQ(node2->GetPreviousNode(), node1);
    delete node1;
    delete node2;
  }

  static void GetPreviousTestNegative() {
    Node *node = new Node('A');
    ASSERT_FALSE(node == nullptr);
    ASSERT_TRUE(node->GetPreviousNode() == nullptr);
    delete node;
  }

  static void GetNextTest() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_EQ(node1->GetNextNode(), node2);
    delete node1;
    delete node2;
  }

  static void GetNextTestNegative() {
    Node *node = new Node('A');
    ASSERT_FALSE(node == nullptr);
    ASSERT_TRUE(node->GetNextNode() == nullptr);
    delete node;
  }

  static void ErasePreviousNode() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_TRUE(node2->ErasePreviousNode());
    ASSERT_TRUE(node2->GetPreviousNode() == nullptr);
    delete node2;
  }

  static void MultipleErasePreviousNode() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    Node *node3 = node2->InsertNextNode('C');
    ASSERT_FALSE(node3 == nullptr);
    ASSERT_TRUE(node3->ErasePreviousNode());
    ASSERT_TRUE(node3->GetPreviousNode() == node1);
    ASSERT_TRUE(node3->ErasePreviousNode());
    ASSERT_TRUE(node3->GetPreviousNode() == nullptr);
    delete node3;
  }
  
  static void ErasePreviousNodeNegative() {
    Node *node = new Node('A');
    ASSERT_FALSE(node == nullptr);
    ASSERT_FALSE(node->ErasePreviousNode());
    delete node;
  }

  static void EraseNextNode() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    ASSERT_TRUE(node1->EraseNextNode());
    ASSERT_TRUE(node1->GetNextNode() == nullptr);
    delete node1;
  }

  static void MultipleEraseNextNode() {
    Node *node1 = new Node('A');
    ASSERT_FALSE(node1 == nullptr);
    Node *node2 = node1->InsertNextNode('B');
    ASSERT_FALSE(node2 == nullptr);
    Node *node3 = node2->InsertNextNode('B');
    ASSERT_FALSE(node3 == nullptr);
    ASSERT_TRUE(node1->EraseNextNode());
    ASSERT_TRUE(node1->GetNextNode() == node3);
    ASSERT_TRUE(node1->EraseNextNode());
    ASSERT_TRUE(node1->GetNextNode() == nullptr);
    delete node1;
  }

  static void EraseNextNodeNegative() {
    Node *node = new Node('A');
    ASSERT_FALSE(node == nullptr);
    ASSERT_FALSE(node->EraseNextNode());
    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
    InsertPreviousTest();
    MulitpleInsertPreviousTest();
    InsertNextTest();
    MulitpleInsertNextTest();
    GetPreviousTest();
    GetPreviousTestNegative();
    GetNextTest();
    GetNextTestNegative();
    ErasePreviousNode();
    MultipleErasePreviousNode();
    ErasePreviousNodeNegative();
    EraseNextNode();
    MultipleEraseNextNode();
    EraseNextNodeNegative();

    // add more..
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  // add more..
}