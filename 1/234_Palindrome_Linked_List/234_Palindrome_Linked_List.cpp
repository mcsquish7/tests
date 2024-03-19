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
    bool isPalindrome(ListNode* head) 
    {   
        string s = "";
        ListNode* curr = head;
        while (curr != nullptr)
        {
            s += to_string(curr->val);
            curr = curr->next;
        }
        const int SIZE = s.size();
        for (int i = 0; i < SIZE/2; i++)
        {
            if (s[i] != s[(SIZE-1)-i])
            {
                return false;
            }
            
        }
        return true;   
    }
};

int main()
{   
    ListNode n4(1);
    ListNode n3(2, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    Solution sol;
    cout << sol.isPalindrome(&n1);
    return 0;
}