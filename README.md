# C++ Module 05: Repetition and Exceptions

## Overview
This module introduces the concepts of **exceptions** in C++, along with further practice in **Object-Oriented Programming (OOP)**, **Orthodox Canonical Form**, and class interactions. The project focuses on designing a small simulation of a bureaucratic system with bureaucrats, forms, and interns, while managing errors using try-catch blocks and custom exceptions.

## Concepts Learned

### 1. Exceptions in C++
Exceptions provide a clean and robust way to handle errors in C++. Instead of returning error codes (as we often do in C), exceptions allow a function to `throw` an error that can be `catch`-ed by the calling code.
- **Custom Exceptions**: We created custom exception classes (e.g., `GradeTooHighException`, `GradeTooLowException`) by inheriting from the standard `std::exception` class.
- **`try/catch` Blocks**: These blocks allow you to attempt executing code that might throw an exception, and if one is thrown, you handle it in the `catch` block without crashing the entire program.

### 2. Abstract Classes and Pure Virtual Functions
In Exercise 02, the `Form` class is refactored into an abstract class, `AForm`. 
- An abstract class cannot be instantiated on its own.
- It contains at least one **pure virtual function** (e.g., `virtual void execute(Bureaucrat const & executor) const = 0;`), which enforces derived classes to implement that specific function.

### 3. Pointers to Member Functions
In Exercise 03, the `Intern` class demonstrates the use of an array of pointers to member functions to dispatch form creation cleanly. This avoids complex and ugly `if/else if/else` logic when instantiating the right form class dynamically based on a string input.

### 4. Orthodox Canonical Form
The module continues to enforce the **Orthodox Canonical Form**, meaning that every class (unless explicitly stated, like exception classes) must include:
1. Default Constructor
2. Copy Constructor
3. Copy Assignment Operator
4. Destructor

## Project Structure
- **ex00**: The `Bureaucrat` class, showcasing basic exception throwing for invalid grades.
- **ex01**: The `Form` class, interacting with the Bureaucrat to simulate signing forms.
- **ex02**: Expanding to specific concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) which inherit from the abstract base class `AForm`. This introduces polymorphism and the `execute` functionality.
- **ex03**: The `Intern` class, who exists solely to create forms using an array of pointers to member functions.

## Compiling
Navigate to the directory of the exercise you want to test and run `make`:
```bash
make
./[executable_name]
```
The codebase complies strictly with the C++98 standard.
