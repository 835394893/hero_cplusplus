#include <iostream>
#include <stdexcept>
using namespace std;
#define eleType int

struct ListNode{
    eleType data;
    ListNode* next;
    ListNode(eleType x):data(x),next(NULL){}
};

class LinkedList{
private:
    ListNode* head;
    int size;
public:
    LinkedList():head(NULL),size(0){}
    ~LinkedList();
    void insert(int i,eleType value);
    void remove(int i);
    ListNode* find(eleType value);
    ListNode* get(int i);
    void update(int i,eleType value);
    void print();
};

LinkedList::~LinkedList(){
    ListNode* curr = head;
    while(curr != NULL)
    {
        ListNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

void LinkedList::insert(int i,eleType value)
{
    if(i < 0 || i > size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode* newNode = new ListNode(value);
    if(i == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else{
        ListNode* curr = head;
        for(int j = 0;j < i - 1;j++)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    ++size;
}

void LinkedList::remove(int i)
{
    if(i < 0 || i >= size)
    {
        throw std::out_of_range("Invalid position");
    }
    if(i == 0)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else{
        ListNode* curr = head;
        for(int j = 0;j < i - 1;j++)
        {
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
}