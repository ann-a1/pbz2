#pragma once
#include <iostream>
#include <vector>
#include "InsuredEmployee.h"

class ListOfEmployees {
	std::vector<InsuredEmployee> list;

public:
	ListOfEmployees() = default;
	void addEmployee(InsuredEmployee employee) {
		list.push_back(employee);
	}
	void delEmployee(short number_of_employee) {
		list.erase(list.begin() + number_of_employee);
	}
	std::vector<InsuredEmployee> getListOfEmployees() {
		return list;
	}
	void employeeListMenu() {
		while (1) {
			std::cout << *this << std::endl << "Add employee? 1 - yes, 0 - no";
			bool answer;
			std::string fio;
			short age;
			char risk;
			std::cin >> answer;
			if (answer) {
				std::cout << "enter FIO";
				std::cin >> fio;
				std::cout << "enter age";
				std::cin >> age;
				std::cout << "enter risk category: 1, 2 or 3";
				std::cin >> risk;
				InsuredEmployee employee(fio, age, risk);
				this->addEmployee(employee);
			}
			else {
				std::cout << std::endl << "Choose agent:" << std::endl;
				short employee_number, option;
				std::cin >> employee_number;
				std::cout << "Choose option:" << std::endl << "1. Change FIO;" << std::endl << "2. Change employee age;" << std::endl
					<< "3. Change risk category;" << std::endl << "4. Delete employee;";
				std::cin >> option;
				switch (option) {
				case 1:
					std::cout << "enter FIO: ";
					std::cin >> fio;
					list[employee_number].changeFIO(fio);
					break;
				case 2:
					std::cout << "enter age: ";
					std::cin >> age;
					list[employee_number].changeAge(age);
					break;
				case 3:
					std::cout << "enter risk category: ";
					std::cin >> risk;
					list[employee_number].changeCategory(risk);
					break;
				case 4:
					this->delEmployee(employee_number);
				}
			}
			std::cout << "do you want to exit? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) return;
		}
	}

	friend std::ostream& operator<<(std::ostream& stream, ListOfEmployees list);
};

std::ostream& operator<<(std::ostream& stream, ListOfEmployees list) {
	stream << "n  employee FIO  age  risk category" << std::endl;
	for (short i = 0; i < list.list.size(); i++) {
		stream << i << "  " << list.list[i] << std::endl;
	}
	return stream;
}