#include "Lexer.h"
#include "Parser.h"
#include "Utils.h"

int main(int argc, char** argv) {
	bfc::Arguments args(argc, argv);

	if (args.error) return 1;

	std::string data = bfc::read_file(args.bf);

	auto tokens = bfc::lexer::tokenize(data);

	std::string code = bfc::parser::parse_c(tokens);

	fs::path c = args.output_c ? args.c : "temp.c";

	bfc::write_file(c, code);

	std::string gnu = "g++ -o out.exe " + c.string();

	system(gnu.c_str());

	system("out");

	remove("out.exe");

	if (!args.output_c)
		remove("temp.c");
}
