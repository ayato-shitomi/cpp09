#include "PmergeMe.hpp"
#include <cstdlib>

// print the error and exit
void	putError(std::string msg) {
	std::cout << "\033[31m" << "[*] ERROR: " << msg << "\033[0m" << std::endl;
	std::exit(1);
}

int main(int ac, char **av) {
	// check the number of arguments
	if (ac < 2)
		putError("No arguments");
	// create the object and check the validity of the arguments
	PmergeMe	res(ac - 1, &av[1]);
	if (!(res.get_valid()))
		putError("Invalid argument was given.");
	// execute the program
	res.exec();
	return 0;
}
