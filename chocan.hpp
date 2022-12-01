#include "functional.hpp"
#include "error.hpp"
#include "person.hpp"
#include "people.hpp"
#include "service_item.hpp"
#include "service_directory.hpp"
#include "invoice.hpp"
#include "invoice_chain.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

#define MANAGERS_FILE "managers.csv"
#define PROVIDERS_FILE "providers.csv"
#define MEMBERS_FILE "members.csv"
#define SERVICE_DIR_FILE "service_directory.csv"
#define INVOICE_FILE "invoices.csv"

//Menu Function Declarations
bool VerifyPerson(People *pool, std::string number, std::string &reply);

//Managers Menu
int
Menu2(People *manDS, People *proDS, People *memDS, Service_Directory *servDS, Invoice_Chain *invoiceDS);

//Providers Menu
int
Menu3(std::string Pro_Number, People *manDS, People *proDS,
      People *memDS, Service_Directory *servDS, Invoice_Chain *invoiceDS);
