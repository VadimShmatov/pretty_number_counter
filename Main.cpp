#include <iostream>
#include "PrettyNumberCounter.h"

int main()
{
	PrettyNumberCounter<13, 13, 6> task_solver;
	std::cout << task_solver.count() << std::endl;
	return 0;
}
