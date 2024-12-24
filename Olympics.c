#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "General.h"
#include "Olympics.h"
void initOlympics(Olympics* olympics)
{
	L_init(&olympics->countries);
	olympics->sports = NULL;
	olympics->numberOfSports = 0;
	initCity(&olympics->host);

}

void printCountries(const Olympics* olympics)
{
	int count = getCountryCount(olympics);
	printf("there are %d countries\n", count);
	L_print(&olympics->countries, printCountryV);
}

int addCountry(Olympics* olympics)
{
	Country* pCountry = (Country*)calloc(1, sizeof(Country));
	if (!pCountry)
		return 0;
	initCountry(pCountry);
	return insertNewCountryToList(&olympics->countries, pCountry);
}

int	insertNewCountryToList(LIST* pList, Country* pCountry)
{
	NODE* pN = pList->head.next;
	NODE* pPrevNode = &pList->head;
	Country* pTemp;
	int compRes;

	while (pN != NULL)
	{
		pTemp = (Country*)pN->key;
		compRes = strcmp(pTemp->teamCode, pCountry->teamCode);
		if (compRes == 0)
		{
			printf("Country is already exist!\n");
			return 0;
		}
		if (compRes > 0)
		{
			if (!L_insert(pPrevNode, pCountry))
				return 0;
			return 1;
		}
		pPrevNode = pN;
		pN = pN->next;
	}
	if (!L_insert(pPrevNode, pCountry))
		return 0;
	return 1;
}

int getCountryCount(const Olympics* olympics)
{
	int count = 0;
	NODE* pN = olympics->countries.head.next;

	while (pN != NULL)
	{
		count++;
		pN = pN->next;
	}
	return count;
}

int	addSport(Olympics* olympics)
{
	olympics->sports = (Sport*)realloc(olympics->sports, (olympics->numberOfSports + 1) * sizeof(Sport));
	if (!olympics->sports)
		return 0;
	initSport(&olympics->sports[olympics->numberOfSports]);
	olympics->numberOfSports++;
	return 1;
}

int	addVenueToCity(Olympics* olympics)
{
	return addVenue(&olympics->host);
}

void printSports(const Olympics* olympics)
{
	generalArrayFunction(olympics->sports, olympics->numberOfSports, sizeof(Sport), printSportV);
}

void freeOlympics(Olympics* olympics)
{
	L_free(&olympics->countries, freeCountryV);
	generalArrayFunction(olympics->sports, olympics->numberOfSports, sizeof(Sport), freeSportV);
}
Sport* selectSport(const Olympics* olympics)
{
	printSports(olympics);
	char* temp = NULL;
	do {
		temp = getStrExactName("Enter the name of the sport you want to pick: ");
	} while (!findSportByName(olympics, temp));

	return findSportByName(olympics, temp);
}
Sport* findSportByName(const Olympics* olympics, const char* name)
{
	for (int i = 0; i < olympics->numberOfSports; i++)
	{
		if (!strcmp(name, olympics->sports[i].name))
			return &olympics->sports[i];
	}
	return NULL;
}

int addAthelte(Olympics* olympics) {
	return addAthleteToCountry(selectCountry(olympics), olympics);
}

Country* findCountryByTeamCode(const Olympics* olympics, const char* code)
{

	NODE* pN = olympics->countries.head.next; 
	if (!pN)
		return NULL;

	Country* pTemp;
	int compRes;
	while (pN != NULL)
	{
		pTemp = (Country*)pN->key;
		compRes = strcmp(pTemp->teamCode, code);
		if (compRes == 0)
			return pTemp;
		if (compRes > 1) //not fount
			return NULL;
		pN = pN->next;
	}

	return NULL;
}

int addAthleteToCountry(Country* country, Olympics* olympics)
{
	Athlete* pAthlete = (Athlete*)calloc(1, sizeof(Athlete));
	if (!pAthlete)
		return 0;
	initAthlete(pAthlete, country, selectSport(olympics));
	country->repAthlete = (Athlete**)realloc(country->repAthlete, (country->numOfAthletes + 1) * sizeof(Athlete*));
	if (!country->repAthlete)
		return 0;
	country->repAthlete[country->numOfAthletes] = pAthlete;
	country->numOfAthletes++;
	return 1;
}

int addMatch(Olympics* olympics)
{
	Sport* theSport = selectSport(olympics);
	if (!theSport)
		return 0;
	if (teamsForSport(olympics, theSport) < theSport->minTeamsInMatch)
		return 0;
	theSport->matches = (Match*)realloc(theSport->matches, (theSport->numOfMatchs + 1) * sizeof(Match));
	if (!theSport->matches)
		return 0;
	initMatch(&theSport->matches[theSport->numOfMatchs],olympics,theSport);
	theSport->numOfMatchs++;
	return 1;

}

