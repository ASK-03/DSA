### 1. **Object-Oriented Programming (OOP)**

- **Definition**: OOP is a programming paradigm that organizes software design around objects, which are instances of classes. These objects can contain data in the form of fields (attributes) and code in the form of procedures (methods).
- **Key Features**: Encapsulation, Inheritance, Polymorphism, and Abstraction.

---

### 2. **Class and Object**

- **Class**: A blueprint for creating objects that defines a set of attributes and methods common to all objects of that type.
    
    ```cpp
    class Car {
    public:
        string brand;
        int speed;
    
        void drive() {
            cout << "Driving at speed: " << speed << endl;
        }
    };
    ```
    
- **Object**: An instance of a class.
    
    ```cpp
    int main() {
        Car myCar;
        myCar.brand = "Toyota";
        myCar.speed = 120;
        myCar.drive();
        return 0;
    }
    ```
    

---

### 3. **Encapsulation**

- **Definition**: Encapsulation is the bundling of data and methods operating on the data within a single unit (class). It restricts direct access to some of an object’s components, protecting the integrity of the data.
- **Key Concept**: Use `private` and `public` access modifiers.
    
    ```cpp
    class Account {
    private:
        double balance;
    
    public:
        void setBalance(double b) {
            if (b >= 0) balance = b;
        }
    
        double getBalance() {
            return balance;
        }
    };
    ```
    

---

### 4. **Inheritance**

- **Definition**: Inheritance is a mechanism by which one class can acquire the properties and behaviors of another class, promoting code reuse.
- **Syntax**: `class DerivedClass : accessModifier BaseClass`
    
    ```cpp
    class Vehicle {
    public:
        void start() {
            cout << "Vehicle started" << endl;
        }
    };
    
    class Car : public Vehicle {
    public:
        void drive() {
            cout << "Car is driving" << endl;
        }
    };
    
    int main() {
        Car myCar;
        myCar.start();  // Inherited from Vehicle
        myCar.drive();
        return 0;
    }
    ```
    

---

### 5. **Polymorphism**

- **Definition**: Polymorphism allows the same interface or method to behave differently for different data types or classes.
- **Types**:
    1. **Compile-time (Function Overloading and Operator Overloading)**:
        
        ```cpp
        class Print {
        public:
            void show(int x) {
                cout << "Integer: " << x << endl;
            }
        
            void show(string str) {
                cout << "String: " << str << endl;
            }
        };
        ```
        
    2. **Runtime (Method Overriding using Virtual Functions)**:
        
        ```cpp
        class Shape {
        public:
            virtual void draw() {
                cout << "Drawing Shape" << endl;
            }
        };
        
        class Circle : public Shape {
        public:
            void draw() override {
                cout << "Drawing Circle" << endl;
            }
        };
        
        int main() {
            Shape* shape = new Circle();
            shape->draw();  // Outputs: Drawing Circle
            return 0;
        }
        ```
        

---

### 6. **Abstraction**

- **Definition**: Abstraction is the process of hiding implementation details and showing only the functionality to the user. It can be achieved using abstract classes or interfaces in C++.
    
    ```cpp
    class AbstractShape {
    public:
        virtual void draw() = 0; // Pure virtual function
    };
    
    class Rectangle : public AbstractShape {
    public:
        void draw() override {
            cout << "Drawing Rectangle" << endl;
        }
    };
    
    int main() {
        AbstractShape* shape = new Rectangle();
        shape->draw();
        return 0;
    }
    ```
    

---

### 7. **Access Modifiers**

- **Definition**: Access modifiers define the scope and visibility of class members.
    
    - `public`: Accessible from anywhere.
    - `private`: Accessible only within the class.
    - `protected`: Accessible within the class and its derived classes.
    
    ```cpp
    class Base {
    private:
        int privateVar;
    protected:
        int protectedVar;
    public:
        int publicVar;
    };
    ```
    

---

### 8. **Constructor and Destructor**

- **Constructor**: A special method called when an object is created, used for initialization.
    
    ```cpp
    class Person {
    public:
        Person(string name) {
            cout << "Hello, " << name << endl;
        }
    };
    
    int main() {
        Person p("John");
        return 0;
    }
    ```
    
- **Destructor**: A special method called when an object is destroyed, used for cleanup.
    
    ```cpp
    class Demo {
    public:
        ~Demo() {
            cout << "Object destroyed" << endl;
        }
    };
    ```
    

---

### 9. **Operator Overloading**

- **Definition**: A feature that allows defining custom behavior for operators.
    
    ```cpp
    class Complex {
    public:
        int real, imag;
    
        Complex(int r, int i) : real(r), imag(i) {}
    
        Complex operator+(const Complex& obj) {
            return Complex(real + obj.real, imag + obj.imag);
        }
    };
    
    int main() {
        Complex c1(1, 2), c2(3, 4);
        Complex c3 = c1 + c2;
        return 0;
    }
    ```
    

---
### 10. **Friend Class Syntax**

A friend class allows one class to access the private and protected members of another class.

```cpp
class ClassA {
private:
    int data;

public:
    ClassA(int val) : data(val) {}

    // Declare ClassB as a friend class
    friend class ClassB;
};

class ClassB {
public:
    void displayData(const ClassA& obj) {
        // Access private member of ClassA
        std::cout << "Data from ClassA: " << obj.data << std::endl;
    }
};
```

---

### 11. **Friend Function Syntax**

A friend function allows a function to access private and protected members of a class.

```cpp
class MyClass {
private:
    int secret;

public:
    MyClass(int val) : secret(val) {}

    // Declare a friend function
    friend void showSecret(const MyClass& obj);
};

// Friend function definition
void showSecret(const MyClass& obj) {
    // Access private member of MyClass
    std::cout << "Secret is: " << obj.secret << std::endl;
}
```

---