#pragma once

#include <string>
#include <ostream>
#include <fstream>
#include <string>
using namespace std;

const auto userFile = "user.con";

class User final
{
private:
	string _name;
	string _login;
	string _pass;

	void reading();
	void recording();

public:
	User();
	~User();
	void setLogin(const string& login);
	void setName(const string& name);
	void setPassword(const string& pass);

	const string& getName() const;
	const string& getLogin() const;
	const string& getPassword() const;

};