#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

const int TOT_FRAMES=500;
const int FRAMES_SEND=16;

class gobkn{
	private:
		int fr_send_at_instance;
		int arr[TOT_FRAMES];
  		int arr1[FRAMES_SEND];
  		int sw;	//sender's window start
  		int rw; //reciever's window start
	public:
  		gobkn();
  		void input();
  		void sender(int m);
		void reciever(int m);
};
gobkn :: gobkn(){
	sw = 0;
	rw = 0;
}
void gobkn :: input(){
 	int n;  // no of bits for the frame
 	int m;  // no of frames from n bits
	do{
		cout <<"==>> Enter the number of bits for the Sequence Number ::\t";
 		cin >> n;
 		if(n>5){
 			cout<<"(ERROR :: Sequence Number Must Be less than 6)\n";
		}
	}while(n>5);
	m = pow (2 , n);
	int t = 0;
	fr_send_at_instance=m-1;
	cout<<"\n==>> Number of frames sent in one go ::\t"<<fr_send_at_instance<<"\n\n";
	for (int i = 0 ; i < TOT_FRAMES ; i++){
		arr[i] = t;
		t = (t + 1) % m; //initializing arr with 0-2^n-1 multiple times
	}
	sender(m);
}

void gobkn :: sender(int m){
	cout<<"\n<<== SENDER ==>>\n";
	int j = 0;
	for (int i = sw ; i < sw + fr_send_at_instance ; i++){
		arr1[j++] = arr[i];//sender start to total frames
	}
	for (int i = 0 ; i < j ; i++){
		cout << "SENDER : Frame " <<arr1[i]<<" SENT!!!\n";		
	}
	reciever (m);
}

void gobkn :: reciever(int m){
	cout<<"\n\t\t\t\t<<== RECIEVER ==>>\n";
	time_t t;
	srand((unsigned) time(&t));
	int f = rand() % fr_send_at_instance;

   // if = 4 frame is discarded 
   // else they are correctly recieved

	if (f != 4){
		int i=0;
		for (i = 0;i<fr_send_at_instance;i++){
			if (rw == arr1[i]){
				cout << "\t\t\t\tRECIEVER : Frame " << arr1[i] << " recieved correctly\n";
				rw = (rw + 1) % m;
			}else{
				cout << "\t\t\t\tRECIEVER : Duplicate frame " << arr1[i] << " discarded\n";
			}
		}
		f = rand() % fr_send_at_instance;

		// if f belongs to second half then
		//     all ack after this (incl this one) lost
		// else
		//     all recieved
   
		if (f>fr_send_at_instance/2){
			cout << "\t\t\t\t(Acknowledgement " << arr1[f] << " & all after this lost)\n";
			cout << "\t\t\t\t (SENDER TIMEOUTS --> RESEND THE FRAME)\n";
			sw = arr1[f];
		}else{
			sw = (sw + fr_send_at_instance) % m;
			cout << "\t\t\t\t(Acknowledgement " << arr[rw] << " is Sent!!!)\n";
		}
	}else{
		int f1 = rand() % fr_send_at_instance;

		// f1 gives index of the frame being lost
   		
		for (int i = 0 ; i < f1 ; i++){
			if (rw == arr1[i]){
				cout << "\t\t\t\tRECIEVER : Frame " << arr1[i] << " recieved correctly\n";
				rw = (rw + 1) % m;
			}else{
				cout << "\t\t\t\tRECIEVER : Duplicate frame " << arr1[i] << " discarded\n";
			}
  		}
		f = rand() % 2;
		
    	// f == 0 frame damaged
    	// else frame lost

		if (f == 0){
			cout<<"\t\t\t\tRECIEVER : Frame " << arr1[f1] << " damaged\n";
			cout<<"\n\t\t\t\tRECIEVER : Damaged frame " << arr1[f1] << " discarded\n\n";
		}
		else
			cout << "\t\t\t\t            (Frame " << arr1[f1] << " lost)\n";
		for (int i = f1 + 1 ; i < fr_send_at_instance ; i++)
			cout << "\t\t\t\tRECIEVER : Frame " << arr1[i] << " discarded\n";
		cout << "\t\t\t\t (SENDER TIMEOUTS --> RESEND THE FRAME)\n";
		sw = arr1[f1];
	}
	char ch;
	cout<<"\n==>> Do you want to continue(y/n) ::\t";
	cin>>ch;
	if(ch=='y')
		sender(m);
	else
		exit(0);
}
int main(){
	gobkn obj;
	obj.input();
	return 0;
}
