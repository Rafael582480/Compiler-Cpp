#include <iostream>
#include <fstream>
#include <string>
#include "./include/lexer/lexer.hpp"
#include "./include/parser/parser.hpp"

int main()
{
  std::string line;
  std::ifstream Arquivo("./test/txt");

  while (getline(Arquivo, line))
  {
    Lexer lexer(line);
    Lexer::TOKENS token = lexer.getTokens();

    ParserPrimary ParserPrimary(token);
  }

  Arquivo.close();

  return 0;
}
