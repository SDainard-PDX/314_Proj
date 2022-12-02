#include "../person.hpp"

void person_getNumber_test();
void person_getName_test();
void person_getAddress_test();
void person_getCity_test();
void person_getState_test();
void person_getZip_test();
void person_getStatus_test();

//void person_def_constructor_test();
//void person_destructor_test();
//void person_constructor_test();
//void person_create_test();   requires IO
//void person_edit_test();     requires IO

void person_type_compare_equals_test();
void person_type_compare_not_equals_test();
void person_number_compare_equals_test();
void person_number_compare_not_equals_test();

void person_display_test();

//Unit tests implementation 

void person_getNumber_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getNumber() test. Expecting 123456789, got ";
	std::cout << test_person.getNumber();
	if(test_number == test_person.getNumber())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_getName_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getName() test. Expecting Matt, got ";
	std::cout << test_person.getName();
	if(test_name == test_person.getName())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_getAddress_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getAddress() test. Expecting 123 SE 1st St, got ";
	std::cout << test_person.getAddress();
	if(test_address == test_person.getAddress())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_getCity_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getCity() test. Expecting Portland, got ";
	std::cout << test_person.getCity();
	if(test_city == test_person.getCity())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_getState_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getState() test. Expecting OR, got ";
	std::cout << test_person.getState();
	if(test_state == test_person.getState())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_getZip_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getZip() test. Expecting 97229, got ";
	std::cout << test_person.getZip();
	if(test_zip == test_person.getZip())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_getStatus_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "getStatus() test. Expecting Valid, got ";
	std::cout << test_person.getStatus();
	if(test_status == test_person.getStatus())
	{
		std::cout << ". Success." << std::endl;
	}
	else
	{
		std::cout << ". Failure!" << std::endl;
	}
}

void person_type_compare_equals_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "== type overload test. Expecting equals, got ";
	if(test_person == test_type)
	{
		std::cout << "equals. Success." << std::endl;
	}
	else
	{
		std::cout << "NOT equals. Failure!" << std::endl;
	}
}

void person_type_compare_not_equals_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "== type overload test. Expecting NOT equals, got ";
	if(test_person == "x")
	{
		std::cout << "equals. Failure!" << std::endl;
	}
	else
	{
		std::cout << "NOT equals. Succes." << std::endl;
	}
}

void person_number_compare_equals_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "== number overload test. Expecting equals, got ";
	if(test_person == test_number)
	{
		std::cout << "equals. Success." << std::endl;
	}
	else
	{
		std::cout << "NOT equals. Failure!" << std::endl;
	}
}

void person_number_compare_not_equals_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "== number overload test. Expecting NOT equals, got ";
	if(test_person == "987654321")
	{
		std::cout << "equals. Failure!" << std::endl;
	}
	else
	{
		std::cout << "NOT equals. Success." << std::endl;
	}
}

//Not sure how to test display() probably doesn't count as a test
void person_display_test()
{
	std::string test_number = "123456789";
	std::string test_name = "Matt";
	std::string test_address = "123 SE 1st St";
	std::string test_city = "Portland";
	std::string test_state = "OR";
	std::string test_zip = "97229";
	std::string test_status = "Valid";
	char test_type = 'm';

	Person test_person(test_number, test_name, test_address, test_city, 
					   test_state, test_zip, test_status, test_type);

	std::cout << "Running display() function\n";
	test_person.display();
}
