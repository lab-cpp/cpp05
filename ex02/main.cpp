#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    std::cout << "\n--- TEST 1: ShrubberyCreationForm ---" << std::endl;
    try {
        Bureaucrat hermes("Hermes", 137);
        ShrubberyCreationForm shrub("home");
        
        hermes.executeForm(shrub);
        hermes.signForm(shrub);
        hermes.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: RobotomyRequestForm ---" << std::endl;
    try {
        Bureaucrat bender("Bender", 45);
        Bureaucrat fry("Fry", 72);
        RobotomyRequestForm robot("Target");

        fry.signForm(robot);
        bender.executeForm(robot);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: PresidentialPardonForm ---" << std::endl;
    try {
        Bureaucrat zaphod("Zaphod", 5);
        PresidentialPardonForm pardon("Ford Prefect");

        zaphod.signForm(pardon);
        zaphod.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Low Grade Execution ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon2("Arthur Dent");

        intern.executeForm(pardon2);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}