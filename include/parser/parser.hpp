#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../lexer/lexer.hpp"

class ParserPrimary
{
private:
  struct Node
  {
    std::string type;

    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    std::string value;
  };

  struct Identifier
  {
    std::string type;

    std::unique_ptr<Node> node;
  };

  std::unique_ptr<Node> ParserPrint(Lexer::TOKENS tokens);

public:
  ParserPrimary(Lexer::TOKENS tokens)
  {
    std::string identifier = tokens.EXPRESSION[0].lexeme;

    for (auto &s : tokens.EXPRESSION)
    {
      s.lexeme.erase(std::remove(s.lexeme.begin(), s.lexeme.end(), '('), s.lexeme.end());
      s.lexeme.erase(std::remove(s.lexeme.begin(), s.lexeme.end(), ')'), s.lexeme.end());
      s.lexeme.erase(std::remove(s.lexeme.begin(), s.lexeme.end(), ';'), s.lexeme.end());
    }
    std::vector<Lexer::Tokens> validTokens;
    for (const auto &token : tokens.EXPRESSION)
    {
      if (!token.lexeme.empty() && token.lexeme != " ")
      {
        validTokens.push_back(token);
      }
    }
    
    tokens.EXPRESSION = validTokens;

    tokens.EXPRESSION.erase(tokens.EXPRESSION.begin() + 0);

    if (identifier == "print")
    {
      Identifier identifierNode;
      identifierNode.type = "print";

      identifierNode.node = ParserPrint(tokens);
    }
  }
};
