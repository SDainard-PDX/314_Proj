#include "../person.hpp"
#include "../people.hpp"

void people_populate_test();  //Done
void people_add_and_remove_person_test();  //Done
void people_find_person_test();
void people_write_out_test();

void people_add_and_remove_person_test()
{
	People * test_DR = new People;
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';
	bool test_success = false;
	Person * test_person_search;

	Person * test_person = new Person(test_number, test_name, test_address, test_city, 
					   				  test_state, test_zip, test_status, test_type);

	test_DR->populate("people_testing.csv", 'm');

	test_success = test_DR->add_person(test_person);
	
	test_person_search = test_DR->find_person(test_number);
	
	std::cout << "Testing People.add_person()...\n";
	std::cout << "  Expecting " << test_number << ", found "
			  << test_person_search->getNumber();

	if(test_success && *test_person_search == test_number)
	{
		std::cout << ".  Success.\n";
	}
	else
	{
		std::cout << ".  Failure!\n";
	}

	//Removing the Person just added
	std::cout << "Testing People.remove_person()...\n";
	test_success = false;
	test_success = test_DR->remove_person(test_number);
	test_person_search = test_DR->find_person(test_number);

	if(test_success && test_person_search == NULL)
	{
		std::cout << "Success.\n";
	}
	else
	{
		std::cout << "Failure!\n";
	}
}

void people_populate_test(int expected_count)
{
	People test_DR;
	float num_passed = 0;
	int count = test_DR.populate("people_testing.csv", 'm');

	std::cout << "\nTesting People.populate()...\n";
	std::cout << "  Count should be " << expected_count << ", it is ";
	std::cout << count << ". ";
	if(count == expected_count)
	{
		std::cout << " Success.\n";
		num_passed++;
	}
	else
		std::cout << " Failure!\n";

	std::cout << "  Displaying the " << expected_count << " entries.\n\n";
	test_DR.display_all();
}

