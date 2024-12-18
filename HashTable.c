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

// Function to initialize the HashTable
void initHashTable(struct HashTable *table) {
    table->capacity = 2;
    table->size = 0;
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
    if (table->capacity == sizeof(table->arr)) {
        reHash(table);
    }
    int index = hashFunction(key, table->capacity);
    if (table->arr[index] == -1) {
        index = collisionFunction(table, key, table->capacity);
    }
    table->arr[index] = key;
    table->size += 1;
}

void addElementAtReserve(struct HashTable *table, int key) {
    if (table->capacity == sizeof(table->arr)) {
        reHash(table);
    }
    int index = hashFunction(key, table->capacity);
    if (table->reserve_arr[index] == -1) {
        index = collisionFunction(table, key, table->capacity);
    }
    table->reserve_arr[index] = key;
    table->reserve_size += 1;
}

void clear_reserve(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        table->reserve_arr[i] = -1;
    }
    table->reserve_size = 0;
}

void reHash(struct HashTable *table) {
    table->capacity *= 2;
    for (int i = 0; i < table->capacity; i++) {
        if (table->arr[i] == -1) {
            continue;
        }
        addElementAtReserve(table, table->arr[i]);
    }
    table->size = 0;
    for (int j = 0; j <= table->reserve_size; j++) {
        addElementAt(table, table->reserve_arr[j]);
    }
    
}



int probeFunction(int i, int j, int capacity) {
    return (3*(j) + i) % capacity;
}

int collisionFunction(struct HashTable *table, int key, int capacity) {
    int i = key % capacity;
    int j = 1;
    int flag = 0;
    while (flag == 0) {
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
    addElementAt(&table, 5);
    for (int i = 0; i <= table.size; i++) {
        printf("%d\n", table.arr[i]);
    }
    return 0;
    
}
