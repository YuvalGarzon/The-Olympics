#include <stdio.h>
#include <stdlib.h>
#include "Sport.h"
#include "General.h"
#include "Match.h"
#include "Olympics.h"
void initSport(Sport* sport)
{
	sport->name = getStrExactName("Enter sport name: ");

	printf("Enter amount players in faceOff: ");
	int x =scanf("%d", &sport->playersInFaceOff);

	printf("\nEnter min amount competing in match: ");
	x = scanf("%d", &sport->minTeamsInMatch);

	printf("\nEnter max amount competing in match: ");
	x = scanf("%d", &sport->maxTeamsInMatch);

	printf("\nEnter min players on one team:  ");
	x = scanf("%d", &sport->minPlayersOnTeam);

	sport->numOfMatchs = 0;
	sport->matches = NULL;
}


void printSportV(void* val)
{
	printSport((const Sport*)val);
}

void printSport(const Sport* sports)
{
	printf("Sport name: %s\n Number of players competing in a game: %d\n", sports->name,sports->playersInFaceOff);

}

void printMatches(const Sport* sports)
{
	generalArrayFunction(sports->matches, sports->numOfMatchs, sizeof(Match), PrintMatchV);
}


void freeSport(Sport* s) {
	generalArrayFunction(s->matches, s->numOfMatchs, sizeof(Match), freeMatchV);
	free(s->name);
}
void freeSportV(void* val) {
	freeSport((Sport*)val);
}