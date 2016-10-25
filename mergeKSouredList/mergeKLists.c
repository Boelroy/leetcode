#include "stdlib.h"
#include "stdio.h"

struct ListNode {
  struct ListNode *next;
  int val;
};

void heapKeep(struct ListNode **heap, int rootIndex, int listsSize);

void heapCreate(struct ListNode** heap, int listsSize);

struct ListNode* mergeKList(struct ListNode** lists, int listsSize) {
  if (listsSize == 0) return NULL;

  struct ListNode *heap[listsSize], *result = NULL, *iter = NULL;
  int i = 0, j = 0;
  // init a heap
  for (; i < listsSize; i++) {
    if (lists[i] == NULL) continue;
    heap[j] = lists[i];
    lists[i] = lists[i]->next;
    j++;
  }

  listsSize = j;
  heapCreate(heap, listsSize);
  result = iter = heap[0];

  while (listsSize > 0) {
    if (heap[0]->next != NULL) {
      heap[0] = heap[0]->next;
    } else {
      listsSize--;
      heap[0] = heap[listsSize];
    }
    heapKeep(heap, 0, listsSize);
    iter->next = heap[0];
    iter = iter->next;
  }

  if (iter!= NULL) iter->next = NULL;
  return j ? result : NULL;
}

void heapCreate(struct ListNode** heap, int listsSize) {
  for ( int i = listsSize / 2 - 1; i >= 0; i--) {
    heapKeep(heap, i, listsSize);
  }
}

void heapKeep(struct ListNode **heap, int rootIndex, int listsSize) {
  int nextChildIndex;
  ListNode *tmp;
  for (; 2 * rootIndex + 1 < listsSize; rootIndex = nextChildIndex) {
    nextChildIndex = 2 * rootIndex + 1;
    if (heap[nextChildIndex] == NULL) return;
    if (nextChildIndex < listsSize - 1 && heap[nextChildIndex + 1]->val > heap[nextChildIndex]->val) nextChildIndex++;
    if (heap[rootIndex]->val < heap[nextChildIndex]->val) {
      tmp = heap[nextChildIndex];
      heap[nextChildIndex] = heap[rootIndex];
      heap[rootIndex] = tmp;
    }
  }
}
