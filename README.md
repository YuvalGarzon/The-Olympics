# The Olympics

## Description
**The Olympics** is a C project designed to simulate the management of an Olympic-like event. It encompasses functionalities for organizing countries, athletes, sports, venues, and matches while ensuring efficient memory management and user-friendly interaction.

## Features
- **Venue Management**: Create and manage venues, including dimensions, attendance limits, and surface types.
- **Sport Management**: Define sports, including rules for team sizes and match configurations.
- **Country and Athlete Management**: Register countries and athletes, maintaining detailed information for each.
- **Match Handling**: Organize matches, validate requirements, and manage team participation.
- **City Hosting**: Manage host cities with details on venues and hotel capacities.
- **Date Handling**: Validate and process event dates.
- **Dynamic Data Structures**: Implement linked lists and arrays for efficient data management.

## Prerequisites
To build and run this project, you need:
- A C compiler supporting C11 standard (e.g., GCC 11+).
- **CMake** (version 3.30 or higher) for building the project.
- A development environment for compiling and executing C programs.

## How the Code Works
The project is designed as a modular system, where each major component is implemented in its own module (e.g., `Venue`, `Sport`, `Country`). These modules interact to simulate the organization of an Olympic event. 

1. **Initialization**:
   - The system initializes the host city, venues, and the list of participating countries.
   - Sports and their rules are defined, and athletes are assigned to their respective countries and sports.

2. **User Interaction**:
   - The user interacts with the system through an interactive console interface, providing input for adding countries, venues, sports, and athletes.
   - Matches can be scheduled, ensuring compliance with predefined rules (e.g., minimum number of teams).

3. **Memory Management**:
   - Dynamic memory allocation is extensively used for storing variable-length data (e.g., names, arrays).
   - Functions are provided to free allocated memory systematically, ensuring no memory leaks.

4. **Data Validation**:
   - Inputs are validated (e.g., unique venue names, valid team codes).
   - Dates and match requirements are checked for correctness.

## File Overview
- **`Venue.h` / `Venue.c`**: Manage venue details and operations.
- **`Sport.h` / `Sport.c`**: Handle sports, rules, and matches.
- **`Country.h` / `Country.c`**: Manage country details and athletes.
- **`Athlete.h` / `Athlete.c`**: Define and manage athlete information.
- **`City.h` / `City.c`**: Manage host cities and associated venues.
- **`Olympics.h` / `Olympics.c`**: Core structure for the Olympic event.
- **`Date.h` / `Date.c`**: Validate and handle dates.
- **`General.h` / `General.c`**: Utility functions for strings and arrays.
- **`List.h` / `List.c`**: Implement a dynamic linked list.
- **`CMakeLists.txt`**: Build instructions for CMake.

## Credits
- **Yuval Garzon** and **Yuval Davidovits**: Project creators and contributors.

---
Feel free to customize this file further to suit your needs.

