#pragma once
#include <iostream>
#include "InsuranceAgent.h"
#include "ListOfAgreements.h"
#include "CollectiveAgreement.h"

class AgentsAgreements {
	InsuranceAgent agent;
	ListOfAgreements list;

public:
	void changeAgent(InsuranceAgent agent) {
		this->agent = agent;
	}
	void addToListOfAgreements(CollectiveAgreement agreement) {
		list.addAgreement(agreement);
	}
			

	friend std::ostream& operator<<(std::ostream& stream, AgentsAgreements list);
};

std::ostream& operator<<(std::ostream& stream, AgentsAgreements list) {
	stream << "Agent: " << list.agent << std::endl;
	stream << list;
}