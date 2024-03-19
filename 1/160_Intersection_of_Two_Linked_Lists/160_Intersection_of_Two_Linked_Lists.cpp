#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//  * Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int len(ListNode* head)
    {   
        int len=0;
        ListNode *current = head;
        while (current != nullptr)
        {
            current=current->next;
            ++len;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {   
        ListNode *A = headA;
        ListNode *B = headB;
        int lenA = len(A);
        int lenB = len(B);
        if (lenA>lenB)
        {
            int diff = (lenA-lenB);
            while (diff != 0)
            {
                --diff;
                A=A->next;
            }
        }
        else if (lenA<lenB)
        {
            int diff = (lenB-lenA);
            while (diff != 0)
            {
                --diff;
                B=B->next;
            }
        }
        while (A!=B)
        {
            A=A->next;
            B=B->next;
        }
        return A;
    }
};