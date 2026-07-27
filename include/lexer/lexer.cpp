#include "lexer.hpp"
#include <iostream>
#include <string>
#include <cstring>

std::string Lexer::RemoveSpace(std::string line)
{
  std::string newLine;

  std::cout << "Como entrou: " << line << std::endl;

  for (char c : line)
  {
    if (c != ' ')
    {
      newLine += c;
    }
  }

  line = newLine;

  std::cout << "Como saiu: " << line << std::endl;
  return line;
}

void Lexer::TransformTokens(std::string line)
{
  std::string indentificador;
  std::string value;
  bool pass = false;

  for (char c : line)
  {
    if (c != '(')
    {
      indentificador += c;
    }
    else
    {
      break;
    }
  }

  for (char c : line)
  {
    if (c == ')')
    {
      pass = false;
    }
    if (pass)
    {
      value += c;
    }

    if (c == '(')
    {
      pass = true;
    }
  }

  pass = false;
  std::string num = "";

  for (char c : value)
  {
    if (c == '+' || c == 'x' || c == '/' || c == '-')
    {
      Lexer::tokens.EXPRESSION.push_back(std::string(1, c));
      pass = true;
      num = "";
      continue;
    }

    num += c;

    if (pass)
    {
      Lexer::tokens.EXPRESSION.push_back(num);
    }

    else
    {
      Lexer::tokens.EXPRESSION.push_back(num);
    }
  }
}
