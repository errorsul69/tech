//1011001
#include<iostream>
#include<cmath>
#include<cstring>
#include<math.h>
#include <cstdlib>
using namespace std;

int fn_power(int);
int main()
		{	char* bits = new char [100];
			cout << "\nPlease input the bits in your data:  ";
					int size=0;
					char bit;
					for(int i=0;i<100;i++)
						{	cout << "\nEnter the Bit (2 to EXIT ): ";
							cin >> bit;
								if(bit!='0' && bit!='1')
								break;
							bits[i]=bit;
							size++;
						}
			int parity;
					cout << "\nPlease select the parity by entering the appropriate choice number: ";
					cout << "\n1. ODD Parity";
					cout << "\n2. EVEN Parity";
					cout << "\n CHOICE: ";
					cin >>parity;
					if(parity!=1 && parity!=2)
						{	cout << "\nInappropriate choice entered !!!! Terminating";
							return 0;
						}

			cout << "\nEntered Dataword:  "<<bits;
			int r=0;

			while(1)
					{	if( pow(2,r) >= size + r + 1 )
						break;

						r++;
					}
					
			char* codeword = new char [size+r];
			cout << "\nNumber of Redundant Bits Required:" << r ;
			int counter = 0;
			int i = 1;
			int bits_count = 0;

			while(bits_count<size)
					{	if ( i == pow(2,counter) )
							{	codeword[i-1] = 'X';
								counter++;
							}
						else
							{	codeword[i-1] = bits[bits_count];
								bits_count++;
							}
						i++;
					}
			cout << "\nTemporary codeword: "<<codeword<<endl;
			//i = 0;
			int value,inpos;
			counter = 0;
			int* cb_count = new int [r];//to hold check_bits
			
			for(int k=0;k<r;k++)
				cb_count[k]=0;

			for(i=0;i<size+r;i++)
				{	if( codeword[i] == '1' )
						{	value = i+1;//array stores the value at (index-1) where index is actual index --->char *codeword[size+r] suppose at index=2 but value at 3
							for ( int j = value-1;j>=0;j-- )//value-1 is same as i
								{	if(codeword[j] == 'X')
										{
                      inpos=fn_power(j+1);//=======================returns which power of 2 does X indicate
                      cb_count[inpos]++;//now use of that power incremented
											value-= (j+1);     //pow(2,j); minus that from value 
											j=value;//now traverse for what value is left
										}
      //if ((value ==1) || (value ==2)) value+=1;  //to access first /second bit
								}
						}
				}

			cout<<"Check Bits:" << endl;
			for(int k=0;k<r;k++)
				cout <<"["<<k<<"] ="<< cb_count[k] << endl;

			i = 0;

				switch(parity)
							{	case 1:
									cout << "\nYou chose odd parity. ";
									while(i<r)
										{	if(cb_count[i]%2==0)
												codeword[(int)pow(2,i)-1]='1';
											else
												codeword[(int)pow(2,i)-1]='0';
											i++;
										}
									break;
								case 2:
									cout << "\nYou chose even parity. ";
									while(i<r)
										{	if(cb_count[i]%2==0)
												codeword[(int)pow(2,i)-1]='0';
											else
												codeword[(int)pow(2,i)-1]='1';
											i++;
										}
									break;
							}
				cout << "\nThe codeword comprising of the information bits and the check bits is as follows: "<<codeword << endl;
				int index=rand()%size;
				char *ecode=new char[size+r];
				for (i=0;i<size+r;i++)
				{
					ecode[i]=codeword[i];
				}
				if (ecode[index]=='1')
				ecode[index]='0';
				else
				ecode[index]='1';
				cout <<"Error at Index: " << index << endl;
				cout <<"Incorrect Codeword: "<<ecode <<endl;
				cout <<"Correct Codeword: " <<codeword  <<endl;
				return 0;
		}






int fn_power(int x)
{
   int i=0;
   while (pow(2,i) < x)
      i++;
    return i;

}
