#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node(int x)
    {
        value = x;
        next = NULL;
    }
};

//pass by value
void traverse(Node *head)
{
    while(head != NULL)
    {
        std::cout << head->value << std::endl;
        head = head->next;
    }
}

//above method is better as below recussive solution requires O(n) auxillary space
void recTraverse(Node *head)
{
    Node *node = head;
    if(node == NULL)
    {
        return;
    }
    std::cout << node->value << std::endl; 
    recTraverse(node->next);
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    recTraverse(head);
}
