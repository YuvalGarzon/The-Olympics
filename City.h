#pragma once

#include "Venue.h"

typedef struct
{
	char* name;
	int venue_count;
	int	hotel_rooms;
	Venue* venues;
}City;

void	initCity(City* city);
void	printCity(const City* city);
int		addVenue(City* city);
int		editHotelRooms(City* city, int num);
void	printVenueArr(Venue* arr, int size);
Venue*	findVenueByName(City* city, const char* name);
void	freeCity(City* c);