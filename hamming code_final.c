#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;


int pow(int i)  //function to calculate power of 2 of a number
{
	int m=1;
	for(int k=0;k<i;k++)
	{
		m*=2;		
	}
	return m;
}

char pbit(int p,int n,char newstr[20])  //function to calculate the redundant bit value 
{
	int count=0;
	int i=p-1;
	while(i<n)   //using while loop to stay in limit of the string
	{
		for(int j=i;j<i+p;j++)   //for loop to find the position to be taken for calculation of redundant bit
		{
			if(newstr[j]=='1')
			{
				count++;
			}
		}
		i+=p*2;
	}
	if(count%2==0)   //using if else to return the value of the redundant bit
	{
		return '0';
	}
	else
	{
		return '1';
	}
}


void transferData(char String[20],int a)   //function to find the data to be transfer
{
	int n=strlen(String);
	char newstr[n+a];    //declaring new string with length including original string length and no. of redundant bit
	int j=0;
	int k=0;
	for(int i=0;i<n+a;i++)  //for loop to find the position of the redundant bits
	{
		if(i==pow(k)-1)
		{
			k++;
			newstr[i]='r';
		}
		else
		{
			newstr[i]=String[j];
			j++;
		}
	}
	printf("\n\nThe data to be sent as hamming code: ");  //printing data with redundant bit position
	for(int i=0;i<n+a;i++)
	{
		printf("%c",newstr[i]);
	}
	printf("\t\tHere 'r' signifies redundant bit\n");
	for(int i=0;i<a;i++)   //for loop to find the data values of each redundant bit
	{
		int p=pow(i);
		char b= pbit(p,n+a,newstr);
		printf("\nThe %d redundant bit: %c\n",i+1,b);  //printing value of redundant bit
		newstr[p-1]=b;
	}
	printf("\n\nThe final data to be sent: ");  //printing the final data
	for(int i=0;i<n+a;i++)
	{
		printf("%c",newstr[i]);
	}
}



int main()
{
	char string[20];
	int i,j,k;
	printf("Enter the data to be transmitted: ");
	scanf("%[^\n]%*c",string);      //getting the input string from user
	int n=strlen(string);     //using strlen functiion to get length of the string
	int a;
	bool f=false;
	i=0;
	while(pow(i)<n+i+1)   //usinh while loop to find the number of redundant bits
	{	
		i++;	
	}
	a=i;      //no. of redundant bits

	printf("\n\nReceived data: ");    //printing the data received
	for(i=0;i<n;i++)
	{
		printf("%c",string[i]);
	}
	transferData(string,a);   //calling transfer data function to find the data to be transferred
}
