#include "User.h"
#include "Message.h"
#include<iostream>

using namespace std;

int main() {

	User user;
	cout << "Name: " << user.getName() << "\n";
	cout << "Login: " << user.getLogin() << "\n";
	cout << "Password: " << user.getPassword() << "\n";
	cout << endl;
	
	cout << "Add user" << endl;
	cout << "Name: ";
	string name1;
	cin >> name1;
	user.setName(name1);
	cout << "Login: ";
	string login1;
	cin >> login1;
	user.setLogin(login1);
	cout << "Password: ";
	string password1;
	cin >> password1;
	user.setPassword(password1);

	Message message;
	cout << "Sender: " << message.getSender() << "\n";
	cout << "Receiver: " << message.getRec() << "\n";
	cout << "Text: " << message.getText() << "\n";

	cout << endl;
	cout << "Add message" << endl;
	cout << "Sender: ";
	string sender1;
	cin >> sender1;
	message.setSender(sender1);
	cout << "Receiver: ";
	string receiver1;
	cin >> receiver1;
	message.setRec(receiver1);
	cout << "Text: ";
	string text1;
	cin >> text1;
	message.setText(text1);
}