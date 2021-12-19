#pragma once
#include <iostream>
#include <vector>
#include "CollectiveAgreement.h"

class ListOfAgreements {
	std::vector<CollectiveAgreement> list;

public:
	void addAgreement(CollectiveAgreement agreement) {
		list.push_back(agreement);
	}
	void delCompany(short number_of_agreement) {
		list.erase(list.begin() + number_of_agreement);
	}

	void task1(std::string full_name, std::string date) {
		for (short i = 0; i < list.size(); i++) {
			if (list[i].getCompany().getFullName() == full_name && list[i].getDate() == date)
				std::cout << list[i];
		}
	}
	void task2(std::string full_name, std::string date) {
		for (short i = 0; i < list.size(); i++) {
			if (list[i].getCompany().getFullName() == full_name && list[i].getDate() == date)
				std::cout << list[i].getAgent();
		}
	}
	void task3(std::string date) {
		for (short i = 0; i < list.size(); i++) {
			if (list[i].getDate() == date) {
				for (short j = 0; j < list[i].getEmployees().getListOfEmployees().size(); j++) {
					std::cout << list[i].getPayment(list[i].getEmployees().getListOfEmployees()[j].getCategory());
				}
			}
		}
	}

	void agreementsListMenu() {
		while (1) {
			bool answer;
			std::cout << *this << std::endl << "Add employee? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) {

			}
			std::cout << *this << std::endl << "Choose agreement";
			short number, option;
			std::cin >> number;
			std::cout << "Choose option: " << std::endl << "1. Come to agreement menu;" << std::endl << "2. Delete agreement;";
			std::cin >> option;
			switch (option) {
			case 1:
				list[number].collectiveAgreementMenu();
				break;
			case 2:
				this->delCompany(number);
			}
			std::cout << "do you want to exit? 1 - yes, 0 - no";
			std::cin >> option;
			if (option) return;
		}
	}
	friend std::ostream& operator<<(std::ostream& stream, ListOfAgreements list);
};

std::ostream& operator<<(std::ostream& stream, ListOfAgreements list) {
	for (short i = 0; i < list.list.size(); i++) {
		stream << "agreement " << i << ":" << std::endl;
		stream << i << "  " << list.list[i] << std::endl << std::endl;
	}
	return stream;
}