# C++ Module 08 - Templated Containers, Iterators, and Algorithms

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/macOS-000000?style-for-the-badge&logo=apple&logoColor=white)
![42](https://img.shields.io/badge/42-Project-00BABC?style-for-the-badge)
![Score](https://img.shields.io/badge/Score-100%25-brightgreen?style-for-the-badge)

## 📋 Project Overview

C++ Module 08 is the ninth project in the 42 school C++ curriculum, focusing on **templated containers**, **iterators**, and **algorithms** in C++98. Through three exercises—**Easy Find**, **Span**, and **MutantStack**—this module teaches the use of the Standard Template Library (STL) to create generic, reusable, and efficient code. It emphasizes template programming, iterator-based operations, and STL algorithms, enforcing strict C++98 compliance, no forbidden functions (`printf`, `alloc`, `free`), and explicit namespace usage. The module ensures robust error handling and leak-free code, verified with `valgrind`.

## ✨ Key Features

- **Exercise 00: Easy Find**:
  - Implements a function template `easyfind` that searches for an integer in a sequential container (`std::vector`, `std::list`, `std::deque`) using `std::find`.
  - Returns an iterator to the first occurrence or throws an exception if not found.
  - Demonstrates template functions and iterator usage.
- **Exercise 01: Span**:
  - Creates a `Span` class to store up to `N` integers in a `std::vector`.
  - Provides methods to add single numbers or iterator ranges, and compute shortest and longest spans (differences) using `std::sort`, `std::min_element`, and `std::max_element`.
  - Tests deep copying and exception handling for full storage or insufficient elements.
- **Exercise 02: MutantStack**:
  - Implements a `MutantStack` class template that extends `std::stack` to add iterator support (`begin`, `end`, `rbegin`, `rend`).
  - Supports different underlying containers (`std::deque`, `std::vector`, `std::list`) and element types (`int`, `double`, `std::string`).
  - Demonstrates inheritance, templates, and iterator access to the underlying container.
- **C++98 Compliance**:
  - Compiled with `-Wall -Wextra -Werror -std=c++98`.
  - No `using namespace`, `friend`, or forbidden functions (`printf`, `alloc`, `free`).
- **Norm Compliance**:
  - Adheres to 42’s coding standards, with newline-terminated outputs and no memory leaks (verified with `valgrind`).

## 🛠️ Prerequisites

- **Operating System**: UNIX-based (Linux, macOS, etc.).
- **Compiler**: `c++` (GCC or Clang, C++98 compatible).
- **Build Tool**: `make`.
- **Debugger**: `valgrind` for memory leak detection.

## 🚀 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/mde-agui/Cpp08.git
   cd Cpp08
   ```

2. Navigate to an exercise directory and compile:
   ```bash
   cd ex00
   make
   ```
   Repeat for `ex01`, `ex02`. This creates executables (e.g., `easyfind`, `span`, `mutantstack`).

## 📖 Usage

Each exercise is independent and run from its respective directory.

### Exercise 00: Easy Find
```bash
cd ex00
./easyfind
```
Output: Searches for integers in containers (e.g., `std::vector<int> {1, 2, 3}`), printing iterator positions or throwing exceptions (e.g., `Value not found`).

### Exercise 01: Span
```bash
cd ex01
./span
```
Output:
```
Shortest span: 2
Longest span: 14
```
Tests single number additions, iterator range additions, and edge cases (e.g., full storage, fewer than 2 numbers).

### Exercise 02: MutantStack
```bash
cd ex02
./mutantstack
```
Output (sample):
```
Stack contents (size: 5): 5 3 4 737 0
Reverse order: 3 2 1
Vector-based stack (size: 3): 100 200 300
```
Tests stack operations, iteration, and different containers/types.

Check for memory leaks:
```bash
valgrind ./mutantstack
```

## 📂 Project Structure

```
cpp_module_08/
├── ex00/                   # Easy Find: Function template with iterators
│   ├── Makefile
│   ├── easyfind.hpp
│   ├── easyfind.tpp
│   └── main.cpp
├── ex01/                   # Span: Class with STL containers and algorithms
│   ├── Makefile
│   ├── Span.hpp
│   ├── Span.cpp
│   └── main.cpp
├── ex02/                   # MutantStack: Template class with iterator support
│   ├── Makefile
│   ├── MutantStack.hpp
│   ├── MutantStack.tpp
│   └── main.cpp
└── README.md               # This file
```

## 🛠️ Makefile Commands

Each exercise has its own `Makefile` with the following commands:

| Command       | Description                              |
|---------------|------------------------------------------|
| `make`        | Builds the executable (e.g., `easyfind`, `span`, `mutantstack`). |
| `make clean`  | Removes object files.                    |
| `make fclean` | Removes object files and executable.     |
| `make re`     | Rebuilds the project from scratch.       |

## 🔍 Technical Details

- **C++ Concepts Covered**:
  - **Templated Containers**: Use of `std::vector`, `std::list`, `std::deque`, and `std::stack` for generic storage (Ex01, Ex02).
  - **Iterators**: Iterator-based traversal and operations (e.g., `begin`, `end`, `rbegin`) in all exercises.
  - **Algorithms**: STL algorithms like `std::find`, `std::sort`, `std::min_element`, `std::max_element` (Ex00, Ex01).
  - **Templates**: Function templates (`easyfind`) and class templates (`MutantStack`, `Span`’s range method).
  - **Exception Handling**: Throws for errors (e.g., value not found, full storage) in all exercises.
  - **Memory Management**: Uses STL containers to avoid manual `new`/`delete`, verified with `valgrind`.
- **Constraints**:
  - Compiled with `-Wall -Wextra -Werror -std=c++98`.
  - No `using namespace`, `friend`, or forbidden functions (`printf`, `alloc`, `free`).
  - Mandatory STL usage for containers and algorithms (unlike Modules 00–07).
  - Outputs end with newlines.
- **External Functions**:
  - Allowed: `std::vector`, `std::list`, `std::deque`, `std::stack`, `std::find`, `std::sort`, `std::min_element`, `std::max_element`, `std::cout`, `std::endl`.
- **Error Handling**:
  - Validates inputs (e.g., full `Span`, value not found in `easyfind`).
  - Ensures no memory leaks in STL container usage.

## 📚 Explanation of Key C++ Concepts

### Templated Containers
- **Definition**: Templated containers are STL classes that store and manage data of any type using templates. Examples include `std::vector<T>`, `std::list<T>`, `std::deque<T>`, and `std::stack<T, Container>`. They provide dynamic sizing, memory management, and iterator support.
- **Usage in Module 08**:
  - **Exercise 00**: `easyfind` works with sequential containers (`std::vector`, `std::list`, `std::deque`) to search for integers.
  - **Exercise 01**: `Span` uses `std::vector<int>` for storage, leveraging its random access and dynamic growth.
  - **Exercise 02**: `MutantStack` extends `std::stack` with a customizable underlying container (default `std::deque`, tested with `std::vector`, `std::list`).
- **Why It Matters**: Templates allow containers to be generic, enabling reuse across different data types and containers while maintaining efficiency and type safety.
- **Example**:
  ```cpp
  std::vector<int> vec = {1, 2, 3};
  MutantStack<double, std::list<double> > stack; // Custom container and type
  ```

### Iterators
- **Definition**: Iterators are objects that traverse container elements, acting like pointers. They support operations like dereferencing (`*it`), incrementing (`++it`), and comparison (`it != end()`). Types include `iterator` (read/write), `const_iterator` (read-only), and `reverse_iterator` (backward traversal).
- **Usage in Module 08**:
  - **Exercise 00**: `easyfind` returns a container’s iterator using `std::find`.
  - **Exercise 01**: `Span`’s template `addNumber` uses iterators to add a range of numbers.
  - **Exercise 02**: `MutantStack` adds `begin`, `end`, `rbegin`, and `rend` to access the underlying container’s iterators.
- **Why It Matters**: Iterators provide a uniform way to access container elements, enabling generic algorithms to work with any container.
- **Example**:
  ```cpp
  MutantStack<int> stack;
  stack.push(1); stack.push(2);
  for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
      std::cout << *it << " "; // Outputs: 1 2
  ```

### Algorithms
- **Definition**: STL algorithms are functions in `<algorithm>` that operate on iterator ranges, performing tasks like searching (`std::find`), sorting (`std::sort`), or finding extremes (`std::min_element`, `std::max_element`).
- **Usage in Module 08**:
  - **Exercise 00**: `easyfind` uses `std::find` to locate an integer.
  - **Exercise 01**: `Span` uses `std::sort` for `shortestSpan` and `std::min_element`/`std::max_element` for `longestSpan`.
  - **Exercise 02**: No algorithms directly, but iterators enable potential algorithm use.
- **Why It Matters**: Algorithms provide efficient, reusable solutions for common tasks, working seamlessly with any iterator-supporting container.
- **Example**:
  ```cpp
  std::vector<int> vec = {3, 1, 4};
  std::sort(vec.begin(), vec.end()); // Sorts to {1, 3, 4}
  ```

## 📝 Notes

- **Implementation Details**:
  - `easyfind` throws `std::runtime_error` for not-found values.
  - `Span` handles deep copying and iterator ranges with `std::vector::insert`.
  - `MutantStack` inherits `std::stack` and exposes the underlying container’s iterators.
- **Testing**:
  - Test programs cover edge cases (e.g., empty containers, full `Span`, large stacks).
  - `valgrind` ensures no memory leaks in all exercises.
- **Evaluation**:
  - Outputs match subject requirements (e.g., spans in Ex01, stack iteration in Ex02).
  - Adheres to 42’s Norminette equivalent (manual checks for line length, naming).

## 📜 License

This project is licensed under the [MIT License](LICENSE).

## 👤 Author

**mde-agui**  
GitHub: [mde-agui](https://github.com/mde-agui)

---

⭐️ If you find this project useful, consider giving it a star on GitHub!