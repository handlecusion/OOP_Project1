# ifndef SIMS_H
# define SIMS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "student.h"

using namespace std;

class	Sims
{
	ifstream			rFile;
	ofstream			wFile;
	vector<Student*>	student;
	int					num;

public:
	Sims(string str);
	vector<string>	split(string str, char sep);
	void	add(string name, string id, string year, string dep, string tel);
	void	search(int s);
	void	print_stu(int index);
	void	insert(Sims s);
};

# endif
