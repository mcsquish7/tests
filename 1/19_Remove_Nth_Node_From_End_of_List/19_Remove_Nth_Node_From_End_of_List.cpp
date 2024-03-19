#include <iostream>
#include <string>
        
using namespace std;


//   Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int counter = 0;
        int size = 1;
        // Node<T> *temp = new Node<T>(data);
        ListNode *current_1 = head;
        while (current_1->next != nullptr)
        {   
            current_1 = current_1->next;
            size++;
        }
        if (size==1)
        {
            head = nullptr;
            return head;
        }
        if (n==size)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode *current = head;
        while (counter != size-n)
        {   
            if (counter == size - n - 1)
            {   
                ListNode *Del = new ListNode;
                Del = current->next;
                ListNode *temp = current->next->next;
                current->next = temp;
                delete Del;
            }
            current = current->next;
            ++counter;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    
    return 0;
}