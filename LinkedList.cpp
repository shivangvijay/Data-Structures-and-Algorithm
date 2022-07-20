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

Node *deleteStart(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node *newHead = head->next;
    delete head;
    return newHead;
}

Node* deleteTail(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while(curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}

Node* insertAtPosition(Node* head, int position, int value)
{
    if(position == 1)
    {
        Node *newHead = new Node(value);
        newHead->next = head;
        return newHead;
    }
    int count = 1;
    Node* node = new Node(value);
    Node* curr = head;
    while(curr != NULL)
    {
        if(count+1 == position)
        {
            break;
        }
        curr = curr->next;
        count++;
    }
    if(curr == NULL)
    {
        return head;
    }
    Node* temp = curr->next;
    curr->next = node;
    curr->next->next = temp;
    return head;
}

//itr solution is also available but better solution is iterative one only
int SearchItr(Node* head, int x)
{
    int count = 1;
    while(head != NULL)
    {
        if(head->value == x)
        {
            return count;
        }
        head = head->next;
        count++;
    }
    return -1;
}

// int SearchItr(Node* head, int x)
// {
//     if(head->value == x)
//     {
//         return 
//     }
//     SearchItr(head->next,x);
// }

int main(){
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head = insertBegin(head,5);
    head = insertBegin(head,19);
    head = insertEnd(head,99);
    Node *head2 = NULL;
    head2 = insertEnd(head2,189);
    head = deleteStart(head);
    head = deleteTail(head);
    head = deleteTail(head);
    head = insertEnd(head,45);
    head = insertEnd(head,50);
    head = insertEnd(head,55);
    head = insertAtPosition(head,2,20);
    traverse(head);
    std::cout << "Searched Itr " << SearchItr(head,100) << std::endl;
}
