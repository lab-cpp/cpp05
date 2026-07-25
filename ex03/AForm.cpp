#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) { }

AForm::AForm(const std::string& name, int gradeToSign, int getGradeToExecute) 
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(getGradeToExecute) {

    if (gradeToSign > 150 || getGradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
    if (gradeToSign < 1 || getGradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm(const AForm& src) 
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

const char* AForm::GradeTooHighException::what() const throw(){
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << "AForm: " << AForm.getName()
    << ", Status: " << (AForm.getIsSigned() ? "Signed" : "Not signed")
    << ", Grade required to sign: " << AForm.getGradeToSign()
    << ", Grade required to execute: " << AForm.getGradeToExecute();
    return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}