#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  LinkedList* list = linked_list();
  int some_number = 4;

  Node test_node = {NULL, NULL, &some_number};

  // Note: Data is a void pointer, so first cast it to the appropriate data
  // type pointer Then we can dereference the data pointer
  printf("Test.data: %d\n", *((int*)test_node.data));

  printf("Head: %p. Tail: %p\n", list->head, list->tail);
  list->head = &test_node;
  printf("Head: %p. Tail: %p\n", list->head, list->tail);
  free(list);

  return 0;
}

LinkedList* linked_list() {
  LinkedList* new_list = malloc(sizeof(LinkedList));
  new_list->head = NULL;
  new_list->tail = NULL;
  return new_list;

}

LinkedList* addLast(LinkedList* list, void* data) {}

LinkedList* addFirst(LinkedList* list, void* data) {}

void* get(LinkedList* list, int index) {}

int indexOf(LinkedList* list, void* data) {}

void insertAfter(LinkedList* list, int index, void* data) {}

void insertBefore(LinkedList* list, int index, void* data) {}

Node* first(LinkedList* list) { return list->head; }

Node* last(LinkedList* list) { return list->tail; }

Node* getNode(LinkedList* list, void* data) {}

void removeNodeWithData(LinkedList* list, void* data) {}
void removeAtIndex(LinkedList* list, int index) {}

void removeFirst(LinkedList* list) {}
void removeLast(LinkedList* list) {}

void addNodeFirst(LinkedList* list, Node* newNode) {}

void addNodeLast(LinkedList* list, Node* newNode) {}

void insertAfterNode(LinkedList* list, Node* newNode, Node* existingNode) {}

void insertBeforeNode(LinkedList* list, Node* newNode, Node* existingNode) {}

void removeNode(LinkedList* list, Node* existingNode) {}

Node* nodeAt(LinkedList* list, int index) {}

void swapNodes(LinkedList* list, Node* first_node, Node* second_node) {}

void clear(LinkedList* list) {}

int size(LinkedList* list) {}

void dump_list(LinkedList* list) {}
