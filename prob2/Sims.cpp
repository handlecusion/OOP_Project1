#include "Sims.h"

Sims::Sims (string str)
{
	string	buf;
	this->str = str;

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
		student.push_back(Student(r[0], r[1], r[2], r[3], r[4]));
	}
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
	cout << endl << setw(20) << "Name" << setw(10) << "StudentID" << setw(20) << "Dept" << setw(10) << "Birth Year" << setw(11) << "Tel"<< endl;
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
	cout << setw(20) << student[index].getName() << setw(10) << student[index].getId() << setw(20) << student[index].getDepartment() << setw(10) << student[index].getBirthyear() << setw(11) << student[index].getTel() << endl;
}

bool	cmpName(Student s1, Student s2)
{
	return (strcmp(s1.getName().c_str(), s2.getName().c_str()));
}

bool	cmpId(Student s1, Student s2)
{
	return (strcmp(s1.getId().c_str(), s2.getId().c_str()));
}
bool	cmpYear(Student s1, Student s2)
{
	return (strcmp(s1.getBirthyear().c_str(), s2.getBirthyear().c_str()));
}
bool	cmpDep(Student s1, Student s2)
{
	return (strcmp(s1.getDepartment().c_str(), s2.getDepartment().c_str()));
}
void	Sims::sorting(int s)
{
	if (s == 1)
	{
		sort(student.begin(), student.end(), cmpName);
	}
	else if (s == 2)
	{
		//
	}
	else if (s == 3)
	{
		//
	}
	else if (s == 4)
	{
		//
	}
	else
		return ;
}
