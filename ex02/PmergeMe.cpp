#include "PmergeMe.hpp"

// constructor
PmergeMe::PmergeMe(int count, char **arg) {
	_valid = _validArgs(arg);
	_countElem = count;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::_putError(std::string msg) {
	std::cout << "\033[31m" << "[*] ERROR: " << msg << "\033[0m" << std::endl;
	return false;	
}

// execute the program
bool	PmergeMe::_validArgs(char **arg) {
	for (int i = 0; arg[i]; i++) {
		int j = 0;
		// check the number
		for (; arg[i][j]; j++) {
			if (!(std::isdigit(arg[i][j])))
				return _putError("argument was not a number: " + std::string(arg[i]));
		}
		// check the length of the number
		if (j == 0)
			return _putError("length of the argument was 0");
		long num;
		// convert the string to the number
		std::istringstream(arg[i]) >> num;
		// check the range of the number
		if (num < 1 || INT_MAX < num) {
			std::stringstream ss;
			ss << num;
			return _putError("argument was out of range: " + ss.str());
		}
		// add the number to the container
		_before.push_back(num);
		_beforeDeque.push_back(num);
		// add the number to the set
		_after.insert(num);
	}
	return true;
}

// put the container
void	PmergeMe::_putBefore() {
	std::cout << "Before: ";
	// put the container
	for (int i = 0; i < _countElem; i++)
		std::cout << " " << _before[i];
	std::cout << std::endl;
}

// put the container
void	PmergeMe::_putAfter() {
	std::cout << "After:  ";
	std::set<long>::iterator itr = _after.begin();
	// put the container
	for (; itr != _after.end(); itr++)
		std::cout << " " << *itr;
	std::cout << std::endl;
}

// check the time to sort
void	PmergeMe::_putSortTime(std::string containerName) {
	// get the time
	timespec start;
	timespec end;
	// get the time before sort
	::clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	if (containerName == "vector")
		_mergeInsertionSort(_before, 0, _before.size() - 1);
	else
		_mergeInsertionSort(_beforeDeque, 0, _before.size() - 1);
	// get the time after sort
	::clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	// calculate the time
	double runSec = end.tv_sec - start.tv_sec;
	double runNSec = end.tv_nsec - start.tv_nsec;
	// put the time
	double sortTime = (runSec * 1000000L) + (runNSec / 1000);
	std::cout << _countElem << " elements with std::" << containerName << ":\t" << sortTime << " us" << std::endl;
}

// sort the container
void	PmergeMe::exec() {
	// put the container
	_putBefore();
	// sort the container
	_putAfter();
	// put the time to sort with vector
	_putSortTime("vector");
	// put the time to sort with deque
	_putSortTime("deque");
}

// get the validity of the arguments
bool	PmergeMe::get_valid() {
	return _valid;
}
