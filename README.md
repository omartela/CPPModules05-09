# CPP Modules 05-09 - Advanced C++ Concepts

This repository contains C++ modules 05 through 09 from the 42 school curriculum, covering advanced C++ programming concepts including exception handling, casting, templates, STL containers, and algorithms.

## 📚 Overview

Each module focuses on specific C++ concepts and contains multiple exercises that build upon each other. The exercises follow the 42 school coding standard and demonstrate practical applications of advanced C++ features.

## 🏗️ Project Structure

```
CPPModules05-09/
├── Module05/          # Exception handling
├── Module06/          # Casting and conversion
├── Module07/          # Templates  
├── Module08/          # Templated containers
├── Module09/          # STL containers and algorithms
└── README.md
```

Each module contains exercises (ex00, ex01, ex02, and sometimes ex03) with the following structure:
```
ModuleXX/
└── exXX/
    ├── inc/           # Header files
    ├── src/           # Source files
    └── Makefile       # Build configuration
```

## 📖 Module Breakdown

### Module 05: Exception Handling
**Learning objectives:** C++ exceptions, exception safety, RAII principles

- **ex00: Bureaucrat** - Basic exception handling with custom exception classes
- **ex01: Form** - Form signing system with grade-based permissions  
- **ex02: Forms** - Concrete form implementations (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm)
- **ex03: Intern** - Factory pattern for form creation

**Key concepts:** `std::exception`, custom exceptions, exception safety, try-catch blocks

### Module 06: Casting and Conversion
**Learning objectives:** C++ casting operators, serialization, RTTI

- **ex00: ScalarConverter** - Converting between different scalar types (char, int, float, double)
- **ex01: Serializer** - Serialization and deserialization of data structures using `uintptr_t`
- **ex02: Identify** - Runtime Type Identification (RTTI) with `dynamic_cast`

**Key concepts:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, serialization

### Module 07: C++ Templates
**Learning objectives:** Function templates, class templates, template specialization

- **ex00: Templates** - Template functions (`swap`, `min`, `max`)
- **ex01: Iter** - Template function for applying functions to container elements
- **ex02: Array** - Template class implementing a generic array with bounds checking

**Key concepts:** Function templates, class templates, template parameters, generic programming

### Module 08: Templated Containers and Iterators
**Learning objectives:** STL-style containers, iterators, container adapters

- **ex00: easyfind** - Template function for finding elements in containers
- **ex01: Span** - Container for storing integers with span calculation functionality
- **ex02: MutantStack** - Stack container with iterator support

**Key concepts:** Container design, iterators, STL algorithms, container adapters

### Module 09: STL Containers and Algorithms
**Learning objectives:** STL containers, algorithms, performance analysis

- **ex00: BitcoinExchange** - Bitcoin price calculator using `std::map` and CSV parsing
- **ex01: RPN** - Reverse Polish Notation calculator using `std::stack`
- **ex02: PmergeMe** - Merge-insert sort implementation with performance comparison between containers

**Key concepts:** `std::map`, `std::stack`, `std::vector`, `std::deque`, sorting algorithms, performance analysis

## 🔨 Building and Running

### Prerequisites
- C++ compiler with C++98 standard support (g++, clang++)
- Make

### Building Individual Exercises
```bash
# Navigate to any exercise directory
cd ModuleXX/exXX/

# Build the project
make

# Run the executable (name varies by exercise)
./executable_name
```

### Building All Modules
```bash
# Build all exercises in a module
for ex in Module05/ex*/; do
    echo "Building $ex"
    (cd "$ex" && make)
done
```

### Cleaning Build Files
```bash
# Clean individual exercise
make clean          # Remove object files
make fclean         # Remove object files and executable
make re             # Rebuild from scratch

# Clean all exercises
find . -name "Makefile" -execdir make fclean \;
```

## 🧪 Example Usage

### Module 05 - Exception Handling
```bash
cd Module05/ex00
make && ./Bureaucrat
# Demonstrates exception throwing and catching with bureaucrat grades
```

### Module 06 - Scalar Conversion
```bash
cd Module06/ex00  
make && ./convert "42.0f"
# Converts and displays the value in different scalar types
```

### Module 07 - Templates
```bash
cd Module07/ex02
make && ./array
# Demonstrates template array class with bounds checking
```

### Module 08 - Containers
```bash
cd Module08/ex01
make && ./span
# Shows span calculation with integer containers
```

### Module 09 - STL Usage
```bash
cd Module09/ex00
make && ./btc input.txt
# Calculates Bitcoin values using historical price data

cd Module09/ex01  
make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# Evaluates Reverse Polish Notation expressions
```

## 🎯 Learning Outcomes

By completing these modules, you will gain proficiency in:

- **Exception Safety**: Writing robust C++ code that handles errors gracefully
- **Type Casting**: Understanding and properly using C++ casting operators
- **Template Programming**: Creating generic, reusable code components
- **STL Mastery**: Effectively using Standard Template Library containers and algorithms
- **Performance Analysis**: Comparing different algorithms and container implementations
- **Memory Management**: Understanding RAII and smart resource handling
- **Design Patterns**: Implementing common patterns like Factory and Adapter

## 📋 Requirements

- All code follows C++98 standard
- Orthodox Canonical Form implementation for classes
- No memory leaks (all heap allocations properly managed)
- Proper exception handling and safety
- Comprehensive error checking and validation
- Clean, readable, and well-documented code

## 🤝 42 School Standards

This project adheres to the 42 school coding standard:
- 25-line function limit
- 5-function-per-file limit  
- Norminette-compliant formatting
- Comprehensive error handling
- No standard library usage restrictions beyond C++98

## 📝 Notes

- Each exercise builds upon concepts from previous ones
- Test your implementations thoroughly with edge cases
- Pay attention to const-correctness and exception safety
- Some exercises include bonus features for additional learning

---

*Part of the 42 school C++ curriculum - Advanced object-oriented programming in C++*
