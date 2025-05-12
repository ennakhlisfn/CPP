#include <iostream>

class Contact{
	public:
		std::string fname;
		std::string	lname;
		std::string	nname;
		std::string	phone;
		std::string	secret;
};

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

void	display_str(std::string	str)
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
	std::cout << "\n\nfirst name: ";
	std::getline(std::cin, contacts[i].fname);
	if (std::cin.fail() || !contacts[i].fname.length())
		return ;
	std::cout << "\nlast name: ";
	std::getline(std::cin, contacts[i].lname);
	if (std::cin.fail() || !contacts[i].lname.length())
		return ;
	std::cout << "\nnickname name: ";
	std::getline(std::cin, contacts[i].nname);
	if (std::cin.fail() || !contacts[i].nname.length())
		return ;
	std::cout << "\nphone number: ";
	std::getline(std::cin, contacts[i].phone);
	if (std::cin.fail() || !contacts[i].phone.length())
		return ;
	std::cout << "\ndarkest secret: ";
	std::getline(std::cin, contacts[i].secret);
	if (std::cin.fail() || !contacts[i].secret.length())
		return ;
	std::cout << "\n\n";
	i++;
	if (k < 8)
		k++;
	if (i == 8)
		i = 0;
}

void	PhoneBook::search(){
	std::cout << "  Index  |  First Name  |  Last Name   |  Nickname    |\n";
	std::cout << "-------------------------------------------------------\n";
	for (int j=0; j < k; j++)
	{
		std::cout << "    " << j << "    |";
		display_str(contacts[j].fname);
		display_str(contacts[j].lname);
		display_str(contacts[j].nname);
		std::cout << std::endl;
	}
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