int teamsForSport(Olympics* olympics, Sport* sport) {
	
	int min = sport->minTeamsInMatch;
	int sum = 0;
	NODE* pN = olympics->countries.head.next;
	if (!pN)
		return sum;

	Country* pTemp;
	while (pN != NULL)
	{
		pTemp = (Country*)pN->key;
		if (athleteInSport(pTemp, sport) >= sport->minPlayersOnTeam)
			sum++;
		pN = pN->next;
	}

	return sum;

}
int athleteInSport(Country* country, Sport* sport) {
	int sum=0;
	for (int i = 0; i < country->numOfAthletes; i++) {
		struct Sport* s = country->repAthlete[i]->sport;
		Sport* sp = (Sport*)s;
		if (!strcmp(sp->name, sport->name))
			sum++;
	}
	return sum;
}


void initAthlete(Athlete* athlete, Country* country, Sport* sport)
{
	athlete->name = getStrExactName("Enter athlete name: ");

	printf("\nEnter athlete height: ");
	int none = scanf("%d", &athlete->height);

	printf("\nEnter athlete age: ");
	none = scanf("%d", &athlete->age);

	printf("\nEnter athlete weieght: ");
	none =scanf("%d", &athlete->weight);

	athlete->country = country;
	athlete->sport = sport;
}

int initMatch(Match* match, Olympics* olympics, Sport* sport)
{
	match->num_of_teams = 0;
	match->teams_playing = NULL;
	match->sport = NULL;
	getCorrectDate(&match->date);
	match->venue = selectVenue(olympics);
	char temp[MAX_STR_LEN] = "";
	strcpy(temp, sport->name);
	match->sport = (char*)malloc((strlen(temp)+1) * sizeof(char));
	if (!match->sport)
		return 0;
	strcpy(match->sport, temp);
	int teams = 0;
	int stop = 0;
	while ((teams<sport->minTeamsInMatch || teams>sport->maxTeamsInMatch) && !stop) {
		addCountryToMatch(match, selectCountryForMatch(match, olympics, sport));
		teams++;
		if (teams >= sport->minTeamsInMatch && teams<sport->maxTeamsInMatch) {
			do {
				printf("Min amount of teams entered to match. Press 1 to stop, 0 to add more teams: ");
				scanf("%d", &stop);
			} while (stop < 0 || stop>1);
		}
	}
	return 1;

}

int	addCountryToMatch(Match* m, Country* c)
{
	m->teams_playing = (Country**)realloc(m->teams_playing, (m->num_of_teams + 1) * sizeof(Country*));
	if (!m->teams_playing)
		return 0;
	m->teams_playing[m->num_of_teams] = c;
	m->num_of_teams++;
	return 1;
}

int isInMatch(Match* m, Country* c) {
	for (int i = 0; i < m->num_of_teams; i++) {
		if (!strcmp(m->teams_playing[i]->name, c->name))
			return 1;
	}
	return 0;
		
}

int PrintValidCountriesForMatch(Match* match, Olympics* olympics, Sport* sport) {
	int min = sport->minTeamsInMatch;
	NODE* pN = olympics->countries.head.next;
	if (!pN)
		return 0;

	Country* pTemp;
	while (pN != NULL)
	{
		pTemp = (Country*)pN->key;
		if (athleteInSport(pTemp, sport) >= sport->minPlayersOnTeam && !isInMatch(match,pTemp))
			printCountry(pTemp);
		pN = pN->next;
	}
	return 1;
}
Country* selectCountryForMatch(Match* match, Olympics* olympics, Sport* sport) {
	printf("Select a country for match from the following:\n");
	PrintValidCountriesForMatch(match, olympics, sport);
	char* temp = NULL;
	do {
		temp = getStrExactName("Enter the team code you want to chose : ");
	} while (!findCountryValidForMatchByTeamCode(olympics, temp, sport));
	return findCountryValidForMatchByTeamCode(olympics, temp, sport);
}

Country* findCountryValidForMatchByTeamCode(const Olympics* olympics, char* code, Sport* sport) {

	NODE* pN = olympics->countries.head.next;
	if (!pN)
		return NULL;

	Country* pTemp;
	int compRes;
	while (pN != NULL)
	{
		pTemp = (Country*)pN->key;
		compRes = strcmp(pTemp->teamCode, code);
		if (compRes == 0 && athleteInSport(pTemp, sport) >= sport->minPlayersOnTeam)
			return pTemp;
		if (compRes > 1) //not fount
			return NULL;
		pN = pN->next;
	}

	return NULL;
}



Venue* selectVenue(Olympics* olympics)
{
	printVenueArr(olympics->host.venues, olympics->host.venue_count);
	char* temp = NULL;
	do {
		temp = getStrExactName("Enter the name of the venue where the match will be played: ");
	} while (!findVenueByName(&olympics->host, temp));

	return findVenueByName(&olympics->host, temp);
}

Country* selectCountry(const Olympics* olympics)
{
	printCountries(olympics);
	char* temp = NULL;
	do {
		temp = getStrExactName("Enter the team code of the country you want select: ");
	} while (!findCountryByTeamCode(olympics, temp));

	return findCountryByTeamCode(olympics, temp);
}

void printMatch(const Match* match) {
	printf("%s match, played in %s, on day:", match->sport, match->venue->name);
	printDate(&match->date);
	printf("Between: ");
	for (int i = 0; i < match->num_of_teams; i++)
		printf("%s ", match->teams_playing[i]->name);
}
