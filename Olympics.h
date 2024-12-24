#ifndef __COMP__
#define __COMP__
#include "List.h"
#include "City.h"
#include "Sport.h"
#include "Country.h"
#include "Athlete.h"
#include "Match.h"
typedef struct
{
	LIST countries;
	City host;
	Sport* sports;
	int numberOfSports;
}Olympics;

void	initOlympics(Olympics* olympics);
void	printCountries(const Olympics* olympics);
int		addCountry(Olympics* olympics);
int		insertNewCountryToList(LIST* pList, Country* pCountry);
int		getCountryCount(const Olympics* olympics);
void	freeOlympics(Olympics* olympics);
int		addSport(Olympics* olympics);
int		addVenueToCity(Olympics* olympics);
void	printSports(const Olympics* olympics);
Sport*	selectSport(const Olympics* olympics);
Sport*	findSportByName(const Olympics* olympics, const char* name);
int		addAthelte(Olympics* olympics);
Country* findCountryByTeamCode(const Olympics* olympics, const char* code);
int athleteInSport(Country* country, Sport* sport);
int teamsForSport(Olympics* olympics, Sport* sport);
int		addAthleteToCountry(Country* country, Olympics* olympics);
int addMatch(Olympics* olympics);
void initAthlete(Athlete* athlete, Country* country, Sport* sport);
int		initMatch(Match* match,  Olympics* olympics,  Sport* sport);
Venue*	selectVenue(Olympics* olympics);
Country* selectCountry(const Olympics* olympics);
void printMatch(const Match* match);
int PrintValidCountriesForMatch(Match* match, Olympics* olympics, Sport* sport);
int isInMatch(Match* m, Country* c);
Country* findCountryValidForMatchByTeamCode(const Olympics* olympics, char* code, Sport* sport);
Country* selectCountryForMatch(Match* match, Olympics* olympics, Sport* sport);
int	addCountryToMatch(Match* m, Country* c);
#endif
