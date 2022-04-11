#include <iostream>
#include <stdlib.h>
using namespace std;
#include <limits.h>
#include "dijkstra.h"



//print a priority queue elements
void print_pq (node * pq , int pos)
{
  if (pos == 0)
  {
    cout << "priority queue is empty" << endl;
  }
  else
  {
    for (int i = 0 ; i < pos ; i++)
    {
      cout << "(" << (pq+i)->vertex << " , " << (pq+i)->edge << ") ";
    }
    cout << endl;
  }
}

// add a node to the adjacency list
void add_node (node ** adj_list ,int from , int to , int edge)
{
  node * n = (node *) malloc (sizeof (node));
  n->edge = edge;
  n->vertex = to;
  n->next = *(adj_list+from);
  *(adj_list+from)= n;
}

//print an adjacency list
void print_adj_list (node ** adj_list , int n)
{
  for (int i = 0 ; i < n ; i ++)
  {
    cout << i << " : ";
    node * tmp = *(adj_list+i);
    
    while (tmp!=NULL)
    {
      cout << "(" << tmp->vertex << " , " << tmp->edge << ") ";
      tmp = tmp->next;
    }
    cout << endl;
  }
}


// set the values of the integer array to the num variable
void set_array (int size, int * arr , int num)
{
  for (int i =0 ; i < size ; i++)
  {
    *(arr+i) = num;
  }
}

// print the values of an integer array
void print_array (int size , int * arr)
{
  for (int i = 0 ; i < size ; i++)
  {
    cout << *(arr+i) << '\t';
  }
  cout << endl;
}

//find the number of the edges in the graph
int edge_num (node ** adj_list , int size)
{
  int num = 0;
  
  for (int i = 0 ; i < size ; i++)
  {
    node * tmp = *(adj_list+i);
    
    while (tmp != NULL)
    {
      num++;
      tmp = tmp->next;
    }
  }
  
  return num;
}

//heapify the priority queue
void min_heapify (node * pq , int index , int size)
{
  
  int left = index*2 +1;
  int right = index*2 + 2;
  
  
  
  int lowest ;
  node tmp;
  
  if (left < size && (pq+left)->edge < (pq+index)->edge)
  {
    lowest = left;
  }
  else
  {
    lowest = index;
  }
  
  if (right < size && (pq+right)->edge < (pq+lowest)->edge)
  {
    lowest = right;
  }
  if (lowest != index)
  {
    tmp = *(pq+index);
    *(pq+index) = *(pq+lowest);
    *(pq+lowest) = tmp;
    min_heapify (pq , lowest , size);
  }
}

//make a heap
void heap (node * pq , int size)
{
  int tmp = (size/2) - 1;
  for (int i = tmp ; i >= 0 ;i-- )
  {
    min_heapify (pq , i , size);
  }
}

// insert a node to the priority queue
void insert_to_pq (node * pq , int vertex , int edge , int * pos)
{
  (pq+(*pos))->edge = edge;
  (pq+(*pos))->vertex = vertex;
  
  (*pos)++;
  
  heap (pq, *pos);
}

// extract the node with the minimum value of the edge in the priority queue
node extract_min (node * pq , int * pos)
{
  node min;
  if (*pos == 0)
  {
    cout << "heap underflow" << endl;
  }
  else
  {
    min = *pq;
    *pq = *(pq+(*pos)-1);
    (*pos)--;
    min_heapify (pq , 0 , *pos);
  }
  return min;
}

// the dijkstara algorithm
void dijkstra (node ** adj_list , int n , int starting , int * dist , int * prev)
{
  int * vis = (int *) malloc (sizeof(int)* n);
  set_array (n , vis , 0); // to false
  
  
  *(dist+starting) = 0; // make the best distance to the starting point 0
  
  int n_edge = edge_num (adj_list , n); // the number of edges in the graph ; we'll use it as the size of the priority queue
  
  node pq [n_edge]; // a priority queue
  int pos = 0; // the priority queue is still empty
  //init_pq (pq, n_edge); // i think i don't need this ; maybe i need this to set .next to null but i'm not going to use it anyway sooo;
  
  insert_to_pq (pq , starting , 0 , &pos);
  
  while (pos != 0)
  {
    node next = extract_min (pq , &pos);
    vis[next.vertex] = 1;
    
    
    if (*(dist+(next.vertex)) < next.edge)
    {
      continue;
    }
    
    node * tmp = *(adj_list+(next.vertex));
    //cout << tmp->vertex << " , " << tmp->edge << endl;
    //return;
    
    while (tmp!=NULL)
    {
      if (vis[tmp->vertex] == 1)
      {
        continue;
      }
      int newdist = dist[next.vertex] + tmp->edge;
      if (newdist < dist[tmp->vertex])
      {
        prev[tmp->vertex] = next.vertex;
        dist[tmp->vertex] = newdist;
        insert_to_pq (pq , tmp->vertex , newdist , &pos);
      }
      
      tmp = tmp->next;
    }
  }
}



