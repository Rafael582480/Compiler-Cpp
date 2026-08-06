#include "lexer.hpp"
#include <iostream>
#include <string>
#include <cstring>

std::string Lexer::RemoveSpace(std::string line)
{
  std::string newLine;

  for (char c : line)
  {
    if (c != ' ')
    {
      newLine += c;
    }
  }

  line = newLine;

  return line;
}

void Lexer::TransformTokens(std::string line)
{
    std::string current;

    for (size_t i = 0; i < line.size(); i++)
    {
        char c = line[i];

        // ignora espaços
        if (std::isspace(static_cast<unsigned char>(c)))
            continue;

        // números
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            current.clear();

            while (i < line.size() &&
                   std::isdigit(static_cast<unsigned char>(line[i])))
            {
                current += line[i];
                i++;
            }

            i--;

            tokens.EXPRESSION.push_back(
                {TokenType::Number, current});

            continue;
        }

        // identificadores / palavras reservadas
        if (std::isalpha(static_cast<unsigned char>(c)))
        {
            current.clear();

            while (i < line.size() &&
                  (std::isalnum(static_cast<unsigned char>(line[i])) ||
                   line[i] == '_'))
            {
                current += line[i];
                i++;
            }

            i--;

            if (current == "print")
            {
                tokens.EXPRESSION.push_back(
                    {TokenType::Print, current});
            }
            else
            {
                tokens.EXPRESSION.push_back(
                    {TokenType::Identifier, current});
            }

            continue;
        }

        switch (c)
        {
        case '+':
            tokens.EXPRESSION.push_back({TokenType::Plus, "+"});
            break;

        case '-':
            tokens.EXPRESSION.push_back({TokenType::Minus, "-"});
            break;

        case 'x':
        case '*':
            tokens.EXPRESSION.push_back({TokenType::Multiply, "*"});
            break;

        case '/':
            tokens.EXPRESSION.push_back({TokenType::Divide, "/"});
            break;

        case '(':
            tokens.EXPRESSION.push_back({TokenType::LeftParen, "("});
            break;

        case ')':
            tokens.EXPRESSION.push_back({TokenType::RightParen, ")"});
            break;

        case ';':
            tokens.EXPRESSION.push_back({TokenType::Semicolon, ";"});
            break;

        default:
            throw std::runtime_error(
                "Caractere inválido: " + std::string(1, c));
        }
    }

    tokens.EXPRESSION.push_back(
        {TokenType::EndOfFile, ""});
}