#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

	// Shrubbery
    try {
        Bureaucrat hermes("Hermes", 137);
        ShrubberyCreationForm shrub("home");
        
        hermes.executeForm(shrub);
        hermes.signForm(shrub);
        hermes.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	// Robotomy
    try {
        Bureaucrat bender("Bender", 45);
        Bureaucrat fry("Fry", 72);
        RobotomyRequestForm robot("Target");

        fry.signForm(robot);
        bender.executeForm(robot);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	// Presidential Pardon
    try {
        Bureaucrat zaphod("Zaphod", 5);
        PresidentialPardonForm pardon("Ford Prefect");

        zaphod.signForm(pardon);
        zaphod.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	// low grade tests
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon2("Arthur Dent");

        intern.executeForm(pardon2);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}