/*
This file defines the interface for Dijkstras shortest path
algo and path printing */

#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

//returns shortest distance by running Dijkstra's Algo
int dijkstra(int start, int end, int prev[]);

//prints shortest path from start to end
void print_path(int start, int end, int prev[]);

#endif