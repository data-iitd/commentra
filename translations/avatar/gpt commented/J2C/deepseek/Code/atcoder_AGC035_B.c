#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void dfs(Node* adjList[], int visited[], bool odd[], char print[], int* printIndex, int crt, int parent) {
    visited[crt] = 1;
    Node* temp = adjList[crt];

    while (temp != NULL) {
        int child = temp->data;
        if (child == parent || visited[child] == 1) {
            temp = temp->next;
            continue;
        } else if (visited[child] == 2) {
            print[(*printIndex)++] = (crt + 1) + '0';
            print[(*printIndex)++] = ' ';
            print[(*printIndex)++] = (child + 1) + '0';
            print[(*printIndex)++] = '\n';
            odd[crt] = !odd[crt];
            temp = temp->next;
        } else {
            dfs(adjList, visited, odd, print, printIndex, child, crt);

            if (odd[child]) {
                print[(*printIndex)++] = (child + 1) + '0';
                print[(*printIndex)++] = ' ';
                print[(*printIndex)++] = (crt + 1) + '0';
                print[(*printIndex)++] = '\n';
                odd[child] = !odd[child];
            } else {
                print[(*printIndex)++] = (crt + 1) + '0';
                print[(*printIndex)++] = ' ';
                print[(*printIndex)++] = (child + 1) + '0';
                print[(*printIndex)++] = '\n';
                odd[crt] = !odd[crt];
            }
            temp = temp->next;
        }
    }
    visited[crt] = 2;
}

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    Node* adjList[MAX_NODES];
    for (int i = 0; i < numNode; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(adjList, a - 1, b - 1);
    }

    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    int visited[MAX_NODES] = {0};
    bool odd[MAX_NODES] = {false};
    char print[1000000];
    int printIndex = 0;

    dfs(adjList, visited, odd, print, &printIndex, 0, -1);

    print[printIndex] = '\0';
    printf("%s", print);

    return 0;
}
