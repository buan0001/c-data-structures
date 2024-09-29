typedef struct
{
    int *data;
    int capacity;
    int size;
} Arraylist;

Arraylist *arraylist();
Arraylist *alst_add(Arraylist *list, int new_num);
Arraylist *grow_if_necessary(Arraylist *list);
Arraylist *shrink_if_necessary(Arraylist *list);