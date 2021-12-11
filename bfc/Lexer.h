#pragma once

#include<vector>
#include<string>
#include "Token.h"

namespace bfc::lexer {
	std::vector<token> tokenize(std::string data);
}
