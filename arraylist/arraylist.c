#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main()
{

    Arraylist *test = arraylist();
    printf("Arraylist adress %p. Capacity: %d. Size: %d\n", &test, (*test).capacity, (*test).size);

    for (int i = 0; i < 11; i++)
    {
        alst_add(test, i);
        printf("Arraylist adress %p. Capacity: %d. Size: %d\n", &test, (*test).capacity, (*test).size);
        for (int i = 0; i < (*test).size; i++)
        {
            printf("%d: %d \t", i, (*test).data[i]);
        }
        printf("\n");
    }

    free(test);
    return 0;
}

Arraylist *arraylist()
{
    int *pointer_to_numbers = malloc(sizeof(int) * 10);

    Arraylist *test = malloc(sizeof(Arraylist));
    (*test).capacity = 10;
    (*test).size = 0;
    (*test).data = pointer_to_numbers;
    return test;
}

Arraylist* grow_if_necessary(Arraylist *list)
{
    if (list->capacity == list->size)
    {
        printf("Data list too small - adding more space\n");
        int *new_data_list = malloc(sizeof(int) * list->capacity * 2);
        if (new_data_list == NULL)
        {
            printf("No memory available");
            exit(1);
        }
        for (size_t i = 0; i < list->size; i++)
        {
            new_data_list[i] = list->data[i];
        }

        free(list->data);
        list->data = new_data_list;
        list->capacity *= 2;
    }
    return list;
}

Arraylist *shrink_if_necessary(Arraylist *list)
{
    if (list->capacity > (list->size * 2) && list->capacity > 10)
    {
        printf("Data needlessly large - removing spaces\n");
        int *new_data_list = malloc(sizeof(int) * list->capacity / 2);
        if (new_data_list == NULL)
        {
            printf("No memory available");
            exit(1);
        }
        for (size_t i = 0; i < list->size; i++)
        {
            new_data_list[i] = list->data[i];
        }

        free(list->data);
        list->data = new_data_list;
        list->capacity /= 2;
    }
    return list;
}

Arraylist *alst_add(Arraylist *list, int new_num)
{
    grow_if_necessary(list);
    printf("Size: %d\n", list->size);
    // Access the data point at the current size of the list and set it's value to the new value
    (*list).data[(*list).size++] = new_num;
    printf("Size: %d\n", list->size);
}

int alst_get(Arraylist *list, int index)
{
    if (index > 0 && index < list->size){
        return list->data[index];
    }
    return NULL;
}
// alst_size(){}
// alst_remove(){}
// alst_removeIndex(index){}
// alst_insertIndex(index, objekt){}
// alst_set(index, obj){}
// alst_clear(){}