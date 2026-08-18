#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
    std::cout << "--- TEST: Intern creating forms ---" << std::endl;
    
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
    unknown = someRandomIntern.makeForm("time travel request", "TARDIS");

    Bureaucrat boss("Boss", 1);

    std::cout << "\n--- TEST: Processing forms ---" << std::endl;
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }
    if (unknown) {
        delete unknown;
    }

    return 0;
}