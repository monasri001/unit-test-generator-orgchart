# Unit Test Generator for C++ using LLMs (Ollama + YAML + gcov)

## 🔧 Project Overview

This project automatically generates, refines, and evaluates unit tests for C++ applications using LLMs, YAML prompts, and code coverage tools like `gcov` and `lcov`. It is built around the `orgChartApi` C++ application.

---

## 🧱 Project Structure

```
unit-test-generator-orgchart/
├── orgChartApi-master/           # Original C++ project
├── tests/                        # AI-generated tests
├── build/                        # CMake build directory
├── test_coverage/                # gcov and lcov reports
├── prompts/                      # YAML prompts for test generation
├── test_runner.py                # Orchestration script for build & run
└── README.md                     # Project documentation
```

---

## 🛠️ Technologies Used

- **LLMs**: Local models via **Ollama**
- **Prompting**: Structured **YAML** templates
- **C++**: Google Test framework
- **Build System**: CMake
- **Coverage**: gcov, lcov, genhtml
- **Ubuntu**: for development and compilation

---

## 🧪 Steps to Run

### 1. Clone the Repository

```bash
git clone https://github.com/monasri001/unit-test-generator-orgchart.git
cd unit-test-generator-orgchart/orgChartApi-master
```

### 2. Install Dependencies

```bash
sudo apt update
sudo apt install cmake g++ lcov libgtest-dev libdrogon-dev -y
```

### 3. Build the C++ Application

```bash
mkdir build && cd build
cmake ..
make
```

### 4. Generate Unit Tests using Ollama

> Requires Ollama installed with a model like `llama3` or `codellama`

```bash
ollama run codellama < prompts/generate_tests.yaml > tests/generated_test.cpp
```

### 5. Run Tests

```bash
cd orgChartApi-master/build
ctest --output-on-failure
```

### 6. Generate Code Coverage Report

```bash
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory test_coverage
xdg-open test_coverage/index.html
```

---

## 📊 Output

- AI-generated unit tests in `tests/`
- HTML code coverage report in `test_coverage/`

---

## ✍️ Author

- Monasri — [GitHub](https://github.com/monasri001)

---

## 🗓️ Last Updated

July 06, 2025
