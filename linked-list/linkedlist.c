#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  LinkedList* list = linked_list();
  int some_number = 4;

  Node* test_node = malloc(sizeof(Node));
  test_node->data = &some_number;

  printf("Size of node (Node*, Node*, void*): %d\n", sizeof(Node));
  printf("\n===========\n\n");

  // Note: Data is a void pointer, so first cast it to the appropriate data
  // type pointer Then we can dereference the data pointer
  printf("Test.data: %d\n", *((int*)test_node->data));
  printf("\n===========\n\n");

  printf("Head: %p. Tail: %p\n", list->head, list->tail);
  addNodeFirst(list, test_node);
  printf("Head: %p. Tail: %p\n", list->head, list->tail);

  printf("\n===========\n\n");
  int some_other_number = 23;

  printf("Node with data. Actual: %p. Expected: %p\n",
         getNode(list, &some_number), &test_node);
  printf("Node with data. Actual: %p. Expected: %p\n",
         getNode(list, &some_other_number), NULL);

  printf("\n===========\n\n");

  dump_list(list);
  addFirst(list, &some_other_number);
  // addLast(list, &some_other_number);
  printf("Last: %d. Expected: %d\n", *((int*)(last(list)->data)), some_number);
  

  int add_last_num = 51;
  addLast(list, &add_last_num);

  printf("Last: %d. Expected: %d\n", *((int*)(last(list)->data)), add_last_num);
  dump_list(list);
  printf("\n===========\n\n");
  
  printf("Head: %p. Tail: %p\n", list->head, list->tail);
  
  printf("\n===========\n\n");

  // Free all the nodes first
  clear(list);
  // Then free the list;
  free(list);

  printf("Sucessfully exited");
  return 0;
}

LinkedList* linked_list() {
  LinkedList* new_list = malloc(sizeof(LinkedList));
  printf("size of linked list (Node*, Node*): %d\n", sizeof(LinkedList));
  new_list->head = NULL;
  new_list->tail = NULL;
  return new_list;
}

LinkedList* addLast(LinkedList* list, void* data) {
  Node* new_node = malloc(sizeof(new_node));
  if (new_node == NULL) exit(1);
  new_node->data = data;
  addNodeLast(list, new_node);
}

LinkedList* addFirst(LinkedList* list, void* data) {
  Node* new_node = malloc(sizeof(new_node));
  if (new_node == NULL) exit(1);
  printf("Incoming data adr: %p\n", data);
  new_node->data = data;
  printf("new node data adr: %p\n", new_node->data);
  addNodeFirst(list, new_node);
}

void* get(LinkedList* list, int index) {
  Node* node_at_index = nodeAt(list, index);
  if (node_at_index) {
    return node_at_index->data;
  }
  return NULL;
}

int indexOf(LinkedList* list, void* data) {
  int index = 0;
  Node* current = list->head;
  while (current) {
    if (current->data == data) {
      return index;
    }
    index++;
    current = current->next;
  }
  return -1;
}

void insertAfter(LinkedList* list, int index, void* data) {
  Node* node_at_index = nodeAt(list, index);
  if (node_at_index) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    insertAfterNode(list, new_node, node_at_index);
  }
}

void insertBefore(LinkedList* list, int index, void* data) {
  Node* node_at_index = nodeAt(list, index);
  if (node_at_index) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    insertBeforeNode(list, new_node, node_at_index);
  }
}

Node* first(LinkedList* list) { return list->head; }

Node* last(LinkedList* list) { return list->tail; }

Node* getNode(LinkedList* list, void* data) {
  Node* current_node = list->head;
  printf("current node's next: %p\n", current_node->next);
  while (current_node) {
    printf("Current adress: %p. Next: %p. Prev: %p. Data: %d\n", current_node,
           current_node->next, current_node->prev,
           *((int*)(current_node->data)));
    if (current_node->data == data) {
      return current_node;
    }
    printf("current node's next: %p\n", current_node->next);
    current_node = current_node->next;
  }
  // This will be the same as return NULL;

  return current_node;
}

