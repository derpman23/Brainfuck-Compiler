#pragma once

#include<string>
#include<vector>
#include "Token.h"

namespace bfc::parser {
	std::string parse_c(std::vector<bfc::Token> tokens);
}
