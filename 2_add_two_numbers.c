#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  int length1 = 0;
  int length2 = 0;
  struct ListNode *count1 = l1;
  while (count1 != NULL) {
    length1++;
    count1 = count1->next;
  }
  struct ListNode *count2 = l2;
  while (count2 != NULL) {
    length2++;
    count2 = count2->next;
  }
  struct ListNode *pos1 = l1;
  struct ListNode *pos2 = l2;
  if (length1 > length2) {
    while (pos1->next != NULL) {
      if (pos2 != NULL) {
        pos1->val = pos1->val + pos2->val;
        if (pos1->val >= 10) {
          pos1->val = pos1->val - 10;
          pos1->next->val += 1;
        }
        pos1 = pos1->next;
        pos2 = pos2->next;
      } else {
        if (pos1->val >= 10) {
          pos1->val = pos1->val - 10;
          pos1->next->val += 1;
        }
        pos1 = pos1->next;
      }
    }
    if (pos1->val >= 10) {
      pos1->val = pos1->val - 10;
      struct ListNode *temp = malloc(sizeof(struct ListNode));
      temp->val = 1;
      temp->next = NULL;
      pos1->next = temp;
    }
    return l1;
  } else if (length1 < length2) {
    while (pos2->next != NULL) {
      if (pos1 != NULL) {
        pos2->val = pos2->val + pos1->val;
        if (pos2->val >= 10) {
          pos2->val = pos2->val - 10;
          pos2->next->val += 1;
        }
        pos2 = pos2->next;
        pos1 = pos1->next;
      } else {
        if (pos2->val >= 10) {
          pos2->val = pos2->val - 10;
          pos2->next->val += 1;
        }
        pos2 = pos2->next;
      }
    }
    if (pos2->val >= 10) {
      pos2->val = pos2->val - 10;
      struct ListNode *temp = malloc(sizeof(struct ListNode));
      temp->val = 1;
      temp->next = NULL;
      pos2->next = temp;
    }
    return l2;
  } else // length1 == length2
  {
    while (pos1->next != NULL) {
      pos1->val = pos1->val + pos2->val;
      if (pos1->val >= 10) {
        pos1->val = pos1->val - 10;
        pos1->next->val += 1;
      }
      pos1 = pos1->next;
      pos2 = pos2->next;
    }
    pos1->val = pos1->val + pos2->val;
    if (pos1->val >= 10) {
      pos1->val = pos1->val - 10;
      struct ListNode *temp = malloc(sizeof(struct ListNode));
      temp->val = 1;
      temp->next = NULL;
      pos1->next = temp;
    }
    return l1;
  }
}

int main() { return 0; }
