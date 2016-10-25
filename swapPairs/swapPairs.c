/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    int p = 0;
    struct ListNode *pre = NULL, *pre_pre = NULL,*iter = head;
    while(iter != NULL) {
        if (p == 1) {
            p = 0;
            if (pre_pre != NULL){
                pre_pre->next = iter;
            } else {
                head = iter;
            }
            pre->next = iter->next;
            iter->next = pre;
            iter = pre;
        } else {
            p++;
            pre_pre = pre,
            pre = iter;
        }
        iter = iter->next;
    }
    return head;
}
