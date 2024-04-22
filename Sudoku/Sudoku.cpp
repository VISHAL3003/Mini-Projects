#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int choice;
int flag=0;
class userid{  //class for storing player details
	
	double score;
	char pwd[30];
	char pwd1[30];
	char pwd2[30];
	
	public:
		int lvl;
		char username[100];
		int current_game[9][9];
		userid(){
			score=0;
			lvl=1;
		}
		void create_id(){ // Function to create account
			cout<<"\n \t\t\t   UserName: ";
			fflush(stdin);
			cin.getline(username,100); // getting  user name from user
			tryagain:
				cout<<"\t\t\t   Password: ";
    		int h = 0; //logic for making password unseen 
    		char a2;
		    for(h=0;;){
		        a2=getch();
		        if((a2>='a'&&a2<='z')||(a2>='A'&&a2<='Z')||(a2>='0'&&a2<='9')){
		            pwd1[h]=a2;
		            ++h;
		            cout<<"*";
		        }
		        if(a2=='\b'&&h>=1){
		            cout<<"\b \b";
		            --h;
		        }
		        if(a2=='\r'){
		            pwd1[h]='\0';
		            break;
		        }
		    } 
		    cout<<"\n\t\t  Re-enter Password: ";
		    int k = 0; //logic for making password unseen 
		    char a1;
		    for(k=0;;){
		        a1=getch();
		        if((a1>='a'&&a1<='z')||(a1>='A'&&a1<='Z')||(a1>='0'&&a1<='9')){
		            pwd2[k]=a1;
		            ++k;
		            cout<<"*";
		        }
		        if(a1=='\b'&&k>=1){
		            cout<<"\b \b";
		            --k;
		        }
		        if(a1=='\r'){
		            pwd2[k]='\0';
		            break;
		        }
		    }
			if(strcmp(pwd1,pwd2)==0) // if condition for checking the password enter is matching with re-entered password
				strcpy(pwd,pwd1);
			else{
				cout<<"The entered password does not match plz try again \n";
				goto tryagain;		
			}
			cout<<"\n\tID created successfully\n";
			system("pause");
			system("cls");
			}
		void enter_username(){ //function to take user name from user
			cout<<"\n \t\t\t   UserId: ";
			fflush(stdin);
			cin.getline(username,100);
		}
		void Display(){ //displaying the name and the level
			cout<<"User name: "<<username;
			cout<<"\nlevel: "<<lvl;
			cout<<endl;
		}
		bool chk_pwd(char a[30]){ //checking password
			if(strcmp(a,pwd)==0){
				return 0;
			}
		}
		bool chk_grid(int grid[9][9], int ans[9][9]){ // function to check the solved sudoku is right or wrong 
			int a=0;
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					if(grid[i][j]!=ans[i][j]){
					    a=1;
						break;
					}
				}
			}
			if(a==0){
				cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSTATUS: CORRECT\nYOU WON\n";
				lvl++;
				flag=0;
				return 0;
			}
			else{
				cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSTATUS: NOT CORRECT \n\n";
				return 1;
			}
		}
		void mod_score(double A){ //function to assign score value
			score=A;
		}
		double ret_score(){ // function to return score value
			return score;
		}
};
void grid1(userid &A){ // sudoku level one 
	int ans1[9][9]={{7,1,4,2,3,8,9,6,5},{5,9,8,6,1,4,7,2,3},{2,3,6,9,5,7,4,8,1},{4,7,5,1,6,2,8,3,9},{8,2,3,4,7,9,1,5,6},{9,6,1,5,8,3,2,7,4},{3,4,9,7,2,5,6,1,8},{1,8,2,3,9,6,5,4,7},{6,5,7,8,4,1,3,9,2}};		
//	int sudoku[9][9]={{0,1,4,2,3,8,9,6,5},{5,9,8,6,1,4,7,2,3},{2,3,6,9,5,7,4,8,1},{4,7,5,1,6,2,8,3,9},{8,2,3,4,7,9,1,5,6},{9,6,1,5,8,3,2,7,4},{3,4,9,7,2,5,6,1,8},{1,8,2,3,9,6,5,4,7},{6,5,7,8,4,1,3,9,2}};	
//	int check[9][9]={{0,1,4,2,3,8,9,6,5},{5,9,8,6,1,4,7,2,3},{2,3,6,9,5,7,4,8,1},{4,7,5,1,6,2,8,3,9},{8,2,3,4,7,9,1,5,6},{9,6,1,5,8,3,2,7,4},{3,4,9,7,2,5,6,1,8},{1,8,2,3,9,6,5,4,7},{6,5,7,8,4,1,3,9,2}};	
	int sudoku[9][9]={{0,0,4,2,3,0,0,0,0},{0,9,8,0,0,0,7,2,0},{0,3,0,0,5,7,0,8,1},{0,0,5,1,0,2,0,0,9},{8,0,3,0,0,0,1,0,6},{9,0,0,5,0,3,2,0,0},{3,4,0,7,2,0,0,1,0},{0,8,2,0,0,0,5,4,0},{0,0,0,0,4,1,3,0,0}};
	int check[9][9]={{0,0,4,2,3,0,0,0,0},{0,9,8,0,0,0,7,2,0},{0,3,0,0,5,7,0,8,1},{0,0,5,1,0,2,0,0,9},{8,0,3,0,0,0,1,0,6},{9,0,0,5,0,3,2,0,0},{3,4,0,7,2,0,0,1,0},{0,8,2,0,0,0,5,4,0},{0,0,0,0,4,1,3,0,0}};
	int temp,r,c;
	while(A.chk_grid(sudoku, ans1)!=0){
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLEVEL : "<<A.lvl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSCORE : "<<A.ret_score()<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tDIFFICULTY : VERY EASY \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter 100 in row or column to exit...\n";
	cout<<"    1    2   3   4   5   6   7   8   9\n";	
	for(int i=0;i<9;i++){
		if(i%3==0)
			cout<<"  !===========!===========!===========!\n";	
		else
			cout<<"  !-----------!-----------!-----------!\n";
		cout<<i+1<<" | ";
		
		for(int j=0;j<9;j++){
			if(sudoku[i][j]==0)
				cout<<" "<<" | ";
			else
				cout<<sudoku[i][j]<<" | ";
		}	
	cout<<endl;
	}
		cout<<"  !===========!===========!===========!\n";
			cout<<"Enter row \n";  //taking row value for puting the number
			cin>>r;
			if(r==100){
				flag=1;
				break;
				}
			cout<<"Enter column \n"; //taking coloum value for puting the number
			cin>>c;
			if(c==100){
				flag=1;
				break;
				}
			if(check[r-1][c-1]==0){ // if condition to check weather the position is accessible
				cout<<"Enter the number"; // taking the number for user
				cin>>temp;
				sudoku[r-1][c-1]=temp;	
			}
			else{
				cout<<"You cannot access this position \n";	
				system("pause");
			}
			system("cls"); //clears the screen
		}
		system("pause"); // screen waits for the user to press any key
}
void grid2(userid &A){ // sudoku level two
	A.mod_score(500);
	int ans2[9][9]={{9,6,5,2,8,7,4,3,1},{3,2,8,9,4,1,5,7,6},{4,1,7,3,6,5,9,2,8},{5,4,6,1,2,9,3,8,7},{1,3,2,5,7,8,6,4,9},{7,8,9,6,3,4,1,5,2},{6,7,1,8,5,3,2,9,4},{2,5,4,7,9,6,8,1,3},{8,9,3,4,1,2,7,6,5}};	
	int sudoku[9][9]={{9,0,5,2,8,7,4,3,1},{3,2,8,9,4,1,5,7,6},{4,1,7,3,6,5,9,2,8},{5,4,6,1,2,9,3,8,7},{1,3,2,5,7,8,6,4,9},{7,8,9,6,3,4,1,5,2},{6,7,1,8,5,3,2,9,4},{2,5,4,7,9,6,8,1,3},{8,9,3,4,1,2,7,6,5}};
	int check[9][9]={{9,0,5,2,8,7,4,3,1},{3,2,8,9,4,1,5,7,6},{4,1,7,3,6,5,9,2,8},{5,4,6,1,2,9,3,8,7},{1,3,2,5,7,8,6,4,9},{7,8,9,6,3,4,1,5,2},{6,7,1,8,5,3,2,9,4},{2,5,4,7,9,6,8,1,3},{8,9,3,4,1,2,7,6,5}};
//	int sudoku[9][9]={{9,0,5,0,8,0,0,0,1},{0,0,0,9,4,1,0,0,0},{0,0,7,3,0,0,9,0,8},{0,4,0,1,0,9,3,8,0},{1,3,0,0,0,0,0,4,9},{0,8,9,6,0,4,0,5,0},{6,0,1,0,0,3,2,0,0},{0,0,0,7,9,6,0,0,0},{8,0,0,0,1,0,7,0,5}};
//	int check[9][9]={{9,0,5,0,8,0,0,0,1},{0,0,0,9,4,1,0,0,0},{0,0,7,3,0,0,9,0,8},{0,4,0,1,0,9,3,8,0},{1,3,0,0,0,0,0,4,9},{0,8,9,6,0,4,0,5,0},{6,0,1,0,0,3,2,0,0},{0,0,0,7,9,6,0,0,0},{8,0,0,0,1,0,7,0,5}};
	int temp,r,c;
	while(A.chk_grid(sudoku, ans2)!=0){
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLEVEL : "<<A.lvl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSCORE : "<<A.ret_score()<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tDIFFICULTY : EASY \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter 100 in row or column to exit...\n";
	cout<<"    1    2   3   4   5   6   7   8   9\n";	
	for(int i=0;i<9;i++){ // loop for displaying grid
		if(i%3==0)
			cout<<"  !===========!===========!===========!\n";	
		else
		cout<<"  !-----------!-----------!-----------!\n";
		cout<<i+1<<" | ";
		
		for(int j=0;j<9;j++){
			if(sudoku[i][j]==0)
				cout<<" "<<" | ";
			else
			cout<<sudoku[i][j]<<" | ";
		}	
	cout<<endl;
	}
		cout<<"  !===========!===========!===========!\n";
			cout<<"Enter row \n";
			cin>>r;
			if(r==100){
				flag=1;
				break;
				}
			cout<<"Enter column \n";
			cin>>c;
			if(c==100){
				flag=1;
				break;
				}
			if(check[r-1][c-1]==0){
				cout<<"Enter the number";
				cin>>temp;
				sudoku[r-1][c-1]=temp;	
			}
			else {
				cout<<"You cannot access this position \n";	
				system("pause");
			}
			system("cls");
		}
		system("pause");				
}
void grid3(userid &A){ // sudoku level three
	A.mod_score(1500);
	int ans3[9][9]={{9,1,5,2,7,6,4,8,3},{8,7,2,3,4,9,5,6,1},{4,6,3,1,8,5,9,2,7},{3,9,7,6,5,8,2,1,4},{6,4,1,7,2,3,8,5,9},{5,2,8,4,9,1,3,7,6},{2,3,9,5,6,7,1,4,8},{7,8,4,9,1,2,6,3,5},{1,5,6,8,3,4,7,9,2}};	
	int sudoku[9][9]={{9,0,5,2,7,6,4,8,3},{8,7,2,3,4,9,5,6,1},{4,6,3,1,8,5,9,2,7},{3,9,7,6,5,8,2,1,4},{6,4,1,7,2,3,8,5,9},{5,2,8,4,9,1,3,7,6},{2,3,9,5,6,7,1,4,8},{7,8,4,9,1,2,6,3,5},{1,5,6,8,3,4,7,9,2}};
	int check[9][9]={{9,0,5,2,7,6,4,8,3},{8,7,2,3,4,9,5,6,1},{4,6,3,1,8,5,9,2,7},{3,9,7,6,5,8,2,1,4},{6,4,1,7,2,3,8,5,9},{5,2,8,4,9,1,3,7,6},{2,3,9,5,6,7,1,4,8},{7,8,4,9,1,2,6,3,5},{1,5,6,8,3,4,7,9,2}};
//	int sudoku[9][9]={{9,0,5,0,7,0,0,0,3},{0,0,0,3,4,0,0,6,0},{0,0,0,0,0,5,0,2,0},{0,9,0,6,0,8,0,1,0},{6,0,0,7,0,0,0,0,0},{0,0,0,0,9,0,3,0,0},{0,3,9,0,6,0,0,0,8},{7,0,0,0,0,2,0,0,0},{1,0,0,8,0,4,0,0,0}};
//	int check[9][9]={{9,0,5,0,7,0,0,0,3},{0,0,0,3,4,0,0,6,0},{0,0,0,0,0,5,0,2,0},{0,9,0,6,0,8,0,1,0},{6,0,0,7,0,0,0,0,0},{0,0,0,0,9,0,3,0,0},{0,3,9,0,6,0,0,0,8},{7,0,0,0,0,2,0,0,0},{1,0,0,8,0,4,0,0,0}};
	int temp,r,c;
	while(A.chk_grid(sudoku, ans3)!=0){
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLEVEL : "<<A.lvl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSCORE : "<<A.ret_score()<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tDIFFICULTY : MEDIUM \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter 100 in row or column to exit...\n";
	cout<<"    1    2   3   4   5   6   7   8   9\n";	
	for(int i=0;i<9;i++){ // loop for displaying grid
		if(i%3==0)
			cout<<"  !===========!===========!===========!\n";	
		else
		cout<<"  !-----------!-----------!-----------!\n";
		cout<<i+1<<" | ";
		
		for(int j=0;j<9;j++){
			if(sudoku[i][j]==0)
				cout<<" "<<" | ";
			else
			cout<<sudoku[i][j]<<" | ";
		}	
	cout<<endl;
	}
		cout<<"  !===========!===========!===========!\n";
			cout<<"Enter row \n";
			cin>>r;
			if(r==100){
				flag=1;
				break;
				}
			cout<<"Enter column \n";
			cin>>c;
			if(c==100){
				flag=1;
				break;
				}
			if(check[r-1][c-1]==0){
				cout<<"Enter the number";
				cin>>temp;
				sudoku[r-1][c-1]=temp;	
			}
			else {
				cout<<"You cannot access this position \n";	
				system("pause");
			}
			system("cls");
		}
		system("pause");				
}
void grid4(userid &A){ // sudoku level four
	A.mod_score(3000);
	int ans4[9][9]={{6,2,5,3,4,7,9,1,8},{9,3,7,5,8,1,2,4,6},{4,8,1,2,6,9,3,7,5},{8,1,3,4,7,6,5,9,2},{7,9,2,8,1,5,6,3,4},{5,6,4,9,3,2,1,8,7},{2,4,8,1,5,3,7,6,9},{1,5,6,7,9,4,8,2,3},{3,7,9,6,2,8,4,5,1}};	
	int sudoku[9][9]={{0,2,5,3,4,7,9,1,8},{9,3,7,5,8,1,2,4,6},{4,8,1,2,6,9,3,7,5},{8,1,3,4,7,6,5,9,2},{7,9,2,8,1,5,6,3,4},{5,6,4,9,3,2,1,8,7},{2,4,8,1,5,3,7,6,9},{1,5,6,7,9,4,8,2,3},{3,7,9,6,2,8,4,5,1}};
	int check[9][9]={{0,2,5,3,4,7,9,1,8},{9,3,7,5,8,1,2,4,6},{4,8,1,2,6,9,3,7,5},{8,1,3,4,7,6,5,9,2},{7,9,2,8,1,5,6,3,4},{5,6,4,9,3,2,1,8,7},{2,4,8,1,5,3,7,6,9},{1,5,6,7,9,4,8,2,3},{3,7,9,6,2,8,4,5,1}};
//	int sudoku[9][9]={{0,0,5,0,4,7,0,0,0},{0,0,0,5,0,0,0,0,0},{0,8,0,2,0,9,0,0,0},{0,1,3,0,7,0,0,0,0},{0,9,0,8,0,0,6,0,0},{0,6,4,0,3,0,0,8,0},{0,0,0,1,0,0,0,0,0},{0,0,6,0,9,0,8,2,0},{0,7,0,0,2,8,4,0,1}};
//	int check[9][9]={{0,0,5,0,4,7,0,0,0},{0,0,0,5,0,0,0,0,0},{0,8,0,2,0,9,0,0,0},{0,1,3,0,7,0,0,0,0},{0,9,0,8,0,0,6,0,0},{0,6,4,0,3,0,0,8,0},{0,0,0,1,0,0,0,0,0},{0,0,6,0,9,0,8,2,0},{0,7,0,0,2,8,4,0,1}};
	int temp,r,c;
	while(A.chk_grid(sudoku, ans4)!=0){
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLEVEL : "<<A.lvl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSCORE : "<<A.ret_score()<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tDIFFICULTY : HARD \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter 100 in row or column to exit...\n";
	cout<<"    1    2   3   4   5   6   7   8   9\n";	
	for(int i=0;i<9;i++){ // loop for displaying grid
		if(i%3==0)
			cout<<"  !===========!===========!===========!\n";	
		else
		cout<<"  !-----------!-----------!-----------!\n";
		cout<<i+1<<" | ";
		
		for(int j=0;j<9;j++){
			if(sudoku[i][j]==0)
				cout<<" "<<" | ";
			else
			cout<<sudoku[i][j]<<" | ";
		}	
	cout<<endl;
	}
		cout<<"  !===========!===========!===========!\n";
			cout<<"Enter row \n";
			cin>>r;
			if(r==100){
				flag=1;
				break;
				}
			cout<<"Enter column \n";
			cin>>c;
			if(c==100){
				flag=1;
				break;
				}
			if(check[r-1][c-1]==0){
				cout<<"Enter the number";
				cin>>temp;
				sudoku[r-1][c-1]=temp;	
			}
			else {
				cout<<"You cannot access this position \n";	
				system("pause");
			}
			system("cls");
		}
		system("pause");				
}
void grid5(userid &A){ // sudoku level five
	A.mod_score(5000);
	int ans5[9][9]={{6,2,5,3,4,7,9,1,8},{9,3,7,5,8,1,2,4,6},{4,8,1,2,6,9,3,7,5},{8,1,3,4,7,6,5,9,2},{7,9,2,8,1,5,6,3,4},{5,6,4,9,3,2,1,8,7},{2,4,8,1,5,3,7,6,9},{1,5,6,7,9,4,8,2,3},{3,7,9,6,2,8,4,5,1}};	
	int sudoku[9][9]={{0,2,5,3,4,7,9,1,8},{9,3,7,5,8,1,2,4,6},{4,8,1,2,6,9,3,7,5},{8,1,3,4,7,6,5,9,2},{7,9,2,8,1,5,6,3,4},{5,6,4,9,3,2,1,8,7},{2,4,8,1,5,3,7,6,9},{1,5,6,7,9,4,8,2,3},{3,7,9,6,2,8,4,5,1}};
	int check[9][9]={{0,2,5,3,4,7,9,1,8},{9,3,7,5,8,1,2,4,6},{4,8,1,2,6,9,3,7,5},{8,1,3,4,7,6,5,9,2},{7,9,2,8,1,5,6,3,4},{5,6,4,9,3,2,1,8,7},{2,4,8,1,5,3,7,6,9},{1,5,6,7,9,4,8,2,3},{3,7,9,6,2,8,4,5,1}};
//	int sudoku[9][9]={{0,0,5,0,4,7,0,0,0},{0,0,0,5,0,0,0,0,0},{0,8,0,2,0,9,0,0,0},{0,1,3,0,7,0,0,0,0},{0,9,0,8,0,0,6,0,0},{0,6,4,0,3,0,0,8,0},{0,0,0,1,0,0,0,0,0},{0,0,6,0,9,0,8,2,0},{0,7,0,0,2,8,4,0,1}};
//	int check[9][9]={{0,0,5,0,4,7,0,0,0},{0,0,0,5,0,0,0,0,0},{0,8,0,2,0,9,0,0,0},{0,1,3,0,7,0,0,0,0},{0,9,0,8,0,0,6,0,0},{0,6,4,0,3,0,0,8,0},{0,0,0,1,0,0,0,0,0},{0,0,6,0,9,0,8,2,0},{0,7,0,0,2,8,4,0,1}};
	int temp,r,c;
	while(A.chk_grid(sudoku, ans5)!=0){
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLEVEL : "<<A.lvl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tSCORE : "<<A.ret_score()<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tDIFFICULTY : VERY HARD \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter 100 in row or column to exit...\n";
	cout<<"    1    2   3   4   5   6   7   8   9\n";	
	for(int i=0;i<9;i++){ // loop for displaying grid
		if(i%3==0)
			cout<<"  !===========!===========!===========!\n";	
		else
		cout<<"  !-----------!-----------!-----------!\n";
		cout<<i+1<<" | ";
		
		for(int j=0;j<9;j++){
			if(sudoku[i][j]==0)
				cout<<" "<<" | ";
			else
			cout<<sudoku[i][j]<<" | ";
		}	
	cout<<endl;
	}
		cout<<"  !===========!===========!===========!\n";
			cout<<"Enter row \n";
			cin>>r;
			if(r==100){
				flag=1;
				break;
				}
			cout<<"Enter column \n";
			cin>>c;
			if(c==100){
				flag=1;
				break;
				}
			if(check[r-1][c-1]==0){
				cout<<"Enter the number";
				cin>>temp;
				sudoku[r-1][c-1]=temp;	
			}
			else { 
				cout<<"You cannot access this position \n";	
				system("pause");
			}
			system("cls");
		}
		system("pause");				
}
void end(){ // function to greet the player who finished all levels
	system("cls");
	cout<<"\n\n\n\n\n\n\t\t\t\t\t CONGRATULATIONS YOU HAVE COMPLETED THE SERIES \n\t\t\t\t\t                  FINAL SCORE : 10000\n\t\t\t\t\t                YOU ARE INSAAAANNEEE!!!!! \n";
	system("pause");
}
void Main_menu(userid &A){ // In game menu
	system("cls");
	cout<<"\t\t\t\t\t\t    Main Menu \n";  // Displaying In game menu
	cout<<"\t\t\t\t\t\t_________________"<<endl;
	cout<<"\t\t\t\t\t\t|Sno|Options    |"<<endl;
	cout<<"\t\t\t\t\t\t|---|-----------| "<<endl;
	cout<<"\t\t\t\t\t\t|1. |New game   |\n\t\t\t\t\t\t|2. |Resume game|\n\t\t\t\t\t\t|3. |Logout     |\n";
	cout<<"\t\t\t\t\t\t|___|___________|"<<endl;
	cout<<"\n\tEnter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice){ //switch case for options
		case 1:{  // case 1 for new game
			A.lvl=1;
		    grid1(A); // new game starts (level 1)
		    if(flag==1)
		    	break;
			char Opp;
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				grid2(A); // level two is loaded
				if(flag==1)
		    	break;
			}
			else{
				break;
			}
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				grid3(A); // level three is loaded
				if(flag==1)
		    	break;
			}
			else{
				break;
			}
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				grid4(A); // level four is loaded
				if(flag==1)
		    	break;
			}
			else{
				break;
			}
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				grid5(A); // level five is loaded
				if(flag==1)
		    	break;
				end();
				break;
			}
				
		}
		case 2:{ // case 2 for resume game 
			int a=A.lvl;
			if(a==1){ // if condition for going to the level which user is left perviously
				goto lvl1;
			}
			else if(a==2){
					goto lvl2;
					}
				else if(a==3){
						goto lvl3;
						}
					else if(a==4){
							goto lvl4;
							}
						else if(a==5){
								goto lvl5;
					}
			lvl1:
			grid1(A);
			if(flag==1)
		    	break;
			char Opp;
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				lvl2:
				grid2(A);
				if(flag==1)
		    	break;
			}
			else{
				break;
			}
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				lvl3:
				grid3(A);
				if(flag==1)
		    	break;
			}
			else{
				break;
			}
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				lvl4:
				grid4(A);
				if(flag==1)
		    	break;
			}
			else{
				break;
			}
			cout<<"Do you want to continue to the next level(y/n)"; // condition to go to next level
			cin>>Opp;
			if(Opp=='y'||Opp=='Y'){
				system("cls");
				lvl5:
				grid5(A);
				if(flag==1)
		    	break;
				end();
				break;
			}
		
		}
		case 3:{ // case 3 for logout 
		
			break;
		}
	}
    if(choice!=3)// if condition for going back to In game menu if loged out
		Main_menu(A);
}
int main(){ //main function starts here
	char pass[30];
	userid A; // object of the class is created
	Game_menu: // Main menu
	cout<<"\t\t\t\t\t\t     SUDOKU\n";
	cout<<"\t\t\t\t\t\t      MENU\n";
	menu:
	cout<<"\t\t\t\t\t\t_______________"<<endl;
	cout<<"\t\t\t\t\t\t|Sno|Options  |"<<endl;
	cout<<"\t\t\t\t\t\t|---|---------| "<<endl;
	cout<<"\t\t\t\t\t\t|1. |Create ID|\n\t\t\t\t\t\t|2. |Login    |\n\t\t\t\t\t\t|3. |Exit     |"<<endl;
	cout<<"\t\t\t\t\t\t|___|_________|"<<endl;
	cout<<"\n\tEnter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice){ // switch
		case 1:{ // case 1 for creating id
			ofstream sf;
			sf.open("Save File.dat",ios::binary|ios::out|ios::app); 
			A.create_id(); // function for creating id is called
			sf.write((char*)&A,sizeof(userid)); // user details is stored in binary file
			Main_menu(A); // goes to In game menu after loged in
			if(choice == 3){
				goto Game_menu; // goes to main menu
				
			}
			sf.close();
			break;
	}
		case 2:{ // case 2 for loging in
			char c;
			ifstream sf;
			sf.open("Save File.dat",ios::binary|ios::in);
			A.enter_username(); // Taking the user id and password
			userid temp;
			int flag=0;
			while(sf.read((char*)&temp,sizeof(userid))){
				if(strcmp(A.username,temp.username)==0){ // if condition for checking password is correct or not
					flag=1;
					A=temp;
					re_enter:
							cout<<" \t\t\t Password: "; // taking password
                 				int i = 0;
    							char a;
    							for(i=0;;)
    							{
       							    a=getch();
        							if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        							{
              							pass[i]=a;
            							++i;
            							cout<<"*";
        							}
        							if(a=='\b'&&i>=1)
       								{
            							cout<<"\b \b";
            							--i;
       							    }
        							if(a=='\r')
        							{
            						pass[i]='\0';
           							 break;
        							}
    								}
					if(A.chk_pwd(pass)==0) // if condition for checking the password is correct or wrong
						cout<<"\n \t Logged in successfully"<<endl;
						else{
							cout<<"Try again(y/n)"<<endl;
							cin>>c;
							if(c=='y'||c=='Y')
							{
								goto re_enter;
							}
							else{
								goto menu;
							}
						}
						system("pause");
						system("cls");	
				}	
			}
			if(flag==0){ //  if condition if account is not found
				cout<<"User id not found \n";
				goto menu;	
		}
			while (choice!=3){
				system("cls");
				Main_menu(A);
			}
				sf.close();
				goto Game_menu;
			break;
			userid B;
			
		}
		
		case 3:{ // case 3 for exiting the game
			exit(1);
			break;
		}

		
		}}
