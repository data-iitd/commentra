
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define MAX 100000

int count, path, cycle;
bool seen[MAX];

struct node {
    int data;
    struct node *next;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addEdge(struct node **head, int x, int y)
{
    struct node *temp = newNode(y);
    temp->next = (*head);
    (*head) = temp;

    temp = newNode(x);
    temp->next = (*head);
    (*head) = temp;
}

int dfs(struct node **head, int child, int par)
{
    if (seen[child]) {
        return cycle;
    }
    seen[child] = true;

    struct node *temp = (*head);
    while (temp) {
        if (temp->data == child) {
            break;
        }
        temp = temp->next;
    }

    while (temp) {
        if (temp->data!= par) {
            count++;
            if (dfs(head, temp->data, child) == cycle) {
                return cycle;
            }
        }
        temp = temp->next;
    }
    return path;
}

int main()
{
    int m, n, x, y;
    scanf("%d %d", &m, &n);
    struct node *head = NULL;
    for (int i = 0; i < m; i++) {
        addEdge(&head, i, i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        addEdge(&head, x, y);
    }

    int toremove = 0;
    for (int i = 0; i < m; i++) {
        if (!seen[i]) {
            count = 0;
            if (dfs(&head, i, 0) == cycle) {
                if (count % 2 == 1) {
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

