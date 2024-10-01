# This is an implementation of the linked list data structure in C. 

**Important note:** To run the program you need a C-compiler! The bash script relies on the gcc compiler being installed

## Running the program
1. Download the project files to a specified folder
2. Open a bash terminal if you want to use the bash script, alternatively use any other shell
3. Navigate to the folder containing the project files
4. Either use the simple provided bash script:
    * Enter `./br.sh` to run the bash script
    * If all goes well, the program should compile and run, maybe
5. Or manually build and combine the files by pasting the following commands:
    1. `gcc -c *.c`
    2. `gcc -o runnable *.o`
    3. `./runnable`

## Using the linked list:

Two structs are used throughout. The list itself:

`typedef struct LinkedList {
  Node* head;
  Node* tail;
} LinkedList;
`

And the Nodes it contains:

`typedef struct Node {
  struct Node* prev;
  struct Node* next;
  void* data;
} Node;`

### The functions

- **LinkedList\* linked_list()**
    - "Constructor method". Returns a pointer to an empty linked list.
- **void addLast(LinkedList\* list, void\* data)**
    - Creates a node with the given data and adds it to the end of the list
- **void addFirst(LinkedList\* list, void\* data)**
    - Creates a node with the given data and adds it to the front of the list
- **void\* get(LinkedList\* list, int index)**
    - Returns the data of the node at the given index
- **int indexOf(LinkedList\* list, void\* data)**
    - Returns the index of the node with the given data
- **void insertAfter(LinkedList\* list, int index, void\* data)**
    - Inserts a node with the given data after the provided index
- **void insertBefore(LinkedList\* list, int index, void\* data)**
    - Inserts a node with the given data before the provided index
- **Node\* first(LinkedList\* list)**
    - Returns the first element in the list
- **Node\* last(LinkedList\* list)**
    - Returns the last element in the list
- **Node\* getNode(LinkedList\* list, void\* data)**
    - Returns a node with data matching the provided data
- **void removeNodeWithData(LinkedList\* list, void\* data)**
    - Removes a node from the list with data matching the provided data
- **void removeAtIndex(LinkedList\* list, int index)**
    - Removes the node from the list at the given index
- **void removeFirst(LinkedList\* list)**
    - Removes the first node from the list
- **void removeLast(LinkedList\* list)**
    - Removes the last node from the list
- **void addNodeFirst(LinkedList\* list, Node\* newNode)**
    - Adds the provided node to the front of the list
- **void addNodeLast(LinkedList\* list, Node\* newNode)**
    - Adds the provided node to the end of the list
- **void insertAfterNode(LinkedList\* list, Node\* newNode, Node\* existingNode)**
    - Adds the provided node after the provided node
- **void insertBeforeNode(LinkedList\* list, Node\* newNode, Node\* existingNode)**
    - Adds the provided node before the provided node
- **void removeNode(LinkedList\* list, Node\* existingNode)**
    - Removes the provided node from the list
- **Node\* nodeAt(LinkedList\* list, int index)**
    - Returns the node at the given index
- **void swapNodes(LinkedList\* list, Node\* first, Node\* second)**
    - Swaps the data of the two provided nodes
- **void clear(LinkedList\* list)**
    - Frees every node in the list and sets both head and tail to NULL
- **int size(LinkedList\* list)**
    - Returns the amount of nodes in the list