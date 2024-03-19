#include <iostream>

using namespace std;
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* temp = res;
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum=0;
            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            temp->val += sum;
            if (temp->val < 10)
            {   
                if (l1 != nullptr || l2 != nullptr)
                    temp->next = new ListNode();
                else
                    temp->next = nullptr;
                temp = temp->next;
            }
            else
            {
                temp->val = temp->val % 10;
                temp->next = new ListNode(1);
                temp = temp->next;
            }
        }
        // temp->next = nullptr;
        return res;
    }
};

int main()
{   
    ListNode n4(8);
    ListNode n3(1, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode n44(0);
    ListNode n33(2, &n44);
    ListNode n22(3, &n33);
    ListNode n11(4, &n22);
    Solution sol;
    sol.addTwoNumbers(&n3, &n44);
    return 0;
}