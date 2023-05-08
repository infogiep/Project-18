#include "User.h"

#include <filesystem>
#include<fstream>

User::User()
{
	reading();
}

User::~User()
{
	recording();
}

void User::setLogin(const string& login)
{
	_login = login;
}

void User::setName(const string& name)
{
	_name = name;
}

void User::setPassword(const string& pass)
{
	_pass = pass;
}

const string& User::getName() const
{
	return _name;
}

const string& User::getLogin() const
{
	return _login;
}

const string& User::getPassword() const
{
	return _pass;
}

void User::reading()
{
	fstream file(userFile, std::ios::in);
	std::filesystem::perms::others_all;
	std::filesystem::permissions(userFile, std::filesystem::perms::others_all | std::filesystem::perms::group_all, std::filesystem::perm_options::remove);

	const std::string delimiter = ": ";
	if (file.is_open()) {
		string line;
		string name; 
		string value;

		while (std::getline(file, line)) {
			size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition + 1);
				if (name == "Name") {
					_name = value;
				}
				else if (name == "Login") {
					_login = value;
				}
				else if (name == "Password") {
					_pass = value;
				}
			}
		}
	}
	file.close();
}

void User::recording()
{
	std::fstream file(userFile, std::ios::out);
	file << "Name: " << _name << "\n";
	file << "Login: " << _login << "\n";
	file << "Password: " << _pass << "\n";
	file.close();
}
