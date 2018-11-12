#include<iostream>
using namespace std;

//------------------------  SENDER'S END  -------------------------------

class Sender
          { 	//0 denotes no wait
	     
	     

	     public:

		void get_data();
		void make_frame();
		void send_frame();
		void go_on_hold();
		void ack_arrives(int x,int n);
		
	  };						//end of class

void Sender :: get_data()
	  {	
		cout << "\nSENDER:Data ready to be converted to frame.\n-----";
		return;
	  } 
void Sender :: make_frame()
	  {	
		cout << "\nSENDER:Frame prepared.\n----- ";
		return;
	  }
void Sender :: send_frame()
	  {
		cout << "\nSENDER:Frame sent .\n-----";
		return;
	  }
void Sender :: go_on_hold()
	  {
		cout << "\nSENDER:On hold.\n-----";
					//sender waits for acknowledgement
		return;
	  }
void Sender :: ack_arrives(int x,int n)
	  {	if(x>=n)
		{	cout << "\nSENDER:Acknowledgement received.";
			return;
		}
		cout << "\nSENDER:Acknowledgement received.";
					//acknowledgement has arrived
		cout << "\nSENDER:Initiating process for sending the next frame.\n-----";
		return;
	  }

	
//---------------------------------------------------------------------------------------------------------------------------------------------

class Receiver
	{	public:

		void get_frame();
		void get_data_from_frame();
		void generate_ack(int x,int n);
		void send_ack();
		void send_data_to_NL();
	};				//end of class

void Receiver :: get_frame()
	{	cout << "\nRECEIVER:Frame received.\n-----";
		return;
	}
void Receiver :: get_data_from_frame()
	{	cout << "\nRECEIVER:Data retrieved from frame.\n-----";
		return;
	}
void Receiver :: generate_ack(int x,int n)
	{	if(x>=n)
		return;
		cout << "\nRECEIVER:Acknowledgement generated for frame number "<<x+1<<"\n----";
		return;
	}
void Receiver :: send_ack()
	{	
		cout << "\nRECEIVER:Acknowledgement Successfully sent.\n-----";
		return;
	}
void Receiver :: send_data_to_NL()
	{	cout << "\nRECEIVER:Data sent to Network Layer.\n-----";
		return;
	}

//---------------------------------------------------------------------------------------------------------------------------------------------

int main()
		{
			int i = 0;	//assuming that 3 frames of data is to be sent
			Sender s;
			Receiver r;
			int n;
            cout<<"Enter number of frames to be send";
            cin>>n;
			do
				{	cout << "\nFRAME: "<<i+1;
					s.get_data();
					s.make_frame();
					s.send_frame();
					s.go_on_hold();
					

					r.get_frame();
					r.get_data_from_frame();
					r.send_data_to_NL();
					r.generate_ack(i+1,n);
					r.send_ack();
					
					
					s.ack_arrives(i+1,n);	//data received successfully at receiver's end
					cout << "\n------------------------------";

					i++;
				
				}while(i<n );
			return 0;
		}

//---------------------------------------------------------------------------------------------------------------------------------------------
			
			
					
