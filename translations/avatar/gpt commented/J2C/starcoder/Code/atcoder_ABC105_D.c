#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 1000000007

typedef struct {
    int value;
    int count;
} Element;

typedef struct {
    Element *elements;
    int size;
    int capacity;
} HashTable;

HashTable *createHashTable(int capacity) {
    HashTable *table = (HashTable *) malloc(sizeof(HashTable));
    table->elements = (Element *) malloc(sizeof(Element) * capacity);
    table->size = 0;
    table->capacity = capacity;
    return table;
}

void destroyHashTable(HashTable *table) {
    free(table->elements);
    free(table);
}

void insertElement(HashTable *table, int value) {
    if (table->size == table->capacity) {
        return;
    }
    Element *element = &(table->elements[table->size]);
    element->value = value;
    element->count = 1;
    table->size++;
}

void mergeElement(HashTable *table, int value) {
    if (table->size == table->capacity) {
        return;
    }
    Element *element = &(table->elements[table->size]);
    element->value = value;
    element->count++;
    table->size++;
}

int getElementCount(HashTable *table, int value) {
    for (int i = 0; i < table->size; i++) {
        if (table->elements[i].value == value) {
            return table->elements[i].count;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int base = 0;
    HashTable *dp = createHashTable(m);
    long ans = 0;
    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        mergeElement(dp, (base + a[i]) % m);
        ans += getElementCount(dp, base);
    }
    printf("%ld\n", ans);
    destroyHashTable(dp);
    return 0;
}

