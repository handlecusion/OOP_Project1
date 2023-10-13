# ifndef SIMS_H
# define SIMS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "student.h"

using namespace std;

class	Sims
{
	ifstream		rFile;
	ofstream		wFile;
	vector<Student*>	student;

public:
	Sims(string str);
	vector<string> split(string str, char sep);

};

# endif
