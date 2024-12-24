#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venue.h"
#include "General.h"

eSurfaceType getSurfaceType()
{
	int option;
	printf("\n\n");
	do {
		printf("Please enter one of the following types\n");
		for (int i = 0; i < eNofSurfaceTypes; i++)
			printf("%d for %s\n", i, SurfaceTypeStr[i]);
		scanf("%d", &option);
	} while (option < 0 || option >= eNofSurfaceTypes);
	getchar();
	return (eSurfaceType)option;
}

void initVenue(Venue* venue, Venue* venueArr, int venueCount) {
	venue->name = getVenueName(venueArr, venueCount);
	int num = 0;
	do {
		printf("Enter max attandance for venue \n");
		scanf("%d", &num);
	} while (num < 0);
	venue->attendance = num;
	do {
		printf("Enter length of playing surface \n");
		scanf("%d", &num);
	} while (num < 0);
	venue->length = num;
	do {
		printf("Enter width of playing surface \n");
		scanf("%d", &num);
	} while (num < 0);
	venue->width = num;
	venue->surface = getSurfaceType();
}

int isVenueNameUnique(Venue* venues, int venueCount, char* name)
{
	for (int i = 0; i < venueCount; i++)
	{
		if (!strcmp(venues[i].name, name))
			return 0;
	}
	return 1;
}

char* getVenueName(Venue* venues, int venueCount)
{
	int unique = 0;
	char* name = NULL;
	do
	{
		name = getStrExactName("Enter venue name (Will repeat untill given an name that does not yet exsit): ");
		unique = isVenueNameUnique(venues, venueCount, name);
	} while (!unique);
	return name;
}

void printVenue(const Venue* venue) {
	printf("\nVenue %s\nMaximun attendance: %d\nDementions: %d in length, %d in width\nPlaying surface: %s", venue->name, venue->attendance, venue->length, venue->width, SurfaceTypeStr[venue->surface]);
}
void	printVenueV(void* val)
{

	printVenue((const Venue*)val);
}
void	freeVenue(Venue* v) {
	free(v->name);
}
void	freeVenueV(void* val) {
	freeVenue((Venue*)val);
}