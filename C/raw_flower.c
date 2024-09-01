//Based on classic Indian game of cards 'Kacchu Ful'

#include<stdio.h>
#include<conio.h>
void main()
{
		int p;
		printf("Enter number of player: ");
		scanf("%d",&p);
		printf("\n");
		char p_name[p][15]; // assumed max length of player name is 15 letters
		unsigned int p_pts[p],n_pts;
		gets(p_name[0]);
		for(int i=0;i<p;i++)
		{
				printf("\n Enter name of player %d : ",(i+1));
				gets(p_name[i]);
		}
		char f_time=1;
		char exit=0,sel;
		while(!exit)
		{
				puts("enter any key to continue or press N to find winner : ");
				sel=getch();
				if(sel=='N')
				{
					exit=1;
					continue;
				}
				for(int i=0;i<p;i++)
				{
					printf("\n Enter score of player %d : ",(i+1));
					scanf("%d",&n_pts);
					if(f_time)
					{
						
						p_pts[i]=0;
					}
					p_pts[i]+=n_pts;
				}
				f_time=0;
		}
			//find max and output winners
			unsigned int max=0,win_indx[p],wnnrs=0;	//theoritically maybe everyone is a winner
			for (int i=0;i<p;i++)
			{
				if(p_pts[i]>max)
				{
					max=p_pts[i];
				}
			}	//max of the whole array found in this for loop
			for (int i=0;i<p;i++)
			{
				if(p_pts[i]==max)
				{
					win_indx[wnnrs]=i;
					wnnrs++;
				}
			}	//in this for loop found index of players with max pts
			printf("\n");
			puts("\n winners are : \n");
			for(int i=0;i<wnnrs;i++)
			{
				puts(p_name[win_indx[i]]);
				printf("\n");
			}
			puts(" with :");printf("%d ",p_pts[0]);puts("pts.\n");
}

