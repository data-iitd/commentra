

#include<stdio.h>
#include<stdlib.h>

// Define a structure to represent a key-value pair in the map
typedef struct{
    int key;
    int value;
} MapEntry;

// Define a structure to represent the map
typedef struct{
    MapEntry *entries;
    int size;
} Map;

// Initialize an empty map named'm'
Map *initMap(){
    Map *m = (Map *)malloc(sizeof(Map));
    m->entries = (MapEntry *)malloc(sizeof(MapEntry) * 1000);
    m->size = 0;
    return m;
}

// Insert a new key-value pair into the map
void insertMap(Map *m, int key, int value){
    if(m->size >= 1000){
        m->entries = (MapEntry *)realloc(m->entries, sizeof(MapEntry) * (m->size + 1000));
    }
    m->entries[m->size].key = key;
    m->entries[m->size].value = value;
    m->size++;
}

// Find the value associated with a given key in the map
int findMap(Map *m, int key){
    for(int i=0;i<m->size;i++){
        if(m->entries[i].key == key){
            return m->entries[i].value;
        }
    }
    return -1;
}

// Free the memory allocated for the map
void freeMap(Map *m){
    free(m->entries);
    free(m);
}

// Initialize an empty map named'm'
int main(){
    Map *m = initMap();

    // Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
    for(int i=0;i*200<5001;i++){
        // Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
        for(int j=0;j*300<5001;j++){
            // Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
            for(int k=0;k*500<5001;k++){
                // Calculate the composite index 'w'
                int w=i*200+j*300+k*500;

                // Calculate the potential value 'p' for the given index 'w'
                int p=i/5*5*380*0.8+i%5*380
                     +j/4*4*550*0.85+j%4*550
                     +k/3*3*850*0.88+k%3*850;

                // If the map'm' already contains the index 'w', update its value with the minimum of the current potential value and the existing one
                int existingValue = findMap(m, w);
                if(existingValue!= -1){
                    insertMap(m, w, existingValue < p? existingValue : p);
                }

                // If the map'm' does not contain the index 'w', add it with the current potential value as its value
                else{
                    insertMap(m, w, p);
                }
            }
        }
    }

    // Read integers from the standard input and print their corresponding potential values from the map'm'
    int n;
    while(scanf("%d", &n), n){
        int value = findMap(m, n);
        printf("%d\n", value);
    }

    // Free the memory allocated for the map
    freeMap(m);

    return 0;
}

