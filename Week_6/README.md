# Решения на задачите след Week 6 OOP FMI

## Задача 1
**Задача 1**: Напишете клас Set, който съдържа множество от числа (без повторения) в диапазона от 0 до n-1, където n е подадено в началото (1 <= n <= 1000). Класът трябва да пази дали съдържа дадено число в битове, т.е ако съдържа дадено число, съответвеният последователен бит ще бъде 1, в противен случай 0. Пример:

{3, 4, 6} => битове на множеството ще бъдат 00011010

{1, 8, 9} => 01000000 11000000

Класът трябва да има следните функции.

- Добавяне на число
- Проверка дали съдържа число
- Принтиране на всички числа, които съдържа
- Принтиране на това как е представено в паметта
- Член-функция, която приема друго множество и връща тяхното обединение
- Член-функция, която приема друго множество и връща тяхното сечение

**Бонус 1**: Направете класът да не зависи от първоначалното n, тоест по-всяко време да можете да добавите, което и да е число >= 0.

**Бонус 2**: Направете функция, която премахва дадено число от множеството.


## Моето решение :

```c++
#include<iostream>

int smaller(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}

int bigger(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

class Set {
private:
	bool* set;
	int n = 0;
public:
	Set() {
		this->n = 0;
		this->set = nullptr;
	}
	Set(const Set& other) {
		setN(other.n);
		for (int i = 0; i < this->n; i++) {
			if (other.set[i] == 1) {
				addNumber(i);
			}
		}
	}
	Set& operator=(const Set& other) {
		setN(other.n);
		for (int i = 0; i < this->n; i++) {
			this->set[i] = other.set[i];
		}
		return *this;
	}
	~Set() {
		delete[] this->set;
	}

	void setN(int a) {
		if (a < 0) {
			this->set = nullptr;
		}
		else {
			bool* setnew = new bool[a];
			for (int i = 0; i < smaller(a, this->n); i++) {
				setnew[i] = this->set[i];
			}
			for (int i = this->n; i < a; i++) {
				setnew[i] = 0;
			}
			delete[] this->set;
			this->n = a;
			this->set = setnew;
		}
	}
	void addNumber(int a) {
		if (a < n) {
			this->set[a] = 1;
		}
		else {
			this->setN(a + 1);
			this->set[a] = 1;
		}
	}
	int getN() const {
		return this->n;
	}
	bool* getSet() const {
		return this->set;
	}
	void print() const {
		std::cout << "{ ";
		for (int i = 0; i < this->n; i++) {
			if (this->set[i] == 1) {
				std::cout << i << " ";
			}
		}
		std::cout << "}";
	}
	void printRaw() const {
		for (int i = 0; i < this->n; i++) {
			std::cout << (bool)this->set[i];
		}
	}

	void removeNumber(int a) {
		if (a < n and this->set[a] == 1) {
			this->set[a] = 0;
		}
		int lastnum;
		for (int i = 0; i < this->n; i++) {
			if (this->set[i] == 1) {
				lastnum = i;
			}
		}
		setN(lastnum + 1);
	}

	bool hasNumber(int a) const {
		for (int i = 0; i < this->n; i++) {
			if (this->set[i] == 1 && i == a) {
				return 1;
			}
		}
		return 0;
	}

	Set Intersection(const Set& other) const {
		Set a;
		a.setN(smaller(this->n, other.n));
		for (int i = 0; i < a.n; i++) {
			if (this->set[i] == 1 && other.set[i] == 1) {
				a.set[i] = 1;
			}
			else {
				a.set[i] = 0;
			}
		}
		return a;
	}

	Set Union(const Set& other) const {
		Set a;
		a.setN(bigger(this->n, other.n));
		for (int i = 0; i < a.n; i++) {
			if (this->set[i] == 1 || other.set[i] == 1) {
				a.set[i] = 1;
			}
			else {
				a.set[i] = 0;
			}
		}
		return a;
	}
};


int main() {

	Set r;
	//r.setN(10);
	r.addNumber(9);
	r.addNumber(1);
	//r.setN(100);
	r.addNumber(50);
	Set a;
	a = r;
	//a.setN(90);
	r.addNumber(78);
	a.addNumber(69);
	r.addNumber(69);
	r.removeNumber(69);
	Set p = a.Intersection(r);
	Set k = a.Union(r);
	p.print();
	std::cout << "\n";
	k.print();
	std::cout << "\n";
	r.print();
	std::cout << "\n";
	a.print();



	return 0;
}

```


 