#pragma once
#include <string>
#include <vector>
#include "../lexer/lexer.hpp"

class Parser
{
public:
  std::vector<std::string> organization;

  Parser(Lexer::TOKENS tokens)
  {
    gramalValue(tokens.EXPRESSION);
    tokens.EXPRESSION = organization;
  };

  std::vector<std::string> getExpression() const
  {
    return organization;
  }

  std::vector<std::string> gramalValue(std::vector<std::string> expression);
};
