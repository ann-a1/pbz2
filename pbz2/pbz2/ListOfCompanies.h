#pragma once
#include <iostream>
#include <vector>
#include "Company.h"

class ListOfCompanies {
	std::vector<Company> list;

public:
	ListOfCompanies() = default;
	void addCompany(Company agent) {
		list.push_back(agent);
	}
	void delCompany(short number_of_company) {
		list.erase(list.begin() + number_of_company);
	}

	void companyListMenu() {
		while (1) {
			std::cout << *this << std::endl << "Add company? 1 - yes, 0 - no";
			bool answer;
			std::cin >> answer;
			if (answer) {
				std::string code, f_name, s_name, address, specializtion;
				short number;
				std::cout << "enter company code";
				std::cin >> code;
				std::cout << "enter full name";
				std::cin >> f_name;
				std::cout << "enter short name";
				std::cin >> s_name;
				std::cout << "enter company address";
				std::cin >> address;
				std::cout << "enter number of bank";
				std::cin >> number;
				std::cout << "enter company specialization";
				std::cin >> specializtion;
				Company company(code, f_name, s_name, address, number, specializtion);
				this->addCompany(company);
			}
			else {
				std::cout << "Choose company:" << std::endl;
				short company_number, option;
				std::cin >> company_number;
				std::cout << "Choose option:" << std::endl << "1. Change company code;" << std::endl << "2. Change full name of company;" << std::endl
					<< "3. Change short name of company;" << std::endl << "4. Change company address;" << std::endl << "5. Change number of bank;"
					<< std::endl << "6. Change specialization of company;" << std::endl << "7. Delete company";
				std::cin >> option;
				std::string data;
				short n_data;
				switch (option) {
				case 1:
					std::cout << "enter code: ";
					std::cin >> data;
					list[company_number].changeCode(data);
					break;
				case 2:
					std::cout << "enter full name: ";
					std::cin >> data;
					list[company_number].changeFullName(data);
					break;
				case 3:
					std::cout << "enter short name: ";
					std::cin >> data;
					list[company_number].changeShortName(data);
					break;
				case 4:
					std::cout << "enter address: ";
					std::cin >> data;
					list[company_number].changeAddress(data);
					break;
				case 5:
					std::cout << "enter number of bank: ";
					std::cin >> n_data;
					list[company_number].changeNumberOfBank(n_data);
					break;
				case 6:
					std::cout << "enter specialization: ";
					std::cin >> data;
					list[company_number].changeSpecialization(data);
					break;
				case 7:
					this->delCompany(company_number);
				}
			}
			std::cout << "do you want to exit? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) return;
		}
	}

	friend std::ostream& operator<<(std::ostream & stream, ListOfCompanies list);
};

std::ostream& operator<<(std::ostream& stream, ListOfCompanies list) {
	stream << "n  code     full company name    short name     address     number of bank    specialization" << std::endl;
	for (short i = 0; i < list.list.size(); i++) {
		stream << i << "  " << list.list[i] << std::endl;
	}
	return stream;
}