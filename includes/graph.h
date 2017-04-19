#ifndef __GRAPH_H
#define __GRAPH_H

#include "collection.h"

typedef struct _Graph{
  int v; /**< Number of vertices in #Graph */
  int e; /**< Number of edges in #Graph */
  Bag *adj;
} Graph;

void Graph_init(Graph* graph, int no_of_vertex);
int Graph_no_of_vertex(Graph* graph);
int Graph_no_of_edge(Graph* graph);
void Graph_add_edge(Graph* graph, int v, int w);
int Graph_degree_of_vertex(Graph* graph, int vertex);
int Graph_max_degree(Graph* graph);
int Graph_average_degree(Graph* graph);
int Graph_no_of_self_loops(Graph* graph);
void Graph_show(Graph* graph);
void Graph_destroy(Graph* graph);

typedef struct _Graph_search_and_path{
  bool* marked;
  int* edge_to;
  int count;
  int source_vertex;
  Graph* graph;
} Graph_path;

typedef enum _Search_method{
  DFS=1,
  BFS=2,
  INVALID=3
} Search_method;

void Graph_path_init(Graph_path* gp, Graph* graph, int source_vertex);
bool Graph_path_has_path_to(Graph_path* gp, int vertex);
int Graph_path_count(Graph_path* gp);
void Graph_path_search(Graph_path* gp, Search_method method);
void Graph_path_show_path(Graph_path* gp, int vertex_to);
void Graph_path_destroy(Graph_path* gp);
#endif
