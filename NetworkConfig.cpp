#include "NetworkConfig.h"
#include <filesystem>
#include <fstream>

//using namespace std;
//using namespace std::filesystem;

NetworkConfig::NetworkConfig() {
	readConfig();
};

NetworkConfig::~NetworkConfig() {
	writeConfig();
};

void NetworkConfig::setIP(const std::string& ip) {
	ip_=ip;
};

void NetworkConfig::setPort (const int port) {
	port_=port;
};

const std::string& NetworkConfig::getIP() const {
	return ip_;
};

int NetworkConfig::getPort() const {
	return port_;
};

void NetworkConfig::readConfig() {
	std::fstream file(networkConfigFile,std::ios::in);
	auto permissions=std::filesystem::perms::group_all |
		std::filesystem::perms::others_all;
	std::filesystem::permissions(networkConfigFile,permissions,
			std::filesystem::perm_options::remove);
	const std::string delimiter=":";
	if (file.is_open()) {
		std::string line;
		std::string name;
		std::string value;
		while (std::getline(file,line)) {
			size_t delimiterPosition=line.find(delimiter);
			if (delimiterPosition>0) {
				name=line.substr(0,delimiterPosition);
				value=line.substr(delimiterPosition+1);

				if(name=="IP") {
					ip_=value;
				}
				else if (name=="port") {
					port_=std::stoi(value);
				}
			}
		}
	};
	file.close();
};

void NetworkConfig::writeConfig() const {
	std::fstream file(networkConfigFile, std::ios::out);
	file<<"IP:"<<ip_<<"\n";
	file<<"port:"<<port_<<"\n";
	file.close();
};


