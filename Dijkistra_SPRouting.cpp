#include<iostream>
#include<iomanip>
using namespace std;
int n,source;
int **adj;
class vertex{
	public:
	int dist; 		//distance from source;
	int visited; 
};
vertex *v;
int *arr;
int array_size;
void input(){
	cout<<"Enter the number of vertices in the graph ::\t";
	cin>>n;
	v=new vertex[n];
	arr=new int[n];
	array_size=n;
	adj=new int*[n];
	for(int i=0 ; i<n; i++){
		adj[i]=new int[n];
	}
	cout<<"\nEnter the Adjacency Matrix...(-1 if not connected)";
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(i==j){
				adj[i][j]=0;
				continue;
			}
			cout<<"\nEnter Distance From vertex "<<i<<" to "<<j<<" ::\t";
			cin>>adj[i][j];
			adj[j][i]=adj[i][j];
		}
	}
	cout<<"\n\n==>> Entered Adjacency Matrix\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<setw(3)<<"("<<adj[i][j]<<")";
		}
		cout<<endl;
	}
	cout<<"\nEnter the source Vertex::";
	cin>>source;
}

void sort(){
	for(int p=0;p<n;p++){
		for(int q=0;q<n;q++){
	 		if(v[arr[p]].dist>v[arr[q]].dist){
	 			int temp=arr[p];
	 			arr[p]=arr[q];
	 			arr[q]=temp;
	 		}
		}
	}
}

void FindShortestPath(){
	for(int i=0; i<n; i++){
		v[i].dist=99999; 
		v[i].visited = 0;
		arr[i]=i;
	}
	v[source].dist=0;
	int k;
	while(array_size>0){
		sort();
		k=arr[array_size--];
		v[k].visited=1;						//mark this vertex as visited
		for(int i=0 ; i <n; i++){
			if(i!=k && adj[k][i]>0 && v[i].visited==0){
				if(v[i].dist>v[k].dist + adj[k][i]){
					v[i].dist=v[k].dist + adj[k][i];
				}
			}
		}	
	}
}

void result(){
	cout<<"\n<<== SHORTEST PATH ==>>\n";
	for(int i=0;i<n;i++){
		cout <<"\n==>> Vertex no. " <<i<< " Shortest distance from Source "<<source<<"  is ::\t"<< v[i].dist;
	}
}
int main(){
	input();
	FindShortestPath();
	result();
	return 0;	
}
