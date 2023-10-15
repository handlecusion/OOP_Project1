#include "Sims.h"

Sims::Sims (string str)
{
	string	buf;
	this->str = str;
	this->smode = 1;

	rFile.open(str);
	if (!rFile.is_open())
	{
		fstream wFile;
		wFile.open(str);
		wFile.close();
		rFile.open(str);
	}

	if (rFile.eof())
		buf = "0";
	else
		getline(rFile, buf);
	num = atoi(buf.c_str());
	
	for (int i = 0; i < num; i++)
	{
		if (rFile.eof())
			break;
		getline(rFile, buf);
		vector<string> r = split(buf, '/');
		r[0] = checkName(r[0]);
		r[1] = checkId(r[1]);
		r[2] = checkBirthyear(r[2]);
		r[3] = checkDepartment(r[3]);
		r[4] = checkTel(r[4]);
		student.push_back(Student(r[0], r[1], r[2], r[3], r[4]));
	}
	sorting(smode);
	rFile.close();
}

vector<string>	Sims::split	(string str, char sep)
{
	istringstream iss(str);
	string buf;

	vector<string> res;
	while(getline(iss, buf, sep))
	{
		res.push_back(buf);
	}
	return (res);
}

void	Sims::add(string name, string id, string year, string dep, string tel)
{
	int		len;
	string	line;
	fstream	wFile;

	if (checkName(name) != name || checkId(id) != id || checkBirthyear(year) != year || checkDepartment(dep) != dep || checkTel(tel) != tel)
	{
		cout << "Error : wrong input" << endl;
		return ;
	}
	for (int i = 0; i < num; i++)
	{
		if (id == student[i].getId())
		{
			cout << "Error : Already inserted" << endl;
			return ;
		}
	}
	num++;
	wFile.open(str);
	line = to_string(num);
	wFile.write(line.c_str(), line.length());
	wFile.close();

	wFile.open(str, ios::app);
	line = name + "/" + id + "/" + year + "/" + dep + "/" + tel;
	len = line.length();
	wFile.write(line.c_str(), len);  
	student.push_back(Student(name, id, year, dep, tel));
	wFile.close();
	sorting(smode);
}

void	Sims::search(int s)
{
	string keyword;
	if (s == 1)
		keyword = "Name ";
	else if (s == 2)
		keyword = "Student ID ";
	else if (s == 3)
		keyword = "Admission year ";
	else if (s == 4)
		keyword = "Department name ";
	else if (s == 5)
		keyword = "all";
	else
		return ;

	if(s != 5)
	{
		cout << keyword << "keyword? ";
		cin >> keyword;
	}
	cout << left;
	cout << endl << setw(20) << "Name" << setw(10) << "StudentID" << setw(20) << "Dept" << setw(10) << "Birth Year" << setw(11) << "Tel"<< endl;
	sorting(smode);
	for (int i = 0; i < num; i++)
	{
		cout << left;
		if (student[i].check(s, keyword) || s == 5)
			print_stu(i);
	}
}

void	Sims::print_stu(int index)
{
	cout << left;
	cout << setw(20) << student[index].getName() << setw(11) << student[index].getId() << setw(20) << student[index].getDepartment() << setw(10) << student[index].getBirthyear() << setw(11) << student[index].getTel() << endl;
}

bool	cmpName(Student s1, Student s2)
{
	int	res = strcmp(s1.getName().c_str(), s2.getName().c_str());
	if (res < 0)
		return (true);
	else
		return (false);
}

bool	cmpId(Student s1, Student s2)
{
	int	res = strcmp(s1.getId().c_str(), s2.getId().c_str());
	if (res < 0)
		return (true);
	else
		return (false);
}

bool	cmpYear(Student s1, Student s2)
{
	int	res = strncmp(s1.getBirthyear().c_str(), s2.getBirthyear().c_str(), 4);
	if (res < 0)
		return (true);
	else
		return (false);
}

bool	cmpDep(Student s1, Student s2)
{
	int	res = strcmp(s1.getDepartment().c_str(), s2.getDepartment().c_str());
	if (res < 0)
		return (true);
	else
		return (false);
}

void	Sims::sorting(int s)
{
	if (s == 1)
		sort(student.begin(), student.end(), cmpName);
	else if (s == 2)
		sort(student.begin(), student.end(), cmpId);
	else if (s == 3)
		sort(student.begin(), student.end(), cmpYear);
	else if (s == 4)
		sort(student.begin(), student.end(), cmpDep);
	else
	{
		cout << "wrong sorting option" << endl;
		smode = 1;
		return ;
	}
	smode = s;
}

string	Sims::checkName(string name)
{
	int	len = name.length();
	if (15 < len)
		return ("");
	for (int i = 0; i < len; i++)
		if (!(('a' <= name[i] && name[i] <= 'z') || ('A' <= name[i] && name[i] <= 'Z')))
			return ("");
	return (name);
}

string	Sims::checkId(string id)
{
	int	len = id.length();
	if (len != 10)
		return ("");
	for (int i = 0; i < len; i++)
		if (!('0' <= id[i] && id[i] <= '9'))
			return ("");
	return (id);
}
string	Sims::checkBirthyear(string year)
{
	int	len = year.length();
	if (len != 4)
		return ("");
	for (int i = 0; i < len; i++)
		if (!('0' <= year[i] && year[i] <= '9'))
			return ("");
	return (year);
}
string	Sims::checkDepartment(string dep)
{
	int	len = dep.length();
	if (40 < len)
		return ("");
	for (int i = 0; i < len; i++)
		if (!(('a' <= dep[i] && dep[i] <= 'z') || ('A' <= dep[i] && dep[i] <= 'Z')))
			return ("");
	return (dep);
}
string	Sims::checkTel(string tel)
{
	int	len = tel.length();
	if (12 < len)
		return ("");
	for (int i = 0; i < len; i++)
		if (!('0' <= tel[i] && tel[i] <= '9'))
			return ("");
	return (tel);
}
