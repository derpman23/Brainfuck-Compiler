#include "Parser.h"

std::string bfc::parser::parse_c(std::vector<bfc::Token> tokens) {
	std::vector<std::string> v = { "#include<stdio.h>\nint main(){char array[30000]={0};char*ptr=array;" };

	int cnt = 1;

	auto prev = bfc::Token::NULL_TOKEN;

	for (auto token : tokens) {
		cnt = token == prev ? cnt + 1 : 1;

		switch (token) {
		case bfc::Token::INC_PTR:
			if (cnt == 1) v.push_back("++ptr;");
			else v[v.size() - 1] = "ptr+=" + std::to_string(cnt) + ";";
			break;
		case bfc::Token::DEC_PTR:
			if (cnt == 1) v.push_back("--ptr;");
			else v[v.size() - 1] = "ptr-=" + std::to_string(cnt) + ";";
			break;
		case bfc::Token::INC_BYTE:
			if (cnt == 1) v.push_back("++*ptr;");
			else v[v.size() - 1] = "*ptr+=" + std::to_string(cnt) + ";";
			break;
		case bfc::Token::DEC_BYTE:
			if (cnt == 1) v.push_back("--*ptr;");
			else v[v.size() - 1] = "*ptr-=" + std::to_string(cnt) + ";";
			break;
		case bfc::Token::PUTCHAR:
			v.push_back("putchar(*ptr);");
			break;
		case bfc::Token::GETCHAR:
			v.push_back("*ptr=getchar();");
			break;
		case bfc::Token::BEGIN_WHILE:
			v.push_back("while(*ptr){");
			break;
		case bfc::Token::END_WHILE:
			v.push_back("}");
			break;
		}

		prev = token;
	}

	std::string code = "";

	for (auto s : v)
		code += s;

	return code + "}";
}