#include "NetworkConfig.h"
#include <iostream>
#include <string>

int main () {
	NetworkConfig config;
	std::cout<<"Initial network config\n";
	std::cout<<"IP: "<<config.getIP()<<"\n";
	std::cout<<"port: "<<config.getPort()<<"\n";

	const std::string newIP="8.8.8.8";
	config.setIP(newIP);
	const int newPort=22;
	config.setPort(newPort);

	std::cout<<"Current network config\n";
	std::cout<<"IP: "<<config.getIP()<<"\n";
	std::cout<<"port: "<<config.getPort()<<"\n";

}

