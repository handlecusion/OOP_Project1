# ifndef STUDENT_H
# define STUDENT_H

#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class	Student
{
	string	name;
	int		id;
	int		birthyear;
	string	department;
	int		tel;

public:
	Student(string name, int id, int bir, string dep, int tel);
	void setName (string name);
	void setId (int id);
	void setBirthyear (int by);
	void setDepartment (string dep);
	void setTel	(int tel);
	string	getName();
	int		getId();
	int		getBirthyear();
	string	getDepartment();
	int		getTel();
};


# endif
