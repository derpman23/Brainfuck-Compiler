#pragma once

#include<string>
#include<vector>
#include "Token.h"

namespace bfc::lexer {
	std::vector<bfc::Token> tokenize(std::string data);
}
