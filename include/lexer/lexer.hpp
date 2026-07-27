#pragma once
#include <string>
#include <vector>
#include <iostream>

class Lexer
{

public:


  struct TOKENS
  {
    std::string IDENTIFICADOR;
    std::vector<std::string> EXPRESSION;
  };

  TOKENS tokens;

  Lexer(std::string line)
  {
    line = RemoveSpace(line);
    TransformTokens(line);
  }

  TOKENS getTokens() const
  {
    return tokens;
  }

  std::string RemoveSpace(std::string line);

  void TransformTokens(std::string line);
};
