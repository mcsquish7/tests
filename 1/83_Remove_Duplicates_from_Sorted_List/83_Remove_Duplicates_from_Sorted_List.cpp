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
    ListNode* deleteDuplicates(ListNode* head) 
    {   
        if (head == nullptr)
        {
            return head;
        }
        
        ListNode* current = head;
        while (current->next != nullptr)
        {   
            int temp_1 = current->val;
            int temp_2 = (current->next)->val;
            if (temp_1 == temp_2)
            {   
                ListNode *Del = new ListNode;
                Del = current->next;
                ListNode *temp = current->next->next;
                current->next = temp;
                delete Del;
            }
            else
            {
                current = current->next;
            }
            
        }
        return head;
    }
};

class Solution_1 {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {   
        if (head == nullptr)
        {
            return head;
        }
        
        ListNode* current = head;
        while (current->next != nullptr)
        {   
            int temp_1 = current->val;
            int temp_2 = (current->next)->val;
            if (temp_1 == temp_2)
            {   
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
            
        }
        return head;
    }
};

int main()
{   
    ListNode n4(4);
    ListNode n3(3, &n4);
    ListNode n2(1, &n3);
    ListNode n1(1, &n2);
    Solution sol;
    sol.deleteDuplicates(&n1);
    return 0;
}