void removeNodeWithData(LinkedList* list, void* data) {
  Node* found_node = getNode(list, data);
  if (found_node) {
    removeNode(list, found_node);
  }
}
void removeAtIndex(LinkedList* list, int index) {}

void removeFirst(LinkedList* list) {
  Node* previous_head = list->head;
  // If head is the same as tail, there's only one element in the list. Clear
  // both head and tail
  if (previous_head == list->tail) {
    clear(list);
  } else {
    // Forget all about the previous head
    list->head = previous_head->next;
    list->head->prev = NULL;
    free(previous_head);
  }
}
void removeLast(LinkedList* list) {
  Node* previous_tail = list->tail;
  // If tail is the same as head, there's only one element in the list. Clear
  // both tail and head
  if (previous_tail == list->head) {
    clear(list);
  } else {
    // Forget all about the previous tail
    list->tail = previous_tail->prev;
    list->tail->next = NULL;
    free(previous_tail);
  }
}

void addNodeFirst(LinkedList* list, Node* newNode) {
  Node* previous_head = list->head;
  list->head = newNode;
  if (previous_head != NULL) {
    list->head->next = previous_head;
    list->head->prev = NULL;
    previous_head->prev = list->head;
  }
  // If head was previously null, that means the list was empty so there also
  // wasn't a tail. Also set the new node as the list's tail
  else {
    list->tail = newNode;
  }
}

void addNodeLast(LinkedList* list, Node* newNode) {
  Node* previous_tail = list->tail;
  list->tail = newNode;
  if (previous_tail != NULL) {
    list->tail->prev = previous_tail;
    list->tail->next = NULL;
    previous_tail->next = list->tail;
  }
  // If tail was previously null, that means the list was empty so there also
  // wasn't a head. Also set the new node as the list's head
  else {
    list->head = newNode;
  }
}

void insertAfterNode(LinkedList* list, Node* newNode, Node* existingNode) {
  if (existingNode == list->tail) {
    addNodeLast(list, newNode);
  } else {
    newNode->prev = existingNode;
    newNode->next = existingNode->next;
    existingNode->next->prev = newNode;
    existingNode->next = newNode;
  }
}

void insertBeforeNode(LinkedList* list, Node* newNode, Node* existingNode) {
  if (existingNode == list->head) {
    addNodeFirst(list, newNode);
  } else {
    newNode->next = existingNode;
    newNode->prev = existingNode->prev;
    existingNode->prev->next = newNode;
    existingNode->prev = newNode;
  }
}

void removeNode(LinkedList* list, Node* existingNode) {
  if (existingNode == list->head) {
    removeFirst(list);
  } else if (existingNode == list->tail) {
    removeLast(list);
  }
  // The node was somewhere in the middle;
  else {
    existingNode->prev->next = existingNode->next;
    existingNode->next->prev = existingNode->prev;
    free(existingNode);
  }
}

Node* nodeAt(LinkedList* list, int index) {
  Node* current_node = list->head;
  for (int i = 0; i < index; i++) {
    // If the index isn't valid, current_node will be null
    if (!current_node) {
      return NULL;
    }
    current_node = current_node->next;
  }
  // Current node will match the index
  return current_node;
}

void swapNodes(LinkedList* list, Node* first_node, Node* second_node) {
  void* prev_data = first_node->data;
  first_node->data = second_node->data;
  second_node->data = prev_data;
}

void clear(LinkedList* list) {
  Node* current_node = list->head;
  while (current_node) {
    Node* next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  list->head = NULL;
  list->tail = NULL;
}

int size(LinkedList* list) {
  int size = 0;
  Node* current = list->head;
  while (current) {
    size++;
    current = current->next;
  }
  return size;
}

void dump_list(LinkedList* list) {
  Node* current = list->head;
  printf("\nDumping list:\n");
  while (current) {
    printf("Current adress: %p. Next: %p. Prev: %p. Data: %d\n", current,
           current->next, current->prev, *((int*)(current->data)));
    current = current->next;
  }
  printf("\n");
}
