typedef struct node
{
  int vertex;
  int edge;
  struct node * next;
}node;

void print_pq (node * pq , int pos);
void add_node (node ** adj_list ,int from , int to , int edge);
void print_adj_list (node ** adj_list , int n);
void set_array (int size, int * arr , int num);
void print_array (int size , int * arr);
int edge_num (node ** adj_list , int size);
void min_heapify (node * pq , int index , int size);
void heap (node * pq , int size);
void insert_to_pq (node * pq , int vertex , int edge , int * pos);
node extract_min (node * pq , int * pos);
void dijkstra (node ** adj_list , int n , int starting , int * dist , int * prev);