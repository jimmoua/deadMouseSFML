#pragma once
#include <fstream>
#include <string>
#include <filesystem>

namespace logger {
  class log {
    public:
      log();
      void err(const std::string&);
    private:
      std::ofstream out;
      const std::string errorFile = "errors.log";
  };

  // Define extern
  extern log logger;
}
