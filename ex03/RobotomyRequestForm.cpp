#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy form", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "* Loud driling noises *" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << _target << " Has been robotomized successfully" << std::endl;
	} else {
		std::cout << _target << " Robotomization failed" << std::endl;
	}
}