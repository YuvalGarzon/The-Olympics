#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "City.h"
#include "General.h"

void initCity(City* city)
{
	city->name = getStrExactName("Enter city name: ");
	int num = 0;
	do {
		printf("Enter how many hotel rooms the city has:");
		scanf("%d", &num);
	} while (num < 0);
	city->hotel_rooms = num;
	city->venues = NULL;
	city->venue_count = 0;
}

int	addVenue(City* city) {
	city->venues = (Venue*)realloc(city->venues, (city->venue_count + 1) * sizeof(Venue));
	if (!city->venues)
		return 0;
	initVenue(&city->venues[city->venue_count], city->venues, city->venue_count);
	city->venue_count++;
	return 1;
}

int	editHotelRooms(City* city, int num) {
	if ((city->hotel_rooms + num) < 0)
		return 0;
	else
	{
		city->hotel_rooms += num;
		return 1;
	}
}

void printCity(const City* city) {
	printf("Host city : %s. Number of hotel rooms in city: %d\n Venues:\n ", city->name, city->hotel_rooms);
	printVenueArr(city->venues, city->venue_count);
}

void	printVenueArr(Venue* arr, int size)
{
	generalArrayFunction(arr, size, sizeof(Venue), printVenueV);
}

Venue* findVenueByName(City* city, const char* name)
{
	for (int i = 0; i < city->venue_count; i++)
	{
		if (!strcmp(name, city->venues[i].name))
			return &city->venues[i];
	}
	return NULL;
}

void	freeCity(City* c) {
	free(c->name);
	generalArrayFunction(c->venues, c->venue_count, sizeof(Venue), freeVenueV);
}