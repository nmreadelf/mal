#include "ReadLine.h"

#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <readline/tilde.h>

ReadLine::ReadLine(const std::string& history_file): _history_path(history_file) {
  read_history(_history_path.c_str());
}

bool ReadLine::get(const std::string& prompt, std::string& out) {
  char *line = readline(prompt.c_str());
  if (line == nullptr) {
    return false;
  }

  add_history(line); // Add input to in-memory history
  append_history(1, _history_path.c_str());

  out = line;
  free(line);

  return true;
}
