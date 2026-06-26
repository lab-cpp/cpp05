#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "--- TEST: Normal creation ---" << std::endl;
    try {
        Bureaucrat hermes("Hermes", 34);
        std::cout << hermes << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST: Grade Too High at creation ---" << std::endl;
    try {
        Bureaucrat god("God", 0);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST: Grade Too Low at creation ---" << std::endl;
    try {
        Bureaucrat noob("Noob", 151);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST: Increment out of bounds ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        boss.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- TEST: Decrement out of bounds ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        intern.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}