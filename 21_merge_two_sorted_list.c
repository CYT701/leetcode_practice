#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *pos1 = list1;
  struct ListNode *pos2 = list2;
  if (pos1 == NULL && pos2 == NULL)
    return list2;
  else if (pos1 == NULL && pos2 != NULL)
    return list2;
  else if (pos1 != NULL && pos2 == NULL)
    return list1;
  if (pos1->val >= pos2->val) {
    while (pos1 != NULL && pos2 != NULL) {
      if (pos2->next != NULL) {
        if (pos1->val <= pos2->next->val) {
          struct ListNode *temp = pos1;
          pos1 = pos1->next;
          temp->next = pos2->next;
          pos2->next = temp;
          pos2 = pos2->next;
        } else // pos1->val >= pos2->next->val
        {
          pos2 = pos2->next;
        }
      } else // pos2->next == NULL
      {
        struct ListNode *temp = pos1;
        pos1 = pos1->next;
        pos2->next = temp;
        temp->next = NULL;
        pos2 = pos2->next;
      }
    }
    return list2;
  } else // pos1->val<pos2->val
  {
    while (pos1 != NULL && pos2 != NULL) {
      if (pos1->next != NULL) {
        if (pos2->val <= pos1->next->val) {
          struct ListNode *temp = pos2;
          pos2 = pos2->next;
          temp->next = pos1->next;
          pos1->next = temp;
          pos1 = pos1->next;
        } else // pos2->val >= pos1->next->val
        {
          pos1 = pos1->next;
        }
      } else // pos1->next == NULL
      {
        struct ListNode *temp = pos2;
        pos2 = pos2->next;
        pos1->next = temp;
        temp->next = NULL;
        pos1 = pos1->next;
      }
    }
    return list1;
  }
}

int main() {
  struct ListNode *list1 = malloc(sizeof(struct ListNode));
  struct ListNode *pos1 = list1;
  struct ListNode *list2 = malloc(sizeof(struct ListNode));
  struct ListNode *pos2 = list2;
  int arr1[3] = {1, 2, 4};
  int arr2[3] = {1, 3, 4};
  for (int i = 0; i < 3; i++) {
    if (pos1 == NULL) {
      pos1->val = arr1[i];
      pos1->next = NULL;
    } else {
      struct ListNode *temp = malloc(sizeof(struct ListNode));
      temp->val = arr1[i];
      temp->next = NULL;
      pos1->next = temp;
      pos1 = pos1->next;
      // free(temp);
    }
  }
  for (int i = 0; i < 3; i++) {
    if (pos2 == NULL) {
      pos2->val = arr2[i];
      pos2->next = NULL;
    } else {
      struct ListNode *temp = malloc(sizeof(struct ListNode));
      temp->val = arr2[i];
      temp->next = NULL;
      pos2->next = temp;
      pos2 = pos2->next;
      // free(temp);
    }
  }
  struct ListNode *output = mergeTwoLists(list1, list2);
  while (output != NULL) {
    printf("%d", output->val);
    output = output->next;
  }
  printf("\n");
  return 0;
}
