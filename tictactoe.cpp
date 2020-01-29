#include<iostream>
#include<string.h>
using namespace std;

struct post
{
	int posn;
	char contr;
}postman;

int flag=0;

class player
{
	char counter;
	char name[30];
	int pos;
	
	public:
        int input();
        int playsend();
        
        int showdetails()
        {
        	cout<<"Congratulations "<<name<<" you are the winner."<<endl;
			cin>>pos;
			return 0;
		}
		
		char access_counter()
		{
			return counter;
		}
};

int player::input()
{
	cout<<"Enter your name (Don't use space): ";
	cin>>name;
	
	cout<<"Choose your counter(x or o):";
    GOURAV:cin>>counter;
    
	if(counter!='x' && counter!='o')
	{
		cout<<"Invalid Entry......Enter again:";
		goto GOURAV;
	}

	return 0;
}
int player::playsend()
{   
    
    cout<<name<<"'s turn:"<<endl<<endl;
	cout<<"Enter position where you want to place your counter:";
	cin>>pos;
	
	if(pos<='0'&&pos>'9')
	{
		cout<<"Invalid move,enter again:";
		cin>>pos;
	}
	
	   postman.posn=pos;
	   postman.contr=counter;
    
	return 0;
}

class Gameboard
{
   	int B[3][3];
	char c;

	public:
		char A[3][4];
	    Gameboard()
		{
			strcpy(A[0],"___");
			strcpy(A[1],"___");			
			strcpy(A[2],"   ");
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				 B[i][j]=0;
			}
		} 
		
		int show2()
		{
			system("cls");
			for(int r=0;r<3;r++)
			cout<<"                                  "<<A[r][0]<<"|"<<A[r][1]<<"|"<<A[r][2]<<endl;
			cout<<endl;			
		}
				
		int work(int m, int n)
    	{
		check(m,n);
		A[m][n]=c;
		B[m][n]=1;
		return 0;
	    } 
		
		int show();
		int recieveassign()
		{
     	c=postman.contr;
         
    	switch(postman.posn)
    	{
		case 1 : work(2,0);
		          break;
		          
		case 2 : work(2,1);
		          break;
		
		case 3 : work(2,2);
		          break;
		
		case 4 : work(1,0);
		          break;
		          
		case 5 : work(1,1);
		          break;
		          
		case 6 : work(1,2);
		          break;
		
		case 7 : work(0,0);
		          break;
				  
		case 8 : work(0,1);
				  break;
				  
		case 9 : work(0,2);
				  break;
    }
				  return 0; 
	
}
		
		int check(int &r,int &i);
		
		int winnerdecider()
		{
			if(A[0][0]==c && A[0][1]==c && A[0][2]==c)
			flag=1;
			
			if(A[1][0]==c && A[1][1]==c && A[1][2]==c)
			flag=1;
			
			if(A[2][0]==c && A[2][1]==c && A[2][2]==c)
			flag=1;
			
			if(A[0][0]==c && A[1][0]==c && A[2][0]==c)
			flag=1;
			
			if(A[0][1]==c && A[1][1]==c && A[2][1]==c)
			flag=1;
			
			if(A[0][2]==c && A[1][2]==c && A[2][2]==c)
			flag=1;
			
			if(A[0][0]==c && A[1][1]==c && A[2][2]==c)
			flag=1;
			
			if(A[0][2]==c && A[1][1]==c && A[2][0]==c)
			flag=1;
			
			return 0;
		}
		
};

int Gameboard::show()
{
	system("cls");   
    cout<<"                                          "<<endl;
    cout<<"This is a game of tic-tac-toe...."<<endl<<"Enter the position you want your counter to be entered as shown..."<<endl<<endl;
	cout<<"7 8 9"<<endl<<"4 5 6"<<endl<<"1 2 3"<<endl<<endl<<endl;
	for(int r=0;r<3;r++)
	cout<<"                                  "<<A[r][0]<<"|"<<A[r][1]<<"|"<<A[r][2]<<endl;
	cout<<endl;
	return 0;
}

int Gameboard::check(int &r,int &i)
{
	if(B[r][i]==1)
	{
		cout<<"Place is filled"<<endl<<"Enter again:";
		cin>>postman.posn;
		
		switch(postman.posn)
    	{
		case 1 : r=2;i=0;
		          break;
		          
		case 2 : r=2;i=1;
		          break;
		
		case 3 : r=2;i=2;
		          break;
		
		case 4 : r=1;i=0;
		          break;
		          
		case 5 : r=1;i=1;
		          break;
		          
		case 6 : r=1;i=2;
		          break;
		
		case 7 : r=0;i=0;
		          break;
				  
		case 8 : r=0;i=1;
				  break;
				  
		case 9 : r=0;i=2;
				  break;
        }
        
        check(r,i);
	}
	return 0;
}

class virtual_player
{
	private:
		char counter;
		char a[3]="xo";
		int id;
		
		int code(int i,int j)
		{
			if(i==0 && j==0)
			return 7;
			
			if(i==0 && j==1)
			return 8;
			
			if(i==0 && j==2)
			return 9;
			
			if(i==1 && j==0)
			return 4;
			
			if(i==1 && j==1)
			return 5;
			
			if(i==1 && j==2)
			return 6;
			
			if(i==2 && j==0)
			return 1;
			
			if(i==2 && j==1)
			return 2;
			
			if(i==2 && j==2)
			return 3;
		}
		
