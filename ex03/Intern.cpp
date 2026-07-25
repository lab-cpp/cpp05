#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
	*this = src;
}

Intern& Intern::operator=(const Intern& rhs) {
	(void) rhs;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubbery(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*funcs[])(const std::string&) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cerr << "Intern cannot create " << formName
			  << " because this form does not exists" << std::endl;
	return NULL;
}