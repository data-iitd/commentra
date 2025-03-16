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

List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    return newList;
}

void addEdge(List* adjList[], int a, int b) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = b;
    newNode->next = adjList[a]->head;
    adjList[a]->head = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = a;
    newNode->next = adjList[b]->head;
    adjList[b]->head = newNode;
}

void dfs(List* adjList[], bool visited[], bool odd[], FILE* output) {
    visited[0] = true;
    odd[0] = false;

    Node* stack[MAX_NODES];
    int top = -1;
    stack[++top] = (Node*)malloc(sizeof(Node));
    stack[top]->data = 0;
    stack[top]->next = NULL;

    while (top != -1) {
        int crt = stack[top]->data;
        Node* temp = stack[top--];
        free(temp);

        Node* neighbor = adjList[crt]->head;
        while (neighbor != NULL) {
            if (!visited[neighbor->data]) {
                visited[neighbor->data] = true;
                stack[++top] = (Node*)malloc(sizeof(Node));
                stack[top]->data = neighbor->data;
                stack[top]->next = NULL;

                if (odd[crt]) {
                    fprintf(output, "%d %d\n", crt + 1, neighbor->data + 1);
                    odd[neighbor->data] = !odd[neighbor->data];
                } else {
                    fprintf(output, "%d %d\n", neighbor->data + 1, crt + 1);
                    odd[crt] = !odd[crt];
                }
            } else if (neighbor->data != crt) {
                if (odd[crt]) {
                    fprintf(output, "%d %d\n", crt + 1, neighbor->data + 1);
                    odd[neighbor->data] = !odd[neighbor->data];
                } else {
                    fprintf(output, "%d %d\n", neighbor->data + 1, crt + 1);
                    odd[crt] = !odd[crt];
                }
            }
            neighbor = neighbor->next;
        }
    }
}

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    List* adjList[numNode];
    for (int i = 0; i < numNode; i++) {
        adjList[i] = createList();
    }

    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        addEdge(adjList, a, b);
    }

    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    bool visited[numNode];
    bool odd[numNode];
    FILE* output = fopen("output.txt", "w");

    dfs(adjList, visited, odd, output);

    fclose(output);
    return 0;
}
