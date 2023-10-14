#include "student.h"

Student::Student(string name, string id, string bir, string dep, string tel)
{
	this->name = name;
	this->id = id;
	this->birthyear = bir;
	this->department = dep;
	this->tel = tel;
}

void	Student::setName (string name)
{
	this->name = name;
}

void	Student::setId (string id)
{
	this->id = id;
}

void	Student::setBirthyear (string by)
{
	this->birthyear = by;
}

void	Student::setDepartment (string dep)
{
	this->department = dep;
}

void	Student::setTel (string tel)
{
	this->tel = tel;
}

string	Student::getName()
{
	return (this->name);
}

string	Student::getId()
{
	return (this->id);
}

string	Student::getBirthyear()
{
	return (this->birthyear);
}

string	Student::getDepartment()
{
	return (this->department);
}

string	Student::getTel()
{
	return (this->tel);
}

int	Student::check(int n, string str)
{
	if (n == 1)
	{
		if (getName() == str)
			return (1);
		else
			return (0);
	}
	else if (n == 2)
	{
		if (getId() == str)
			return (1);
		else
			return (0);
	}
	else if (n == 3)
	{
		if (getId().substr(0, 4) == str)
			return (1);
		else
			return (0);
	}
	else if (n == 4)
	{
		if (getDepartment() == str)
			return (1);
		else
			return (0);
	}
	return (0);
}
