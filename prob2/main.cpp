#include <iostream>
#include <string>
#include <stdlib.h>
#include "Sims.h"

void	print_main();
void	print_search();
void	print_sort();

int main (int ac, char** av)
{
	int mode = 0;

	if (ac == 2)
	{
		Sims sims(av[1]);
		while (1)
		{
			print_main();
			cin >> mode;
			cin.ignore();
			if (mode == 1)
			{
				string	name;
				string	id;
				string	year;
				string	dep;
				string	tel;

				cout << "Name ? ";
				cin >> name;
				cout << "Student ID (10 digits) ? ";
				cin >> id;
				cout << "Birth Year (4 digits) ? ";
				cin >> year;
				cout << "Department ? ";
				cin >> dep;
				cout << "Tel ? ";
				cin >> tel;
				
				if (name == "" || id == "")
				{
					cout << "that can't be null value" << endl;
					continue;
				}
				sims.add(name, id, year, dep, tel);
			}
			else if (mode == 2)
			{
				int s;
				print_search();
				cin >> s;
				cin.ignore();
				sims.search(s);
				cout << endl;
			}
			else if (mode == 3)
			{
				int	s;
				print_sort();
				cin >> s;
				cin.ignore();
				sims.sorting(s);
				cout << endl;
			}
			else if (mode == 4)
			{
				return (0);
			}
			else 
			{
				cout << "wrong input" << endl;
				continue;
			}
		}
	}
	else
	{
		cout << "Wrond arguments" << endl;
	}
	return (0);
}

void	print_main()
{
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Sorting Option" << endl;
	cout << "4. Exit" << endl;
	cout << "> ";
}

void	print_search()
{
	cout << "- Search -" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by admission year (4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
	cout << "> ";
}

void	print_sort()
{
	cout << "- Sorting -" << endl;
	cout << "1. Sort by Name" << endl;
	cout << "2. Sort by Student ID" << endl;
	cout << "3. Sort by Admission Year" << endl;
	cout << "4. Sort by Department name" << endl;
	cout << "> ";
}
