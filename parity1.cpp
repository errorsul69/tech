#include<iostream>
using namespace std;
int main()
		{	
		    char* bits = new char [100];
		    int e=0;
			cout << "\nPlease input the bits in your data:  ";
					int size=0;
					char bit;
					for(int i=0;i<100;i++)
						{	cout << "\nEnter the Bit (2 to EXIT ): ";
							cin >> bit;
								if(bit!='0' && bit!='1')
								break;
								if(bit=='1')
								e++;
							bits[i]=bit;
							size++;
						}
						
						cout<<e<<endl;
			int parity;
					cout << "\nPlease select the parity by entering the appropriate choice number: ";
					cout << "\n1. ODD Parity";
					cout << "\n2. EVEN Parity";
					cout << "\n CHOICE: ";
					cin >>parity;
					switch(parity)
					{
						case 1:
							{
								if(e%2==1)
								bits[size]='0';
								else 
								bits[size]='1';
							}
							break;
							case 2:
							{
								if(e%2==1)
								bits[size]='1';
								else 
								bits[size]='0';
							}
							break;
					}
					
								cout<<bits;
							
				}
