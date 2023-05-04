#pragma once

#include <string>

constexpr auto networkConfigFile="work.con";

class NetworkConfig final {
	public:
		NetworkConfig();
		~NetworkConfig();

		void setIP(const std::string& ip);
		void setPort(const int port);

		const std::string& getIP() const;
		int getPort() const;

	private:
		std::string ip_;
		int port_{0};
		void readConfig();
		void writeConfig() const;
};

