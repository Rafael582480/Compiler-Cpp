#pragma once
#include <string>
#include <vector>
#include <iostream>

class Lexer
{

public:
  enum class TokenType
  {
    Number,
    Identifier,

    Plus,
    Minus,
    Multiply,
    Divide,

    LeftParen,
    RightParen,
    Semicolon,

    Print,

    EndOfFile
  };

  struct Tokens
  {
    TokenType type;
    std::string lexeme;
  };

  struct TOKENS
  {
    std::vector<Tokens> EXPRESSION;
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
