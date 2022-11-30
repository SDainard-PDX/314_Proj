#include "../person.hpp"

using namespace std;

void person_getNumber_test();
void person_getName_test();
void person_getAddress_test();
void person_getCity_test();
void person_getState_test();
void person_getZip_test();
void person_getStatus_test();

void person_def_constructor_test();
void person_destructor_test();
void person_constructor_test();
void person_create_test();
void person_edit_test();
void person_display_test();

void person_type_compare_test();
void person_number_compare_test();

//Unit tests implementation 

void person_getNumber_test()
{
	int test_number = 123456789;
	person test_person(test_number, Matthew, "123 SE 1st St"
					   "Portland", "OR", 97229, "valid");

	cout << "getNumber() test. Expecting 123456789, got ";
	cout << test_person.getNumber();
	if(test_number == test_person.geNumber())
	{
		cout << ". Success." << endl;
	}
	else
	{
		cout << ". Failure!" << endl;
	}
}


