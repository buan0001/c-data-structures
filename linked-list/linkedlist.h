#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
  struct Node* prev;
  struct Node* next;
  void* data;
} Node;

typedef struct LinkedList {
  Node* head;
  Node* tail;
} LinkedList;

LinkedList* linked_list();
void addLast(LinkedList* list, void* data);
void addFirst(LinkedList* list, void* data);
void* get(LinkedList* list, int index);

int indexOf(LinkedList* list, void* data);

void insertAfter(LinkedList* list, int index, void* data);

void insertBefore(LinkedList* list, int index, void* data);

Node* first(LinkedList* list);

Node* last(LinkedList* list);

Node* getNode(LinkedList* list, void* data);

void removeNodeWithData(LinkedList* list, void* data);
void removeAtIndex(LinkedList* list, int index);

void removeFirst(LinkedList* list);
void removeLast(LinkedList* list);

void addNodeFirst(LinkedList* list, Node* newNode);

void addNodeLast(LinkedList* list, Node* newNode);

void insertAfterNode(LinkedList* list, Node* newNode, Node* existingNode);

void insertBeforeNode(LinkedList* list, Node* newNode, Node* existingNode);

void removeNode(LinkedList* list, Node* existingNode);

Node* nodeAt(LinkedList* list, int index);

void swapNodes(LinkedList* list, Node* first_node, Node* second_node);

void clear(LinkedList* list);

int size(LinkedList* list);

void dump_list(LinkedList* list);

// Tests

void run_tests();

int assert(int actual, int expected, int test_num);
int convert_void_ptr_to_int(void* annoying_ptr);

#endif