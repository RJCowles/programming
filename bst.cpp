#include <iostream>
#include <vector>
class Node
{
public:
    Node() { leftChild = rightChild = nullptr; }
    Node(int data)
    {
        this->data = data;
        leftChild = rightChild = nullptr;
    }
    int data;
    Node *leftChild;
    Node *rightChild;
};
int main()
{
    Node node1(5);
    std::cout << node1.data << " ";
    std::cout << node1.leftChild<< " ";
    std::cout << node1.rightChild;
}