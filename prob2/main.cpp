#include <iostream>
#include "Sims.h"

int main (int ac, char** av)
{
	if (ac == 2)
	{
		Sims sims = Sims(av[1]);
	}
	else
	{
		cout << "Wrond arguments" << endl;
	}
	return (0);
}
