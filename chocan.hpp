#include "functional.hpp"
#include "error.hpp"
#include "person.hpp"
#include "people.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

#define MANAGERS_IN "managers.csv"
#define PROVIDERS_IN "providers.csv"
#define MEMBERS_IN "members.csv"

//Menu Function Declarations
bool VerifyPerson(People *pool, int number);

//Managers Menu
int Menu2(People *manDS, People *proDS, People *memDS);

//Providers Menu
int Menu3(People *manDS, People *proDS, People *memDS);