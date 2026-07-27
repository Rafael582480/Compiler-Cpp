#include "parser.hpp"
#include <iostream>

std::vector<std::string> Parser::gramalValue(std::vector<std::string> expression)
{
  std::vector<std::string> organization;

  for (int i = expression.size() - 1; i >= 0; i--)
  {
    organization.push_back(expression[i]);
  }

  expression = organization;
  return expression;
}