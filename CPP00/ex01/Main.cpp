#include <iostream>
#include <string>

class Contact{
	private:
		std::string fname;
		std::string	lname;
		std::string	nname;
		std::string	phone;
		std::string	secret;
	public:
		std::string	get_fname();
		std::string	get_lname();
		std::string	get_nname();

		void	set_fname(std::string str);
		void	set_lname(std::string str);
		void	set_nname(std::string str);
		void	set_phone(std::string str);
		void	set_secret(std::string str);
};

std::string	Contact::get_fname(){
	return fname;
}
std::string	Contact::get_lname(){
	return lname;
}
std::string	Contact::get_nname(){
	return nname;
}

void	Contact::set_fname(std::string str){
	fname = str;
}
void	Contact::set_lname(std::string str){
	lname = str;
}
void	Contact::set_nname(std::string str){
	nname = str;
}
void	Contact::set_phone(std::string str){
	phone = str;
}
void	Contact::set_secret(std::string str){
	secret = str;
}

std::string	replaceTabsWithSpaces(std::string str){
	size_t	pos = 0;
	std::string	tab = "\t";
	std::string	spaces = "    ";

	while((pos = str.find(tab, pos)) != std::string::npos){
		str.replace(pos, tab.size(), spaces);
		pos += spaces.size();
	}
	return	str;
}

void	DisplayStr(std::string	str)
{
	int	sz;
	std::string NewStr;

	NewStr = replaceTabsWithSpaces(str);
	sz = NewStr.size();
	std::cout << "  ";
	if (sz > 10)
	{
		NewStr.resize(9);
		NewStr.resize(10, '.');
	}
	else if (sz < 10)
		NewStr.resize(sz+(10 - sz), ' ');
	std::cout << NewStr << "  |";
}


class PhoneBook{
	int	i = 0, k = 0;
	Contact	contacts[8];

	public:
		std::string cmd;
		void	add();
		void search();
};

void PhoneBook::add(){
	std::string	tmp;
	std::cout << "\n\nfirst name: ";
	std::getline(std::cin, tmp);
	if (std::cin.fail() || !tmp.length())
		return ;
	contacts[i].set_fname(tmp);

	std::cout << "\nlast name: ";
	std::getline(std::cin, tmp);
	if (std::cin.fail() || !tmp.length())
		return ;
	contacts[i].set_lname(tmp);

	std::cout << "\nnickname name: ";
	std::getline(std::cin, tmp);
	if (std::cin.fail() || !tmp.length())
		return ;
	contacts[i].set_nname(tmp);

	std::cout << "\nphone number: ";
	std::getline(std::cin, tmp);
	if (std::cin.fail() || !tmp.length())
		return ;
	contacts[i].set_phone(tmp);

	std::cout << "\ndarkest secret: ";
	std::getline(std::cin, tmp);
	if (std::cin.fail() || !tmp.length())
		return ;
	contacts[i].set_secret(tmp);

	std::cout << "\n\n";
	i++;
	if (k < 8)
		k++;
	if (i == 8)
		i = 0;
}

void	DisplayTable(Contact *contacts ,int start, int end){
	std::cout << "  Index  |  First Name  |  Last Name   |  Nickname    |\n";
	std::cout << "-------------------------------------------------------\n";
	for (int j=start; j < end; j++)
	{
		std::cout << "    " << j << "    |";
		DisplayStr(contacts[j].get_fname());
		DisplayStr(contacts[j].get_lname());
		DisplayStr(contacts[j].get_nname());
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------\n";
}

void	PhoneBook::search(){
	int	i;
	std::string	indexs = "01234567";
	std::string	tmp;

	std::cout << "\nINDEX: ";
	std::getline(std::cin, tmp);
	if (tmp.length() != 1 || indexs.find(tmp) > 7){
		return ;
	}
	i = stoi(tmp);
	if (std::cin.fail() || tmp.length() != 1 || i >= k || i < 0)
		return ;
	std::cout << "  Index  |  First Name  |  Last Name   |  Nickname    |\n";
	std::cout << "-------------------------------------------------------\n";
	std::cout << "    " << i << "    |";
	DisplayStr(contacts[i].get_fname());
	DisplayStr(contacts[i].get_lname());
	DisplayStr(contacts[i].get_nname());
	std::cout << "\n-------------------------------------------------------\n";
	std::cout << std::endl;
	std::cout << std::endl;
}

int main() {
	PhoneBook	phonebook;
	
	while (1){
		std::cout << "---------------* WELCOME TO PHONEBOOK *----------------\n\n";
		std::cout << "Pleas Enter One Of This Three Commands:\n";
		std::cout << "\tADD : to save a new phonebookact\n";
		std::cout << "\tSEARCH : to display a specific phonebookact\n";
		std::cout << "\tEXIT : to quits\n\n";
		std::cout << "command : ";
		std::getline(std::cin, phonebook.cmd);
		if (std::cin.fail()) break ;
		if (phonebook.cmd.compare("EXIT") == 0) break ;
		else if (phonebook.cmd.compare("ADD") == 0) phonebook.add();
		else if (phonebook.cmd.compare("SEARCH") == 0) phonebook.search();
		if (std::cin.fail()) break;
	}
  return 0;
}
