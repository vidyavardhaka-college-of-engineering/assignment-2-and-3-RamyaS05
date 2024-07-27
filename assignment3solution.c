#include <stdio.h>
#include <stdlib.h>

#define M 11 // Number of slots in the hash table

// Hash function h1
int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % M;
    return x;
}

// Secondary hash function Reverse(key)
int Reverse(int key) {
    int reversed = 0;
    while (key > 0) {
        reversed = reversed * 10 + key % 10;
        key = key / 10;
    }
    return reversed;
}

// Linear probing function
void linearProbe(int hashTable[], int key) {
    int homeSlot = h1(key);
    int currentSlot = homeSlot;
    while (hashTable[currentSlot] != -1) {
        currentSlot = (currentSlot + 1) % M;
    }
    hashTable[currentSlot] = key;
    printf("Home Slot: %d, Key: %d, Probe Sequence: ", homeSlot, key);
    printf("%d\n", currentSlot);
}

// Quadratic probing function
void quadraticProbe(int hashTable[], int key) {
    int homeSlot = h1(key);
    int currentSlot = homeSlot;
    int i = 0;
    while (hashTable[currentSlot] != -1) {
        currentSlot = (homeSlot + i*i) % M;
        i++;
    }
    hashTable[currentSlot] = key;
    printf("Home Slot: %d, Key: %d, Probe Sequence: ", homeSlot, key);
    printf("%d\n", currentSlot);
}

// Double hashing function
void doubleHashing(int hashTable[], int key) {
    int homeSlot = h1(key);
    int currentSlot = homeSlot;
    int stepSize = Reverse(key);
    int i = 0;
    while (hashTable[currentSlot] != -1) {
        currentSlot = (homeSlot + i * stepSize) % M;
        i++;
    }
    hashTable[currentSlot] = key;
    printf("Home Slot: %d, Key: %d, Probe Sequence: ", homeSlot, key);
    printf("%d\n", currentSlot);
}

// Print final hash table contents
void printHashTable(int hashTable[]) {
    printf("Final Hash Table:\n");
    printf("Slot 0 1 2 3 4 5 6 7 8 9 10\nContents ");
    for (int i = 0; i < M; i++) {
        if (hashTable[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", hashTable[i]);
        }
    }
    printf("\n");
}

int main() {
    int hashTable[M];
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1; // Initialize all slots to -1 (indicating empty)
    }

    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Insert keys using linear probing
    printf("Using Linear Probing:\n");
    for (int i = 0; i < numKeys; i++) {
        linearProbe(hashTable, keys[i]);
    }
    printHashTable(hashTable);

    // Clear hash table for next probing method
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1;
    }

    // Insert keys using quadratic probing
    printf("\nUsing Quadratic Probing:\n");
    for (int i = 0; i < numKeys; i++) {
        quadraticProbe(hashTable, keys[i]);
    }
    printHashTable(hashTable);

    // Clear hash table for next probing method
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1;
    }

    // Insert keys using double hashing
    printf("\nUsing Double Hashing:\n");
    for (int i = 0; i < numKeys; i++) {
        doubleHashing(hashTable, keys[i]);
    }
    printHashTable(hashTable);

    return 0;
}
