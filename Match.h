#pragma once

#include "Date.h"
#include "Venue.h"
#include "Country.h"
typedef struct
{
	Venue* venue;
	char* sport;
	Country** teams_playing;
	int num_of_teams;
	Date date;
}Match;

void	PrintMatchV(void* val);
void	freeMatch(Match* m);
void	freeMatchV(void* val);
