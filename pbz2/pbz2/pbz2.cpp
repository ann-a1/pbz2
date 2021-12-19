#include <iostream>
#include "ListOfCompanies.h"
#include "ListOfEmployees.h"
#include "ListOfAgents.h"
#include "ListOfAgreements.h"

int main()
{
    short option;
    ListOfCompanies companies;
    ListOfEmployees employees;
    ListOfAgents agents;
    ListOfAgreements organization;
    while (1) {
        std::cout << "Choose option:" << std::endl << "1. Companies;" << std::endl << "2. Employees;" << std::endl << "3. Agents;"
            << std::endl << "4. Organization;" << std::endl << "5. Task1;" << std::endl << "6. Task2;" << std::endl << "7. Task3";
        std::cin >> option;
        std::string name, date;
        switch (option) {
        case 1:
            companies.companyListMenu();
            break;
        case 2:
            employees.employeeListMenu();
            break;
        case 3:
            agents.agentListMenu();
            break;
        case 4:
            organization.agreementsListMenu();
            break;
        case 5:
            std::cout << "enter Full name and date";
            std::cin >> name >> date;
            organization.task1(name, date);
            break;
        case 6:
            std::cout << "enter Full name and date";
            std::cin >> name >> date;
            organization.task2(name, date);
            break;
        case 7:
            std::cout << "enter date";
            std::cin >> date;
            organization.task3(date);
        }
    }
}
