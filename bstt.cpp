#include <iostream>
#include <vector>
class BST
{
public:
    BST()
    {
        root = nullptr;
    }
    void insertKey(int newKey);
    std::vector<int> inOrder();

private:
    class Node
    {
    public:
        Node() { leftChild = rightChild = nullptr; }
        Node(int nodeData)
        {
            this->data = nodeData;
            leftChild = rightChild = nullptr;
        }
        int data;
        Node *leftChild;
        Node *rightChild;
    };
    Node *root;
    Node *makeNewNode(int data);
    void helperInsertKey(Node *root, int inputData);
    void helperInOrder(Node *root);
    std::vector<int> listInOrder;
};
void BST::helperInOrder(Node *root)
{
    if (root != nullptr)
    {
        if (root->leftChild != nullptr)
        {
            helperInOrder(root->leftChild);
        }
        std::cout << root->data << " ";
        listInOrder.push_back(root->data);
        if (root->rightChild != nullptr)
        {
            helperInOrder(root->rightChild);
        }
    }
    else
    {
        std::cout << "tree is empty";
    }
    // helperInOrder(root->leftChild);
    // std::cout << root->data;
    // listInOrder.push_back(root->data);
    // helperInOrder(root->rightChild);
}
std::vector<int> BST::inOrder()
{
    helperInOrder(root);
    return listInOrder;
}
BST::Node *BST::makeNewNode(int data)
{
    Node *newNode = new Node(data);
    return newNode;
}
void BST::helperInsertKey(Node *root, int inputData)
{
    std::cout << root << "original root address " << std::endl;
    if (root == nullptr)
    {
        root = makeNewNode(inputData);
        std::cout << root << std::endl;
    }
    else if (root->data > inputData)
    {
        if (root->leftChild == nullptr)
        {
            root->leftChild = makeNewNode(inputData);
            std::cout << root->leftChild << " leftchild" << std::endl;
        }
        else
        {
            helperInsertKey(root->leftChild, inputData);
        }
        helperInsertKey(root->leftChild, inputData);
    }
    else if (root->data < inputData)
    {
        if (root->rightChild == nullptr)
        {

            root->rightChild = makeNewNode(inputData);
        }
        else
        {
            helperInsertKey(root->rightChild, inputData);
        }
    }
    else
    {
        std::cout << "same value";
        // check out for this, need to error check what values will crash it
    }
}
void BST::insertKey(int newKey)
{
    helperInsertKey(root, newKey);
}

// which root
// check by couting root after creating a tree

int main()
{
    BST bst1;
    bst1.insertKey(5);
    bst1.insertKey(3);
    bst1.insertKey(4);
    bst1.insertKey(10);
    bst1.inOrder();
}