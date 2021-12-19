#pragma once
#include <iostream>

class InsuredEmployee {
private:
	std::string emp_fio;
	short emp_age;
	char risk_category;

public:
	InsuredEmployee(std::string fio, short age, char risk_category) {
		emp_fio = fio;
		emp_age = age;
		this->risk_category = risk_category;
	}
	InsuredEmployee() = default;
	InsuredEmployee(const InsuredEmployee& other): emp_fio(other.emp_fio), emp_age(other.emp_age), risk_category(other.risk_category){}

	void changeFIO(std::string fio) {
		emp_fio = fio;
	}
	void changeAge(short age) {
		emp_age = age;
	}
	void changeCategory(char category) {
		risk_category = category;
	}
	char getCategory() {
		return risk_category;
	}

	friend std::ostream& operator<<(std::ostream& stream, InsuredEmployee employee);
};

std::ostream& operator<<(std::ostream& stream, InsuredEmployee employee) {
	stream << employee.emp_fio << "  " << employee.emp_age << "  " << employee.risk_category;
	return stream;
}