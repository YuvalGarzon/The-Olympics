#include <stdio.h>
#include <stdlib.h>
#include "Match.h"
#include "Olympics.h"
#include "General.h"


void	freeMatch(Match* m) {
	free(m->sport);
	generalArrayFunction(m->teams_playing, m->num_of_teams, sizeof(Country*), free);
}
void	freeMatchV(void* val) {
	freeMatch((Match*)val);
}

void	PrintMatchV(void* val) {
	printMatch((const Match*)val);
}

