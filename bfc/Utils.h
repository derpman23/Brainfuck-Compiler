#pragma once

#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>

namespace fs = std::filesystem;

namespace bfc {
	struct Arguments {
		Arguments(int argc, char** argv);

		fs::path bf;
		fs::path c;
		bool output_c = false;
		bool error = false;
	};

	std::string read_file(fs::path path);

	void write_file(fs::path path, std::string data);
}
