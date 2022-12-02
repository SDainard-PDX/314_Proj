#include "person_tests.hpp"

/*
g++ -g -Wall -Wno-deprecated -o person_tests person_tests.cpp ../person.cpp ../functional.cpp
*/

int main() {

	std::cout << "Running Person tests...\n";
	person_getNumber_test();
	person_getName_test();
	person_getAddress_test();
	person_getCity_test();
	person_getState_test();
	person_getZip_test();
	person_getStatus_test();
	person_type_compare_equals_test();
	person_type_compare_not_equals_test();
	person_number_compare_equals_test();
	person_number_compare_not_equals_test();
	person_display_test();

    return 0;
}
