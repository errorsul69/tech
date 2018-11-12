#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
using namespace std;
class simple
{
	public:
		void ready_data();
		void send_data();
		
		void receive_data();
		void n_layer();	
};
void simple::ready_data()
{
	cout << "Data Ready for Transmission" << endl;
}
void simple::send_data()
{
	cout<<"Data send to Receiver" << endl;
}
void simple::receive_data()
{
	cout <<"\t\tData received by Receiver"<< endl;
}
void simple::n_layer()
{
	cout <<"\t\tData send to network layer" << endl;
}
int main()
{
	cout <<"Considering 10 frames" << endl;
	simple s;
	int i=1;
	int x,z,y;
	z=rand()%10;
	char c;
	i=0;
	while (i<10)
	{
		z=rand()%10;
		x=0;
		while (x<z)
		{
		cout << "--------------------" <<endl;	
		cout << "Send "<<i++ << endl;
		s.ready_data();
		s.send_data();
	//	cout << "--------------------" <<endl;
		x++;
		}
		i=i-x;//frame send already
		x=0;
		while (x<z)
		{
			cout << "\t\tReceived " << i++ << endl;
			s.receive_data();
		    s.n_layer();
		    cout << "\t\t--------------------" <<endl;
		    x++;
		}
		if (i<10){
		
		cout << "Want to continue (y) ::";
		cin >> c;
		cout << endl;
		if (c!='y')
		break;}
		
	}
		
	

	cout << "Terminated" <<endl;

	return 0;
}
