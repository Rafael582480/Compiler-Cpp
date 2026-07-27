#pragma once
#include <string>
#include <vector>
#include "../lexer/lexer.hpp"

class Parser
{
public:
  Parser(Lexer::TOKENS tokens)
  {
    gramalValue(tokens.EXPRESSION);
  };

  std::vector<std::string> gramalValue(std::vector<std::string> expression);
};
