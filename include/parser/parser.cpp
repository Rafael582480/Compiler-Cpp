#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "parser.hpp"
#include "../lexer/lexer.hpp"

std::unique_ptr<ParserPrimary::Node> ParserPrimary::ParserPrint(Lexer::TOKENS tokens)
{
  auto tree = std::make_unique<Node>();

  tree->type = "number";
  tree->value = tokens.EXPRESSION[0].lexeme;

  for (size_t i = 0; i < tokens.EXPRESSION.size(); i++)
  {
    if (i + 1 >= tokens.EXPRESSION.size())
      break;

    std::string op = tokens.EXPRESSION[i].lexeme;
    std::string nextNum = tokens.EXPRESSION[i + 1].lexeme;

    auto newTree = std::make_unique<Node>();

    newTree->type = "operator";
    newTree->value = op;
    newTree->left = std::move(tree);

    newTree->right = std::make_unique<Node>();

    newTree->right->type = "number";
    newTree->right->value = nextNum;

    tree = std::move(newTree);
  }

  return tree;
}
