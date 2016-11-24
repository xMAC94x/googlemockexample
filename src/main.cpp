#include <iostream>
#include <chrono>
#include <thread>
#include "cmake.h"
#include "mult.h"

int main() {
	std::cout << "googlemockexample version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
	int first = 0;
	int second = 0;
	std::cout << "Please enter a first number: " << std::endl;
	std::cin >> first;
	std::cout << "Please enter a second number: " << std::endl;
	std::cin >> second;
	int result = multNumbers(first,second);
	std::cout << "result: " << result << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}