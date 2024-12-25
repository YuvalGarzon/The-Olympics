#include <stdio.h>
#include <stdlib.h>
#include "Athlete.h"
#include "General.h"
#include "Country.h"
#include "Sport.h"

void freeAthlete(Athlete* a) {
	free(a->country);
	//free(a->sport);
}

void freeAthletePtr(void* pAthletePtr) {
	Athlete* temp = *(Athlete**)pAthletePtr;
	freeAthlete(temp);
	free(temp);
}