# ifndef SIMS_H
# define SIMS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include "student.h"

using namespace std;

class	Sims
{
	ifstream			rFile;
	vector<Student>		student;
	int					num;
	string				str;
	int					smode;

public:
	Sims(string str);
	vector<string>	split(string str, char sep);
	void	add(string name, string id, string year, string dep, string tel);
	void	search(int s);
	void	print_stu(int index);
	void	insert(Sims s);
	void	sorting(int s);
	string	checkName(string name);
	string	checkId(string id);
	string	checkBirthyear(string year);
	string	checkDepartment(string dep);
	string	checkTel(string tel);
};

bool	cmpName(Student s1, Student s2);
bool	cmpId(Student s1, Student s2);
bool	cmpYear(Student s1, Student s2);
bool	cmpDep(Student s1, Student s2);
# endif
