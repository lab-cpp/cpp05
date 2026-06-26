#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& src);
        Form& operator=(const Form& rhs);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);
        
};

#endif