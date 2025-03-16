#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

typedef struct {
    int count;
    bool seen[MAX_NODES + 1];
    int path, cycle;
    LinkedList graph[MAX_NODES + 1];
} Main;

int dfs(Main* ft, int child, int par) {
    if (ft->seen[child]) return ft->cycle;
    ft->seen[child] = true;
    Node* temp = ft->graph[child].head;
    while (temp != NULL) {
        if (temp->data != par) {
            ft->count++;
            if (dfs(ft, temp->data, child) == ft->cycle) return ft->cycle;
        }
        temp = temp->next;
    }
    return ft->path;
}

int main() {
    Main ft;
    ft.path = 0;
    ft.cycle = 1;
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i <= m; i++) {
        ft.graph[i].head = NULL;
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = y;
        newNode->next = ft.graph[x].head;
        ft.graph[x].head = newNode;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = ft.graph[y].head;
        ft.graph[y].head = newNode;
    }
    int toremove = 0;
    for (int i = 1; i <= m; i++) {
        if (!ft.seen[i]) {
            ft.count = 0;
            if (dfs(&ft, i, 0) == ft.cycle) {
                if (ft.count % 2 == 1) toremove++;
            }
        }
    }
    if ((m - toremove) % 2 == 1) toremove++;
    printf("%d\n", toremove);
    return 0;
}

