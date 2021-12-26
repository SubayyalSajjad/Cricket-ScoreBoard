#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Team;

class toss_mechanics{

public:
	
	int toss (string t1,string t2)
	{   int a,b;
	    Toss:
		cout<<"Who Won The Toss? [ 1) "<<t1<<" 2) "<<t2<<" ]"<<endl;
		cin>>a;
		if (a==1)
		{
			cout<<t1<<" Won The Toss!!!"<<endl<<endl;
			return 1;
		}
		
		else if (a==2)
		{
			cout<<t2<<" Won The Toss!!!"<<endl<<endl;
			return 2;
		}
		
		else
		{
		cout<<"Invalid Entry Re-Enter Value!!!"<<endl<<endl;
		goto Toss;
	}
}

int choice()
{ int b;
		
	cout<<"What Did The Captain Choose To Do? [ 1) Batting 2) Bowling]"<<endl;
	cin>>b;
	if (b==1)
	{
		cout<<"And Chose to Bat!!!"<<endl<<endl;
		
		return 1;
	}
	
	else if (b==2)
	{
		cout<<"And Chose to Bowl!!!"<<endl<<endl;
		
		return 2;
	}
		
	}
	
};


class Team:public toss_mechanics{
	
	private:
		string team_name,player_name[11],player_type[11],venue,bowlers[11],striker,non_striker,bowler;
		int no_of_players,no_of_bowlers,no_of_overs,team_runs,player_runs[11],player_balls[11],bowlers_balls[11],bowlers_runs[11],bowlers_wickets[11],wickets_lost,target;
		double overs,check_overs,bowlers_overs[11];
		
	public:
		
		
		Team()
		{
			team_name="NIL";
			
			for (int i=0;i<11;i++)
			{
				player_name[i]="NIL";
				player_type[i]="NIL";
				bowlers[i]="NIL";
				player_runs[i]=0;
				player_balls[i]=0;
				bowlers_balls[i]=0;
				bowlers_overs[i]=0;
				bowlers_wickets[i]=0;
				bowlers_runs[i]=0;
							}
			
			no_of_players=0;
			no_of_bowlers=0;
			no_of_overs=0;
			check_overs=0;
			overs=0;
			team_runs=0;
			wickets_lost=0;
		}
//------------------------------------------------------------------------------------------------------------------------
		//setters
		
		void set_target(int a)
		{
			target=a;
		}
		
		void set_TeamName()
		{
			cout<<"Enter Team Name: ";
			getline(cin,team_name);
			cout<<endl;
		}
		
		
		
		void set_NoOfPlayers()
		{
		
			rerun:
			cout<<"Enter Number of Players in Team "<<team_name<<" : ";
			cin>>no_of_players;
			if (no_of_players>11 || no_of_players<1)
			{
				cout<<"Invalid Number of Players!!!! Re-Enter Value "<<endl;
				goto rerun;
			}
			
		
		}
		
		
		
		void set_players()
		{
			int count;
			count=0;
			for (int i=0;i<no_of_players;i++)
			{
	             cin.ignore(10,'\n');
				cout<<"Enter Name For Player "<<i+1<<" :";
				getline(cin,player_name[i]);
				cout<<"Enter Player Type: ";
				getline(cin,player_type[i]);
				
				if(player_type[i]=="bowler"||player_type[i]=="Bowler")
				{
					bowlers[count]=player_name[i];
					count++;
					no_of_bowlers++;
				}
			}
			}
		
		
		
			void set_Venue()
		{
			cout<<"Enter Venue: ";
			cin>>venue;
		}
		
		
		
			void set_Venue(string i)
		{
			venue=i;
		}
		
		
		void set_striker(string a)
{
	striker=a;
}



void set_non_striker(string a)
{
	non_striker=a;
}



void set_no_of_overs(int o)
{
	no_of_overs=o;
}
		
