#include<iostream>

using namespace std;

struct info{
	int up;
	int right;
	int cursor;
};

void draw(info* p[]);	
void input(info* p[], int &playerNo);
void check(info* p[], int &player,int &playerNo1,int &playerNo2,int &total);

int main()
{
info* p[5];

for(int i =0; i<5; i++)
	p[i] = new info[5];
		
int playerNo1=0;
int playerNo2=0;
int player = 1;
p[1]->cursor=1;	
int total=0;
while(true)
{	
	draw(p);
	if(total >= 16)
	{
		cout<<"game over";
		break;
	}
	
	if(player%2 == 1)
	{
		cout<<"First players turn\n";
	}
	else if(player%2==2) 
	{
		cout<<"Second players turn\n";
	}
	
	cout<<playerNo1<<endl;
	cout<<playerNo2<<endl;
	input(p,player);
	check(p,player,playerNo1,playerNo2,total);
}
for(int i=0; i<5; i++)
	delete p[i];	
}
void draw(info* p[]){

	for(int i =0; i<5; i++)
	{	if(i!=0)
			for(int j=0; j<5; j++)
			{
				cout<<" ";
				if(((p[i]+j)->up)==1)
					cout<<"|";
				else
					cout<<" ";
				cout<<" ";
				cout<<"        ";
			}
		cout<<"\n";
		
		for(int j=0; j<5; j++)
		{
			if((((p[i]+j)->cursor)==1))
				cout<<"+";
			else
				cout<<" ";
			if(((p[i]+j)->up)==1)
				cout<<"|";
			else
				cout<<" ";
			if((((p[i]+j)->cursor)==1))
				cout<<"+";
			else
				cout<<" ";
			cout<<"        ";
		}
		cout<<"\n";

		for(int k=0; k<5; k++)
		{
			cout<<" 0 ";
			if(((p[i]+k)->right)==1)
				cout<<"--------";
			else
				cout<<"        ";
		}
		cout<<"\n";

	}
}

void input(info* p[],int &playerNo)		
{
	char input;
	cin>>input;
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
		{
		
			if((p[i]+j)->cursor == 1)
			{	if(input == 'd')
				{
					((p[i]+(j+1))->cursor = 1);
					((p[i]+j)->cursor = 0);
					break;
				}
				else if(input == 'a')
				{
					((p[i]+(j-1))->cursor = 1);
					((p[i]+j)->cursor = 0);
					break;
				}
				else if(input == 'w')
				{
					((p[i-1]+(j))->cursor = 1);
					((p[i]+j)->cursor = 0);
					break;
				}
				else if(input == 'z')
				{
					((p[i]+j)->cursor = 0);
					i++;
					((p[i]+(j+0))->cursor = 1);
					break;
				}
				else if(input == 'D')
				{
					(p[i]+j)->right = 1;
					((p[i]+(j+1))->cursor = 1);
					((p[i]+j)->cursor = 0);
					playerNo++;
					break;
				}
				else if(input == 'A')
				{
					(p[i]+(j-1))->right = 1;
					((p[i]+(j-1))->cursor = 1);
					((p[i]+j)->cursor = 0);
					playerNo++;
					break;
				}
				else if(input == 'W')
				{
					(p[i]+j)->up = 1;
					(p[i-1]+(j))->cursor = 1;
					(p[i]+j)->cursor = 0;
					playerNo++;
					break;
				}
				else if(input == 'Z')
				{
					(p[i]+j)->cursor = 0;
					i++;
					(p[i]+(j+0))->cursor = 1;
					(p[i]+j)->up = 1;
					playerNo++;
					break;
				}
			}	
		}
}

void check(info* p[], int &player,int &playerNo1,int &playerNo2,int &total)
{
	int count = 0;
	for(int i=1; i<5; i++)
	{
		for(int j=0; j<4; j++)
		{	
			if(((p[i]+j)->up==1)&&((p[i]+j)->right==1)&&((p[i]+(j+1))->up==1)&&((p[i-1]+j)->right==1))
				count++;
			if(count>total)
			{
				if(player%2==1)
					playerNo1++;
				else
				playerNo1++;
				total++;
				player++;
			}
		}
	}
}
