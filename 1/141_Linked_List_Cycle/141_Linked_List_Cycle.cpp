#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        while (true)
        {
            if (head == nullptr)
            {
                return false;
            }
            auto res = visited.insert(head);
            if (!res.second)
            {
                return true;
            }
            head = head->next;
        }
    }
};
// Второй способ
class Solution_1
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}