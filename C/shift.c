//Prog to shift elements of array n times

#include<stdio.h>

void main()
{	
	//create variable size array
	int size_arr;
	printf("Enter size of array : ");
	scanf("%d",&size_arr);
	int arr[size_arr];
	//create few working variables
	int shift=0,rem,quo,buff;
	printf("\n Enter array elements : ");
	//input elements of array
	for (int i=0;i<size_arr;i++)
	{
			scanf("%d",&arr[i]);
	}
	//get elements to shift, negative means left shift, positive means right shift, 0 means no shift
	printf("\n enter a proper shift number , negative=left, positive=right: ");
	scanf("%d",&shift);
	//if number is bigger than number of elements of array, then simply shift,else to increase speed of 
	//program ,integer multiples of array size will yield same array, so skip hose iterations, and directly execute
	//leftover iterations i.e if array size is 5 and shift is 6, then only 1 right shift in net is needed, and so on.
	rem=size_arr%shift;
	quo=size_arr/shift;
	//for shift =0 menas no shift
	if (shift==0)
	{
		printf("\n shifted array is : \n");
		for(int i=0; i<size_arr;i++)
		{
			printf("%d ",arr[i]);
		}
	}
	//for right shift by n elemnts
	if (shift>0)
	{
		printf("\n shifted array is : \n");
		
		if(quo>1)
		{
			for(int i=0;i<rem;i++)	
			{
				buff=arr[(size_arr-1)];
				for(int j=0;j<size_arr;j++)
				{
					arr[(size_arr-j-1)]=arr[(size_arr-j-2)];
				}
				arr[0]=buff;
			}
		} 
		
		if(quo<1)
		{
			for(int i=0;i<shift;i++)	
			{
				buff=arr[(size_arr-1)];
				for(int j=0;j<size_arr;j++)
				{
					arr[(size_arr-j-1)]=arr[(size_arr-j-2)];
				}
				arr[0]=buff;
			}
		}
			
		for(int i=0; i<size_arr;i++)
		{
			printf("%d ",arr[i]);
		}
	}
	//for left shift by n elements
	if (shift<0)
	{
		if(quo<-1)
		{
			for(int i=0;i<=rem;i++)	
			{
				buff=arr[0];
				for(int j=0;j<size_arr;j++)
				{
					arr[(j)]=arr[j+1];
				}
				arr[(size_arr-1)]=buff;
			}
		} 
		
		if(quo>-1)
		{
			for(int i=0;i<(-shift);i++)	
			{
				buff=arr[0];
				for(int j=0;j<size_arr;j++)
				{
					arr[(j)]=arr[j+1];
				}
				arr[(size_arr-1)]=buff;
			}
		}
		
		printf("\n shifted array is : \n");
		for(int i=0; i<size_arr;i++)
		{
			printf("%d ",arr[i]);
		}
	}	
	
}