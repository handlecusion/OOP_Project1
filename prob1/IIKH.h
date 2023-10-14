# ifndef IIKH_H
# define IIKH_H

class Iikh
{
public:
	Iikh();
	void run();
	void exit();
};

class Recipe
{
	string	needs;
	int		time;
	string*	proc;
	string	comment;

public:
	Recipe(string needs, int time, string* proc);
	void	setNeeds(string n);
	void	setTime(int t);
	void	setProc(string *proc);
	void	setComment(string c);
	string	getNeeds();
	int		getTime();
	string*	getProc();
	string	getComment();
};

class RecipeDB
{
	Recipe*	recipeDB;

	public:
		RecipeDB recipeDB();
		void	search(string str);
		void	select(int n);
		void	print_recipe(int n);
		void	add(Recipe R); 
};

#endif