		string getTeam_name()
		{
			return team_name;
		}
		
		
		void set_bowlers_runs(int a,int b)
{

	bowlers_runs[a]+=b;

}



void set_bowlers_overs(int a,int b)
{
	bowlers_overs[a]+=b;
}

void set_bowler(string a)
{
	bowler=a;
}

void set_bowlers_balls(int a,int b)
{
	bowlers_balls[a]=b;
}

void increase_bowlers_wickets(int a)
{
	bowlers_wickets[a]++;
}

void set_new_bowler()
{
	int q;
	string temp;
	cout<<endl<<"End Of The Over!!!"<<endl<<endl;
	cout<<endl<<"Who is Going to Bowl? :";
	cin>>q;
	
	bowler=bowlers[q-1];
	temp=striker;
	striker=non_striker;
	non_striker=temp;
	cout<<endl;
	
}
//-------------------------------------------------------------------------------------------


//  Getter-----------------------------------------------------------------------------------------------		
		
		string getVenue ()
		{
			return venue;
		}

int get_team_score()
{
	return team_runs;
}

string get_team_name()
{
	return team_name;
}


string get_player_name(int a)
{
	return player_name[a];
}


double get_overs()
{
	return overs;
}

int get_no_of_overs()
{
	return no_of_overs;
}

string get_bowler()
{
	return bowler;
}

string get_bowlers(int a)
{
	return bowlers[a];
}

int get_bowler_runs(int a)
{
	return bowlers_runs[a];
}

int get_bowler_wickets(int a)
{
	return bowlers_wickets[a];
}

double get_bowlers_overs(int a)
{
	return bowlers_overs[a];
}

int get_bowlers_balls(int a)
{
	return bowlers_balls[a];
}
//--------------------------------------------------------------------------------------------


//       show---------------------------------------------------------------------------------------------------------
		void Show_Players()
		{
			cout<<"			"<<"-----------------------------------------"<<endl;
			cout<<"			"<<"| Player Name "<<setw(20)<<"|"<<" Player Type"<<endl;
			cout<<"			"<<"-----------------------------------------"<<endl;
			
			for (int i=0;i<no_of_players;i++)
			{
	cout<<"			"<<"|"<<" "<<i+1<<")"<<" "<<player_name[i]<<" "<<setw(27)<<"|"<<" "<<player_type[i]<<endl;
			}
			cout<<"			"<<"-----------------------------------------"<<endl;
		}
		
		
	void show_bowlers()
{
		    cout<<"			"<<"------------------------------------------------"<<endl;
			cout<<"			"<<"| Bowler's Name   "<<setw(10)<<endl;
			cout<<"			"<<"------------------------------------------------"<<endl;
			
			for (int i=0;i<no_of_bowlers;i++)
			{
	cout<<"			"<<"|"<<" "<<i+1<<")"<<" "<<bowlers[i]<<" "<<endl;
			}
				cout<<"			"<<"----------------------------"<<endl;
			
}


void show_scoreboard(Team *t)
{
 int i,j,k;

 
i=0;
j=0;
k=0;

	while(player_name[i]!=striker)
	{
		i++;
	}
	
		while(player_name[j]!=non_striker)
	{
		j++;
	}
	
	while (t->get_bowlers(k)!=t->get_bowler())
	{
		k++;
	}
	cout<<"----------------------------------------"<<endl;
	cout<<"| "<<striker<<" *"<<"    "<<player_runs[i]<<"("<<player_balls[i]<<")"<<setw(20)<<"|"<<" Score:"<<team_runs<<"-"<<wickets_lost<<"   "<<team_name<<" VS "<<t->get_team_name()<<"     "<<"Overs: "<<overs<<endl;
	cout<<"| "<<non_striker<<"      "<<player_runs[j]<<"("<<player_balls[j]<<")"<<setw(20)<<"|"<<"     "<<"    "<<t->get_bowlers(k)<<"     "<<t->get_bowler_wickets(k)<<"-"<<t->get_bowler_runs(k)<<endl;
	cout<<"----------------------------------------"<<endl<<endl;
}
	
	
	void show_bowlers_array()
	{
		for (int i=0;i<11;i++)
		{
			cout<<bowlers[i]<<endl;
		}
		
		}
		
