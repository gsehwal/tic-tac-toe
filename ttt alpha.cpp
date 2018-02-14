#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>

using namespace std;
char  p1[10],p2[10];
int main();

int player(char mat[3][3],int c,int ch);

void end (int event,char ch);
int checkmat(char mat[3][3],int p,char ch, int event);
void cpu(char mat[3][3],int c,char ch);
int checkex(char mat[3][3],int pos)
{  int ex=0;
	switch(pos)
	{
		case 1 : if(mat[2][0]=='O' || mat[2][0]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 2 : if(mat[2][1]=='O' || mat[2][1]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 3 : if(mat[2][2]=='O' || mat[2][2]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 4 : if(mat[1][0]=='O' || mat[1][0]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1;
				}break;
		case 5 : if(mat[1][1]=='O' || mat[1][1]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 6 : if(mat[1][2]=='O' || mat[1][2]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 7 : if(mat[0][0]=='O' || mat[0][0]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 8 : if(mat[0][1]=='O' || mat[0][1]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
		case 9 : if(mat[0][2]=='O' || mat[0][2]=='X')
				{cout<<"\nAlready Exists...Try a different position!";
					ex=1; 
				}break;
	
	}
	
	return ex;
}
void initialize(char mat[3][3]);
int player1(char mat[3][3],int c,char ch);
int player2(char mat[3][3],int c,char ch);
int emptycenter(char mat[3][3]) {
	if(mat[1][1]=='.') {
		return 1;
	}
	else {
		return 0;
	}
}
void centermove(char mat[3][3],char ch) {
	switch(ch) {
		case 'o' : mat[1][1]='X'; break;
		case 'x' : mat[1][1]='O'; break;
	}
}
int emptycorner(char mat[3][3]) {
	if(mat[0][0]=='.' || mat[0][2]=='.' || mat[2][0]=='.' || mat[2][2]=='.') {
		return 1;
	}
	else {
		return 0;
	}
}
void cornermove(char mat[3][3], char ch) {
	switch(ch) {
		case 'o' :
				if(mat[0][0]=='.') {
					mat[0][0]='X';
				}
				else if(mat[0][2]=='.') {
					mat[0][2]='X';
				}
				else if(mat[2][0]=='.') {
					mat[2][0]='X';
				}
				else if(mat[2][2]=='.') {
					mat[2][2]='X';
				}
		case 'x' :
				if(mat[0][0]=='.') {
					mat[0][0]='O';
				}
				else if(mat[0][2]=='.') {
					mat[0][2]='O';
				}
				else if(mat[2][0]=='.') {
					mat[2][0]='O';
				}
				else if(mat[2][2]=='.') {
					mat[2][2]='O';
				}
	}
}
void othermove(char mat[3][3], char ch) {
	switch(ch) {
		case 'o' :
				if(mat[0][1]=='.') {
					mat[0][1]='X';
				}
				else if(mat[1][0]=='.') {
					mat[1][0]='X';
				}
				else if(mat[1][2]=='.') {
					mat[1][2]='X';
				}
				else if(mat[2][1]=='.') {
					mat[2][1]='X';
				}
		case 'x' :
				if(mat[0][1]=='.') {
					mat[0][1]='O';
				}
				else if(mat[1][0]=='.') {
					mat[1][0]='O';
				}
				else if(mat[1][2]=='.') {
					mat[1][2]='O';
				}
				else if(mat[2][1]=='.') {
					mat[2][1]='O';
				}
	}
}
void cpumove(char mat[3][3],int c,int ch)
{
	 switch(ch)
	 {
		 case 'o' : 
		 		//If the CPU can win in this move, make that move
					if(((mat[0][0]=='X' && mat[1][0]=='X')||(mat[1][1]=='X' && mat[0][2]=='X')||(mat[2][1]=='X' && mat[2][2]=='X'))&&(mat[2][0]=='.'))
					{
						mat[2][0]='X';
					}
					else if(((mat[2][0]=='X' && mat[2][2]=='X')||(mat[0][1]=='X' && mat[1][1]=='X')) && (mat[2][1]=='.'))
					{
						mat[2][1]='X';
					}
					else if(((mat[2][0]=='X' && mat[2][1]=='X')||(mat[0][0]=='X' && mat[1][1]=='X')||(mat[0][2]=='X' && mat[1][2]=='X'))&&(mat[2][2]=='.'))
					{
						mat[2][2]='X';
					}
					else if(((mat[0][0]=='X' && mat[2][0]=='X')||(mat[1][1]=='X' && mat[1][2]=='X'))&&(mat[1][0]=='.'))
					{
						mat[1][0]='X';
					}
					else if(((mat[2][0]=='X' && mat[0][2]=='X')||(mat[0][0]=='X' && mat[2][2]=='X')||(mat[2][1]=='X' && mat[0][1]=='X')||(mat[1][0]=='X' && mat[1][2]=='X'))&&(mat[1][1]=='.'))
					{
						mat[1][1]='X';
					}
					else if(((mat[1][0]=='X' && mat[1][1]=='X')||(mat[0][2]=='X' && mat[2][2]=='X'))&&(mat[1][2]=='.'))
					{
						mat[1][2]='X';
					}
					else if(((mat[1][0]=='X' && mat[2][0]=='X')||(mat[1][1]=='X' && mat[2][2]=='X')||(mat[0][1]=='X' && mat[0][2]=='X'))&&(mat[0][0]=='.'))
					{
						mat[0][0]='X';
					}
					else if(((mat[0][0]=='X' && mat[0][2]=='X')||(mat[1][1]=='X' && mat[2][1]=='X'))&&(mat[0][1]=='.'))
					{
						mat[0][1]='X';
					}
					else if(((mat[0][0]=='X' && mat[0][1]=='X')||(mat[2][0]=='X' && mat[1][1]=='X')||(mat[1][2]=='X' && mat[2][2]=='X'))&&(mat[0][2]=='.'))
					{
						mat[0][2]='X';
					}
		 		//If the user can win in next move, block it
					else if(((mat[0][0]=='O' && mat[1][0]=='O')||(mat[1][1]=='O' && mat[0][2]=='O')||(mat[2][1]=='O' && mat[2][2]=='O'))&&(mat[2][0]=='.'))
					{
						mat[2][0]='X';
					}
					else if(((mat[2][0]=='O' && mat[2][2]=='O')||(mat[0][1]=='O' && mat[1][1]=='O')) && (mat[2][1]=='.'))
					{
						mat[2][1]='X';
					}
					else if(((mat[2][0]=='O' && mat[2][1]=='O')||(mat[0][0]=='O' && mat[1][1]=='O')||(mat[0][2]=='O' && mat[1][2]=='O'))&&(mat[2][2]=='.'))
					{
						mat[2][2]='X';
					}
					else if(((mat[0][0]=='O' && mat[2][0]=='O')||(mat[1][1]=='O' && mat[1][2]=='O'))&&(mat[1][0]=='.'))
					{
						mat[1][0]='X';
					}
					else if(((mat[2][0]=='O' && mat[0][2]=='O')||(mat[0][0]=='O' && mat[2][2]=='O')||(mat[2][1]=='O' && mat[0][1]=='O')||(mat[1][0]=='O' && mat[1][2]=='O'))&&(mat[1][1]=='.'))
					{
						mat[1][1]='X';
					}
					else if(((mat[1][0]=='O' && mat[1][1]=='O')||(mat[0][2]=='O' && mat[2][2]=='O'))&&(mat[1][2]=='.'))
					{
						mat[1][2]='X';
					}
					else if(((mat[1][0]=='O' && mat[2][0]=='O')||(mat[1][1]=='O' && mat[2][2]=='O')||(mat[0][1]=='O' && mat[0][2]=='O'))&&(mat[0][0]=='.'))
					{
						mat[0][0]='X';
					}
					else if(((mat[0][0]=='O' && mat[0][2]=='O')||(mat[1][1]=='O' && mat[2][1]=='O'))&&(mat[0][1]=='.'))
					{
						mat[0][1]='X';
					}
					else if(((mat[0][0]=='O' && mat[0][1]=='O')||(mat[2][0]=='O' && mat[1][1]=='O')||(mat[1][2]=='O' && mat[2][2]=='O'))&&(mat[0][2]=='.'))
					{
						mat[0][2]='X';
					}
				//Else, make any safe move
					else {
						if(emptycenter(mat)) {
							centermove(mat,ch); 
						}
						else if(emptycorner(mat)) {
							cornermove(mat,ch);
						}
						else {
							othermove(mat,ch);
						}
					}

		case 'x' :
				//If the CPU can win in this move, make that move
					if(((mat[0][0]=='O' && mat[1][0]=='O')||(mat[1][1]=='O' && mat[0][2]=='O')||(mat[2][1]=='O' && mat[2][2]=='O'))&&(mat[2][0]=='.'))
					{
						mat[2][0]='O';
					}
					else if(((mat[2][0]=='O' && mat[2][2]=='O')||(mat[0][1]=='O' && mat[1][1]=='O')) && (mat[2][1]=='.'))
					{
						mat[2][1]='O';
					}
					else if(((mat[2][0]=='O' && mat[2][1]=='O')||(mat[0][0]=='O' && mat[1][1]=='O')||(mat[0][2]=='O' && mat[1][2]=='O'))&&(mat[2][2]=='.'))
					{
						mat[2][2]='O';
					}
					else if(((mat[0][0]=='O' && mat[2][0]=='O')||(mat[1][1]=='O' && mat[1][2]=='O'))&&(mat[1][0]=='.'))
					{
						mat[1][0]='O';
					}
					else if(((mat[2][0]=='O' && mat[0][2]=='O')||(mat[0][0]=='O' && mat[2][2]=='O')||(mat[2][1]=='O' && mat[0][1]=='O')||(mat[1][0]=='O' && mat[1][2]=='O'))&&(mat[1][1]=='.'))
					{
						mat[1][1]='O';
					}
					else if(((mat[1][0]=='O' && mat[1][1]=='O')||(mat[0][2]=='O' && mat[2][2]=='O'))&&(mat[1][2]=='.'))
					{
						mat[1][2]='O';
					}
					else if(((mat[1][0]=='O' && mat[2][0]=='O')||(mat[1][1]=='O' && mat[2][2]=='O')||(mat[0][1]=='O' && mat[0][2]=='O'))&&(mat[0][0]=='.'))
					{
						mat[0][0]='O';
					}
					else if(((mat[0][0]=='O' && mat[0][2]=='O')||(mat[1][1]=='O' && mat[2][1]=='O'))&&(mat[0][1]=='.'))
					{
						mat[0][1]='O';
					}
					else if(((mat[0][0]=='O' && mat[0][1]=='O')||(mat[2][0]=='O' && mat[1][1]=='O')||(mat[1][2]=='O' && mat[2][2]=='O'))&&(mat[0][2]=='.'))
					{
						mat[0][2]='O';
					}
		 		//If the user can win in next move, block it
					else if(((mat[0][0]=='X' && mat[1][0]=='X')||(mat[1][1]=='X' && mat[0][2]=='X')||(mat[2][1]=='X' && mat[2][2]=='X'))&&(mat[2][0]=='.'))
					{
						mat[2][0]='O';
					}
					else if(((mat[2][0]=='X' && mat[2][2]=='X')||(mat[0][1]=='X' && mat[1][1]=='X')) && (mat[2][1]=='.'))
					{
						mat[2][1]='O';
					}
					else if(((mat[2][0]=='X' && mat[2][1]=='X')||(mat[0][0]=='X' && mat[1][1]=='X')||(mat[0][2]=='X' && mat[1][2]=='X'))&&(mat[2][2]=='.'))
					{
						mat[2][2]='O';
					}
					else if(((mat[0][0]=='X' && mat[2][0]=='X')||(mat[1][1]=='X' && mat[1][2]=='X'))&&(mat[1][0]=='.'))
					{
						mat[1][0]='O';
					}
					else if(((mat[2][0]=='X' && mat[0][2]=='X')||(mat[0][0]=='X' && mat[2][2]=='X')||(mat[2][1]=='X' && mat[0][1]=='X')||(mat[1][0]=='X' && mat[1][2]=='X'))&&(mat[1][1]=='.'))
					{
						mat[1][1]='O';
					}
					else if(((mat[1][0]=='X' && mat[1][1]=='X')||(mat[0][2]=='X' && mat[2][2]=='X'))&&(mat[1][2]=='.'))
					{
						mat[1][2]='O';
					}
					else if(((mat[1][0]=='X' && mat[2][0]=='X')||(mat[1][1]=='X' && mat[2][2]=='X')||(mat[0][1]=='X' && mat[0][2]=='X'))&&(mat[0][0]=='.'))
					{
						mat[0][0]='O';
					}
					else if(((mat[0][0]=='X' && mat[0][2]=='X')||(mat[1][1]=='X' && mat[2][1]=='X'))&&(mat[0][1]=='.'))
					{
						mat[0][1]='O';
					}
					else if(((mat[0][0]=='X' && mat[0][1]=='X')||(mat[2][0]=='X' && mat[1][1]=='X')||(mat[1][2]=='X' && mat[2][2]=='X'))&&(mat[0][2]=='.'))
					{
						mat[0][2]='O';
					}
				//Else, make any safe move
					else {
						if(emptycenter(mat)) {
							centermove(mat,ch); 
						}
						else if(emptycorner(mat)) {
							cornermove(mat,ch);
						}
						else {
							othermove(mat,ch);
						}
					}
					
	 }
}
void cpu(char mat[3][3],int c,char ch)
{
	system("cls");
	
	int p=1,event=1;
	checkmat(mat,p,ch,event);
	if(c==9)
	{
		event=2;
	end(event,ch);
	}
	
	int i,j;
	
	cout<<"Current Board is ";
	for(i=0;i<3;i++)
	{
		cout<<endl<<endl;
		for(j=0;j<3;j++)
		{
			cout<<mat[i][j]<<"   ";
		}
	}
	getchar();
if(c<9)
{	
	cpumove(mat,c,ch);
	c++;
	player(mat,c,ch);

	}
}
void names(int opt)			//Names function
{
	switch(opt)
	{
	case 2 :
		
	system("cls");
	cout<<"Enter your name :";
	cin>>p1;
	cout<<"\nEnter friend's name :";
	cin>>p2;  break;
	
	case 1 : system("cls");
			cout<<"Enter your name :";
			cin>>p1;
			break;
    
    }	
}
void end (int event,char ch)			//End function
{
	system("cls");
	char ans;
	
	switch(event)
	{
		case 1 :		//When a player wins
	cout<<"Play Again? (Y/N) :";
	cin>>ans;
	if(ans=='y' || ans=='Y')
	{
		char mat[3][3];
		int c=0;
		initialize(mat);
		player1(mat,c,ch);
	}
	else
	{
		exit(0);
	}
	break;
	
	case 2 : system("cls");		//When Game Draws
	         cout<<"DRAW!!!";
	         
	         cout<<"\n\nLet's Play Again (Y/N) :";
	         cin>>ans;
	if(ans=='y' || ans=='Y')
	{
		char mat[3][3];
		int c=0;
		initialize(mat);
		player1(mat,c,ch);
	}
	else
	{
		exit(0);
	}
	break;
}
	
}
char select(int opt)			//select function
{
	system("cls");
	char s;
	int c=0;
	ifstream file;
	switch(opt)
	{
		case 3 :
			
			file.open("help.txt");
			system("cls");
			cout<<file.rdbuf();
			
			file.close();
			
			getchar();
			getchar();
			main();
			
	break;
			
	
	    case 2 :
	 
			names(opt);
			system("cls");
			cout<<p1;

			cout<<"\n\nSelect O or X :";
			cin>>s;  break;
			
		case 1 : names(opt);
				char mat[3][3];
				 char ch;
				initialize(mat);
				system("cls");
				cout<<p1<<"\n\nSelect 'O' or 'X'\n\n...";
				cin>>ch;
		         player(mat,c,ch);
		         break;
		
		case 4 : exit(0); break;
 }

return s;
}
int checkmat(char mat[3][3],int p,char ch,int event)			//Check Matrix function
{
	int f=0,i,j;

	if((mat[0][0]=='O' && mat[1][0]=='O' && mat[2][0]=='O')||(mat[0][0]=='X' && mat[1][0]=='X' && mat[2][0]=='X'))
  {
	

	f=1;
	
  }
  else if((mat[0][1]=='O' && mat[1][1]=='O' && mat[2][1]=='O')||(mat[0][1]=='X' && mat[1][1]=='X' && mat[2][1]=='X'))
  {
	  
	  
		  f=1;
	  
  }
    else if((mat[0][2]=='O' && mat[1][2]=='O' && mat[2][2]=='O')||(mat[0][2]=='X' && mat[1][2]=='X' && mat[2][2]=='X'))
  {
	  
	  
		  f=1;
	  
  }
    else if((mat[0][0]=='O' && mat[0][1]=='O' && mat[0][2]=='O')||(mat[0][0]=='X' && mat[0][1]=='X' && mat[0][2]=='X'))
  {
	 
	  
		  f=1;
	  
  }
     else if((mat[1][0]=='O' && mat[1][1]=='O' && mat[1][2]=='O')||(mat[1][0]=='X' && mat[1][1]=='X' && mat[1][2]=='X'))
  {
	  
	  
		  f=1;
	  
  }
     else if((mat[2][0]=='O' && mat[2][1]=='O' && mat[2][2]=='O')||(mat[2][0]=='X' && mat[2][1]=='X' && mat[2][2]=='X'))
  {
	  
	  f=1;
  }
  else if((mat[0][0]=='O' && mat[1][1]=='O' && mat[2][2]=='O')||(mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X'))
  {
	  
	  f=1;
  }
  else if((mat[2][0]=='O' && mat[1][1]=='O' && mat[0][2]=='O')||(mat[2][0]=='X' && mat[1][1]=='X' && mat[0][2]=='X'))
  {
	  
	  f=1;
  }
  if(f==1)
  {
	  system("cls");
	  cout<<"CHECKMATE";
	  event=1;
	  if(p==1)
	  {
	  cout<<"\n\n"<<p1<<" WINS!!!";
	  for(i=0;i<3;i++)
	  {
		  cout<<"\n\n";
		  for(j=0;j<3;j++)
		  {
			  cout<<mat[i][j]<<"  ";
		  }
	  }
	   getchar();
	  getchar();
	  end(event,ch);
  }
else if(p==2)
	  {
	  cout<<"\n\n"<<p2<<" WINS!!!";
	  for(i=0;i<3;i++)
	  {
		  cout<<"\n\n";
		  for(j=0;j<3;j++)
		  {
			  cout<<mat[i][j]<<"  ";
		  }
	  }
	   getchar();
	  getchar();
	  end(event,ch);
  } 
  else if (p==3)
  {
	   cout<<"\n\nCPU WINS!!!";
	  for(i=0;i<3;i++)
	  {
		  cout<<"\n\n";
		  for(j=0;j<3;j++)
		  {
			  cout<<mat[i][j]<<"  ";
		  }
	  }
	   getchar();
	  getchar();
	  end(event,ch);
  }
  getchar();
  
}
return 0;
}
void initialize(char mat[3][3])			//Initialize function
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mat[i][j]='.';
		}
	}
	
}
int player(char mat[3][3],int c,int ch)
{
	system("cls");
	int p=3,event=1,ex;
	if(c!=0)
	{
	checkmat(mat,p,ch,event);
    }
	int i,j;
	char pos;
	cout<<"Current Board is ";
	for(i=0;i<3;i++)
	{
		cout<<endl<<endl;
		for(j=0;j<3;j++)
		{
			cout<<mat[i][j]<<"   ";
		}
	}
	
	if(c<9)
{
	switch(ch)
	{
		case 'o' : caseO:	//label
				cout<<"\n\n"<<p1<<"\n\n";
				cout<<"Enter position :";
				cin>>pos;
				
				switch(pos)
				{
					case '1' : ex=checkex(mat,1);
							if(ex==0)
							{
							mat[2][0]='O';
					        c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '2' : ex=checkex(mat,2);
							if(ex==0)
							{
							mat[2][1]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}
								break;
					case '3' : ex=checkex(mat,3);
							if(ex==0)
							{
							mat[2][2]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '4' : ex=checkex(mat,4);
							if(ex==0)
							{
							mat[1][0]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '5' : ex=checkex(mat,5);
							if(ex==0)
							{
							mat[1][1]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '6' : ex=checkex(mat,6);
							if(ex==0)
							{
							mat[1][2]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '7' : ex=checkex(mat,7);
							if(ex==0)
							{
							mat[0][0]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '8' : ex=checkex(mat,8);
							if(ex==0)
							{
							mat[0][1]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '9': ex=checkex(mat,9);
							if(ex==0)
							{
							mat[0][2]='O';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					
					default : cout<<"\nWrong choice...Enter a number (1-9)";
							  goto caseO;
					
				}break;

		case 'x' : caseX:	//label
				cout<<"\n\n"<<p1<<"\n\n";
				cout<<"Enter position :";
				cin>>pos;
				
				switch(pos)
				{
					case '1' : ex=checkex(mat,1);
							if(ex==0)
							{
							mat[2][0]='X';
					        c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '2' : ex=checkex(mat,2);
							if(ex==0)
							{
							mat[2][1]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}
								break;
					case '3' : ex=checkex(mat,3);
							if(ex==0)
							{
							mat[2][2]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '4' : ex=checkex(mat,4);
							if(ex==0)
							{
							mat[1][0]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '5' : ex=checkex(mat,5);
							if(ex==0)
							{
							mat[1][1]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '6' : ex=checkex(mat,6);
							if(ex==0)
							{
							mat[1][2]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '7' : ex=checkex(mat,7);
							if(ex==0)
							{
							mat[0][0]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '8' : ex=checkex(mat,8);
							if(ex==0)
							{
							mat[0][1]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '9': ex=checkex(mat,9);
							if(ex==0)
							{
							mat[0][2]='X';
							c++;
								cpu(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					
					default : cout<<"\nWrong choice...Enter a number (1-9)";
							  goto caseX;
					
				}break;
	
	}
}
	
return 0;
}
int player1(char mat[3][3],int c,char ch)			//player 1 function
{ system("cls");
	int p=2,event=1,ex;
	if(c!=0)
	{
	checkmat(mat,p,ch,event);
    }
	int i,j;
	char pos;
	cout<<"Current Board is ";
	for(i=0;i<3;i++)
	{
		cout<<endl<<endl;
		for(j=0;j<3;j++)
		{
			cout<<mat[i][j]<<"   ";
		}
	}
if(c<9)
{	
	switch(ch)
	{
		case 'o' : caseO:	//label
				cout<<"\n\n"<<p1<<"\n\n";
				cout<<"Enter position :";
				cin>>pos;
				
				switch(pos)
				{
					case '1' : ex=checkex(mat,1);
							if(ex==0)
							{
							mat[2][0]='O';
					        c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '2' : ex=checkex(mat,2);
							if(ex==0)
							{
							mat[2][1]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}
								break;
					case '3' : ex=checkex(mat,3);
							if(ex==0)
							{
							mat[2][2]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '4' : ex=checkex(mat,4);
							if(ex==0)
							{
							mat[1][0]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '5' : ex=checkex(mat,5);
							if(ex==0)
							{
							mat[1][1]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '6' : ex=checkex(mat,6);
							if(ex==0)
							{
							mat[1][2]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '7' : ex=checkex(mat,7);
							if(ex==0)
							{
							mat[0][0]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '8' : ex=checkex(mat,8);
							if(ex==0)
							{
							mat[0][1]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '9': ex=checkex(mat,9);
							if(ex==0)
							{
							mat[0][2]='O';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					
					default : cout<<"\nWrong choice...Enter a number (1-9)";
							  goto caseO;
					
				}break;
			
		case 'x' :  
		            caseX:	//label
				cout<<"\n\n"<<p1<<"\n\n";
				cout<<"Enter position :";
				cin>>pos;
				
				switch(pos)
				{
					case '1' : ex=checkex(mat,1);
							if(ex==0)
							{
							mat[2][0]='X';
					        c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '2' : ex=checkex(mat,2);
							if(ex==0)
							{
							mat[2][1]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '3' : ex=checkex(mat,3);
							if(ex==0)
							{
							mat[2][2]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '4' : ex=checkex(mat,4);
							if(ex==0)
							{
							mat[1][0]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '5' : ex=checkex(mat,5);
							if(ex==0)
							{
							mat[1][1]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '6' : ex=checkex(mat,6);
							if(ex==0)
							{
							mat[1][2]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '7' : ex=checkex(mat,7);
							if(ex==0)
							{
							mat[0][0]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '8' : ex=checkex(mat,8);
							if(ex==0)
							{
							mat[0][1]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '9': ex=checkex(mat,9);
							if(ex==0)
							{
							mat[0][2]='X';
							c++;
								player2(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
								
					default : cout<<"\nWrong choice...Enter a number (1-9)";
								goto caseX;
				}break;
			
			default : system("cls");
						cout<<"Wrong choice!\nYou had to select either 'O' or 'X' ";
						getchar();
		
	}
}


return 0;
}
int player2(char mat[3][3],int c,char ch)			//player 2 function
{    
	system("cls");
	
	int p=1,event=1,ex;
	checkmat(mat,p,ch,event);
	if(c==9)
	{
		event=2;
	end(event,ch);
	}
	
	int i,j;
	char pos;
	cout<<"Current Board is ";
	for(i=0;i<3;i++)
	{
		cout<<endl<<endl;
		for(j=0;j<3;j++)
		{
			cout<<mat[i][j]<<"   ";
		}
	}
if(c<9)
{
	switch(ch)
	{
		case 'o' :caseO:	//label
				cout<<"\n\n"<<p2<<"\n\n";
				cout<<"Enter position :";
				cin>>pos;
				switch(pos)
				{
					case '1' : ex=checkex(mat,1);
							if(ex==0)
							{
							mat[2][0]='X';
					        c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '2' : ex=checkex(mat,2);
							if(ex==0)
							{	
							mat[2][1]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '3' : ex=checkex(mat,3);
							if(ex==0)
							{
							mat[2][2]='X';
							c++;
								player1(mat,c,ch);
							}
								else
								{
									goto caseO;
									}break;
					case '4' : ex=checkex(mat,4);
							if(ex==0)
							{
							mat[1][0]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '5' : ex=checkex(mat,5);
							if(ex==0)
							{
							mat[1][1]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '6' : ex=checkex(mat,6);
							if(ex==0)
							{
							mat[1][2]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '7' : ex=checkex(mat,7);
							if(ex==0)
							{
							mat[0][0]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '8' : ex=checkex(mat,8);
							if(ex==0)
							{
							mat[0][1]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
					case '9' : ex=checkex(mat,9);
							if(ex==0)
							{
							mat[0][2]='X';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseO;
									}break;
								
					default : cout<<"\nWrong choice...Enter a number (1-9)";
								goto caseO;
				}
		       break;
		  
		case 'x' :  caseX:	//label
				cout<<"\n\n"<<p2<<"\n\n";
				cout<<"Enter position :";
				cin>>pos;
				switch(pos)
				{
					case '1' : ex=checkex(mat,1);
							if(ex==0)
							{
							mat[2][0]='O';
					        c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '2' : ex=checkex(mat,2);
							if(ex==0)
							{
							mat[2][1]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '3' : ex=checkex(mat,3);
							if(ex==0)
							{
							mat[2][2]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '4' : ex=checkex(mat,4);
							if(ex==0)
							{
							mat[1][0]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '5' : ex=checkex(mat,5);
							if(ex==0)
							{
							mat[1][1]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '6' : ex=checkex(mat,6);
							if(ex==0)
							{
							mat[1][2]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '7' : ex=checkex(mat,7);
							if(ex==0)
							{
							mat[0][0]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '8' : ex=checkex(mat,8);
							if(ex==0)
							{
							mat[0][1]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
					case '9' : ex=checkex(mat,9);
							if(ex==0)
							{
							mat[0][2]='O';
							c++;
								player1(mat,c,ch);
								}
								else
								{
									goto caseX;
									}break;
								
					default : cout<<"\nWrong choice...Enter a number (1-9)";
								goto caseX;
				}
				break;
	}
}

return 0;
}

int main()			//Main function
{
system("cls");;
 char mat[3][3],ch;
	int c=0,opt;
	
initialize(mat);
ifstream ifile;
	ifile.open("title.txt");
	
	cout<<ifile.rdbuf();
	
	ifile.close();
	
	cout<<"\t\t\t1.Play with CPU\n\t\t\t2.Play with Friend\n\t\t\t3.How to play\n\t\t\t4.Exit\n\t\t\t...";
	cin>>opt;

ch=select(opt);
getchar();
player1(mat,c,ch);
	
return 0;
}