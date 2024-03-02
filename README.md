# Argentine Residential Analysis

## Overview
This project focuses on the exploration and analysis of data from the Permanent Household Survey, collected by the National Institute of Statistics and Census (INDEC) of Argentina. This work is carried out as part of the Practical Assignments for Specification and Implementation within the course Algorithms and Data Structures I, where we will use a specification language based on first-order logic to precisely define the problems that we will subsequently implement. Additionally, we aim to achieve a 100% line coverage.

## Table of Contents
- [Introduction](#introduction)
- [Repository Structure](#repository-structure)
- [Database](#database)
- [License](#license)

## Introduction

The Permanent Household Survey collects a wide range of data, including approximately 80 attributes of households and 150 attributes of the individuals who inhabit them.

The households selected for the survey represent strategically assigned samples with the aim of obtaining an accurate representation of the population inhabiting the Argentine territory.

The collected information is organized into two main tables: the household table and the person table. For more details on the statement and resolution, please refer to the `.pdf` file located in the corresponding folder.

## Repository Structure
The project is organized into several files and folders, each serving a specific purpose:

- `/pdfs`: Statement and Resolution
- `/datos`: Data used in the tests, as well as real data corresponding to the years 2016 and 2017 from the Permanent Household Survey in CABA (Ciudad Autónoma de Buenos Aires).
-  `/test`: Test suites.
- `definiciones.h`: Typedefs and declaration of the enum Item.
- `ejercicios.cpp`: Implementations.
- `ejercicios.h`: Headers.
- `auxiliares.cpp` and `auxiliares.h`: Auxiliary functions.
- `lib`: Contains everything necessary to run Google Tests.
- `CMakeLists.txt`: File necessary for compiling and running the project in CLion.

## Database
Each row in the data tables represents a unit of analysis (either a household or a person), and the columns correspond to the different attributes of these units. All data used in this project are represented as integer types, with categorical attributes encoded using enumerated data types.

Each household is identified by a unique numerical code called "CODUSU," while each individual is identified by a combination of this code and a unique component number within the household.
### HOGARES:

- HOGCODUSU: Identifier or key (N) of the household. It also allows tracking through the quarters.
- HOGAÑO: Year of the survey.
- HOGTRIMESTRE: Quarter of the survey year.
- HOGLATITUD: Latitude (geolocation of the household).
- HOGLONGITUD: Longitude (geolocation of the household).
- II7: Tenure regime of the inhabitants:
  - 1 - Owner
  - 2 - Tenant
  - 3 - Occupant
- REGION: Region code:
  - 1 - Greater Buenos Aires
  - 2 - NOA (Northwest)
  - 3 - NEA (Northeast)
  - 4 - Cuyo
  - 5 - Pampeana
  - 6 - Patagonia
- MAS 500: The household is located within an agglomeration of more than 500,000 inhabitants:
  - 0 - No
  - 1 - Yes
- IV1: Type of household (by observation):
  - 1 - House
  - 2 - Apartment
  - 3 - Room in a tenement
  - 4 - Room in a hotel/pension
  - 5 - Unconstructed premises for habitation
- IV2: Total number of rooms or bedrooms (excluding bathroom/s, kitchen, hallway/s, laundry room, garage).
- II2: Of these, how many are habitually used for sleeping?
- II3: Do you use any exclusively as a workspace (for office, study, workshop, business, etc.)?
  - 1 - Yes
  - 2 - No
 
### PERSONAS:

- INDCODUSU: Unique identifier or key (N) of the household. Corresponds to a HOGCODUSU from the household table. Also allows tracking through the quarters.
- COMPONENTE: Order number identifying a person within a household.
- INDAÑO: Year of the survey.
- INDTRIMESTRE: Quarter of the survey year.
- CH4: Gender:
  - 1 - Male
  - 2 - Female
- CH6: Age in completed years.
- NIVEL ED: Completed university studies:
  - 0 - No
  - 1 - Yes
- ESTADO: Activity status:
  - 0 - Unemployed, Inactive
  - 1 - Employed
  - -1 - Not reported
- CAT OCUP: Occupational category (For employed and unemployed with previous occupation):
  - 0 - Not specified/Not reported
  - 1 - Employer
  - 2 - Self-employed
  - 3 - Worker or employee
  - 4 - Unpaid family worker
- P47T: Total individual income amount. It can be -1 if not reported.
- PP04G: Where the person mainly performs their tasks:
  - 1 - In a premises/office/business establishment/workshop/farm/estate
  - 2 - In a fixed street stall or kiosk
  - 3 - In vehicles: bicycle/motorcycle/cars/boats (does not include transportation services)
  - 4 - In vehicles for passenger and goods transportation - air, maritime, land (includes taxis, buses, trucks, vans, fuel transportation, removals, etc.)
  - 5 - In construction sites, infrastructure, mining, or similar
  - 6 - In this household
  - 7 - In the partner's or employer's household
  - 8 - At the clients' address/premises
  - 9 - On the street/public spaces/itinerant/street vendor/home-to-home/mobile street stall
  - 10 - Elsewhere

## Classmates
- Agustín Hernández [@agushernandezz](https://github.com/agushernandezz)
- Guido Freire [@freire-guido](https://github.com/freire-guido)


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


