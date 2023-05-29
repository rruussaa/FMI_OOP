# Решения на задачите след Week 1 OOP FMI

## Задача 1

**Задача 1:** Въвежда се цяло число **N**  и после **N** тригъгълника в равнината, определени от 3 точки ( 6 координати). <br />
Отпечатайте тригълниците **сортирани по лицата им.**

## Моето решение :

```c++
#include <iostream>

struct Rational // we create a struct that is going to represent a rational number
{
    int p; // each rational number is p/q where q != 0 so we have p
    int q; // and q
};

int GCD(int a, int b) { // we need to simplify our Rational numbers so we need to be able to find GCD
    if (b == 0) { // if b = 0 the recurtion won't end 
        std::cout<<"\n"<<"\n" << "Please run the program again and input a rational"<<"\n"<<"\n";
        return 1;
    }
    if (a % b == 0) { // this is the bottom of our recurtion, we base the recurtion of the Evclid's Algorithum
        return b; // We return b (the GCD)
    }
    else {
        return GCD(b, a % b); // we call the function again but with differnt numbers
    }

}

void simplify(int& a, int& b) { // we make a function that is going to simplify we pass as reffernace because we want to change the actual numbers
    int c = GCD(a, b); // we find the GDC
    a = a / c; // we devide each number by the GDC
    b = b / c; // we devide by GDC
}

void printRational(const Rational& A) { // we make a function that prints a RAtional number
    std::cout << A.p << "/" << A.q; //we print p/q
}

void inputRational(Rational& A) { // a function that can input a rational number
    int a;
    int b;
    std::cin >> a >> b;
    A.p = a;
    A.q = b;
}

Rational add(const Rational& A, const Rational& B) { // a function that takes two const Rational number reffernces
    Rational C;// const because we aren't going to change the number in the course of the function -- we make A rational C
    C.q = A.q * B.q; // a/b+c/d = (a*d+c*b)/(b*d) so we make q = b*d
    C.p = A.p * B.q + B.p * A.q; // here we make p = a*d+c*b
    simplify(C.p, C.q); // we simpify
    return C; // we return C
}

Rational subtract(const Rational& A, const Rational& B) { // a function that subtrcts 
    Rational C; // we make a ration C
    C.q = A.q * B.q; // a/b+c/d = (a*d-c*b)/(b*d) so we make q = b*d
    C.p = A.p * B.q - B.p * A.q; // we make p = a*d-c*b
    simplify(C.p, C.q); // we simplify
    return C; 
}

Rational multiply(const Rational& A, const Rational& B) {
    Rational C;
    C.q = A.q * B.q;
    C.p = A.p * B.p; // same here only a/b*c/d = (a*b)/(c*d)
    simplify(C.p, C.q);
    return C;
}

Rational divide(const Rational& A, const Rational& B) {
    Rational C;
    C.q = A.q * B.p; // here we use the rule that a/b:c/d = a/b*d/c
    C.p = A.p * B.q;
    simplify(C.p, C.q);
    return C;
}

bool isRational(const Rational& A) { // here we check if q = 0 
    return A.q; // if q = 0 A is not a rational if q != 0 A is rational
}

bool isInt(const Rational& A) { // we check if A is a whole number
    return !(A.p % A.q); // if p is devidable by q than A is a int else it isn't
}

int main()
{
    Rational C; // we create a rational C later refferd as first rational
    inputRational(C); // the user input C
    Rational D; // same here with D later reffered as Second rational
    inputRational(D);
    std::cout << "Sum of Rationals ";
    printRational(add(C, D)); // we test add
    std::cout <<"\n" << "Multiplication of Rationals ";
    printRational(multiply(C, D)); // we test multiply
    std::cout << "\n" << "Subtraction of first rational - second rational ";
    printRational(subtract(C, D)); // we test subtract
    std::cout << "\n" << "Subtraction of second rational - first rational ";
    printRational(subtract(D, C)); // we check if subtract works in opposite order 
    std::cout << "\n" << "fist rational devided by second rational ";
    printRational(divide(C, D)); // we check if divide works 
    std::cout << "\n" << "fist Second devided by first rational ";
    printRational(divide(C, D)); // we check if divide works in opposite order
    std::cout << "\n" << "Is first rational an INT ";
    std::cout<<isInt(C); // we test isInt
    std::cout << "\n" << "is second rational a rational ";
    std::cout << isRational(D); // we test isRational
    return 0;
}

```
 В OOP_task_1_notcomplete.cpp има частично решение, което само смята лицата на триъгълниците без да ги сортира, за да може по-лесно да се проследи хода на програмата.
 
 ## Задача 2
 
 **Задача 2:** Резлизирайте структура Rational, която е за работа с рационални числа. <br />
