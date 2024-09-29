# ====================================== PLACEHOLDER ======================================
# ====================================== PLACEHOLDER ======================================
# ====================================== PLACEHOLDER ======================================


# This is a simple implementation of the ArrayList data structure from java, implemented in C. 

**The list can currently only handle integers!**

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

## The functions:

- **Arraylist\* arraylist()**
    - "Constructor method". Returns a pointer to an empty "Array list"
- **Arraylist\* alst_add(Arraylist\* list, int index)**
    - Adds the number to the end of the list
- **int alst_get(Arraylist\* list, int index)**
    - Returns the value at the provided index, or -1 if the index is out of bounds
- **int alst_size(Arraylist\* list)**
    - Returns the size of the list
- **Arraylist\* alst_remove(Arraylist\* list)**
    - Removes the last entry in the list ("pop" function)
- **Arraylist alst_removeIndex(Arraylist\*, int index)**
    - Removes the value from the provided index and shifts all the following values to the left. Does nothing if the index is out of bounds.
- **Arraylist\* alst_insertIndex(Arraylist\*, int index, int new_num)**
    - Inserts a value at the provided index and shifts all the following values to the right. Does nothing if the index is out of bounds.
- **Arraylist\* alst_set(Arraylist\* list, int index, int new_val)**
    - Changes the value at the provided index to the new value.
- **Arraylist\* alst_clear(Arraylist\* list)**
    - Empties the array (sets the size to 0)