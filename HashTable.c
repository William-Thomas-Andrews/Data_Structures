#include <stdio.h>
#include <stdlib.h>


// Define the struct
struct HashTable {
    int *arr;      // Pointer for the dynamic array
    int *reserve_arr;
    int size;      // Current size of the array
    int reserve_size;
    int capacity;  // Capacity of the array
};

void initHashTable(struct HashTable *table);
int hashFunction(int key, int capacity);
void addElementAt(struct HashTable *table, int key);
void addElementAtReserve(struct HashTable *table, int key);
void clear_reserve(struct HashTable *table);
void reHash(struct HashTable *table);
int probeFunction(int i, int j, int capacity);
int collisionFunction(struct HashTable *table, int key, int capacity);
void clear_arr(struct HashTable *table);
void clear_reserve(struct HashTable *table);

// Function to initialize the HashTable
void initHashTable(struct HashTable *table) {
    table->capacity = 2;
    table->size = 0;
    table->reserve_size = 0;
    table->arr = (int *)malloc(table->capacity * sizeof(int));
    for (int i = 0; i < table->capacity; i++) {
        table->arr[i] = -1; // Sentinel value indicating "empty"
    }
    table->reserve_arr = (int *)malloc(table->capacity * sizeof(int));
    for (int i = 0; i < table->capacity; i++) {
        table->reserve_arr[i] = -1; // Sentinel value indicating "empty"
    }
}

int hashFunction(int key, int capacity) {
    return key % capacity; // Always returns an index within the table bounds
}

void addElementAt(struct HashTable *table, int key) {
    if (table->size == table->capacity) {
        printf("Rehash triggered\n");
        reHash(table);
    }
    int index = hashFunction(key, table->capacity);
    if (table->arr[index] == -1) {
        table->arr[index] = key;
    } else {
        index = collisionFunction(table, key, table->capacity);  // Handle collision
    }
    table->size += 1;
}

void addElementAtReserve(struct HashTable *table, int key) {
    printf("size vs capacity: %d, vs %d\n", table->size, table->capacity);
    printf("reserve size vs capacity: %d, vs %d\n", table->reserve_size, table->capacity);
    if (table->size == table->capacity) {
        // printf("huh?\n");
        reHash(table);
    }
    int index = hashFunction(key, table->capacity);
    
    if (table->reserve_arr[index] == -1) {
        printf("huh?\n");
        index = collisionFunction(table, key, table->capacity);
    }
    table->reserve_arr[index] = key;
    table->reserve_size += 1;
}

void clear_arr(struct HashTable *table) {
    for (int i = 0; i < table->capacity; i++) {
        table->arr[i] = -1;
    }
    table->size = 0;
}

void clear_reserve(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        table->reserve_arr[i] = -1;
    }
    table->reserve_size = 0;
}

void reHash(struct HashTable *table) {
    table->capacity *= 2;
    table->reserve_arr = (int *)realloc(table->reserve_arr, table->capacity * sizeof(int));
    if (table->reserve_arr == NULL) {
        printf("Memory allocation failed for reserve array.\n");
        exit(1);  // to handle memory allocation failure
    }
    // for (int i = 0; i < table->capacity; i++) {
    //     if (table->arr[i] != -1) {
    //         addElementAtReserve(table, table->arr[i]);
    //     }
    // }

    for (int j = 0; j < table->capacity; j++) {
        table->reserve_arr[j] = -1;
    }

    printf("Rehash reached: new capacity = %d\n", table->capacity);
    printf("table->size = %d\n", table->size);
    int j = 0;
    for (int i = 0; i < table->size; i++) {
        if (table->arr[i] != -1) {
            table->reserve_arr[j] = table->arr[i];
            j++;
            table->reserve_size++;
            // addElementAtReserve(table, table->arr[i]);
        }
    }

    // printf("Done\n");

    for (int i = 0; i < table->capacity; i++) {
        printf("Index %d: %d\n", i, table->arr[i]);
    }

    // table->size = 0; 
    // for (int i = 0; i < table->size; i++) {
    //     table->arr[i] = -1;
    // }

    clear_arr(table);

    for (int i = 0; i < table->capacity; i++) {
        printf("Index %d: %d\n", i, table->arr[i]);
    }

    for (int p = 0; p < table->reserve_size; p++) {
        addElementAt(table, table->reserve_arr[p]);
        // printf("Done");
        printf("%d\n", table->reserve_arr[p]);
    }

    for (int i = 0; i < table->capacity; i++) {
        printf("Index %d: %d\n", i, table->arr[i]);
    }

    clear_reserve(table);
    
    printf("Done\n");
}


int probeFunction(int i, int j, int capacity) {
    /*
    We are using f(k) = (3 * iteration_num) + original_key
    */
    return (3*(j) + i) % capacity;
}

int collisionFunction(struct HashTable *table, int key, int capacity) {
    for (int i = 0; i < table->capacity; i++) {
        printf("Index %d: %d\n", i, table->arr[i]);
    }
    int i = key % capacity;
    int j = 1;
    int flag = 0;
    while (flag == 0) {
        // printf("marker\n");
        // printf("%d\n", i);
        // printf("%d\n", table->arr[i]);
        if (table->arr[i] == -1) {
            table->arr[i] = key;
            flag = 1;
        }
        i = probeFunction(i, j, capacity);
        j++;
    };
    return key % capacity;
}


int main() {
    struct HashTable table;
    initHashTable(&table);
    printf("HashTable initialized with capacity: %d\n", table.capacity);
    printf("table.size = %d, and table.capacity = %d\n", table.size, table.capacity);
    addElementAt(&table, 5);
    printf("table.size = %d, and table.capacity = %d\n", table.size, table.capacity);
    addElementAt(&table, 10);
    printf("table.size = %d, and table.capacity = %d\n", table.size, table.capacity);
    addElementAt(&table, 15); // Trigger rehash
    printf("table.size = %d, and table.capacity = %d\n", table.size, table.capacity);
    printf("Elements added successfully.\n");

    for (int i = 0; i < table.capacity; i++) {
        printf("Index %d: %d\n", i, table.arr[i]);
    }

    // Free dynamically allocated memory
    free(table.arr);
    free(table.reserve_arr);
    return 0;
    
}
