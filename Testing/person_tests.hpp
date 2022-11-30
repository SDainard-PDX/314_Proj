#include "../person.hpp"

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
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	char test_status = 'i';
	Person * test_person;

	test_person = new Person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status);

	std::cout << "getNumber() test. Expecting 123456789, got ";
	std::cout << test_person->getNumber();
	if(test_number == test_person->getNumber())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}


