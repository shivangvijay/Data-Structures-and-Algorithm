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

void traverse(Node *head)
{
    while(head != NULL)
    {
        std::cout << head->value << std::endl;
        head = head->next;
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    traverse(head);
}
