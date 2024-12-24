#pragma once

typedef enum {
	eGrass, eHardwood, eClay, eNofSurfaceTypes
} eSurfaceType;

static const char* SurfaceTypeStr[eNofSurfaceTypes] = { "Grass", "Hardwood", "Clay" };


typedef struct
{
	char* name;
	int	length;
	int	width;
	int attendance;
	eSurfaceType surface;
}Venue;

eSurfaceType getSurfaceType();
void	initVenue(Venue* venue, Venue* venueArr, int venueCount);
void	printVenue(const Venue* venue);
void	printVenueV(void* val);
int		isVenueNameUnique(Venue* venues, int venueCount, char* name);
char* getVenueName(Venue* venues, int venueCount);
void	freeVenue(Venue* v);
void	freeVenueV(void* val);