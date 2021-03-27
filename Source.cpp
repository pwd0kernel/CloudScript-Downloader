#include <string>
#include <iostream>

#include "Libs/http.h"
#include "Libs/Base64.h"

/*
* The codes are shit and its just for a test
* and lowkey useless
* 
* i am also using other peope libs because 
* i'm too lazy so credits to them:
* 
* macaron - Base64
* Code-Building - requests
*/

std::string readNdecode(int code) {
	std::string url = "http://lynx.rip/dashboard/home/cloudscripts/storage/" + std::to_string(code) + "_src.lua";
	auto* const request = requests::get(url);
	const auto data = request->text;
	std::string data_out;
	macaron::Base64::Decode(data, data_out);
	return data_out;
}

int main() {
	SetConsoleTitleA("CloudScript Downloader");
	while (true) {
		int code;
		std::cout << "[Code]: ";
		std::cin >> code;
		std::cout << "\nScript:\n" << readNdecode(code) << std::endl;
	}
}