	void show_ballers_runs()
	{
			for (int i=0;i<11;i++)
		{
			cout<<bowlers_runs[i]<<endl;
		}
		}	
//--------------------------------------------------------------------------------------------------------



//  Miscellaneous   Functions----------------------------------------------------------------  
void setup(Team *t)
	{  int v;
	
	cout<<endl<<"How Many Overs in This Match ? "<<endl;
	cin>>v;
	no_of_overs=v;
	t->set_no_of_overs(v);
	
        striker=player_name[0];
		non_striker=player_name[1];
		
		
		cout<<endl<<"Who is Bowling From Team "<<t->getTeam_name()<<" (Enter Player Number):";
		cin>>v;
		t->set_bowler(t->get_bowlers(v-1));
		

	}
	


int play_ball(Team *t )
{ char ch,p,c;
int i,b,a;
string temp;
i=0;
a=0;

b=t->get_bowlers_balls(a);

	while(player_name[i]!=striker)   //find Striker Index
	{
		i++;
	}
	
while(t->get_bowlers(a)!=t->get_bowler())   // find bowler index
{
	a++;
}
	cout<<endl<<"What Happened in This Ball? ( 0,1,2,3,4,6,O (out) ,w (wide),l (leg By),n (no Ball) ) : ";
	cin>>ch;
	
	
		
	switch (ch)               //Define Whats Happening in Match
{
	//                0 Runs
	case '0':
	
		player_runs[i]+=0;
		player_balls[i]+=1;
	
		t->set_bowlers_runs(a,0);
	
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
		t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
     	
		
		//team runs
		team_runs+=0;
		
	if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;
		
	//                1 Run	
		case '1':
	
	player_runs[i]+=1;
		player_balls[i]+=1;
	
		t->set_bowlers_runs(a,1);
	
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
     	
     	//rotate strike
		
		temp=non_striker;
		non_striker=striker;
		striker=temp;
		
		//team runs
		team_runs+=1;
		
	if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
				t->set_new_bowler();
		
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;
	
//                 2 Runs
	case '2':
	
		player_runs[i]+=2;
		player_balls[i]+=1;
	
		t->set_bowlers_runs(a,2);
	
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
     	
		
		//team runs
		team_runs+=2;
		
	if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;
		
//                      3 Runs		
		case '3':
	
			player_runs[i]+=3;
		player_balls[i]+=1;
	
		t->set_bowlers_runs(a,3);
	
			if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
     	
		//rotate strike
		temp=non_striker;
		non_striker=striker;
		striker=temp;
			
		//team runs
		team_runs+=3;
		
	if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
				t->set_new_bowler();
		
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;
		
//                    4 Runs		
		case '4':
	
			player_runs[i]+=4;
		player_balls[i]+=1;
	
		t->set_bowlers_runs(a,4);
	
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
     	
		
		//team runs
		team_runs+=4;
		
	if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
				t->set_new_bowler();
		
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;
		
//                   6 Runs	
		case '6':
	
		player_runs[i]+=6;
		player_balls[i]+=1;
	
		t->set_bowlers_runs(a,6);
	
			if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
     	
		
		//team runs
		team_runs+=6;
		
	if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;

//               OUT		
	case 'o':

	if((wickets_lost==(no_of_players-1))|| striker=="NIL" || non_striker=="NIL")
	{
		cout<<"No More Players Can Bat, Innings is Over!!"<<endl;
		return 0;
	}
	
	else if (player_name[i+1]==non_striker)
	{
		striker=player_name[i+2];
	}
	else
	striker=player_name[i+1];
	
	wickets_lost++;
    t->increase_bowlers_wickets(a);
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
	
		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		
		break;
		
//               OUT (Capital)
		case 'O':
	
	if((wickets_lost==(no_of_players-1))||striker=="NIL"|| non_striker=="NIL")
	{
		cout<<"No More Players Can Bat, Innings is Over!!"<<endl;
		return 0;
	}
	
	else if (player_name[i+1]==non_striker)
	{
		striker=player_name[i+2];
	}
	else
	striker=player_name[i+1];
	
	wickets_lost++;
    t->increase_bowlers_wickets(a);
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);
	
		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;
			
		}
		break;
	
//                       WIDE	
	case 'w':
	team_runs+=1;
	t->set_bowlers_runs(a,1);
	break;
	
//                       WIDE
	case'W':
	team_runs+=1;
	t->set_bowlers_runs(a,1);
	break;

//                  LEG BY	
	case 'l':
		cout<<"How Many Runs from Leg By (1,2,3,4,5,6):";
		cin>>c;
		
		switch(c)
		{
			case'1':
			team_runs+=1;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
				t->set_new_bowler();
		
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
	
	case '2':
					team_runs+=2;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '3':
					team_runs+=3;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '4':
					team_runs+=4;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '5':
					team_runs+=5;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '6':
				team_runs+=6;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;	
	}
	break;
	
//                             LEG BYES (Capital)
		case 'L':
		cout<<"How Many Runs from Leg By (1,2,3,4,5,6):";
		cin>>c;
		
