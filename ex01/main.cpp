#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- TEST: Form Creation Exceptions ---" << std::endl;
    try {
        Form impossible("Impossible", 0, 150);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form impossible2("Impossible2", 150, 151);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "--- TEST: Successful Signing ---" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        Form tax("Tax Form", 50, 50);
        std::cout << tax << std::endl;
        ceo.signForm(tax);
        std::cout << tax << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST: Failed Signing ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Form nda("NDA", 50, 50);
        intern.signForm(nda);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}