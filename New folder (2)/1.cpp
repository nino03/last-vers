#include <stdio.h>

int findprime(__int64 x)
{
	if(x%2!=0)
	{
			for(int i=3;i<x/2;i+=2)
			{
				if(x%i==0)
				return 1;
			}	
	}
	else
	return 1;

return 0;
}

void main()
{

int x=0;
x=findprime(101);
printf("%d",x);

}