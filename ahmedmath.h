#pragma once		// compiler directive

#include <random>

namespace ahmed {
	unsigned long long summation(unsigned long long number) {
		unsigned long long sum = 0;

		for (unsigned long long i = number; i > 0; i--)
			sum += i;

		return sum;
	}

	unsigned long long fact(unsigned long long number) {
		unsigned long long factorial = 1;

		for (unsigned long long i = number; i > 1; i--)
			factorial *= i;

		return factorial;
	}

	bool isEven(long long number) {
		if (number % 2 == 0)
			return true;

		return false;
	}

	bool isOdd(long long number) {
		if (number % 2 != 0)
			return true;

		return false;
	}

	bool isPrime(unsigned long long number) {
		if (number == 2)
			return true;					// 2 is the only prime even number

		if (number % 2 == 0 || number < 2)	// 1 and all evens are not prime
			return false;

		for (unsigned long long i = 3; i <= number / i; i += 2)
			if (number % i == 0)			// i += 2 to sqrt(number)
				return false;

		return true;
	}

	unsigned long long sum_divs(unsigned long long number) {
		unsigned long long divs_sum = 1;		// common div

		if (number <= divs_sum)
			return 0;

		for (unsigned long long i = 2; i <= number / i; i++) {
			if (number % i == 0) {
				divs_sum += i;

			if (number / i != i)
				divs_sum += number / i;
			}
		}

		return divs_sum;
	}

	bool isPerfect(unsigned long long number) {
		if (sum_divs(number) == number)
			return true;

		return false;
	}

	unsigned long long reverse_number(unsigned long long number) {
		unsigned long long reversed = 0;

		while (number != 0) {
			reversed = reversed * 10 + number % 10;

			number /= 10;
		}

		return reversed;
	}

	bool isPalindrom(unsigned long long number) {
		if (reverse_number(number) == number)
			return true;

		return false;
	}

	long long rand_in_range(long long from, long long to) {
		return rand() % (to - from + 1) + from;
	}
}