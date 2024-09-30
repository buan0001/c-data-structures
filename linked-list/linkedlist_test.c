#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  run_tests();

  printf("Sucessfully exited");
  return 0;
}

void run_tests() {
  // Used in all testes
  LinkedList* list = linked_list();
  int wrongs_corrects[] = {0, 0};
  int test_num = 0;

  // AddLast
  int first_num = 4;
  addLast(list, &first_num);

  wrongs_corrects[assert(convert_void_ptr_to_int(list->tail->data) == first_num,
                         1, test_num++)]++;

  // AddFirst
  int second_num = 12;
  addFirst(list, &second_num);
  wrongs_corrects[assert(
      convert_void_ptr_to_int(list->head->data) == second_num, 1,
      test_num++)]++;
  //   wrongs_corrects[convert_void_ptr_to_int(list->head->data) ==
  //   first_num]++;

  // Get
  wrongs_corrects[assert(get(list, 0) == list->head->data, 1, test_num++)]++;
  printf("%p == %p\n", get(list, -1), NULL);
  //   printf("%p == %p\n", get(list, 1), list->tail->data);
  printf("Test num: %d\n", test_num);
  wrongs_corrects[assert(get(list, 1) == list->tail->data, 1, test_num++)]++;
  wrongs_corrects[assert(get(list, -1) == NULL, 1, test_num++)]++;
  wrongs_corrects[assert(get(list, 10) == NULL, 1, test_num++)]++;

  // IndexOf
  int random_number = 99;
  wrongs_corrects[assert(indexOf(list, &first_num) == 1, 1, test_num++)]++;
  wrongs_corrects[assert(indexOf(list, &second_num) == 0, 1, test_num++)]++;
  wrongs_corrects[assert(indexOf(list, &random_number) == -1, 1, test_num++)]++;

  // InsertAfter
  int insert_after_num = 104;
  insertAfter(list, 1, &insert_after_num);
  printf("index of new val: %d\n", indexOf(list, &insert_after_num));
  wrongs_corrects[assert(indexOf(list, &insert_after_num), 2, test_num++)]++;

  dump_list(list);

  printf("\n===========\n\n");
  printf("Corrects: %d\n", wrongs_corrects[1]);
  printf("Wrongs: %d\n", wrongs_corrects[0]);
  // Free all the nodes first
  clear(list);
  // Then free the list;
  free(list);
}

// int run_single_node_test(LinkedList* list, Node* test_node,
// void(*func)(LinkedList*, Node*))
// {

// }

int convert_void_ptr_to_int(void* annoying_ptr) {
  return *((int*)annoying_ptr);
}

int assert(int actual, int expected, int test_num) {
  if (actual == expected)
    return 1;
  else {
    printf("Test failed for test_num %d. Actual: %d. Expected: %d\n", test_num,
           actual, expected);
    return 0;
  }
}