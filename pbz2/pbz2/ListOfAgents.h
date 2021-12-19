#pragma once
#include <iostream>
#include <vector>
#include "InsuranceAgent.h"

class ListOfAgents {
	std::vector<InsuranceAgent> list;

public:
	ListOfAgents() = default;
	void addAgent(InsuranceAgent agent) {
		list.push_back(agent);
	}
	void delAgent(short number_of_agent) {
		list.erase(list.begin() + number_of_agent);
	}

	void agentListMenu() {
		while (1) {
			std::cout << *this << std::endl << "Add agent? 1 - yes, 0 - no";
			bool answer;
			std::cin >> answer;
			if (answer) {
				std::string fio, passp;
				std::cout << "enter FIO";
				std::cin >> fio;
				std::cout << "enter passport data";
				std::cin >> passp;
				InsuranceAgent agent(fio, passp);
				this->addAgent(agent);
			}
			else {
				std::cout << std::endl << "Choose agent:" << std::endl;
				short agent_number, option;
				std::cin >> agent_number;
				std::cout << "Choose option:" << std::endl << "1. Change FIO;" << std::endl << "2. Change passport data;" << std::endl
					<< "3. Delete agent;";
				std::cin >> option;
				std::string data;
				switch (option) {
				case 1:
					std::cout << "enter FIO";
					std::cin >> data;
					list[agent_number].changeFio(data);
					break;
				case 2:
					std::cout << "enter passport data";
					std::cin >> data;
					list[agent_number].changePasData(data);
					break;
				case 3:
					this->delAgent(agent_number);
				}
			}
			std::cout << "do you want to exit? 1 - yes, 0 - no";
			std::cin >> answer;
			if (answer) return;
		}
	}

	friend std::ostream& operator<<(std::ostream& stream, ListOfAgents list);
};

std::ostream& operator<<(std::ostream& stream, ListOfAgents list) {
	stream << "n  agent FIO     passport data" << std::endl;
	for (short i = 0; i < list.list.size(); i++) {
		stream << i << "  " << list.list[i] << std::endl;
	}
	return stream;
}