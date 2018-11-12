/* PROGRAM TO IMPLEMENT STOP AND WAIT PROTOCOL FOR A NOISY CHANNEL */

#include<iostream>
#include<cstdlib>
#include<unistd.h>
using namespace std;

//-------------------- PROTOTYPES ---------------------

void sender_side(int* arr, int n);    //for the processing on the sender's side
int receiver_side(int seq,int v);     //for the processing on the receiver's side

//-------------------- MAIN FUNCTION -------------------

int main()
{
  int frame_count;

  cout<<"\nPlease input the number of frames : ";
  cin>>frame_count;

  int* arr = new int[frame_count];

  for(int i=0;i<frame_count;i++)
  {
      if(i % 2==0)
          arr[i]=1;
      else
          arr[i]=0;
  }


    sender_side(arr,frame_count);
    return 0;
}

//-------------------------- FOR THE SENDER'S SIDE ------------------------

void sender_side(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {

     	cout<<"\n\nSENDER: Sending frame number :: "<<i<<" with a bit value "<< arr[i];

        int ack = receiver_side(i,arr[i]);
        while(ack==i)
		{
	        	cout<<"\n\nSENDER: Resending frame number "<<i<<" with a bit value "<< arr[i];
	     		  ack = receiver_side(i,arr[i]);
		}
  }     // end of for loop

	cout<<"\n\n"<<n<<" SENDER: Packets have been successfully sent!";
}

//-------------------------- FOR THE RECEIVER'S SIDE ----------------------

int receiver_side(int seq, int v)
{

    int x=rand()%10;
    int value;

    if(x<5)
        {
            cout<<"\n\nRECEIVER: Received frame number :: "<<seq<<" with a bit value "<<v;
            value = seq + 1;
            cout<<"\n\nRECEIVER: ACKNOWLEDGMENT "<<value<<" sending for a bit value "<<!v;
        }

    else if(x > 5 && x < 7)
      {
            cout<<"\n\nRECEIVER: Frame lost during transmission";
            cout<<"\n\nRECEIVER: Timer Timed Out!";
            value = seq;
      }

    else
      {
            cout<<"\n\nRECEIVER: Acknowledgement Lost during transmission!!";
            cout<<"\n\nRECEIVER: Timer Timed Out!!!";
            value = seq;
      }
    return value;
}

//---------------------------------------------
