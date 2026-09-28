## ✅ **1. SOLID Principles**

### 🔹 Introduction

SOLID is an acronym for five design principles that make OOP software more understandable, flexible, and maintainable.

- **S**: Single Responsibility Principle (SRP)
- **O**: Open/Closed Principle (OCP)
- **L**: Liskov Substitution Principle (LSP)
- **I**: Interface Segregation Principle (ISP)
- **D**: Dependency Inversion Principle (DIP)    

---

### 🔹 Advantages

- Reduces code duplication and coupling.
- Improves testability and readability.
- Makes systems easier to scale and modify.
- Promotes reuse and abstraction.

---

### 🔹 Real-Life Use Cases

- Building services in a microservices architecture.    
- Designing extensible UI components in large applications.
- Separating concerns in a backend system (e.g., controller vs service vs DAO).
- Making flexible payment or notification systems.

---

### 🔹 Example in C++ (SRP + OCP)

```cpp
#include <iostream>
using namespace std;

// SRP: Class with only one reason to change (Invoice-related logic)
class Invoice {
    string customer;
    double amount;
public:
    Invoice(string c, double a): customer(c), amount(a) {}
    double getTotal() const { return amount; }
};

// OCP: Open for extension, closed for modification
class InvoicePrinter {
public:
    virtual void print(const Invoice& invoice) = 0;
};

class PDFPrinter : public InvoicePrinter {
public:
    void print(const Invoice& invoice) override {
        cout << "Printing invoice as PDF: $" << invoice.getTotal() << endl;
    }
};

int main() {
    Invoice invoice("John", 250.0);
    PDFPrinter pdfPrinter;
    pdfPrinter.print(invoice);
    return 0;
}
```

---

## ✅ **2. DRY – Don’t Repeat Yourself**

### 🔹 Introduction

The DRY principle states: _"Every piece of knowledge must have a single, unambiguous, authoritative representation in the system."_

### 🔹 Advantages

- Reduces bugs due to changes in duplicated logic.
- Increases maintainability.
- Promotes reuse and modular design.

### 🔹 Real-Life Use Cases

- Reusable utility functions (e.g., `calculateTax`, `validateEmail`)
- Common API response formatters.
- Shared logging modules.

### 🔹 Example in C++

```cpp
double calculateDiscount(double amount) {
    return amount * 0.1;
}

double finalAmount(double amount) {
    return amount - calculateDiscount(amount); // reused logic
}
```

---

## ✅ **3. KISS – Keep It Simple, Stupid**

### 🔹 Introduction

KISS encourages simplicity in design and implementation. Avoid overengineering.

### 🔹 Advantages

- Makes code easy to understand, debug, and maintain.
- Reduces cognitive load on future developers (or yourself).
- Faster development cycles.

### 🔹 Real-Life Use Cases

- Choosing simple data structures (e.g., maps instead of custom trees for basic lookup)
- Using clear naming and short functions.
- Avoiding unnecessary abstractions and patterns.

### 🔹 Example in C++ (Anti-pattern and improved)

**❌ Over-engineered**

```cpp
class Logger {
public:
    virtual void log(string message) = 0;
};

class FileLogger : public Logger {
    // unnecessary complexity
};
```

**✅ Simpler**

```cpp
void log(string message) {
    cout << "Log: " << message << endl;
}
```

---

## ✅ **4. YAGNI – You Aren’t Gonna Need It**

### 🔹 Introduction

YAGNI tells you **not to implement features until they are actually needed.**

### 🔹 Advantages

- Saves time and effort.
- Keeps codebase lean and understandable.
- Reduces unused and untested code paths.

### 🔹 Real-Life Use Cases

- Avoiding building complex caching layers unless performance demands it.
- Not adding an extra layer of abstraction unless truly needed.
- Skipping future-proofing features until there's evidence of need.

### 🔹 Example in C++

**❌ Violates YAGNI (future config not used yet)**

```cpp
class ConfigLoader {
    string cloudSource; // Unused
public:
    void loadFromFile(string path) { /*...*/ }
};
```

**✅ Follows YAGNI**

```cpp
class ConfigLoader {
public:
    void loadFromFile(string path) { /*...*/ }
};
```
