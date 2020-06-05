#include <gtest/gtest.h>
#include "BST.h"

class BstTest : public testing::Test {
public:
    BST* tree;

    void SetUp() {
    }

    void TearDown() {
    }

};

TEST_F(BstTest, InitTree) {
    tree = new BST;
    ASSERT_TRUE(tree->isEmpty());
}

TEST_F(BstTest, FillTree) {
    tree->rAdd(10);
    tree->add(7);
    tree->rAdd(21);
    tree->add(5);
    tree->rAdd(17);
    tree->add(12);
    tree->rAdd(16);
    EXPECT_TRUE(tree->rFind(16) != nullptr);
    EXPECT_TRUE(tree->find(17) != nullptr);
    ASSERT_TRUE(tree->rFind(11) == nullptr);
}

TEST_F(BstTest, Traversals) {
    ASSERT_EQ(tree->rPreOrderTraversal(), "10 7 5 21 17 12 16 ");
    ASSERT_EQ(tree->preOrderTraversal(), "10 7 5 21 17 12 16 ");
    ASSERT_EQ(tree->rInOrderTraversal(), "5 7 10 12 16 17 21 ");
    ASSERT_EQ(tree->rPostOrderTraversal(), "5 7 16 12 17 21 10 ");
    ASSERT_EQ(tree->breadthTraversal(), "10 7 21 5 17 12 16 ");
}

TEST_F(BstTest, TreeHeight) {
    ASSERT_EQ(tree->getHeight(), 4);
}

TEST_F(BstTest, ClearTree) {
    tree->clear();
    ASSERT_TRUE(tree->isEmpty());
}

TEST_F(BstTest, AddAndDelete) {
    tree->add(9);
    int deleted = tree->rDeleteNode(9);

    ASSERT_EQ(deleted, 9);
    ASSERT_EQ(tree->rDeleteNode(9), 1); // not found
}
