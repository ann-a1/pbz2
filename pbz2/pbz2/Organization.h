#pragma once
#include <iostream>
#include "AgentsAgreements.h"
#include "CollectiveAgreement.h"
#include "InsuranceAgent.h"


class Organization {
	std::vector<AgentsAgreements> list;

public:
	void addAgreement(short number_of_agent, CollectiveAgreement agreement) {
		list[number_of_agent].addToListOfAgreements(agreement);
	}
	void changeAgent(short number_of_agent, InsuranceAgent agent) {
		list[number_of_agent].changeAgent(agent);
	}
	void delAgent(short number_of_agent) {
		list.erase(list.begin() + number_of_agent);
	}
	void organizationMenu() {
		while (1) {
			bool answer;
			std::cout << *this << std::endl << "Add agent? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) {
				std::string fio, passp;
				std::cout << "enter FIO";
				std::cin >> fio;
				std::cout << "enter passport data";
				std::cin >> passp;
				InsuranceAgent agent(fio, passp);
			}
			std::cout << "do you want to exit? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) return;
		}
	}

	friend std::ostream& operator<<(std::ostream& stream, Organization org);
};

std::ostream& operator<<(std::ostream& stream, Organization org) {
	for (short i = 0; i < org.list.size(); i++) {
		stream << i << "  " << org.list[i] << std::endl << std::endl;
	}
	return stream;
}