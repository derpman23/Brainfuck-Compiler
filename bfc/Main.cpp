#include "Lexer.h"
#include "Utils.h"

int main(int argc, char** argv) {
	bfc::Arguments args(argc, argv);

	if (args.error)
		return 1;

	std::string data = bfc::read_file(args.bf);

	auto tokens = bfc::lexer::tokenize(data);
}
