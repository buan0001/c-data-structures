#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main()
{

    Arraylist* test = arraylist();
    printf("Arraylist adress %p. Capacity: %d. Size: %d\n", &test, (*test).capacity, (*test).size);

    printf("\n===============\n\n");
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

    printf("\n===============\n\n");
    for (int i = 0; i < 5; i++)
    {
        alst_remove(test);
        printf("Arraylist adress %p. Capacity: %d. Size: %d\n", &test, (*test).capacity, (*test).size);
        for (int i = 0; i < (*test).size; i++)
        {
            printf("%d: %d \t", i, (*test).data[i]);
        }
        printf("\n");
    }

    printf("\n===============\n\n");

    printf("Value at index 0: %d\n", alst_get(test, 0));
    printf("Value at index 4: %d\n", alst_get(test, 4));
    printf("Value at index -1: %d\n", alst_get(test, -1));
    printf("Value at index 30: %d\n", alst_get(test, 30));

    printf("\n===============\n\n");
    printf("Entries before removing index 2\n");
    printf("Capacity: %d. Size: %d\n", (*test).capacity, (*test).size);
    for (int i = 0; i < (*test).size; i++)
    {
        printf("%d: %d \t", i, (*test).data[i]);
    }
    printf("\n");
    alst_removeIndex(test, 2);

    printf("Entries after removing index 2\n");
    printf("Capacity: %d. Size: %d\n", (*test).capacity, (*test).size);
    for (int i = 0; i < (*test).size; i++)
    {
        printf("%d: %d \t", i, (*test).data[i]);
    }
    printf("\n");

    printf("\n===============\n\n");
    printf("Entries before adding 2 at index 2\n");
    printf("Capacity: %d. Size: %d\n", (*test).capacity, (*test).size);
    for (int i = 0; i < (*test).size; i++)
    {
        printf("%d: %d \t", i, (*test).data[i]);
    }
    printf("\n");
    alst_insertIndex(test, 2, 2);

    printf("Entries after adding 2 at index 2\n");
    printf("Capacity: %d. Size: %d\n", (*test).capacity, (*test).size);
    for (int i = 0; i < (*test).size; i++)
    {
        printf("%d: %d \t", i, (*test).data[i]);
    }
    printf("\n");
    printf("\n===============\n\n");
    printf("Setting the value at index 2 to 6\n");
    printf("Value at index 2 BEFORE: %d\n", test->data[2]);
    alst_set(test, 2, 6);
    printf("Value at index 2 AFTER: %d\n", test->data[2]);

    printf("\n===============\n\n");

    printf("Clearing the array list\n");

    alst_clear(test);

    printf("list after clearing:\n");
    printf("Capacity: %d. Size: %d\n", (*test).capacity, (*test).size);
    for (int i = 0; i < (*test).size; i++)
    {
        printf("%d: %d \t", i, (*test).data[i]);
    }

    // Free the data pointer inside the Arraylist
    free(test->data);
    // Free the Arraylist itself
    free(test);

    return 0;
}

Arraylist* arraylist()
{
    int* pointer_to_numbers = malloc(sizeof(int) * 10);

    Arraylist* new_array_list = malloc(sizeof(Arraylist));
    (*new_array_list).capacity = 10;
    (*new_array_list).size = 0;
    (*new_array_list).data = pointer_to_numbers;
    return new_array_list;
}



Arraylist* alst_add(Arraylist* list, int new_num)
{
    grow_if_necessary(list);
    printf("Size: %d\n", list->size);
    // Access the data point at the current size of the list and set it's value to the new value
    (*list).data[(*list).size++] = new_num;
    printf("Size: %d\n", list->size);
}

int alst_get(Arraylist* list, int index)
{
    if (is_valid_index(list, index)) {
        return list->data[index];
    }
    return -1;
}


int alst_size(Arraylist* list)
{
    return list->size;
}

// Removes the last element
Arraylist* alst_remove(Arraylist* list)
{
    shrink_if_necessary(list);
    printf("Removing last entry\n");
    // Access the data point at the current size of the list and set it's value to the new value
    (*list).data[(*list).size--] = 0;
    printf("Size after removing: %d\n", list->size);
}

// Removes the element at the specified index
Arraylist* alst_removeIndex(Arraylist* list, int index)
{
    if (is_valid_index(list, index)) {
        shrink_if_necessary(list);
        // -1 because we dont want the last element to copy something outside of the array
        for (int i = index; i < list->size - 1; i++)
        {
            list->data[i] = list->data[i + 1];
        }

        list->size--;
    }
    return list;
}

// Insert an element at the specified index
Arraylist* alst_insertIndex(Arraylist* list, int index, int new_num)
{
    if (is_valid_index(list, index)) {
        grow_if_necessary(list);
        // -1 because we dont want the last element to copy something outside of the array
        int temp = list->data[index];
        for (int i = list->size; i > index; i--)
        {
            list->data[i] = list->data[i - 1];
        }
        list->data[index] = new_num;

        list->size++;

    }
    return list;
}

// Overrides the value at the given index by the new value
Arraylist* alst_set(Arraylist* list, int index, int new_val)
{
    if (is_valid_index(list, index)) {
        // Boring syntax:
        // list->data[index] = new_val;

        // Ninja syntax:
        int* q = &new_val;
        *((*list).data + index) = *q;
    }

    return list;
}

// Clears the arraylist
Arraylist* alst_clear(Arraylist* list)
{
    // Do we actually care about resetting the values? Surely this suffices
    list->size = 0;
    return list;
}

// Helpers <3
Arraylist* grow_if_necessary(Arraylist* list)
{
    if (list->capacity == list->size)
    {
        printf("Data list too small - adding more space\n");
        int* new_data_list = malloc(sizeof(int) * list->capacity * 2);
        if (new_data_list == NULL)
        {
            printf("No memory available");
            exit(1);
        }
        for (size_t i = 0; i < list->size; i++)
        {
            new_data_list[i] = list->data[i];
        }

        // Free the old list, use the new one and double the capacity to reflect the change
        free(list->data);
        list->data = new_data_list;
        list->capacity *= 2;
    }
    return list;
}

Arraylist* shrink_if_necessary(Arraylist* list)
{
    // Proceed if more than half the spots are unused and the capacity is above the minimum length
    if (list->capacity > (list->size * 2) && list->capacity > 10)
    {
        printf("Data needlessly large - removing spaces\n");
        int* new_data_list = malloc(sizeof(int) * list->capacity / 2);
        if (new_data_list == NULL)
        {
            printf("No memory available");
            exit(1);
        }
        for (size_t i = 0; i < list->size; i++)
        {
            new_data_list[i] = list->data[i];
        }

        // Free the old list, use the new one and half the capacity to reflect the change
        free(list->data);
        list->data = new_data_list;
        list->capacity /= 2;
    }
    return list;
}

int is_valid_index(Arraylist* list, int index)
{
    if (index >= 0 && index < list->size) {
        return 1;
    }
    printf("Invalid index\n");
    return 0;
}