		int evaluate(char b[3][4])
		{
			if(b[0][0]==a[id] && b[0][0]==b[0][1] && b[0][0]==b[0][2])
				return 1;
				
			if(b[1][0]==a[id] && b[1][0]==b[1][1] && b[1][0]==b[1][2])
				return 1;
				
			if(b[2][0]==a[id] && b[2][0]==b[2][1] && b[2][0]==b[2][2])
				return 1;
			
			if(b[0][0]==a[id] && b[0][0]==b[1][0] && b[0][0]==b[2][0])
				return 1;
				
			if(b[0][1]==a[id] && b[0][1]==b[1][1] && b[0][1]==b[2][1])
				return 1;
				
			if(b[0][2]==a[id] && b[0][2]==b[1][2] && b[0][2]==b[2][2])
				return 1;
				
			if(b[0][0]==a[id] && b[0][0]==b[1][1] && b[0][0]==b[2][2])
				return 1;
			
			if(b[2][0]==a[id] && b[2][0]==b[1][1] && b[2][0]==b[0][2])
				return 1;
				
				
				
			if(b[0][0]==a[(id+1)%2] && b[0][0]==b[0][1] && b[0][0]==b[0][2])
				return -1;
				
			if(b[1][0]==a[(id+1)%2] && b[1][0]==b[1][1] && b[1][0]==b[1][2])
				return -1;
				
			if(b[2][0]==a[(id+1)%2] && b[2][0]==b[2][1] && b[2][0]==b[2][2])
				return -1;
			
			if(b[0][0]==a[(id+1)%2] && b[0][0]==b[1][0] && b[0][0]==b[2][0])
				return -1;
				
			if(b[0][1]==a[(id+1)%2] && b[0][1]==b[1][1] && b[0][1]==b[2][1])
				return -1;
				
			if(b[0][2]==a[(id+1)%2] && b[0][2]==b[2][2] && b[0][2]==b[2][2])
				return -1;
				
			if(b[0][0]==a[(id+1)%2] && b[0][0]==b[1][1] && b[0][0]==b[2][2])
				return -1;
			
			if(b[2][0]==a[(id+1)%2] && b[2][0]==b[1][1] && b[2][0]==b[0][2])
				return -1;
				
			return 10;							
		}
		
		public:
			
			
			int assign_id(char a)
			{
				if(a=='x')
				{
					counter='o';
					id=1;
				}
				
				else
				{
					counter='x';
					id=0;
				}
				
				return id;
			}
			
			int decide(char board[3][4], int c)
			{
				int temp;
				
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						if(board[i][j]=='_')
						{
							board[i][j]=a[c];
							if(evaluate(board)==1)
							{
								board[i][j]='_';
								return code(i,j);
							}
							board[i][j]='_';
						}
					}
				}
				
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						if(board[i][j]=='_')
						{
							board[i][j]=a[(c+1)%2];
							if(evaluate(board)==-1)
							{
								board[i][j]='_';
								return code(i,j);
							}
							board[i][j]='_';
						}
					}
				}
				
				int count=0;
				
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						if(board[i][j]!='_')
						count++;
						
				if(count==9)
					return 0;
					
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						if(board[i][j]=='_')
						{
							board[i][j]=a[c];
							temp=decide(board,(c+1)%2);
							board[i][j]='_';
							
							if(temp>=1 && temp<=9)
								return temp;
						}
					}
				}
				
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						if(board[i][j]=='_')
							return code(i,j);		
			}


			char access_counter()
			{
				return counter;
			}
};


int main()
{
	Gameboard g;
	
	
	cout<<"This is a game of tic-tac-toe...."<<endl<<"Enter the position you want your counter to be entered as shown..."<<endl<<endl;
	cout<<"7 8 9"<<endl<<"4 5 6"<<endl<<"1 2 3"<<endl<<endl;
	
	int no_players;
	
	cout<<"Enter no. of players:";
	cin>>no_players;
	
	if(no_players==1)
	{
		player p;
		virtual_player v;
		p.input();
		
		char co=p.access_counter();
		
		int id=v.assign_id(co);	
		
		cout<<"Let's start.......\n";
		
		for(int i=1;i;i++)
		{
			system("cls");
			g.show();
			
			if(i%2==1)
			{
				postman.contr=v.access_counter();
				postman.posn=v.decide(g.A,id);
           }
			
			else p.playsend();
			
			g.recieveassign();
			system("cls");
			g.show();
			g.winnerdecider();
			
			if(flag==1)
			{
				
				p.showdetails();
				break;
			}
			
			if(i==9)
			{
				g.show();
				cout<<"Game Drawn...";
				break;
			}
		}
	}
	
	else
	{	
		player p[2];
		for(int i=0;i<2;i++)
		{
			cout<<"For player"<<i+1<<endl;
		    p[i].input();
		}
		
		cout<<"Let's start....."<<endl;
		
		int w;
		int n[9]={0,1,0,1,0,1,0,1,0};
		
		
		
		for(int z=0;z>=0;z++)
		{
			system("cls");
			g.show();
			w=n[z];
			p[w].playsend();
			g.recieveassign();
			g.show();
			g.winnerdecider();
			
			if(flag==1)
			{
				system("cls");
				g.show2();
				p[w].showdetails();
				break;
			}
			
			if(z==8)
			{
				cout<<"Game Drawn...";
				break;
			}
		char ch=cin.get();
		}
    }
	return 0;
}
