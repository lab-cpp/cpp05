#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "string"

class Intern {
	private:
		AForm* makeShrubbery(const std::string& target) const;
		AForm* makeRobotomy(const std::string& target) const;
		AForm* makePresidential(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif