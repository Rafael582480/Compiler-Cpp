#include "parser.hpp"
#include <iostream>

std::vector<std::string> Parser::gramalValue(std::vector<std::string> expression)
{
  for (int i = expression.size() - 1; i >= 0; i--)
  {
    Parser::organization.push_back(expression[i]);
  }

  return Parser::organization;
}