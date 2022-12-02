#include "people_tests.hpp"

/*
g++ -g -Wall -Wno-deprecated -o people_tests people_tests.cpp ../person.cpp ../people.cpp ../functional.cpp
*/

int main()
{
	People * test_DR = new People;
	int num_of_people = test_DR->populate("people_testing.csv", 'm');

	people_add_and_remove_person_test();
	people_populate_test(num_of_people);

	return 0;
}
