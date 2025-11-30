# Report
Fill out these report questions. 


1. What is the difference between a directed and undirected graph?
- A directed graph and an undirected graph are both ways to show connections between things, but the big difference is whether those connections go one way or both ways. In an undirected graph, you can travel in both directions, so if city A connects to city B, you can go from A to B and also from B back to A. These kinds of graphs don’t use arrows and are good for things like two-way streets. In a directed graph, the connection only goes one way, so if there’s an arrow from A to B, you can go from A to B but not the other way unless there’s another arrow pointing back. Directed graphs are used for things like one way streets. In my program, I used an undirected graph because the cities are connected by two way roads, so I save the distance in both directions in the data.

2. What is the Big O of Dijkstra's algorithm.... 
   * Assuming you used an array (or list) to store the vertices.
   - If an array or list is used to store the vertices, Dijkstra’s algorithm runs in O(V²) time, where V is the number of vertices. This is because for each vertex, the algorithm has to scan through the entire list to find the next closest unvisited vertex, which takes O(V) time, and this happens V times. This is the version I used in my program because it is simpler to implement and works well for smaller graphs.
   * Assuming you used a heap / priority queue to store the vertices.
   - If a heap or priority queue is used instead, the runtime improves to O((V + E) log V), where E is the number of edges. This is faster because the heap allows the algorithm to quickly find and update the closest vertex using log V time instead of scanning the whole list. In short, using an array is easier but slower, while using a heap is more efficient for large graphs.

3. Explain in your own words what that means for larger graphs when trying to find the shortest distance. 
- Basically, when graphs get really big, the Big O of Dijkstra’s algorithm starts to matter a lot. If you use the simple array version with O(V²), the program has to keep scanning through all the cities over and over to find the next closest one, and that gets slow fast as more cities are added. So on a small map it feels fine, but on a huge map with hundreds or thousands of cities, it can really drag and take a long time to finish. When you use a heap or priority queue with O((V + E) log V), the program is way more efficient because it can quickly grab the next closest city without checking everything every time.


## Deeper Thinking
4. For this assignment, you didn't need the most "efficient" set of data structures (for example, a heap wasn't required). However, think on the scale of google/apple maps - they have to deal with millions of vertices and edges. What data structures would you use to store the graph? Why? Somethings to consider - would you be able to store the entire graph at a time? Could you break it up into smaller pieces? How would you do that? Would there be advantages to caching/memoization of paths? You are free to explore your thoughts on this subject/reflect on various ideas. Other than a realization of some scalability of problems, there isn't a wrong answer. 
- To think on a scale of google/apple maps, sounds overwhelming since it maps out the entire areas of the world but thinking of accomplishing it little by little would help complete the task at hand. If I had millions of insersections and roads, I would use an adjacency list instead of a adjacency matrix. With the list, each city (vertex) only stores the roads (edges) that actually exits, so better use of memory for huge maps like the scale of google/apple maps. With a matrix, we would store every possible connection even if they didnt exist. It would also not be ideal to graph in memory all at once, but break it up in regions and store it in a database section by section (like a puzzle).In regards to caching and memoization, caching common paths users request like the airport, museums, downtown areas so the computer doesn't run it each time. 



## Future Understanding
5. Related to shortest distance, is a problem called the "messenger" or "traveling sales person" problem commonly abbreviated to TSP. This problem is to find the shortest path that visits **every** vertex in a graph. Another way to look at it, is you are an delivery driver, and you have a series of packages to deliver. Can you find an optimal path for your deliveries that minimizes the total distance traveled? Imagine if you had 5 stops. How many different paths are there?  There are 120 possible paths to look at! (assuming fully connected routes). 
   * How many possible paths are there if you have 6 stops? 
   - 6! = 6 × 5 × 4 × 3 × 2 × 1 = 720 possible paths for 6 stops.
   * How many possible paths are there if you have 10 stops?
   - 10! = 10 × 9 × 8 × 7 × 6 × 5 × 4 × 3 × 2 × 1 = 3,628,800 possible paths for 10 stops.
6. What type of growth is this problem? 
- This type of growth is called factorial growth.
7. Take some time to research TSP problems. It falls under a certain classification of problems? What is it? 
- TSP is classified as an NP hard problem. It means there is no known fast algorithm that is able to solve it efficiently for large number of cities. A solution can be checked pretty fast but the best possible route takes a long time.
8. Provide some examples of fields / problems that use TSP.
- Graph Coloring
- Vertex Cover
- Subset sum
- Knapsack

> [!TIP]
> We are having you explore TSP, so you can see the terms used for problem classification that are often the foundation of computer science theory. You will not be asked to know about TSP outside of this assignment or even problem classification. Computer Science is often about dealing with problems considered "too hard" or "impossible", and finding ways to make them possible! As such, knowing topics such as N, NP, NP-Complete, etc. is important to understand the limits (to break).


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.
- QUESTION: How does a binary tree differ from a binary search tree?
- ANSWER: A binary tree is just a tree where each node can have at most two children (a left and a right), but there are no rules about the values stored in the nodes and can be in any order. A binary search tree (BST) is a special type of binary tree that follows an order rule: all values on the left side are smaller, and all values on the right side are larger than the parent. Because of this rule, a BST makes it way faster to search, add, and remove values, while a regular binary tree is mostly used just for structure.
2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 
- In Group Google Doc