#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon form", 25, 5), _target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	if (!this->getIsSigned()) {
		throw AForm::NotSignedException();
	}

	std::cout << _target << " Has been pardoned by Zaphod Beeblebrox." << std::endl;
}