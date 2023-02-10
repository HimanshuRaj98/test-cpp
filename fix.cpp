#include <iostream>
#include <string>
#include <map>
#include <fstream>
enum TokenType {
  INTEGER,
  IDENTIFIER,
  OPERATOR,
  KEYWORD,
  UNKNOWN
};

struct Token {
  TokenType type;
  std::string lexeme;
};

std::map<std::string, TokenType> keywords = {
  {"int", KEYWORD},
  {"printf", KEYWORD},
  {"scanf", KEYWORD},
};

std::map<char, TokenType> operators = {
  {'+', OPERATOR},
  {'-', OPERATOR},
  {'*', OPERATOR},
  {'/', OPERATOR},
  {'%', OPERATOR},
  {'<', OPERATOR},
  {'>', OPERATOR},
  {'=', OPERATOR},
  {'!', OPERATOR},
  {'&', OPERATOR},
  {'|', OPERATOR},
};

Token getNextToken(std::istream& input) {
char c = input.get();
while (c == ' ' || c == '\t' || c == '\n') {
c = input.get();
}
if (isdigit(c)) {
std::string number;
do {
number += c;
c = input.get();
} while (isdigit(c));
input.unget();
return {INTEGER, number};
} else if (isalpha(c)) {
std::string identifier;
do {
identifier += c;
c = input.get();
} while (isalnum(c));
input.unget();
if (keywords.count(identifier)) {
return {keywords[identifier], identifier};
} else {
return {IDENTIFIER, identifier};
}
} else if (operators.count(c)) {
return {operators[c], std::string(1, c)};
} else {
return {UNKNOWN, std::string(1, c)};
}
}

int main() {
//From Console
//std::istream& input = std::cin;

// Reading From The Files
std::ifstream input("input.txt");
if (!input) {
  std::cerr << "Could not open input file\n";
  return 1;
}
//==========================================//
while (input) {
Token token = getNextToken(input);
switch (token.type) {
case INTEGER:
std::cout << "INTEGER: " << token.lexeme << '\n';
break;
case IDENTIFIER:
std::cout << "IDENTIFIER: " << token.lexeme << '\n';
break;
case OPERATOR:
std::cout << "OPERATOR: " << token.lexeme << '\n';
break;
case KEYWORD:
std::cout << "KEYWORD: " << token.lexeme << '\n';
break;
case UNKNOWN:
std::cout << "UNKNOWN: " << token.lexeme << '\n';
break;
}
}
return 0;
}