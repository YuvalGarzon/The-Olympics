#include "Olympics.h"
#include <stdio.h>
int main(){
	Olympics h;
	initOlympics(&h);
	addCountry(&h);
	addSport(&h);
	addVenue(&h.host);
	addAthelte(&h);
	addMatch(&h);
	printCountries(&h);
	printCity(&h.host);
	printSports(&h);
	printMatch(&h.sports->matches[0]);
	freeOlympics(&h);
	return 1;
}