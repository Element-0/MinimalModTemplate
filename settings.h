#pragma once

#include <yaml.h>
#include <string>

struct Settings {
  bool optionA = false;
  bool optionB = true;

  struct Nested {
    std::string value;

    template <typename IO> static inline bool io(IO f, Nested &nested, YAML::Node &node) {
      return f(nested.value, node["value"]);
    }
  } nested;

  template <typename IO> static inline bool io(IO f, Settings &settings, YAML::Node &node) {
    return f(settings.optionA, node["opt-a"]) && f(settings.optionB, node["opt-b"]) &&
           f(settings.nested, node["nested"]);
  }
};

inline Settings settings;
