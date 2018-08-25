/*Monty Hall Problem Checker
Created by WilliamBD
in August 2018
to simulate the Monty Hall Problem*/
#include <cstdio>
#include <cstdlib>
#include <time.h>
int main()
{	
	int winsSwitch=0;
	int switchGames=0;

	int winsStay = 0;
	int stayGames = 0;
	srand(time(NULL));
	printf("Switching:\n");
	for (int i = 0; i<2000; i++)
	{

		//the car is always behind door 1, for simplicity (It doesn't really matter).

		int car = 1;

		//the choice made by player
		int choice = rand()%3+1;

		//if the choice is same as car, pick 2 xor 3 to reveal
		int reveal;
		if (choice == car){
			reveal = rand()%2+2;
		}else{
			//picks the only door left to reveal
			reveal = (6-(car+choice));
		}

		//picks the other door
		choice = (6-(reveal+choice));

		if(choice == car){
			printf("Win %d\n",switchGames);
			winsSwitch++;

		}else{
			printf("Loss %d\n",switchGames);
		}
		switchGames++;
	}
	double winRateSwitch = ((double)winsSwitch / (double)switchGames);
	printf("%d \n",winsSwitch);
	printf("%d \n",switchGames);
	printf("%f \n",winRateSwitch);

	printf("Staying:\n");
	for (int i = 0; i<2000; i++)
	{

		//the car is always behind door 1, for simplicity (It doesn't really matter).

		int car = 1;

		//the choice made by player
		int choice = rand()%3+1;

		if(choice == car){
			printf("Win %d\n",stayGames);
			winsStay++;

		}else{
			printf("Loss %d\n",stayGames);
		}
		stayGames++;
	}
	double winRateStay = (double)winsStay / (double)stayGames;
	printf("%d \n",winsStay);
	printf("%d \n",stayGames);
	printf("%f \n",winRateStay);
	printf("<-----For comparison----->\n");
	printf("winRateStay: %f \n",winRateStay);
	printf("winRateSwitch: %f \n",winRateSwitch);
	//cool project would be to do a significance test

	return 0;



}