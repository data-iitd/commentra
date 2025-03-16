

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data;
 struct Node *next;
} Node;

typedef struct {
 Node **array;
 int size;
} Graph;

void addEdge(Graph *g, int src, int dest) {
 Node *newNode = (Node *)malloc(sizeof(Node));
 newNode->data = dest;
 newNode->next = g->array[src];
 g->array[src] = newNode;

 Node *newNode2 = (Node *)malloc(sizeof(Node));
 newNode2->data = src;
 newNode2->next = g->array[dest];
 g->array[dest] = newNode2;
}

void dfs(Graph *g, int *seen, int *path, int *cycle, int v, int parent) {
 if (seen[v] == 1) {
  *cycle = 1;
  return;
 }
 seen[v] = 1;
 *path = *path + 1;

 Node *p = g->array[v];
 while (p!= NULL) {
  if (p->data!= parent) {
   dfs(g, seen, path, cycle, p->data, v);
  }
  p = p->next;
 }
}

int main() {
 int m, n, i, x, y, toremove = 0;
 scanf("%d %d", &m, &n);
 Graph *g = (Graph *)malloc(sizeof(Graph));
 g->array = (Node **)malloc(sizeof(Node *) * (m + 1));
 for (i = 0; i <= m; i++) {
  g->array[i] = NULL;
 }
 g->size = m;

 for (i = 0; i < n; i++) {
  scanf("%d %d", &x, &y);
  addEdge(g, x, y);
 }

 int *seen = (int *)malloc(sizeof(int) * (m + 1));
 int *path = (int *)malloc(sizeof(int));
 int *cycle = (int *)malloc(sizeof(int));
 for (i = 1; i <= m; i++) {
  if (seen[i] == 0) {
   *path = 0;
   *cycle = 0;
   dfs(g, seen, path, cycle, i, 0);
   if (*cycle == 1) {
    if (*path % 2 == 1) {
     toremove++;
    }
   }
  }
 }

 if ((m - toremove) % 2 == 1) {
  toremove++;
 }

 printf("%d\n", toremove);

 return 0;
}
