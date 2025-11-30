/*
I created this header file to define the data structure and function protoypes to be used to represent the ciry graph using an adjacency matrix
*/

#ifndef CITY_GRAPH_H
#define CITY_GRAPH_H

#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 250
#define MAX_NAME 150
#define INF INT_MAX

//global graph data
extern char cities[MAX_CITIES][MAX_NAME];
extern int city_count;
extern int graph[MAX_CITIES][MAX_CITIES];

//initialize adj matrix w INF values
void init_graph(void);

//loads city names from file
void load_vertices(const char *filename);

//loads the distance into grph - city1 city2 distance
void load_distances(const char *filename);

//will return the indec of the city name or if not found result in -1
int find_city_index(const char *name);

//print a list of all cities
void print_cities(void);

//print the full adj matrix
void print_graph_debug(void);

#endif
