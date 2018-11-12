#include<iostream>
#include<iomanip>
using namespace std;

//-------------------

class node
          {
              public:
                        int distance, v;
          };  //end of class

//Creating an object of node type
node *n;//global object of class
//--------------------

void input(int routers);

void perform_sorting(int routers);

void calculate_shortest_path(int routers,int source_router);

void display(int routers);

//--------------------

int main()
            {     int routers;

                  cout << "\nPlease enter the number of routers: ";
                  cin >> routers;

                  int source_router = 0;


                  input(routers);
                  calculate_shortest_path(routers,source_router);
                  display(routers);

                  return 0;

            }     //end of main()

//----------------------
int* arr;               //global pointer
int size;               //global variable
int** matrix;           //global double pointer

void input(int routers)
              {


                  n = new node[routers];// two variables are associated distance and v ........object array
                  arr = new int[routers];

                  size = routers;

                  matrix = new int*[routers];

                  for(int i=0;i<routers;i++)
                            {
                                matrix[i] = new int[routers];
                            }

                  cout << "\nPlease enter the connections between the routers.";
                  cout << "\nEnter -1 if they are not connected";

                  for(int i=0;i<routers;i++)
                            {
                                for(int j=0;j<=i;j++)
                                            {
                                              if(i==j)
                                                      {
                                                        matrix[i][j] = 0;
                                                        continue;
                                                      }
                                              cout << "\nEnter distance from vertex "<<i<<" to vertex "<<j<<" : ";
                                              cin >> matrix[i][j];
                                              matrix[j][i]=matrix[i][j];
                                            }
                            }
                  cout << "\nThe following matrix has been formed according to the entered data.\n";
                  for(int i=0;i<routers;i++)
                              {
                                    for(int j=0;j<routers;j++)
                                          cout << matrix[i][j] << "  ";
                                    cout << endl;
                              }


                  return;

              }

//---------------------------------

void perform_sorting(int routers)
              {
		  cout << "\nIn sorting!!";
                  for(int i=0;i<routers;i++)
                            {
                                for(int j=0;j<routers;j++)
                                          {
                                              if(n[arr[i]].distance > n[arr[j]].distance)
                                                      {
                                                        int t = arr[i];
                                                        arr[i] = arr[j];
                                                        arr[j] = t;
                                                      }
                                          }
                            }
              }

//------------------------------------------

void calculate_shortest_path(int routers,int source_router)
              {
                    for(int i=0;i<routers;i++)
                              {
                                  n[i].distance = 9999;
                                  n[i].v = 0;
                                  arr[i] = i;
                              }
                    n[source_router].distance = 0;// 0 which is source router has distance 0 and rest has distance 9999
                    int k;

			//cout << "\nhello!";

		   
                //size=routers;
                    while(size>0)
                              {
                                perform_sorting(routers);
                                k = arr[--size];
                                n[k].v =1;      //to indicate that the particular router has been visited

                                for(int i=0;i<routers;i++)
                                        {
                                            if(i!=k && matrix[k][i]>0 && n[i].v==0)
                                                    {
                                                      if(n[i].distance > n[k].distance+matrix[k][i])
                                                              n[i].distance = n[k].distance+matrix[k][i];   //if the distance of ith router is greater than the sum of the distance of kth router and distance between kth and ith router
                                                    }
                                        }
                              }

              }

//--------------------------------------------

void display(int routers)
              {
                cout << "\n---------DISPLAYING THE SHORTEST PATHS-------------";

                for(int i=0;i<routers;i++)
                      cout << "\n ROUTER NO: "<<i<<" has a SHORTEST DISTANCE of "<<n[i].distance<<" from the source.";
                return;
              }

//--------------------------------------------
