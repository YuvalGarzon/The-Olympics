#pragma once
struct Sport;
struct Country;
typedef struct
{
	char* name;
	int height;
	int weight;
	int age;
	struct Country* country;
	struct Sport* sport;
}Athlete;

void freeAthlete(Athlete* a);
void freeAthletePtr(void* pAthletePtr);

