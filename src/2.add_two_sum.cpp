//
// Created by andrew on 2021/3/7.
//

#include <iostream>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        if(carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }

};


int main(int argc, char *argv[]) {
    ListNode * l1 = nullptr;
    ListNode * l2 = nullptr;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);


    ListNode * head = nullptr;
    head = Solution::addTwoNumbers(l1, l2);
    while (nullptr != head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}

