#pragma once 

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::string> GetSubstrs(const std::string& str,
                                                char delimiter) {
  size_t last = 0;
  std::vector<std::string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter) {
      std::string substr = str.substr(last, i - last);
      last = i + 1;
      substr.erase(remove(substr.begin(), substr.end(), '"'), substr.end());
      substrs.push_back(substr);
    }
  }
  std::string substr = str.substr(last, str.length() - last);
  substrs.push_back(substr);

  return substrs;
}

