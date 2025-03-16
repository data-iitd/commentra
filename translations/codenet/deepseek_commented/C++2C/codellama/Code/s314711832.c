#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a < b) ? a : b)
#define INF 1000000001
#define N 100000

struct edge {
  int source;
  int target;
  int weight;
};

struct edge *edges;

int distances[N];
int prev_distances[N] = {0};

int main() {
  int V, E, r;

  scanf("%d %d %d", &V, &E, &r);

  edges = (struct edge *)malloc(E * sizeof(struct edge));

  for (int i = 0; i < E; i++) {
    int source, target, distance;
    scanf("%d %d %d", &source, &target, &distance);
    edges[i].source = source;
    edges[i].target = target;
    edges[i].weight = distance;
    
  }

  //initialize distances array
 
  for (int i = 0; i < N; i++) {
    distances[i] = INF ; //max value
  }

  distances[r] = 0;

 
  for (int i = 1; i < V; i++) {
    for (int j=0; j< V; j++) {
      prev_distances[j] = distances[j];  
    }
    
    for (int j=0; j< E; j++) {
      distances[edges[j].target] = MIN(distances[edges[j].source] + edges[j].weight, distances[edges[j].target]);
    
    }

    bool same = true;
    for (int j=0; j< V; j++) {
      if (distances[j] != prev_distances[j]) {
	same = false;
	break;
      }
    }

    if (same) break;
  }

  for (int i = 0; i < V; i++) {
    if (distances[i] == INF) {
      printf("INF\n");
    } else {
      printf("%d\n", distances[i]);
    }
  }
}

