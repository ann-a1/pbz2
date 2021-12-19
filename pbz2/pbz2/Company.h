#pragma once
#include <iostream>

class Company {
private:
	std::string code;
	std::string full_name;
	std::string short_name;
	std::string address;
	short number_of_bank;
	std::string company_specialization;

public:
	Company(std::string code, std::string full_name, std::string short_name, std::string address, short number_of_bank, std::string specialization) {
		this->code = code;
		this->full_name = full_name;
		this->short_name = short_name;
		this->address = address;
		this->number_of_bank = number_of_bank;
		company_specialization = specialization;
	}
	Company (const Company& other): code(other.code), full_name(other.full_name), short_name(other.short_name), address(other.address),
		number_of_bank(other.number_of_bank), company_specialization(other.company_specialization){}
	Company() = default;

	void changeCode(std::string code) {
		this->code = code;
	}
	void changeFullName(std::string full_name) {
		this->full_name = full_name;
	}
	std::string getFullName() {
		return full_name;
	}
	void changeShortName(std::string short_name) {
		this->short_name = short_name;
	}
	void changeAddress(std::string address) {
		this->address = address;
	}
	void changeNumberOfBank(short number_of_bank) {
		this->address = address;
	}
	void changeSpecialization(std::string specialization) {
		company_specialization = specialization;
	}

	friend std::ostream& operator<<(std::ostream& stream, Company company);
};

std::ostream& operator<<(std::ostream& stream, Company company) {
	stream << company.code << "  " << company.full_name << "  " << company.short_name << "  " << company.address << "  " << company.number_of_bank
		<< "  " << company.company_specialization;
	return stream;
}