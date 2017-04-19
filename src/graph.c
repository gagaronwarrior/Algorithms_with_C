#include "graph.h"

/*****************************************************************
 * GRAPH object implementation.
 * It initialize graph object and populates it.
 ******************************************************************/
void Graph_init(Graph* graph, int no_of_vertex){
  graph->v = no_of_vertex;
  graph->e = 0;
  graph->adj = (Bag* )Malloc(sizeof(Bag) * no_of_vertex);
  for (int i = 0; i < no_of_vertex; i++){
    Bag_init(&graph->adj[i]);
  }
}

int Graph_no_of_vertex(Graph* graph){
  return graph->v;
}

int Graph_no_of_edge(Graph* graph){
  return graph->e;
}

int Graph_no_of_self_loops(Graph* graph){
  int count = 0;
  for (int v = 0; v < graph->v; v++){
    for (Node* n = Bag_iterator_begin(&graph->adj[v]); n != Bag_iterator_end(); n = Bag_iterator_next(n)){
      if (v == n->data) count++;
    }
  }
  return count;
}

void Graph_add_edge(Graph* graph, int v, int w){
  Bag_add(&graph->adj[v], w);
  Bag_add(&graph->adj[w], v);
  graph->e += 1;
}

int Graph_degree_of_vertex(Graph* graph, int vertex){
  return Bag_count(&graph->adj[vertex]);
}

int Graph_max_degree(Graph* graph){
  int max_degree = 0;
  for (int i = 0; i < graph->v; i++){
    int degree = Graph_degree_of_vertex(graph, i);
    if (max_degree < degree){
      max_degree = degree;
    }
  }
  return max_degree;
}

int Graph_average_degree(Graph* graph){
  return ((2 * graph->e)/graph->v);
}

void Graph_show(Graph* graph){
  printf("GRAPH: no of vertices: %d\n", graph->v);
  printf("GRAPH: no of edges: %d\n", graph->e);
  printf("-------------------------------------------------\n");
  printf("GRAPH: printing adjacency list for vertex\n");
  printf("-------------------------------------------------\n");
  for (int i = 0; i < graph->v; i++){
    printf("GRAPH: vertex %d: ", i);
    Bag_show(&graph->adj[i]);
  }
}

void Graph_destroy(Graph* graph){
  for (int i = 0; i < graph->v; i++){
    Bag_destroy(&graph->adj[i]);
  }
  Free(graph->adj);
  graph->v = 0;
  graph->e = 0;
}

/****************************************************************************
 * GRAPH_SEARCH_AND_PATH: It takes Graph object and does graph search for 
 * given source vertex and populates the data structure for path reachable 
 * from given source vertex.
 ***************************************************************************/
void Graph_path_init(Graph_path* gp, Graph* graph, int source_vertex){
  gp->source_vertex = source_vertex;

  gp->marked = (bool* )Malloc(sizeof(bool) * graph->v);
  for (int v = 0; v < graph->v; v++){
    gp->marked[v] = false;
  }
  gp->edge_to = (int* )Malloc(sizeof(int) * graph->v);
  for (int i = 0; i < graph->v; i++){
    gp->edge_to[i] = -1;
  }
  gp->count = 0;
  gp->graph = graph;
}

bool Graph_path_has_path_to(Graph_path* gp, int vertex){
  return gp->marked[vertex];
}

int Graph_path_count(Graph_path* gp){
  return gp->count;
}

void _Graph_path_depth_first_search(Graph_path* gp, int s){
  gp->marked[s] = true;
  for (Node* n = Bag_iterator_begin(&gp->graph->adj[s]); n != Bag_iterator_end(); n = Bag_iterator_next(n)){
    if (!gp->marked[n->data]){
      gp->edge_to[n->data] = s;
      gp->count += 1;
      _Graph_path_depth_first_search(gp, n->data);
    }
  }
}   

void _Graph_path_breath_first_search(Graph_path* gp, int s){
}


void Graph_path_search(Graph_path* gp, Search_method method){
  if (method == DFS){
    _Graph_path_depth_first_search(gp, gp->source_vertex);
  }
  else if (method == BFS){
    _Graph_path_breath_first_search(gp, gp->source_vertex);
  }
  else{
    printf("GRAPH_PATH: ERROR, invalid search method\n");
    exit(EXIT_FAILURE);
  }
}

void Graph_path_show_path(Graph_path* gp, int v){
  if (!gp->marked[v]) {
    printf("GRAPH PATH: WARNING, no path exist to %d\n", v);
    return;
  }
  FixStack st;
  FixStack_init(&st, gp->count);
  for (int x = v; x != gp->source_vertex; x = gp->edge_to[x]){
    FixStack_push(&st,x);
  }
  printf("%d to %d: %d", gp->source_vertex, v, gp->source_vertex);
  while (!FixStack_isEmpty(&st)){
    printf("--%d", FixStack_pop(&st));
  }
  printf("\n");
  FixStack_destroy(&st);
}

void Graph_path_destroy(Graph_path* gp){
  Free(gp->marked);
  Free(gp->edge_to);
  gp->count = 0;
  gp->source_vertex = 0;
  gp->graph = NULL;
}
