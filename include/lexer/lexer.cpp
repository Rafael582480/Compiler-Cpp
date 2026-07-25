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

  Lexer::tokens.IDENTIFICADOR = indentificador;
  Lexer::tokens.VALOR = value;
}
