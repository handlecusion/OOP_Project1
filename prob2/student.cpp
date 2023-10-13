#include "student.h"

Student::Student(string name, int id, int bir, string dep, int tel)
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

void	Student::setId (int id)
{
	this->id = id;
}

void	Student::setBirthyear (int by)
{
	this->birthyear = by;
}

void	Student::setDepartment (string dep)
{
	this->department = dep;
}

void	Student::setTel (int tel)
{
	this->tel = tel;
}

string	Student::getName()
{
	return (this->name);
}

int	Student::getId()
{
	return (this->id);
}

int	Student::getBirthyear()
{
	return (this->birthyear);
}

string	Student::getDepartment()
{
	return (this->department);
}

int	Student::getTel()
{
	return (this->tel);
}


