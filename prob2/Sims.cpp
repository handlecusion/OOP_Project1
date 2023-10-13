#include "Sims.h"

Sims::Sims (string str)
{
	int		num;
	string	buf;

	rFile.open(str);
	if (!rFile.is_open())
	{
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
		vector<string> r = split(buf, ' ');
		Student *stu = new Student(r[0], atoi(r[1].c_str()), atoi(r[2].c_str()), r[3], atoi(r[4].c_str()));
		student.push_back(stu);
	}
	cout << student[0]->getName() << endl;
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


