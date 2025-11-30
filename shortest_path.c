/*
This file implements Dijkstra's Algo by using an adjancency
matric by finding the shortest distance between two cities and reconstructing the path*/

#include <stdio.h>
#include "city_graph.h"
#include "shortest_path.h"

//Dijkstra' Algo (0(V^2))
int dijkstra(int start, int end, int prev[]){
  int dist[MAX_CITIES];
  int visited[MAX_CITIES];

  for (int i = 0; i < city_count; i++){
    dist[i]=INF;
    visited[i]=0;
    prev[i] = -1;

  }
  dist[start]=0;

for (int i=0; i < city_count; i++){
  int u = -1;
  int min_dist = INF;

  //finds the closest unvisited node
  for (int j=0; j <city_count; j++){
    if (!visited[j] && dist[j] < min_dist){
      u=j;
    }

  }
  if (u == -1)break;

  visited[u] = 1;

  for (int v=0; v < city_count; v++){
    if (graph[u][v] != INF) {
      int alt = dist[u]+graph[u][v];
      if (alt < dist[v]){
        dist[v] = alt;
        prev[v]=u;
      }
    }
  }
}
return dist[end];

}

//using prev [] array -> print the shortest path
void print_path(int start, int end, int prev[]){
  int path[MAX_CITIES];
  int count = 0;
  int current = end;

  while (current != -1){
    path[count++] = current;
    current = prev[current];
  }

  printf("Path found   \n");
  for (int i=count-1; i >= 0; i--){
    printf("\t%s\n", cities[path[i]]);
  }

}