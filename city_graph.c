/*
This file includes all the graph functionality of the assignment
1-initialied the adh matrix
2-loads city and distances
3-abile to search for cities by name
4-debg print for the graph */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "city_graph.h"

//global storage for graph
char cities[MAX_CITIES][MAX_NAME];
int city_count = 0;
int graph[MAX_CITIES][MAX_CITIES];

//removes any new line char from strings in fgets
static void trim_down_newline(char *s){
  size_t len = strlen(s);
  if (len > 0 && s[len-1] == '\n'){
    s[len - 1]= '\0';
  }
}

//initializing the adj matrix

void init_graph(void){
  for (int i=0; i < MAX_CITIES; i++){
    for (int j=0; j < MAX_CITIES; j++){
      if (i == j) {
          graph[i][j]=0;
        } else {
          graph[i][j] = INF;
        }
      }
    }
  }

void load_vertices(const char *filename){
  FILE *f = fopen(filename, "r");
  if (!f){
    printf("Alert: Error unable to open file %s\n", filename);
    exit(1);
  }
  char line[256];
  city_count = 0;

  while (fgets(line, sizeof(line), f)){
    trim_down_newline(line);

    if (line[0]== '\0') {
      continue;
    }
    if (city_count >= MAX_CITIES){
      printf("Alert: too many cities (max %d)\n", MAX_CITIES);
      break;
    }
    strncpy(cities[city_count], line, MAX_NAME -1);
    cities[city_count][MAX_NAME -1]= '\0';
    city_count++;
  }
  fclose(f);
}

int find_city_index(const char *name){
  for (int i=0; i< city_count; i++){
    if (strcmp(cities[i], name) == 0){
      return i;
    }
  }
  return -1;
}

//loads the distance from the distance file to the graph
void load_distances(const char *filename){
  FILE *f = fopen(filename, "r");
  if (!f){
    printf("Alert Error could no open distance file %s\n", filename);
    exit(1);
  }
  char line[256], c1[MAX_NAME], c2[MAX_NAME];
  int d;

  while (fgets(line, sizeof(line), f)){
    if (sscanf(line, "%s %s %d", c1, c2, &d) == 3){
      int i=find_city_index(c1);
      int j=find_city_index(c2);

      if (i != -1 && j != -1){
        graph[i][j]=d;
        graph[j][i]=d;
      }
    }
  }
  fclose(f);
}

//prints all the cities
void print_cities(void){
  for (int i=0;i<city_count; i++){
    printf("%s\n", cities[i]);
  }
}

//prints the adj matrix for debugging
void print_graph_debug(void){
  for (int i=0; i<city_count; i++){
    for (int j=0; j<city_count; j++){
      if (graph[i][j] == INF)
      printf("INF ");
      else printf("%3d ", graph[i][j]);
    }
  }
  printf("\n");
}