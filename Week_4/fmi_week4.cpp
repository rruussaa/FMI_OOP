#include <iostream>

int lenght(int x) {
	x = abs(x);
	int count = 0;
	while (x != 0) {
		count += 1;
		x = x / 10;
	}
	return count;
}

int numberinplace(int a, int b) {
	if (b > lenght(a) - 1) {
		std::cout << "number is too short";
		return -1;
	}
	else {
		for (int i = 0; i < b; i++) {
			a = a / 10;
		}
		return a % 10;
	}


}

bool isPrime(int a) {
	a = abs(a);
	if (a == 0 || a == 1) {
		return 0;
	}
	bool notPrime = 0;
	int p = sqrt(a);
	for (int i = 2; i <= p; i++) {
		if ((a % i) == 0) {
			notPrime = 1;
		}
	}
	return !notPrime;
}

bool isPalindrome(int x) {
	x = abs(x);
	int len = lenght(x);
	for (int i = 0; i < len / 2; i++) {
		if (numberinplace(x, len - i - 1) == numberinplace(x, i)) {
		}
		else {
			return 0;
		}
	}
	return 1;

}

bool repNumbers(int a) {
	a = abs(a);
	int len = lenght(a);
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (numberinplace(a, i) == numberinplace(a, j)) {
				return 1;
			}
		}
	}
	return 0;
}

bool ispowof2(int a) {
	a = abs(a);
	if (a == 0) {
		return 0;
	}
	while (a != 1) {
		if (a % 2 == 0) {
			a = a / 2;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int bigger(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int smaller(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

struct Interval {

private:
	int a;
	int b;

public:
	Interval() {
		a = 0;
		b = 0;
	}
	Interval(int a, int b) {
		if (a <= b) {
			this->a = a;
			this->b = b;
		}
		else {
			Interval();
		}
	}

	void setA(int a) {
		this->a = a;
	}

	void setB(int b) {
		this->b = b;
	}

	int getA() const {
		return this->a;
	}

	int getB() const {
		return this->b;
	}


	int Lenght() const {
		return b - a;
	}
	bool init(int x) const {
		if (this->a <= x && this->b >= x) {
			return true;
		}
		else {
			return false;
		}
	}
	int countPrimes() const {
		int count = 0;
		for (int i = this->a; i <= this->b; i++) {
			count += isPrime(i);
		}
		return count;
	}
	int countPalindromes() const {
		int count = 0;
		for (int i = this->a; i <= this->b; i++) {
			count += isPalindrome(i);
		}
		return count;
	}

	int countNORepnumbers() const {
		int count = 0;
		for (int i = this->a; i <= this->b; i++) {
			count += !repNumbers(i);
		}
		return count;
	}

	bool arepowof2() const {
		if (ispowof2(this->a) && ispowof2(this->b)) {
			return 1;
		}
		else {
			return 0;
		}
	}

	Interval intersect(const Interval& A) const {
		Interval B;
		if (this->a > A.b || this->b < A.a) {
			return B;
		}
		B.setA(bigger(this->a, A.a));
		B.setB(smaller(this->b, A.b));
		return B;
	}

	bool isinit(const Interval& A) const {
		if (A.a >= this->a && A.b <= this->b) {
			return 1;
		}
		return 0;
	}


};

int main() {

	Interval t1(3, 10);
	Interval t2(5, 14);
	Interval t3;

	Interval result = t2.intersect(t1);

	std::cout << "[" << result.getA() << "," << result.getB() << "]";

	std::cout << " " << t2.isinit(t1);

	//std::cout << x.arepowof2();

	return 0;
}