// this is the used function


#include <Rcpp.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

using namespace Rcpp;

//' dijkstra algorithm
//' @param adj_matrix the adjacency matrix
//' @param starting the starting vertex we want to run the algorithm from
//' @return a 2*n matrix (first row : the best distance from the starting vertex vector , second row : the previous vertex vector)
// [[Rcpp::export]]
NumericMatrix dijkstraAlgorithm (NumericMatrix adj_matrix , int starting)
{
  int n = adj_matrix.nrow(); // number of rows of the adjacency matrix
  int c = adj_matrix.ncol(); // number of colomns of the adjacency matrix
  
  
  if (n != c)
  {
    std::cout << "matrix not square";
    return -1;
  }
  
  // making an array of node pointers with size n
  node ** adj_list = (node**) malloc (sizeof(node*)*n);
  for (int i = 0 ; i < n ; i++) // making every pointer in the array equal NULL
  {
    *(adj_list+i) = NULL;
  }
  
  // converting the adjacency matrix to the adjacency list
  for (int i = 0; i < n ; i++)
  {
    for (int j = 0 ; j < n ; j++)
    {
      if (adj_matrix(i , j) != 0)
      {
        add_node(adj_list , i , j , adj_matrix (i , j));
      }
    }
  }
  
  int * dist = (int *) malloc (sizeof(int)*n); // an array that stores the best distance from the starting vertex to all the other vertices
  int * prev = (int *) malloc (sizeof(int)*n); // an array that stores the previous vertex that lead to this vertex
  set_array (n , dist , INT_MAX);
  set_array (n , prev , -1);
  
  
  dijkstra(adj_list , n , starting ,dist ,  prev); //  the function that do the calculations
  
  
  // convert the dist and prev to a matrix
  NumericMatrix values (2 , n);
  
  for (int i = 0 ; i < n ; i ++)
  {
    values (0 , i) = dist[i];
    values (1 , i) = prev[i];
  }
  
  return (values);
}
