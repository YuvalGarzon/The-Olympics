#pragma once

#include "Athlete.h"
#define CODE_LEN 3
typedef struct
{
	char* name;
	char teamCode[CODE_LEN + 1];
	Athlete** repAthlete;
	int numOfAthletes;
}Country;

void initCountry(Country* country);
void getCountryCode(char* code);
void printCountryV(const void* val);
void freeCountry(Country* country);
void freeCountryV(void* val);
void printCountry(const Country* country);
