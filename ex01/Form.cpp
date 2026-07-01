#include "Form.hpp"
#include <ostream>

Form::Form() : _name("Default form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {

}

Form::Form(const std::string& name, int gradeToSign, int getGradeToExecute) 
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(getGradeToExecute) {

    if (gradeToSign > 150 || getGradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
    if (gradeToSign < 1 || getGradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
}

Form::Form(const Form& src) 
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form& Form::operator=(const Form& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
    << ", Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
    << ", Grade required to sign: " << form.getGradeToSign()
    << ", Grade required to execute: " << form.getGradeToExecute();
    return os;
}
