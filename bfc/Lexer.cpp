#include "Lexer.h"

std::vector<bfc::Token> bfc::lexer::tokenize(std::string data) {
	std::vector<bfc::Token> tokens;

	for (char c : data) {
		switch (c) {
		case '>':
			tokens.push_back(bfc::Token::INC_PTR);
			break;
		case '<':
			tokens.push_back(bfc::Token::DEC_PTR);
			break;
		case '+':
			tokens.push_back(bfc::Token::INC_BYTE);
			break;
		case '-':
			tokens.push_back(bfc::Token::DEC_BYTE);
			break;
		case '.':
			tokens.push_back(bfc::Token::PUTCHAR);
			break;
		case ',':
			tokens.push_back(bfc::Token::GETCHAR);
			break;
		case '[':
			tokens.push_back(bfc::Token::BEGIN_WHILE);
			break;
		case ']':
			tokens.push_back(bfc::Token::END_WHILE);
			break;
		}
	}

	return tokens;
}