		switch(c)
		{
			case'1':
			team_runs+=1;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
	
	case '2':
					team_runs+=2;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '3':
					team_runs+=3;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '4':
					team_runs+=4;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '5':
					team_runs+=5;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;
		
	case '6':
				team_runs+=6;
    
		if(b==6)
		{
		t->set_bowlers_overs(a,1);
		t->set_bowlers_balls(a,0);
			t->set_new_bowler();
     	}
     	else
     	t->set_bowlers_overs(a,0.1);

		if (overs==0)
	{
		overs+=0.1;
		check_overs+=0.1;
	}
	
	else if (check_overs==0.5)
		{
			overs+=check_overs;
			check_overs=0;
			t->set_new_bowler();
		}
		else
		{
			check_overs+=0.1;
			overs+=0.1;	
		}
		break;	
		
		}
		break;

//                        No Ball	
	case'n':
		cout<<endl<<"No Ball, Free Hit!!"<<endl;
		cout<<endl<<"What had happened on The Ball? (0,1,2,3,4,6,o (out),l(Leg By),w (wide) ) :";
		cin>>p;
		
		switch(p)
		{
				case '0':
	
		t->set_bowlers_runs(a,0);
     	
		
		//team runs
		team_runs+=0;

		break;
		
		
		case '1':
	
		t->set_bowlers_runs(a,1);
		//team runs
		team_runs+=1;
		break;
	
	
	case '2':
	
	
		t->set_bowlers_runs(a,2);
		//team runs
		team_runs+=2;
		break;
		
		
		case '3':
	
		t->set_bowlers_runs(a,3);
		//team runs
		team_runs+=3;
		break;
		
		
		case '4':
	
		t->set_bowlers_runs(a,4);
		//team runs
		team_runs+=4;
		break;
		
	
		case '6':
		t->set_bowlers_runs(a,6);
		//team runs
		team_runs+=6;
		break;
		
	case 'o':
	cout<<endl<<"Not Out!!!"<<endl;
	break;

		case 'O':
	cout<<endl<<"Not Out!!!"<<endl;
	break;
		
	case 'w':
	team_runs+=1;
	t->set_bowlers_runs(a,1);
	break;
	
	case'W':
	team_runs+=1;
	t->set_bowlers_runs(a,1);
	break;
	
	case 'l':
		team_runs+=1;
		t->set_bowlers_runs(a,1);
		
		cout<<"How Many Runs from Leg By (1,2,3,4,5,6) on No-Ball :";
		cin>>c;

		switch(c)
		{
			case'1':
		team_runs+=1;
		break;
	
	case '2':
		team_runs+=2;
		break;
		
	case '3':
		team_runs+=3;
		break;
		
	case '4':
		team_runs+=4;
		break;
		
	case '5':
		team_runs+=5;
		break;
		
	case '6':
		team_runs+=6;
		break;	
	}
	break;
	
		case 'L':
		team_runs+=1;
		cout<<"How Many Runs from Leg By (1,2,3,4,5,6) on No-Ball :";
		cin>>c;
		switch(c)
		{
			case'1':
		team_runs+=1;
		break;
	
	case '2':
		team_runs+=2;
		break;
		
	case '3':
		team_runs+=3;
		break;
		
	case '4':
		team_runs+=4;
		break;
		
	case '5':
		team_runs+=5;
		break;
		
	case '6':
		team_runs+=6;
		break;	
		}
		break;
	
		}
		break;
		
//                     No Ball (Capital)
		case'N':
		cout<<endl<<"No Ball, Free Hit!!"<<endl;
		cout<<endl<<"What had happened on The Ball? (0,1,2,3,4,6,o (out),l(Leg By),w (wide) ) :";
		cin>>p;
		
