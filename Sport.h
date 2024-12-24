#pragma once

#include "Match.h"
typedef struct
{
	char* name;
	int playersInFaceOff;
	int minTeamsInMatch;
	int maxTeamsInMatch;
	int minPlayersOnTeam;
	int numOfMatchs;
	Match* matches;
}Sport;

void initSport(Sport* sport);
void printSportV(void* val);
void printMatches(const Sport* sports);
void printSport(const Sport* sports);
void freeSport(Sport* s);
void freeSportV(void* val);

