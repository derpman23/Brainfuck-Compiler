#include "Lexer.h"

std::vector<bfc::token> bfc::lexer::tokenize(std::string data) {
	std::vector<bfc::token> tokens;

	for (char c : data) {
		switch (c) {
		case '>':
			tokens.push_back(bfc::token::INC_PTR);
			break;
		case '<':
			tokens.push_back(bfc::token::DEC_PTR);
			break;
		case '+':
			tokens.push_back(bfc::token::INC_BYTE);
			break;
		case '-':
			tokens.push_back(bfc::token::DEC_BYTE);
			break;
		case '.':
			tokens.push_back(bfc::token::PUTCHAR);
			break;
		case ',':
			tokens.push_back(bfc::token::GETCHAR);
			break;
		case '[':
			tokens.push_back(bfc::token::BEGIN_WHILE);
			break;
		case ']':
			tokens.push_back(bfc::token::END_WHILE);
			break;
		default:
			break;
		}
	}

	return tokens;
}
