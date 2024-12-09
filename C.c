#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair *pairs;
    int size;
    int capacity;
} Map;

// Function to initialize the map
void initMap(Map *map) {
    map->size = 0;
    map->capacity = 10;
    map->pairs = (Pair *)malloc(map->capacity * sizeof(Pair));
}

// Function to add or update a key-value pair in the map
void addToMap(Map *map, int key) {
	int i;
    for (i = 0; i < map->size; i++) {
        if (map->pairs[i].key == key) {
            map->pairs[i].value++;
            return;
        }
    }
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->pairs = (Pair *)realloc(map->pairs, map->capacity * sizeof(Pair));
    }
    map->pairs[map->size].key = key;
    map->pairs[map->size].value = 1;
    map->size++;
}

// Function to get the maximum frequency from the map
int getMaxFrequency(Map *map) {
    int maxFreq = 0;
    int i;
    for (i = 0; i < map->size; i++) {
        if (map->pairs[i].value > maxFreq) {
            maxFreq = map->pairs[i].value;
        }
    }
    return maxFreq;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of chunks

    int *peanut = (int *)malloc(N * sizeof(int)); // Array to store peanut values
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &peanut[i]); // Read the peanut bits for each chunk
    }

    int *jumlah = (int *)malloc(N * sizeof(int)); // Array to store sum of pairs
    jumlah[0] = 0; // Initialize the first element of jumlah array

    // Process sums of consecutive chunks
    int j;
    for (j = 0; j < N - 1; j++) {
        int total = peanut[j] + peanut[j + 1]; // Sum of two consecutive chunks
        if (jumlah[j] != total) {
            jumlah[j + 1] = total; // If the sum is not equal to the previous sum, store it
        } else {
            jumlah[j + 1] = 0; // Otherwise, set to 0
        }
    }

    Map freq;
    initMap(&freq); // Initialize the map for storing frequency of sums

    // Add all the sums to the map if they are not 0
    int l;
    for (l = 0; l < N; l++) {
        if (jumlah[l] != 0) {
            addToMap(&freq, jumlah[l]); // Update the frequency of the sum
        }
    }

    int maxFreq = getMaxFrequency(&freq); // Get the maximum frequency from the map
    printf("%d\n", maxFreq); // Print the result

    // Free the allocated memory
    free(peanut);
    free(jumlah);
    free(freq.pairs);

    return 0;
}

