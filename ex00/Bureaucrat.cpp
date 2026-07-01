#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) { }

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (maximum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (minimum is 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

