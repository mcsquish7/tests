#include <iostream>
#include <cmath>
#include <algorithm>

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

    }
};
// второй способ (наглядный, наверное)
class Solution_1 {
public:
    int ListLen(ListNode* head)
    {   
        int Len=1;
        ListNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
            ++Len;
        }
        return Len;
    }
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr)
            return head;
        ListNode* A = head;
        int lenA = ListLen(A);
        if (lenA == 1)
        {
            return head;
        }
        ListNode* ANS = new ListNode();
        ListNode* temp = nullptr;
        ListNode* temp_1 = ANS;
        int count = 0;
        while (lenA != 1)
        {   
            if (count == lenA-1)
            {
                temp_1->val = A->val;
                temp_1->next = temp;
                temp_1 = temp_1->next;
                lenA--;
                count = 0;
                temp = nullptr;
                A = nullptr;
                A = head;
                continue;
            }
            // ListNode* temp = new ListNode(A->val);
            temp = A;
            A=A->next;
            count++;
        }
        temp_1->next = head;
        temp_1->next->next = nullptr;
        return ANS;
    }
};

int main()
{   
    ListNode n4(4);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    Solution_1 sol;
    sol.reverseList(&n1);
    return 0;
}