#include <algorithm>
#include <conio.h>
#include <iostream>
#include <string>
#include <chrono>
int palindrome(int n) {
	std::string tmp;
	std::string rev;
	unsigned long long l1 = 1, l2 = 9;
	for (int i = 0; i < n - 1; i++) {
		l1 = l1 * 10;
		l2 = l2 * 10 + 9;
	}
	for (int i = 0; i<l2; i++) {
		tmp = std::to_string(l2-i);
		if (tmp.length() != 1) {
			rev = tmp;
			std::reverse(rev.begin(), rev.end());
			tmp = tmp + rev;
		}
		unsigned long long liczba = std::stoull(tmp, nullptr, 10);
		for (int j = l2; j > l1; j--) {
			if (liczba / j > l2)break;
			if (liczba%j == 0) {
				std::cout << "For n="<<n<<": "<<liczba << "=" << j << "*" << liczba / j << std::endl;
				return 1;
			}
		}
	}
	return -1;
}
void main() {
	for (int i = 1; i < 10; i++) {
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		if (palindrome(i) == 1) {
			std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
			std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms" << std::endl;
		}
		else std::cout << "You can't build palindrome from these numbers!" << std::endl;
	}
	_getch();
}