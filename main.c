/*
This is the main driver file for the shortest path application. It loads the graph from files and provides an easy to read user interface for finding shortest paths between two cities*/

#include <stdio.h>
#include <string.h>
#include "city_graph.h"
#include "shortest_path.h"

//added the removal of newline from a users input for ease of comparing user input strings

void trim_down_newline(char *s){
  size_t len = strlen(s);
  if (len > 0 && s[len - 1] == '\n'){
    s[len - 1] = '\0';
  }
}

//prints the help messaging like the sample test provideds in the assignment using '\t' character for indentation
void print_help_user(void){
  printf("Commands:\n");
  printf("\tlist - list all cities\n");
  printf("\t<city1><city2> - find the shortest path between two cities\n");
  printf("\thelp - print this help message\n");
  printf("\texit - exit the program\n");
}

int main(int argc, char *argv[]){
  if (argc != 3){
    printf("Usage: %s <vertices><distances>\n", argv[0]);
    return 1;
  }
  //initializing the graph and loading the data from the given files
  init_graph();
  load_vertices(argv[1]);
  load_distances(argv[2]);
  //splash page 
  printf(" ----****Welcome to the shortest path finder****----\n");
  print_help_user();
  printf("*******************************************************\n");

  char input[256];

  while (1){
    printf("Where do you want to go today? ");
    fflush(stdout);
    //read the input by user, if EOF, exit the loop
    if (fgets(input, sizeof(input), stdin)== NULL){
      break;
    }

    trim_down_newline(input);

    //if user just hits enter button, make it an invalid input
    if (strlen(input) == 0){
      printf("Invalid Command\n");
      print_help_user();
      continue;
    }
    //handling simple commands at first
    if(strcmp(input, "exit")== 0){
      printf("Goodbye!\n");
      break;
    }
    else if (strcmp(input, "help")== 0){
      print_help_user();
      continue;
    }
    else if (strcmp(input, "list")==0){
      print_cities();
      continue;
    }

    //parse <city1> <city2>

    char city1[MAX_NAME];
    char city2[MAX_NAME];
    int num_tokens = sscanf(input, "%s %s", city1, city2);

  if (num_tokens == 2){
      //declaring the variables 
      int start_index = find_city_index(city1);
      int end_index = find_city_index(city2);
    
      //if none of the cities are found, it makes it an invalid command by the user
      if (start_index == -1 || end_index == -1){
        printf("Invalid command\n");
        print_help_user();
        continue;
      }
      //run dijkstras to find shortest path
      int prev[MAX_CITIES];
      int distance = dijkstra(start_index, end_index, prev);

      if(distance == INF){
        //if the cities exist but there is no path between them
        printf("Path not found...\n");
      }else{
        //print both the path & total distance
        print_path(start_index, end_index, prev);
        printf("Total Distance: %d\n", distance);
      }

    }  else {
      //any other format will be an invalid command
      printf("Invalid Command\n");
      print_help_user();
    }
  }

  return 0;
}