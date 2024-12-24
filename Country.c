#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Country.h"
#include "General.h"
#include "Olympics.h"
#include "Athlete.h"
void initCountry(Country* country)
{
    country->name = getStrExactName("Enter country name: ");
    getCountryCode(country->teamCode);
    country->repAthlete = NULL;
    country->numOfAthletes = 0;
}

void getCountryCode(char* code)
{
    char temp[MAX_STR_LEN];
    int ok = 1;
    do {
        ok = 1;
        printf("Enter country team code (broadcasted on score broad)  - %d UPPER CASE letters\t", CODE_LEN);
        myGets(temp, MAX_STR_LEN, stdin);
        if (strlen(temp) != CODE_LEN)
        {
            printf("code should be %d letters\n", CODE_LEN);
            ok = 0;
        }
        else {
            for (int i = 0; i < CODE_LEN; i++)
            {
                if (isupper(temp[i]) == 0)
                {
                    printf("Need to be upper case letter\n");
                    ok = 0;
                    break;
                }
            }
        }
    } while (!ok);

    strcpy(code, temp);
}

void printCountry(const Country* country) {
    printf("Country name: %s. Team code: %s", country->name, country->teamCode);
}

void printCountryV(const void* val)
{
    printCountry((const Country*)val);
}

void freeCountry(Country* country)
{
    free(country->name);
    generalArrayFunction(country->repAthlete, country->numOfAthletes, sizeof(Athlete*), freeAthletePtr);
}
void freeCountryV(void* val)
{
    freeCountry((Country*)val);
}