/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
  if(head == NULL) return NULL;
  int count = 0;
  struct ListNode *start = head, *end = head, *tmp, *last = NULL;

  while(end != NULL) {
    if (count < k - 1) {
      count++;
      end = end->next;
    } else {
      tmp = end->next;
      reverseList(start, end);

      if (last == NULL){
        head = end;
      } else {
        last->next = end;
      }

      last = start;
      start = tmp;
      end = tmp;
      count = 0;
    }
  }
  if ((count < k - 1 || end == NULL) && last == NULL) {
    return head;
  } else {
    last->next = start;
  }

  return head;
}

void reverseList(struct ListNode* head, struct ListNode* tail) {

  struct ListNode *prev = NULL, *iter = head, *tmp;
  while(iter != tail) {
    tmp = iter;
    iter = iter->next;
    tmp->next = prev;
    prev = tmp;
  }
  iter->next = prev;
  return tail;
}