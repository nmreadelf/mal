#pragma once

#include <string>

class ReadLine {
public:
  ReadLine(const std::string& history_file);

  bool get(const std::string& prompt, std::string& out);

private:
  std::string _history_path;
};
