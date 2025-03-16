
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList* arrList = (ArrayList*)malloc(sizeof(ArrayList));
    arrList->arr = (int*)malloc(sizeof(int) * capacity);
    arrList->size = 0;
    arrList->capacity = capacity;
    return arrList;
}

void add(ArrayList* arrList, int element) {
    if (arrList->size == arrList->capacity) {
        arrList->capacity *= 2;
        arrList->arr = (int*)realloc(arrList->arr, sizeof(int) * arrList->capacity);
    }
    arrList->arr[arrList->size++] = element;
}

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    ArrayList** connect = (ArrayList**)malloc(sizeof(ArrayList*) * numNode);
    for (int i = 0; i < numNode; i++) {
        connect[i] = createArrayList(numNode);
    }

    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(connect[a - 1], b - 1);
        add(connect[b - 1], a - 1);
    }

    if (numEdge % 2!= 0) {
        printf("-1\n");
        return 0;
    }

    int* visited = (int*)malloc(sizeof(int) * numNode);
    bool* odd = (bool*)malloc(sizeof(bool) * numNode);
    char* print = (char*)malloc(sizeof(char) * (numEdge * 10));
    int printIndex = 0;

    dfs(0, -1, connect, visited, odd, &printIndex, print);

    printf("%s", print);

    free(connect);
    free(visited);
    free(odd);
    free(print);

    return 0;
}

void dfs(int crt, int parent, ArrayList** connect, int* visited, bool* odd, int* printIndex, char* print) {
    visited[crt] = 1;
    ArrayList* crtConnect = connect[crt];
    for (int i = 0; i < crtConnect->size; i++) {
        int child = crtConnect->arr[i];
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            sprintf(print + *printIndex, "%d %d\n", crt + 1, child + 1);
            odd[crt] =!odd[crt];
            *printIndex += 10;
        } else {
            dfs(child, crt, connect, visited, odd, printIndex, print);
            if (odd[child]) {
                sprintf(print + *printIndex, "%d %d\n", child + 1, crt + 1);
                odd[child] =!odd[child];
                *printIndex += 10;
            } else {
                sprintf(print + *printIndex, "%d %d\n", crt + 1, child + 1);
                odd[crt] =!odd[crt];
                *printIndex += 10;
            }
        }
    }
    visited[crt] = 2;
}

// 