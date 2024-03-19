
//   Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) 
    {

    }
    ListNode(int x) : val(x), next(nullptr) 
    {

    }
    ListNode(int x, ListNode *next) : val(x), next(next) 
    {

    }
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode res(0); // Dummy node to ease the insertion
        ListNode* cur = &res;
        while(true)
        {
            if(list1 == nullptr && list2 == nullptr)
            {
                return res.next;
            }
            else if (list1 == nullptr)
            {
                cur->next = list2;
                return res.next;
            }
            else if (list2 == nullptr)
            {
                cur->next = list1;
                return res.next;
            }
            else
            {
                if (list1->val < list2->val)
                {
                    cur->next = list1;
                    cur = list1;
                    list1 = list1->next;
                }
                else
                {
                    cur->next = list2;
                    cur = list2;
                    list2 = list2->next;
                }
                
            }
            
        }
        return res.next;
    }
};