		switch(p)
		{
		case '0':
		t->set_bowlers_runs(a,0);
		//team runs
		team_runs+=0;
		break;
		
		
		case '1':
		t->set_bowlers_runs(a,1);
		//team runs
		team_runs+=1;
		break;
	
	
	case '2':
		t->set_bowlers_runs(a,2);
		//team runs
		team_runs+=2;
		break;
		
		
	case '3':
		t->set_bowlers_runs(a,3);
		//team runs
		team_runs+=3;
		break;
		
		
	case '4':
		t->set_bowlers_runs(a,4);
		//team runs
		team_runs+=4;
		break;
		
	
	case '6':
		t->set_bowlers_runs(a,6);
		//team runs
		team_runs+=6;
		break;
		
	case 'o':
	cout<<endl<<"Not Out!!!"<<endl;
	

		case 'O':
	cout<<endl<<"Not Out!!!"<<endl;
		
	case 'w':
	team_runs+=1;
	t->set_bowlers_runs(a,1);
	
	case'W':
	team_runs+=1;
	t->set_bowlers_runs(a,1);
	
	case 'l':
		team_runs+=1;
		t->set_bowlers_runs(a,1);
		cout<<"How Many Runs from Leg By (1,2,3,4,5,6) on No-Ball :";
		cin>>c;
		switch(c)
		{
			case'1':
			team_runs+=1;
		break;
	
	case '2':
		team_runs+=2;
		break;
		
	case '3':
		team_runs+=3;
		break;
		
	case '4':
		team_runs+=4;
		break;
		
	case '5':
		team_runs+=5;
		break;
		
	case '6':
		team_runs+=6;
		break;	
	}
	break;
	

		case 'L':
		team_runs+=1;
		t->set_bowlers_runs(a,1);
		cout<<"How Many Runs from Leg By (1,2,3,4,5,6) on No-Ball :";
		cin>>c;

		
		switch(c)
		{
			case'1':
		team_runs+=1;
		break;
	
	case '2':
		team_runs+=2;
		break;
		
	case '3':
		team_runs+=3;
		break;
		
	case '4':
		team_runs+=4;
		break;
		
	case '5':
		team_runs+=5;
		break;
		
	case '6':
		team_runs+=6;
		break;	
		}
     break;
			
		}
		break;
		
		}
	
	}
};


//-----------------------------------------------------------------------------------------------------------------------





