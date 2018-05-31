/*
 * rps.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: Kathan Patel
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// max rounds per game
const int MAX_ROUNDS = 20;

int name(string& username_f);					/*this function takes the USER NAME*/
int choice(int& count_f, char& user_choice_f);	/*this function takes the user CHOICE*/
int random_number(int& count_f,int& computer_choice_f);	/*this function generates the RANDOM number*/
int winner(char& user_choice_f, int& computer_choice_f,int& tie_f,int& human_wins_f, int& computer_wins_f); /*this function decides the winner of each round*/
void record_win( int& tie_f, int& human_wins_f, int& computer_wins_f ); /*this function records the winner of each round*/


int main()
{
	string username;

	int count;								/*counts the round number# */
	count=1;								/*initialize the counter*/
	int computer_choice;
    srand(time(NULL));  					/* seed the random number generator */

    char user_choice;

    int tie=0;
    int human_wins=0;
    int computer_wins=0;

    name(username);							/* calling the function to get NAME */
    cout<<"\n \n";
    while(count<=MAX_ROUNDS)
    {
    choice( count, user_choice );				/* calling this function to get user CHOICE */
    computer_choice=random_number( count, computer_choice );		/* calling this function to get RANDOM number */
    winner( user_choice, computer_choice, tie, human_wins, computer_wins ); /*this function chooses the winner*/

    cout<<"\n 'the summary till CURRENT round' \n";
    record_win(tie, human_wins, computer_wins); /*this function records the winner at the end of each round*/
    }

    cout<<"\n \n \n";
    cout<<"\n \n"<<"SUMMARY"<<"\n"<<"-------"<<"\n";
    record_win(tie, human_wins, computer_wins);/*calling this function to display the FINAL SCORES*/

	return 0;
}






/*function-1: 					 to get the USERNAME*/

int name(string& username_f)
{
	cout<<"Enter your name:  ";
	cin>>username_f;
	return 0;
}






/*function -2: 					to get USER choice*/

int choice(int& count_f, char& user_choice_f)
{
	cout<<"Round "<<count_f<<"\n";
	cout<<"Your choice? ";
	cin>>user_choice_f;
	if(user_choice_f=='r' || user_choice_f=='R')
		cout<<"You chose ROCK."<<"\n";
	else if(user_choice_f=='p' || user_choice_f=='P' )
		cout<<"You chose PAPER."<<"\n";
	else if(user_choice_f=='s' || user_choice_f=='S' )
		cout<<"You chose SCISSORS."<<"\n";
	else
		{cout<<"*** ERROR: Valid choices are R, P, or S \n"<<"this ROUND will be repeated \n"; count_f--;}

	/*repeats the round if NON-VALID choices are entered*/
	return 0;
}






/*function-3: 					 to get RANDOM NUMBERS*/

int random_number(int& count_f, int& computer_choice_f)
{
    computer_choice_f=(rand()%3);
    if(computer_choice_f==0)
    	cout<<"The computer chose ROCK."<<"\n";
    if(computer_choice_f==1)
    	cout<<"The computer chose PAPER."<<"\n";
    if(computer_choice_f==2)
    	cout<<"The computer chose SCISSORS."<<"\n";
    count_f++;
	return computer_choice_f;
}






/*function-4: 					 to DEICDE the winner*/

int winner(char& user_choice_f, int& computer_choice_f, int& tie_f, int& human_wins_f, int& computer_wins_f)
{
	if((user_choice_f=='r' || user_choice_f=='R')&& computer_choice_f==0)
			{ cout<<"This is a TIE"<<"\n"; tie_f++;}
	else if((user_choice_f=='r' || user_choice_f=='R') && computer_choice_f==1)
			{ cout<<"The winner is COMPUTER"<<"\n"; computer_wins_f++;}
	else if((user_choice_f=='r' || user_choice_f=='R') && computer_choice_f==2)
			{ cout<<"The winner is YOU"<<"\n"; human_wins_f++;}
	else if((user_choice_f=='p' || user_choice_f=='P') && computer_choice_f==0)
			{ cout<<"The winner is YOU"<<"\n"; human_wins_f++;}
	else if((user_choice_f=='p' || user_choice_f=='P') && computer_choice_f==1)
			{ cout<<"This is a TIE"<<"\n"; tie_f++;}
	else if((user_choice_f=='p' || user_choice_f=='P') && computer_choice_f==2)
			{ cout<<"The winner is COMPUTER"<<"\n"; computer_wins_f++;}
	else if((user_choice_f=='s' || user_choice_f=='S') && computer_choice_f==0)
			{ cout<<"The winner is COMPUTER"<<"\n"; computer_wins_f++;}
	else if((user_choice_f=='s' || user_choice_f=='S') && computer_choice_f==1)
			{ cout<<"The winner is YOU"<<"\n"; human_wins_f++;}
	else if((user_choice_f=='s' || user_choice_f=='S') && computer_choice_f==2)
			{ cout<<"This is a TIE"<<"\n"; tie_f++;}
	else
			{cout<<"this is NOT a VALID round \n ";}

	return 0;
}






/*function-5: 					to record the winner after each round*/

void record_win( int& tie_f, int& human_wins_f, int& computer_wins_f )
{
		cout<<setw(15)<<"Human wins: "<<human_wins_f<<"\n";
		cout<<setw(15)<<"Computer wins: "<<computer_wins_f<<"\n";
		cout<<setw(15)<<"Ties: "<<tie_f<<"\n";
		cout<<"\n \n";
}