Имплементирайте функции за събиране, изваждане, умножение и деление. <br />
Имеплементирайте функция, която приема истанция(обект) от новия тип и връща дали е валидно рационално число, както и функция, която връща дали е цяло число. <br />


 ## Моето решение :
 
 ```c++
 #include <iostream>

struct Rational // we create a struct that is going to represent a rational number
{
    int p; // each rational number is p/q where q != 0 so we have p
    int q; // and q
};

int GCD(int a, int b) { // we need to simplify our Rational numbers so we need to be able to find GCD
    if (b == 0) { // if b = 0 the recurtion won't end 
        std::cout<<"\n"<<"\n" << "Please run the program again and input a rational"<<"\n"<<"\n";
        return 1;
    }
    if (a % b == 0) { // this is the bottom of our recurtion, we base the recurtion of the Evclid's Algorithum
        return b; // We return b (the GCD)
    }
    else {
        return GCD(b, a % b); // we call the function again but with differnt numbers
    }

}

void simplify(int& a, int& b) { // we make a function that is going to simplify we pass as reffernace because we want to change the actual numbers
    int c = GCD(a, b); // we find the GDC
    a = a / c; // we devide each number by the GDC
    b = b / c; // we devide by GDC
}

void printRational(const Rational& A) { // we make a function that prints a RAtional number
    std::cout << A.p << "/" << A.q; //we print p/q
}

void inputRational(Rational& A) { // a function that can input a rational number
    int a;
    int b;
    std::cin >> a >> b;
    A.p = a;
    A.q = b;
}

Rational add(const Rational& A, const Rational& B) { // a function that takes two const Rational number reffernces
    Rational C;// const because we aren't going to change the number in the course of the function -- we make A rational C
    C.q = A.q * B.q; // a/b+c/d = (a*d+c*b)/(b*d) so we make q = b*d
    C.p = A.p * B.q + B.p * A.q; // here we make p = a*d+c*b
    simplify(C.p, C.q); // we simpify
    return C; // we return C
}

Rational subtract(const Rational& A, const Rational& B) { // a function that subtrcts 
    Rational C; // we make a ration C
    C.q = A.q * B.q; // a/b+c/d = (a*d-c*b)/(b*d) so we make q = b*d
    C.p = A.p * B.q - B.p * A.q; // we make p = a*d-c*b
    simplify(C.p, C.q); // we simplify
    return C; 
}

Rational multiply(const Rational& A, const Rational& B) {
    Rational C;
    C.q = A.q * B.q;
    C.p = A.p * B.p; // same here only a/b*c/d = (a*b)/(c*d)
    simplify(C.p, C.q);
    return C;
}

Rational divide(const Rational& A, const Rational& B) {
    Rational C;
    C.q = A.q * B.p; // here we use the rule that a/b:c/d = a/b*d/c
    C.p = A.p * B.q;
    simplify(C.p, C.q);
    return C;
}

bool isRational(const Rational& A) { // here we check if q = 0 
    if (A.q == 0) {
        return false; // if q = 0 A is not a rational
    }
    else {
        return true; // if q != 0 A is rational
    }
}

bool isInt(const Rational& A) { // we check if A is a whole number
    if (A.p % A.q == 0) { // if p is devidable by q than A is a int 
        return true;
    }
    else {
        return false; // else it isn't
    }
}

int main()
{
    Rational C; // we create a rational C later refferd as first rational
    inputRational(C); // the user input C
    Rational D; // same here with D later reffered as Second rational
    inputRational(D);
    std::cout << "Sum of Rationals ";
    printRational(add(C, D)); // we test add
    std::cout <<"\n" << "Multiplication of Rationals ";
    printRational(multiply(C, D)); // we test multiply
    std::cout << "\n" << "Subtraction of first rational - second rational ";
    printRational(subtract(C, D)); // we test subtract
    std::cout << "\n" << "Subtraction of second rational - first rational ";
    printRational(subtract(D, C)); // we check if subtract works in opposite order 
    std::cout << "\n" << "fist rational devided by second rational ";
    printRational(divide(C, D)); // we check if divide works 
    std::cout << "\n" << "fist Second devided by first rational ";
    printRational(divide(C, D)); // we check if divide works in opposite order
    std::cout << "\n" << "Is first rational an INT ";
    std::cout<<isInt(C); // we test isInt
    std::cout << "\n" << "is second rational a rational ";
    std::cout << isRational(D); // we test isRational
    return 0;
}
```

 