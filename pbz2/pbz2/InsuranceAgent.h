#pragma once
#include <iostream>

class InsuranceAgent {
private:
	std::string fio;
	std::string pas_data;

public:
	InsuranceAgent(std::string fio, std::string pas_data) {
		this->fio = fio;
		this->pas_data = pas_data;
	}
	InsuranceAgent() = default;
	InsuranceAgent(const InsuranceAgent& other): fio(other.fio), pas_data(other.pas_data){}

	void changeFio(std::string n_fio) {
		fio = n_fio;
	}
	void changePasData(std::string n_pas_data) {
		pas_data = n_pas_data;
	}

	friend std::ostream& operator<<(std::ostream& stream, InsuranceAgent agent);
};

std::ostream& operator<<(std::ostream& stream, InsuranceAgent agent) {
	stream << agent.fio << "  " << agent.pas_data;
	return stream;
}