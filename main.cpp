#include <iostream>
#include <fstream>
#include <string>
#include "./include/lexer/lexer.hpp"

int main()
{
  std::string line;
  std::ifstream Arquivo("./test/txt");

  while (getline (Arquivo, line))
  {
    Lexer lexer(line);
    Lexer::TOKENS token = lexer.getTokens();
  }


  Arquivo.close();

  return 0;
}
