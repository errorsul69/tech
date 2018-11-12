#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int Xor(int x,int y){
	if(x==y)
		return 0;
	else
		return 1;
}
int main(){
	int d1[40],d2[40],q[20],r[10],rem[10],m,n,i,j,size;
	int ch,index1,index2,b_start,len;
	do{
		cout<<"\n==>> DATAWORD_MENU <<=="
        	<<"\n1).Usesr generated"
        	<<"\n2).System generated"
        	<<"\n3).Exit"
        	<<"\n\nEnter your choice ::\t";
    	cin>>ch;
    	if(ch==3){
    		cout<<"\nEXIT!!!";
    		exit(0);
		}
    	cout<<"Enter number of bits of DataWord ::\t";
    	cin>>m;
    	while(m<2||m>40){
        	cout<<"\nIncorrect input";
        	cout<<"\nEnter no.of bits for dividend (>2&&<40) ::";
        	cin>>m;
   	 	}
    	switch(ch){
        	case 1: cout<<"\nEnter the DataWord ::\n";
        			d1[0]=1;
        			cout<<d1[0]<<endl;
                	for(i=1;i<m-1;i++){
                    	cin>>d1[i];
                    	while(d1[i]!=0&&d1[i]!=1){
                        	cout<<"\nPlease enter 0 or 1 only\n";
                        	cin>>d1[i];
                    	}
                	}
                	d1[m-1]=1;
                	cout<<d1[m-1]<<endl;
                	break;
        	case 2: for(int i=1;i<m-1;i++){
                    	srand(time(NULL)+i);
                    	d1[i]=rand()%2;
                	}
                	d1[0]=d1[m-1]=1;
               	 	break;
        	default:cout<<"\nWRONG CHOICE ENTERED!!!\n";
                    exit(0);
    	}
    	cout<<"\nDATAWORD :: \t";
    	for(i=0;i<m;i++)
        	cout<<d1[i];
    	cout<<"\n\n==>> GENERATOR_MENU <<=="
    		<<"\n1). 1-bit(to show it doesn't affect)"
    		<<"\n2). User-Generated"
    		<<"\n3). System-Generated"
    		<<"\n4). CRC-8"
    		<<"\n5). CRC-16"
    		<<"\n\n==>> Enter your choice ::\t";
    	cin>>ch;
    	switch(ch){
    		case 1:	{
    					cout<<"\nNumber of bits for Generator ::\t1";
						n=1;
						cout<<"\nGenerator Polynomial :: 1\n";
						int d2[]={1};
					}
    				break;
    		case 2:	{
    					do{
    						cout<<"\nEnter the number of bits for Generator ::\t";
    						cin>>n;
    						if(n<3){
    							cout<<"\nNumber of bits for Generator should be(>2)!!!\n";
							}
						}while(n<3);
    					cout<<"\nEnter Generator Polynomial ::\n";
    					for(i=1;i<n-1;i++){
                    		cin>>d2[i];
                    		while(d2[i]!=0&&d2[i]!=1){
                        		cout<<"\nPlease enter 0 or 1 only\n";
                        		cin>>d2[i];
                    		}
                    	}
                    	cout<<"\nGenerator Polynomial :: \t";
                    	d2[0]=1;d2[n-1]=1;
						for(i=0;i<n;i++)
							cout<<d2[i];
					}
					break;
    		case 3:	{
    					do{
    						cout<<"\nEnter the number of bits for Generator ::\t";
    						cin>>n;
    						if(n<3){
    							cout<<"\nNumber of bits for Generator should be(>2)!!!\n";
							}
						}while(n<3);
						d2[0]=1;d2[n-1]=1;
    					for(i=1;i<n-1;i++){
                    		srand(time(NULL)+i);
                    		d2[i]=rand()%2;
                    	}
                    	cout<<"\nGenerator Polynomial :: \t";
						for(i=0;i<n;i++)
							cout<<d2[i];
					}
    				break;
    		case 4:	{
						cout<<"\nNumber of bits for Generator ::\t9";
						n=9;
						cout<<"\nGenerator Polynomial :: 100000111\n";
						int d2[]={1,0,0,0,0,0,1,1,1};
					}
    				break;
    		case 5:	{
    					cout<<"\nNumber of bits for Generator ::\t17";
						n=17;
						cout<<"\nGenerator Polynomial :: 10001000000100001\n";
						int d2[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
					}
    				break;
    		default:cout<<"\nWRONG CHOICE ENTERED!!!";
					return 1;
    	
		}
		for(i=0;i<n-1;i++){
			d1[m+i]=0;
		}
		size=m+n-1;
		cout<<"\nIntial CodeWord ::\t";
		for(i=0;i<size;i++){
			cout<<d1[i];
		}
		int k=n-1;
    	for(i=0;i<n;i++)
       		r[i]=d1[i];
		for(i=0;i<m;i++){
			if(r[i]==1){
				for(j=n-1;j>=0;j--){
				  	r[i+j]=Xor(r[i+j],d2[j]);
				}
				q[i]=1;
			}
			else{
				q[i]=0;
			}
			k++;
			if(k<size)
				r[k]=d1[k];
		}
		cout<<"\n==>> Remainder ::\t";
		for(j=m,i=0;j<size;j++,i++){
			rem[i]=r[j];
			cout<<rem[i];
		}
		for(i=0;i<n-1;i++){
			d1[m+i]=rem[i];
		}
		cout<<"\nFinal CodeWord ::\t";
		for(i=0;i<size;i++){
			cout<<d1[i];
		}
		cout<<"\n\n==>> ERROR_MENU <<=="
			<<"\n1). 1-Bit Error"
			<<"\n2). 2-Bit Error (isolated)"
			<<"\n3). Burst Error"
			<<"\n\n ==>> Enter your choice ::\t";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n==>>Random Error At Bit :: \t";
					srand(time(NULL));
					index1 = rand()%size+1;			//generating random Error
					cout<<index1;
					d1[index1-1]=1-d1[index1-1];
					break;
			case 2:	cout<<"\n==>>Random Error At Bits :: \t";
					srand(time(NULL));
					index1 = rand()%size+1;			//generating random Error
					cout<<index1<<"  ";
					do{
						index2=rand()%size+1;
					}while(index2==index1||index2==index1+1||index2==index1-1);
					cout<<index2;
					d1[index1-1]=1-d1[index1-1];
					d1[index2-1]=1-d1[index2-1];
					break;
			case 3:	do{
						cout<<"\nEnter the Start Location ::\t";
						cin>>b_start;
						cout<<"\nEnter the Length of the Error ::\t";
						cin>>len;
						if(b_start<0||len<0||b_start+len>=size){
							cout<<"WRONG INPUT!!!!";
						}
					}while(b_start<0||len<0||b_start+len>=size);
					d1[b_start-1]=1-d1[b_start-1];
					d1[b_start+len-2]=1-d1[b_start+len-2];
					for(i=b_start;i<b_start+len-1;i++){
            	        srand(time(NULL)+i);
                	    d1[i]=rand()%2;
               		}
               		ch=2;
					break;
			default:cout<<"\nWRONG CHOICE ENTERED!!!";
					return 1;	
		}
		cout<<"\nRecieved CodeWord ::\t";
		for(i=0;i<size;i++)
			cout<<d1[i];
		//again receiver end's divide
		k=n-1;
    	for(i=0;i<n;i++)
    	    r[i]=d1[i];
		for(i=0;i<m;i++){
			if(r[i]==1){
				for(j=n-1;j>=0;j--){
				  	r[i+j]=Xor(r[i+j],d2[j]);
				}
				q[i]=1;
			}
			else{
				q[i]=0;
			}
			k++;
			if(k<size)
			r[k]=d1[k];
		}
		bool flag=true;
		cout<<"\n==>> Remainder ::\t";
		for(j=m,i=0;j<size;j++,i++){
			rem[i]=r[j];
			cout<<rem[i];
			if(rem[i]==1){
				flag=false;
			}
		}
		if(flag)
			cout<<"\n\n==>> NO ERROR DETECTED !!!\n";
		else
			cout<<"\n\n==>>	ERROR DETECTED !!!\n";	
	}while(ch!=3);
	return 0;
}
