#include <iostream>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int numVertices = 0;
  int numEdges = 0;
  string a;
   public:
   //Is empty check
   void isEmpty(){
       if (numVertices == 0)
       cout<<"true\n";
       else
       cout<<"false\n";
   }
  // Initialize the matrix to zero
 void graph (int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }
   

   // Add Vertex
   void addVertex(int i){
      numVertices++;
      graph(numVertices);
  }
   
   // Remove Vertex
   void removeVertex(int i){
      numVertices--;
      graph(numVertices);
      
  }
  
  // Number of vertices
  void numVertex(){
      cout<<"The number of Vertex are "<<numVertices<<"\n";
  }
 
  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    if (isDirected() == false)
    {adjMatrix[j][i] = true;}
    numEdges=numEdges+1; 
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    if (isDirected() == false)
    adjMatrix[j][i] = false;
    numEdges=numEdges-1; 
  }

  // Number of edges
  void numEdge(){
     cout<<"The number of edges are "<<numEdges<<"\n";
  }

  // Print the martix
  void Matrix() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
  
  void direction(string n){
        a = n;
  }

  int isDirected(){
   if (a == "d")
   {return true;}
   else
   {return false;}
 }

int indegree(int k)
{
  int count=0;
  if(k > numVertices)
  {
    cout <<"Vertex doesnt exist"<<"\n";
  }
  else
  {
    for(int i=0; i<numVertices; ++i)
    {
      if(adjMatrix[i][k] == true)
      {
        count++;
      }
    }
  }
  return count;
} 

int outdegree(int k)
{
  int count=0;
  if(k > numVertices)
  {
    cout <<"Vertex doesnt exist"<<"\n";
  }
  for(int i=0; i<numVertices; ++i)
  {
    if(adjMatrix[k][i] == true)
    {
      count++;
    }
  }
  return count;
}

int degree(int k)
{
  int count = indegree(k) + outdegree(k);
  return count; 
}

};

 

int main() 
{
  Graph g;
  string n;
  cout<<"Please enter d for a Directed graph or any other key for undirected\n";
  cin>>n;
  g.direction(n);
  g.isEmpty();
  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addVertex(5);
  g.numVertex();
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.numEdge();
  g.numVertex();
  g.removeEdge(1,2);
  g.numEdge();
  g.Matrix();
  cout<<g.outdegree(2)<<"\n"; 
  g.isEmpty();
}
