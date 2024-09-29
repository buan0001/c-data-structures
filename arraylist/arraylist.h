#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct
{
    int *data;
    int capacity;
    int size;
} Arraylist;

Arraylist *arraylist();
Arraylist *alst_add(Arraylist *list, int new_num);
int alst_get(Arraylist* list, int index);
int alst_size(Arraylist* list);
Arraylist* alst_remove(Arraylist* list);
Arraylist* alst_removeIndex(Arraylist* list, int index);
Arraylist* alst_insertIndex(Arraylist* list, int index, int new_num);
Arraylist* alst_set(Arraylist* list, int index, int new_val);
Arraylist* alst_clear(Arraylist* list);

// Helpers
Arraylist* grow_if_necessary(Arraylist* list);
Arraylist* shrink_if_necessary(Arraylist* list);
int is_valid_index(Arraylist* list, int index);

#endif