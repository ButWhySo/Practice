//Program Que: Take coordinates of diagonals of 2 rectangles(Assume rectangles’ sides to be parallel and perpendicular to x axis) and calculate common area

//strictly for rectangles whose edges are parrallel to coordinate axes
#include<stdio.h>

int r,c;
float diag[4][2],Area=0;

int chkCommArea();
void calcCommArea();
void sort();

void main()
{
	
	//upper coord diag 1 x,y diag[0]
	//lower coord diag 1 x,y diag[1]
	//upper coord diag 2 x,y diag[2]
	//lower coord diag 2 x,y diag[3]
	for(r=0;r<=3;r++)
	{
		for(c=0;c<=1;c++)
		{
				printf("Enter %c coord of diag %d : ",(c==0)?('x'):('y'),(r==0||r==1)?(1):(2));
				scanf("%f",&diag[r][c]);
		}
	}
	
	//compare relative locs of diags
	if(chkCommArea())
	{
		calcCommArea();
	}
	
	printf("\nCommon area is : %f",Area);
}

int chkCommArea()
{
	char flagx[2]={0,0},flagy[2]={0,0};
	for(int x=0;x<2;x++)
	{
		
		if( ((diag[2][0]<=diag[x][0]&&diag[x][1]<=diag[3][0]) || (diag[3][0]<=diag[x][0]&&diag[x][1]<=diag[2][0])))	//chk x coord first
		{
			flagx[x]=1;			
		}
		if(((diag[2][1]<=diag[x][1]&&diag[x][1]<=diag[3][1]) || (diag[3][1]<=diag[x][1]&&diag[x][1]<=diag[2][1])))	//chk x coord first
		{
			flagy[x]=1;
		}
	}
	if((flagx[0]||flagx[1])&&(flagy[0]||flagy[1]))
	{
		return 1;
	}
	return 0;
}

void calcCommArea()
{
	sort();
	float l=0,b=0;
	l=diag[1][0]-diag[2][0];
	b=diag[1][1]-diag[2][1];
	
	Area=l*b;
	if(Area<0)
	{
		Area*=(-1);
	}
}

void sort()
{
	float temp=0;
	for(int d=0;d<2;d++)
	{
		for(int k=0;k<4;k++)
		{
			for(int z=0;z<4;z++)
			{
				if((z>k)&&(diag[z][d]>diag[k][d]))
				{
					temp =diag[k][d];
					diag[k][d]=diag[z][d];
					diag[z][d]=temp;
				}
			}
		
		}
	}//original coords will be destroyed/lost after this
}

/*
**********************************************TEST CASES AND ANSWERS*************************************************

Enter x coord of diag 1 : 2
Enter y coord of diag 1 : -3
Enter x coord of diag 1 : 4
Enter y coord of diag 1 : -6
Enter x coord of diag 2 : 3
Enter y coord of diag 2 : 6
Enter x coord of diag 2 : 7
Enter y coord of diag 2 : 1

Common area is : 0.000000



Enter x coord of diag 1 : -2
Enter y coord of diag 1 : -3
Enter x coord of diag 1 : -4
Enter y coord of diag 1 : -5
Enter x coord of diag 2 : 3
Enter y coord of diag 2 : 6
Enter x coord of diag 2 : 7
Enter y coord of diag 2 : 1

Common area is : 0.000000


Enter x coord of diag 1 : 0
Enter y coord of diag 1 : 5
Enter x coord of diag 1 : 2
Enter y coord of diag 1 : 2
Enter x coord of diag 2 : 3
Enter y coord of diag 2 : 6
Enter x coord of diag 2 : 7
Enter y coord of diag 2 : 1

Common area is : 0.000000



Enter x coord of diag 1 : 2
Enter y coord of diag 1 : 5
Enter x coord of diag 1 : 4
Enter y coord of diag 1 : 2
Enter x coord of diag 2 : 3
Enter y coord of diag 2 : 6
Enter x coord of diag 2 : 7
Enter y coord of diag 2 : 1

Common area is : 3.000000



Enter x coord of diag 1 : 2
Enter y coord of diag 1 : 5
Enter x coord of diag 1 : 3
Enter y coord of diag 1 : 2
Enter x coord of diag 2 : 3
Enter y coord of diag 2 : 6
Enter x coord of diag 2 : 7
Enter y coord of diag 2 : 1

Common area is : 0.000000



Enter x coord of diag 1 : 3
Enter y coord of diag 1 : 2
Enter x coord of diag 1 : 5
Enter y coord of diag 1 : 5
Enter x coord of diag 2 : 3
Enter y coord of diag 2 : 6
Enter x coord of diag 2 : 7
Enter y coord of diag 2 : 1


Common area is : 6.000000
**********************************************TEST CASES AND ANSWERS*************************************************
*/