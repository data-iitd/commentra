#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 10
#define MAX_COM_LEN 13
#define MAX_MAP_SIZE 1000

typedef struct {
    char key[MAX_STR_LEN];
    bool value;
} MapEntry;

MapEntry map[MAX_MAP_SIZE];
<<<<<<< HEAD
int map_size = 0;

bool find_in_map(const char *key) {
    for (int i = 0; i < map_size; i++) {
=======
int mapSize = 0;

bool findInMap(const char *key) {
    for (int i = 0; i < mapSize; i++) {
>>>>>>> 98c87cb78a (data updated)
        if (strcmp(map[i].key, key) == 0) {
            return map[i].value;
        }
    }
    return false;
}

<<<<<<< HEAD
void insert_into_map(const char *key) {
    strcpy(map[map_size].key, key);
    map[map_size].value = true;
    map_size++;
=======
void insertIntoMap(const char *key, bool value) {
    strcpy(map[mapSize].key, key);
    map[mapSize].value = value;
    mapSize++;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n;
    char str[MAX_STR_LEN], com[MAX_COM_LEN];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", com, str);
        if (com[0] == 'i') {
<<<<<<< HEAD
            insert_into_map(str);
        } else {
            if (find_in_map(str)) {
=======
            insertIntoMap(str, true);
        } else {
            if (findInMap(str)) {
>>>>>>> 98c87cb78a (data updated)
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}

// <END-OF-CODE>
