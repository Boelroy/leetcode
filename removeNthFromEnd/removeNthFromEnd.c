#include "stdio.h"
#include "stdlib.h"

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  int iter = 0;
  struct ListNode* node1 = head, *node2 = head;
  struct ListNode* prev = node2;
  while(node1 != NULL) {
    node1 = node1->next;
    if (iter < n) iter++;
    else {
      prev = node2;
      node2 = node2->next;
    }
  }
  if (head == node2) return head->next;
  else {
    prev->next = node2->next;
  }
  return head;
}

int main(void)
{

  return 0;
}
