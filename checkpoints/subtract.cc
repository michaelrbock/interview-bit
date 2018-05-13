// https://www.interviewbit.com/problems/subtract/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode *A) {
    // Save a ptr to the first node to return.
    ListNode *result = A;
    
    // Fast/slow traverse list to get to middle.
    ListNode *slow = A;
    ListNode *fast = A;
    while (fast) {
        if (!fast->next) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Correct for odd/even length of list.
    ListNode *middle = nullptr;
    if (fast) {
        // The list is length odd.
        middle = slow;
        // So move slow over one past mid.
        slow = slow->next;
    }
    
    // Reverse the second half of the list.
    // new_curr is the head of the split list.
    ListNode *new_curr = nullptr;
    ListNode *curr = slow;
    while (curr) {
        ListNode *temp = curr->next;
        curr->next = new_curr;
        new_curr = curr;
        curr = temp;
    }
    
    // Subtract while traversing both lists.
    ListNode *first = A;
    ListNode *second = new_curr;
    while (second) {
        first->val = second->val - first->val;
        if (second->next) {
            first = first->next;
        }
        second = second->next;
    }
    
    // Re-reverse second half of list.
    curr = new_curr;
    // new_curr is head of the split list.
    new_curr = nullptr;
    while (curr) {
        ListNode *temp = curr->next;
        curr->next = new_curr;
        new_curr = curr;
        curr = temp;
    }
    
    // Merge lists.
    if (middle) {
        first->next = middle;
        middle->next = new_curr;
    } else {
        first->next = new_curr;
    }
    
    return result;
}
