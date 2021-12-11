#include "Utils.h"

bfc::Arguments::Arguments(int argc, char** argv) {
	bool bf_set = false;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-bf") == 0) {
			if (bf_set) {
				std::cerr << "Cannot have multiple input file options." << std::endl;
				error = true;
				return;
			}

			i++;

			if (!fs::exists(argv[i]) || !fs::is_regular_file(argv[i])) {
				std::cerr << "File \"" << argv[i] << "\" not found." << std::endl;
				error = true;
				return;
			}

			fs::path path(argv[i]);

			if (!path.has_extension() || !(path.extension().string() == ".b" || path.extension().string() == ".bf")) {
				std::cerr << "Invalid filetype \"" << path.extension().string() << "\". Please specify a brainfuck file with the extension \".b\" or \".bf\"" << std::endl;
				error = true;
				return;
			}

			bf = path;
			bf_set = true;
		}

		else if (strcmp(argv[i], "-c") == 0) {
			if (output_c) {
				std::cerr << "Cannot have multiple output file options." << std::endl;
				error = true;
				return;
			}

			i++;

			fs::path path(argv[i]);

			if (!path.has_extension() || path.extension().string() != ".c") {
				std::cerr << "Invalid filetype \"" << path.extension().string() << "\". Please specify an output file with the extension \".c\"" << std::endl;
				error = true;
				return;
			}

			c = path;
			output_c = true;
		}
	}

	if (!bf_set) {
		std::cerr << "Input file is not set." << std::endl;
		error = true;
	}
}

std::string bfc::read_file(fs::path path) {
	std::string data = "", s;

	std::ifstream in(path);

	if (in.is_open()) {
		while (std::getline(in, s))
			data += s;

		in.close();
	}

	return data;
}

void bfc::write_file(fs::path path, std::string data) {
	std::ofstream out(path);

	if (out.is_open()) {
		out << data;

		out.close();
	}
}
