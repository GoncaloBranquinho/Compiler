#include "tokenizer.h"
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  std::string str(reinterpret_cast<const char *>(Data), Size);
  str += '\0';
  std::ofstream f("./fuzzFile");
  f << str;
  f.close();

  std::vector<std::pair<std::string, Token>> tokens;

  std::ifstream file("./fuzzFile");

  std::string line;
  while (std::getline(file, line)) {
    tokenize(line, tokens);
  }
  // std::cout << "{ ";
  bool first = true;
  for (auto p : tokens) {
    if (!first) {
      // std::cout << ", ";
    }
    // std::cout << "<" << toString(p.second) << ", " << "'" << p.first << "'"
    // << ">";
    first = false;
  }

  // std::cout << " }" << std::endl;

  file.close();
  return 0; // Values other than 0 and -1 are reserved for future use.
}
