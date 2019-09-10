#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

struct post
{
	char posn;
	char contr;
}postman;

int flag=0;

class player
{
	char counter;
	char pos,temp[100];
	string name;
	
	public:
        int input();
        int playsend();
        
        int showdetails()
        {
        	cout<<"Congratulations "<<name<<" you are the winner."<<endl<<"press a letter and enter to exit.....";
			cin>>pos;
			return 0;
		}
};

int player::input()
{
	cout<<"Enter your name (Don't use space):";
	cin>>name;
	cout<<"Enter your counter(X or O):";
    cin>>counter;
	

	return 0;
}
int player::playsend()
{
	cout<<name<<"'s turn:"<<endl;
	cout<<"Enter position where you want to place your counter:";
	LABEL:cin>>temp;
	pos=temp[0];
	if(pos<='0'||pos>'9')
	{
		cout<<"Invalid move,enter again:";
		goto LABEL;
	}
	
	postman.posn=pos;
	postman.contr=counter;
	return 0;
}

	



class Gameboard
{
    char A[3][4];	int B[3][3];
	char c;

	public:
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
		case'1' : work(2,0);
		          break;
		          
		case'2' : work(2,1);
		          break;
		
		case'3' : work(2,2);
		          break;
		
		case'4' : work(1,0);
		          break;
		          
		case'5' : work(1,1);
		          break;
		          
		case'6' : work(1,2);
		          break;
		
		case'7' : work(0,0);
		          break;
				  
		case'8' : work(0,1);
				  break;
				  
		case'9' : work(0,2);
				  break;
    }
				  return 0; 
	
}
		void show2()
		{
			for(int r=0;r<3;r++)
	        cout<<"                                      "<<A[r][0]<<"|"<<A[r][1]<<"|"<<A[r][2]<<endl;
	        cout<<endl;
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
    cout<<endl;
    cout<<"This is a game of tic-tac-toe...."<<endl<<"Enter the position you want your counter to be entered as shown..."<<endl<<endl;
	cout<<"7 8 9"<<endl<<"4 5 6"<<endl<<"1 2 3"<<endl<<endl;
	
	for(int r=0;r<3;r++)
	cout<<"                                      "<<A[r][0]<<"|"<<A[r][1]<<"|"<<A[r][2]<<endl;
	cout<<endl;
	return 0;
}

int Gameboard::check(int &r,int &i)
{
	if(B[r][i]==1)
	{
		cout<<"Place "<<postman.posn<<" is filled"<<endl<<"Enter again: ";
		cin>>postman.posn;
		
		switch(postman.posn)
    	{
		case'1' : r=2;i=0;
		          break;
		          
		case'2' : r=2;i=1;
		          break;
		
		case'3' : r=2;i=2;
		          break;
		
		case'4' : r=1;i=0;
		          break;
		          
		case'5' : r=1;i=1;
		          break;
		          
		case'6' : r=1;i=2;
		          break;
		
		case'7' : r=0;i=0;
		          break;
				  
		case'8' : r=0;i=1;;
				  break;
				  
		case'9' : r=0;i=2;;
				  break;
    }
    check(r,i);
	}
	return 0;
}

int main()
{
	player p[2];
	
	cout<<"This is a game of tic-tac-toe...."<<endl<<"Enter the position you want your counter to be entered as shown..."<<endl<<endl;
	cout<<"7 8 9"<<endl<<"4 5 6"<<endl<<"1 2 3"<<endl<<endl;
	
		for(int i=0;i<2;i++)
	{
		cout<<"For player"<<i+1<<endl;
	    p[i].input();
	}
	
	cout<<"Let's start....."<<endl;
	
	LABEL:Gameboard g;
	
	int w;
	int n[9]={0,1,0,1,0,1,0,1,0};
	
	for(int z=0;z>=0;z++)
	{
		system("cls");
		g.show();
		
		if(z>=5)
		{
			char ask;
			cout<<endl<<endl<<"Do you want to reset(y/n)? "<<endl;
			ASD:cin>>ask;
			
			if(ask=='y')
			  goto LABEL;
			  
			else if(ask!='n')
			   {
			   	  cout<<"Invalid entry........Enter again: ";
			   	  goto ASD;
			   }
			system("cls");
			g.show();     
		}
		
		w=n[z];
		p[w].playsend();
		g.recieveassign();
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
	
	return 0;
}
