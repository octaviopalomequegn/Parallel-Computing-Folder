#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 500
#define INFINITE INT_MAX
typedef int bool;
#define true 1
#define false 0


void dijkstra(int G[MAX][MAX],int n,int startnode);
void dijkstra2();
int printSolution(int dist[]) ;

int main(){

	dijkstra2();

	return 0;

}

void dijkstra(int G[MAX][MAX],int n,int startnode){

}

int minDistance(int resulting[], bool visited[]){ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < MAX; v++) 
		if (visited[v] == false && resulting[v] <= min) 
			min = resulting[v], min_index = v; 

	return min_index; 
} 

int printSolution(int dist[]) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < MAX; i++) 
		printf("%d --> %d\n", i, dist[i]); 
} 

void matrixFill(int n, int(*m)[n]){
	int result[n][n];
	srand(time(NULL));

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i != j){
				m[i][j] = rand();
			}
		}
	}
}

void dijkstra2(){
	
	int costs[MAX][MAX];
	matrixFill(MAX,costs);
	int resulting[MAX];

	//Print Matrix
	/*for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			printf("%d ",costs[i][j]);
		}
		printf("\n" );
	}*/
	bool visited[MAX];

	clock_t begin_clock = clock();

	for (int i = 0; i < MAX; i++){
		resulting[i] = INT_MAX;
		visited[i] = false;
	}
	//set the resulting[0][0] node as 0
	resulting[0] = 0;
	
	
	//Itera desde el primer nodo hasta el ultimo, 
	for (int i = 0; i < MAX-1; i++){
		int min = minDistance(resulting, visited);
		visited[min] = true;
		for (int j = 0; j < MAX; j++){
			if(!visited[j] && costs[min][j] && resulting[min] != INT_MAX &&  resulting[min] + costs[min][j] < resulting[j]){
				resulting[j] = resulting[min] + costs[min][j];
			}
		}
	}

	clock_t end_clock = clock();
	double time_spent = ((double)(end_clock - begin_clock))/ CLK_TCK;
	printSolution(resulting);
	printf("%s Ya estoy aqui\n");
	printf("%f Tiempo inicio: \n", (double)begin_clock );
	printf("%f Tiempo final: \n", (double)end_clock );
	printf("%f Tiempo \n", time_spent);
	

}