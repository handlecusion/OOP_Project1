# ifndef STUDENT_H
# define STUDENT_H

#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class	Student
{
	string	name;
	string	id;
	string	birthyear;
	string	department;
	string	tel;

public:
	Student(string name, string id, string bir, string dep, string tel);
	void setName (string name);
	void setId (string id);
	void setBirthyear (string by);
	void setDepartment (string dep);
	void setTel	(string tel);
	string	getName();
	string	getId();
	string	getBirthyear();
	string	getDepartment();
	string	getTel();
	int	check(int n, string str);
};


# endif
