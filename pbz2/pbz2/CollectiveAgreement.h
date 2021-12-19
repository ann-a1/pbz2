#pragma once
#include <iostream>
#include <vector>
#include "ListOfEmployees.h"
#include "Company.h"
#include "InsuranceAgent.h"

class CollectiveAgreement {
private:
	Company company;
	ListOfEmployees list_of_employees;
	std::string conclusion_date;
	std::string validity_period;
	short payment[3];
	InsuranceAgent agent;

public:
	CollectiveAgreement(Company company, std::string conclusion_date, std::string validity_period, InsuranceAgent agent) {
		this->company = company;
		this->conclusion_date = conclusion_date;
		this->validity_period = validity_period;
		this->agent = agent;
		payment[0] = 100;
		payment[1] = 150;
		payment[2] = 200;
	}
	CollectiveAgreement() = default;
	CollectiveAgreement(const CollectiveAgreement& other) : company(other.company), conclusion_date(other.conclusion_date),
		validity_period(other.validity_period), agent(other.agent) {
		list_of_employees = other.list_of_employees;
		payment[0] = other.payment[0];
		payment[1] = other.payment[1];
		payment[2] = other.payment[2];
	}

	void changeCompany(Company company) {
		this->company = company;
	}
	Company getCompany() {
		return company;
	}
	std::string getDate() {
		return conclusion_date;
	}
	InsuranceAgent getAgent() {
		return agent;
	}
	ListOfEmployees getEmployees() {
		return list_of_employees;
	}
	short getPayment(char type) {
		switch (type) {
			case '1':
				return payment[0];
				break;
			case '2':
				return payment[1];
				break;
			case '3':
				return payment[2];
		}
	}
	void changeConclusionDate(std::string date) {
		this->conclusion_date = conclusion_date;
	}
	void changeValidityPeriod(std::string date) {
		this->validity_period = validity_period;
	}
	void changeAgent(InsuranceAgent agent) {
		this->agent = agent;
	}
	void collectiveAgreementMenu() {
		while (1) {
			std::cout << *this << std::endl;
			std::cout << "Choose option:" << std::endl << "1. Change date of conclusion;" << std::endl
				<< "2. Change validity period;" << std::endl << "3. Come to Employees menu;";
			short option;
			std::string data;
			std::cin >> option;
			switch (option) {
			case 1:
				std::cout << "enter date of conclusion: ";
				std::cin >> data;
				this->conclusion_date = data;
				break;
			case 2:
				std::cout << "enter validity period: ";
				std::cin >> data;
				this->validity_period = data;
				break;
			case 3:
				list_of_employees.employeeListMenu();
			}
			bool answer;
			std::cout << "do you want to exit? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) return;
		}
	}

	friend std::ostream& operator<<(std::ostream& stream, CollectiveAgreement agreement);
};

std::ostream& operator<<(std::ostream& stream, CollectiveAgreement agreement) {
	stream << "Company: " << agreement.company << std::endl;
	stream << "Date of conclusion: " << agreement.conclusion_date << std::endl;
	stream << "Validity period: " << agreement.validity_period << std::endl;
	stream << "n  employee FIO  age  risk category  payment" << std::endl;
	for (short i = 0; i < agreement.list_of_employees.getListOfEmployees().size(); i++) {
		stream << i << "  " << agreement.list_of_employees.getListOfEmployees()[i];
		switch (agreement.list_of_employees.getListOfEmployees()[i].getCategory()) {
		case '1':
			stream << "           " << agreement.payment[0];
			break;
		case '2':
			stream << "           " << agreement.payment[1];
			break;
		case '3':
			stream << "           " << agreement.payment[2];
		}
	}
	return stream;
}