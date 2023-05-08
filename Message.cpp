#include "Message.h"
#include <filesystem>
#include<fstream>

Message::Message()
{
	reading();
}

Message::~Message()
{
	recording();
}

void Message::setText(const string& text)
{
	_text = text;
}

void Message::setSender(const string& sender)
{
	_sender = sender;
}

void Message::setRec(const string& rec)
{
	_receiver = rec;
}

const string& Message::getText() const
{
	return _text;
}

const string& Message::getSender() const
{
	return _sender;
}

const string& Message::getRec() const
{
	return _receiver;
}

void Message::reading()
{
	fstream file(messageFile, std::ios::in);
	std::filesystem::perms::others_all;
	std::filesystem::permissions(messageFile, std::filesystem::perms::others_all | std::filesystem::perms::group_all, std::filesystem::perm_options::remove);

	const std::string delimiter = ": ";
	if (file.is_open()) {
		string line;
		string name; string value;

		while (std::getline(file, line)) {
			size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition + 1);
				if (name == "Text") {
					_text = value;
				}
				else if (name == "Sender") {
					_sender = value;
				}
				else if (name == "Receiver") {
					_receiver = value;
				}
			}

		}
	}
	file.close();
}

void Message::recording()
{
	std::fstream file(messageFile, std::ios::out);
	file << "Sender: " << _sender << "\n";
	file << "Receiver: " << _receiver << "\n";
	file << "Text: " << _text << "\n";
	file.close();
}
