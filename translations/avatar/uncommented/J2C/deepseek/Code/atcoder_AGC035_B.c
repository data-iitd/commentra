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
} List;

List* adjacencyList[MAX_NODES];
int visited[MAX_NODES];
bool odd[MAX_NODES];
char print[100000];

void dfs(int crt, int parent) {
    visited[crt] = 1;
    Node* temp = adjacencyList[crt]->head;
    while (temp != NULL) {
        int child = temp->data;
        if (child == parent || visited[child] == 1) {
            temp = temp->next;
            continue;
        } else if (visited[child] == 2) {
            sprintf(print + strlen(print), "%d %d\n", crt + 1, child + 1);
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if (odd[child]) {
                sprintf(print + strlen(print), "%d %d\n", child + 1, crt + 1);
                odd[child] = !odd[child];
            } else {
                sprintf(print + strlen(print), "%d %d\n", crt + 1, child + 1);
                odd[crt] = !odd[crt];
            }
        }
        temp = temp->next;
    }
    visited[crt] = 2;
}

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    for (int i = 0; i < numNode; i++) {
        adjacencyList[i] = (List*)malloc(sizeof(List));
        adjacencyList[i]->head = NULL;
    }

    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = b;
        newNode->next = adjacencyList[a]->head;
        adjacencyList[a]->head = newNode;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a;
        newNode->next = adjacencyList[b]->head;
        adjacencyList[b]->head = newNode;
    }

    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    dfs(0, -1);
    printf("%s", print);

    for (int i = 0; i < numNode; i++) {
        Node* temp = adjacencyList[i]->head;
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
        free(adjacencyList[i]);
    }

    return 0;
}
