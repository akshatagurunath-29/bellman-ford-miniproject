/* ============================================================
 * Mini Project: Implementation and Analysis of Bellman-Ford      Algorithm for Shortest Path Detection in Weighted Graphs
 * Algorithm  : Bellman-Ford Algorithm
 * Author      : Akshata |  USN:R24EJ014
 * Date        : 24-05-26
 * Description : Program to find shortest paths from a
   source vertex and detect negative cycles in a weighted graph.
 * ============================================================ */
/* --- Include necessary header files --- */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /* Used for INT_MAX */

/* --- Constants and Macro Definitions --- */
#define MAX_EDGES 100
#define MAX_VERTICES 100

/* ============================================================
* Structure: Edge
* Purpose : Stores source, destination, and weight
* of each edge in the graph.
* ============================================================ */
struct Edge {
int source;
int destination;
int weight;
};

/* ============================================================
* Module / Function: bellmanFord
* Purpose : Implements Bellman-Ford Algorithm to
* find shortest paths from source vertex
* and detect negative weight cycles.
* Input : vertices -> number of vertices
* edges -> number of edges
* edgeList -> array of graph edges
* source -> source vertex
* Output : Prints shortest distance to all vertices
* ============================================================ */
void bellmanFord(int vertices, int edges,
struct Edge edgeList[],
int source) {

/* Distance array to store shortest path values */
int distance[MAX_VERTICES];

int i, j;

/* Step 1: Initialize all distances as infinity */
for (i = 0; i < vertices; i++) {
distance[i] = INT_MAX;
}

/* Distance to source vertex is always 0 */
distance[source] = 0;

/* Step 2: Relax all edges (V - 1) times */
for (i = 1; i <= vertices - 1; i++) {

for (j = 0; j < edges; j++) {

int u = edgeList[j].source;
int v = edgeList[j].destination;
int weight = edgeList[j].weight;

/* Update distance if shorter path found */
if (distance[u] != INT_MAX &&
distance[u] + weight < distance[v]) {

distance[v] = distance[u] + weight;
}
}
}

/* Step 3: Check for negative weight cycles */
for (j = 0; j < edges; j++) {

int u = edgeList[j].source;
int v = edgeList[j].destination;
int weight = edgeList[j].weight;

/* If relaxation is still possible,
graph contains negative cycle */
if (distance[u] != INT_MAX &&
distance[u] + weight < distance[v]) {

printf("\nGraph contains a "
"negative weight cycle.\n");
return;
}
}

/* Step 4: Display shortest distances */
printf("\nShortest distances from source vertex %d:\n",
source);

for (i = 0; i < vertices; i++) {

if (distance[i] == INT_MAX) {
printf("Vertex %d --> Infinity\n", i);
} else {
printf("Vertex %d --> %d\n",
i, distance[i]);
}
}
}

/* ============================================================
* Module / Function: main
* Purpose : Reads graph input from user and
* calls Bellman-Ford Algorithm.
* Input : User enters vertices, edges,
* edge details, and source vertex.
* Output : Displays shortest paths or
* negative cycle message.
* ============================================================ */
int main() {

int vertices, edges, source;
int i;

/* Array to store graph edges */
struct Edge edgeList[MAX_EDGES];

/* Step 1: Read number of vertices and edges */
printf("Enter number of vertices: ");
scanf("%d", &vertices);

printf("Enter number of edges: ");
scanf("%d", &edges);

/* Step 2: Read edge information */
printf("\nEnter edge details "
"(source destination weight):\n");

for (i = 0; i < edges; i++) {

printf("Edge %d: ", i + 1);

scanf("%d %d %d",
&edgeList[i].source,
&edgeList[i].destination,
&edgeList[i].weight);
}

/* Step 3: Read source vertex */
printf("\nEnter source vertex: ");
scanf("%d", &source);

/* Step 4: Call Bellman-Ford function */
bellmanFord(vertices, edges,
edgeList, source);

return 0;
}




















