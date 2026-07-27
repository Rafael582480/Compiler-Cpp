#include <iostream>
#include <fstream>
#include <string>
#include "./include/lexer/lexer.hpp"
#include "./include/parser/parser.hpp"

int main()
{
  std::string line;
  std::ifstream Arquivo("./test/txt");

  while (getline (Arquivo, line))
  {
    Lexer lexer(line);
    Lexer::TOKENS token = lexer.getTokens();

    Parser parser(token);
    std::vector<std::string> expression = parser.getExpression();

    token.EXPRESSION = expression;

  }

  Arquivo.close();

  return 0;
}
