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

Node *insertBegin(Node *head, int x)
{
    Node *newHead = new Node(x);
    newHead->next = head;
    return newHead;
}

// need to make some changes
Node *insertEnd(Node *head, int x)
{
    Node *node = head;
    if(node == NULL)
    {
        node = new Node(x);
        return node;
    }
    while(node->next != NULL)
    {
        node = node->next;
    }
    node->next = new Node(x);
    return head;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head = insertBegin(head,5);
    head = insertBegin(head,19);
    head = insertEnd(head,99);
    Node *head2 = NULL;
    head2 = insertEnd(head2,189);
    traverse(head);
}