int main()
{
  Team t1,t2,*t;
  

  
  string a,b,d,g,h;
  int c,e,f,l,m,n,o,p;
  char ch;
  double k;
  
  // Team 1 Data Entry
  cout<<"-----------------------------------------"<<endl;
  cout<<"\t Enter Data For Team 1 \t\t"<<endl;
  cout<<"-----------------------------------------"<<endl<<endl;
  t1.set_TeamName();
  t1.set_NoOfPlayers();
  t1.set_players();	
  t1.Show_Players();
  
  //Team 2 Data Entry
  cout<<"-----------------------------------------"<<endl;
  cout<<"\t\t Enter Data For Team 2 \t\t"<<endl;
  cout<<"-----------------------------------------"<<endl<<endl;
  t2.set_TeamName();
  t2.set_NoOfPlayers();
  t2.set_players();	
  t2.Show_Players();
  
  //Venue
  t1.set_Venue();
  d=t1.getVenue();
  t2.set_Venue(d);
  
  
  // Toss
  cout<<endl<<"Heading Over To The Toss!!!!"<<endl<<endl;
  a=t1.getTeam_name();
  b=t2.getTeam_name();
  c=t1.toss(a,b);
  
  
  
  g=t1.getTeam_name();
  h=t2.getTeam_name();
   
  if (c==1)
  {
  	e=t1.choice();
  	system("PAUSE");
	system("CLS");
  	// team order if t1 wins the toss and bats
  	if (e==1)
  	{ 
  	                 //   First Innings
  	                                        
  	    cout<<"Team "<<g<<" Won The Toss and Elected to Bat!!!"<<endl<<endl;
  	   t1.Show_Players();
  	   cout<<endl;
  	   
	   t2.show_bowlers();
	   cin.ignore(100,'\n');
  	   cout<<endl<<"Press \"Enter\" to Begin First Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t2;
  	    t1.setup(t);
  	   
  	    t1.show_scoreboard(t);
  	    
  	    l=t1.get_no_of_overs();
  	    do 
		  {
		  	
		 n= t1.play_ball(t);
		 
		if(n==0)
	    {
		break;
		 }
	
		    k=t1.get_overs();
		  t1.show_scoreboard(t);
		
  	   }
  	   while (k<l);
  	   cout<<"Innings Ended!! , "<<t1.getTeam_name()<<" Gave a Target of "<<t1.get_team_score()<<" to "<<t2.getTeam_name()<<endl;
  	   
		 }
		 system("PAUSE");
		 system("CLS");
		   //      Second Innings
  	    t2.set_target(t1.get_team_score());
  	    
  	     t2.Show_Players();
  	   cout<<endl;
  	   
	   t1.show_bowlers();
	   cin.ignore(100,'\n');
	   
  	   cout<<endl<<"Press \"Enter\" to Begin Second Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t1;
  	    t2.setup(t);
  	   
  	    t2.show_scoreboard(t);
  	    
  	    l=t2.get_no_of_overs();
  	    p=t1.get_team_score();
  	    
  	    
  	    do 
		  {
		  	
		 n= t2.play_ball(t);
		 
		if(n==0)
	    {
	    	cout<<t1.getTeam_name()<<" Won The Match!!! "<<endl;
		break;
		 }
	
		    k=t2.get_overs();
		    o=t2.get_team_score();
		    
		cout<<endl<<" "<<o<<" "<<p<<endl<<endl;
		    
		  t2.show_scoreboard(t);
		if (o>=p)
		{
			cout<<endl<<t2.get_team_name()<<" Won the Match!!"<<endl;
			break;
		}
  	   }
  	   while ( k<l);
  	  
  	   
		 }
	  }
  
  

  	// team order if t1 wins the toss and bowls
  	else if (e==2)
  	{
  		 cout<<"Team "<<g<<" Won The Toss and Elected to Bowl!!!"<<endl<<endl;
  		t2.Show_Players();
  		cout<<endl;
  		t1.show_bowlers();
  		cin.ignore(100,'\n');
  	   cout<<endl<<"Press \"Enter\" to Begin First Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t1;
  	    t2.setup(t);
  	   
  	    t2.show_scoreboard(t);
  	    
  	    l=t2.get_no_of_overs();
  	    do 
		  {
		  	
		 n= t2.play_ball(t);
		 
		if(n==0)
	    {
		break;
		 }
	
		    k=t2.get_overs();
		  t2.show_scoreboard(t);
		
  	   }
  	   while (k<l);
  	   cout<<"Innings Ended!! , "<<t2.getTeam_name()<<" Gave a Target of "<<t2.get_team_score()<<" to "<<t1.getTeam_name()<<endl;
  	   
		 }
		 system("PAUSE");
		 system("CLS");
		   //      Second Innings
  	    t1.set_target(t2.get_team_score());
  	    
  	     t1.Show_Players();
  	   cout<<endl;
  	   
	   t2.show_bowlers();
	   cin.ignore(100,'\n');
	   
  	   cout<<endl<<"Press \"Enter\" to Begin Second Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t2;
  	    t1.setup(t);
  	   
  	    t1.show_scoreboard(t);
  	    
  	    l=t1.get_no_of_overs();
  	    p=t2.get_team_score();
  	    
  	    
  	    do 
		  {
		  	
		 n= t1.play_ball(t);
		 
		if(n==0)
	    {
	    	cout<<t2.getTeam_name()<<" Won The Match!!! "<<endl;
		break;
		 }
	
		    k=t1.get_overs();
		    o=t1.get_team_score();
		    
		cout<<endl<<" "<<o<<" "<<p<<endl<<endl;
		    
		  t1.show_scoreboard(t);
		if (o>=p)
		{
			cout<<endl<<t1.get_team_name()<<" Won the Match!!"<<endl;
			break;
		}
  	   }
  	   while ( k<l);
  	  
  	   
		 }
	  }
  }
  
  
  
  else if (c==2)
  {
  	f=t2.choice();
  	system("CLS");
  	// team order if t2 wins the toss and bats
  	if (f==1)
  	{
  		 cout<<"Team "<<h<<" Won The Toss and Elected to Bat!!!"<<endl<<endl;
  		t2.Show_Players();
  		cout<<endl;
  		t1.show_bowlers();
  			cin.ignore(100,'\n');
  	   cout<<endl<<"Press \"Enter\" to Begin First Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t1;
  	    t2.setup(t);
  	   
  	    t2.show_scoreboard(t);
  	    
  	    l=t2.get_no_of_overs();
  	    do 
		  {
		  	
		 n= t2.play_ball(t);
		 
		if(n==0)
	    {
		break;
		 }
	
		    k=t2.get_overs();
		  t2.show_scoreboard(t);
		
  	   }
  	   while (k<l);
  	   cout<<"Innings Ended!! , "<<t2.getTeam_name()<<" Gave a Target of "<<t2.get_team_score()<<" to "<<t1.getTeam_name()<<endl;
  	   
		 }
		 system("PAUSE");
		 system("CLS");
		   //      Second Innings
  	    t1.set_target(t2.get_team_score());
  	    
  	     t1.Show_Players();
  	   cout<<endl;
  	   
	   t2.show_bowlers();
	   cin.ignore(100,'\n');
	   
  	   cout<<endl<<"Press \"Enter\" to Begin Second Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t2;
  	    t1.setup(t);
  	   
  	    t1.show_scoreboard(t);
  	    
  	    l=t1.get_no_of_overs();
  	    p=t2.get_team_score();
  	    
  	    
  	    do 
		  {
		  	
		 n= t1.play_ball(t);
		 
		if(n==0)
	    {
	    	cout<<t2.getTeam_name()<<" Won The Match!!! "<<endl;
		break;
		 }
	
		    k=t1.get_overs();
		    o=t1.get_team_score();
		    
		cout<<endl<<" "<<o<<" "<<p<<endl<<endl;
		    
		  t1.show_scoreboard(t);
		if (o>=p)
		{
			cout<<endl<<t1.get_team_name()<<" Won the Match!!"<<endl;
			break;
		}
  	   }
  	   while ( k<l);
  	  
  	   
		 }
	  }
  		
	  }
	  
	  
	// team order if t2 wins the toss and bowls
	else if (f==2)
	{
	              //   First Innings
  	                                        
  	    cout<<"Team "<<h<<" Won The Toss and Elected to Bowl!!!"<<endl<<endl;
  	   t1.Show_Players();
  	   cout<<endl;
  	   
	   t2.show_bowlers();
	   cin.ignore(100,'\n');
  	   cout<<endl<<"Press \"Enter\" to Begin First Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t2;
  	    t1.setup(t);
  	   
  	    t1.show_scoreboard(t);
  	    
  	    l=t1.get_no_of_overs();
  	    do 
		  {
		  	
		 n= t1.play_ball(t);
		 
		if(n==0)
	    {
		break;
		 }
	
		    k=t1.get_overs();
		  t1.show_scoreboard(t);
		
  	   }
  	   while (k<l);
  	   cout<<"Innings Ended!! , "<<t1.getTeam_name()<<" Gave a Target of "<<t1.get_team_score()<<" to "<<t2.getTeam_name()<<endl;
  	   
		 }
		 system("PAUSE");
		 system("CLS");
		   //      Second Innings
  	    t2.set_target(t1.get_team_score());
  	    
  	     t2.Show_Players();
  	   cout<<endl;
  	   
	   t1.show_bowlers();
	   cin.ignore(100,'\n');
	   
  	   cout<<endl<<"Press \"Enter\" to Begin Second Innings!!!";
	   cin.get(ch);
	   
  	   if (ch=='\n')
  	   { t=&t1;
  	    t2.setup(t);
  	   
  	    t2.show_scoreboard(t);
  	    
  	    l=t2.get_no_of_overs();
  	    p=t1.get_team_score();
  	    
  	    
  	    do 
		  {
		  	
		 n= t2.play_ball(t);
		 
		if(n==0)
	    {
	    	cout<<t1.getTeam_name()<<" Won The Match!!! "<<endl;
		break;
		 }
	
		    k=t2.get_overs();
		    o=t2.get_team_score();
		    
		cout<<endl<<" "<<o<<" "<<p<<endl<<endl;
		    
		  t2.show_scoreboard(t);
		if (o>=p)
		{
			cout<<endl<<t2.get_team_name()<<" Won the Match!!"<<endl;
			break;
		}
  	   }
  	   while ( k<l);
  	  
  	   
		 }
	
	}
	
	system("PAUSE");
	system("CLS");
	cout<<"~~~~~~~~~~ Program By ~~~~~~~~~~"<<endl;
	cout<<"Subayyal Sajjad (201098)"<<endl;
	cout<<"Muhammad Asad   (201158)"<<endl;
	cout<<"Ghazal Aamir    (201121)"<<endl;
  }
  
  





