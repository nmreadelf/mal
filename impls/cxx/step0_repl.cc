#include "ReadLine.h"

#include <iostream>

std::string PRINT(const std::string& ast) {
  return ast;
}

std::string EVAL(const std::string& ast) {
  return ast;
}

std::string READ(const std::string& input) {
  return input;
}

std::string repl(const std::string& input) {
  return PRINT(EVAL(READ(input)));
}

static ReadLine s_readLine("~/.mal-history");

int main(int argc, char* argv[]) {
  std::string prompt = "user> ";
  std::string input;
  while (s_readLine.get(prompt, input)) {
    std::cout << repl(input) << std::endl;
  }
  return 0;
}
