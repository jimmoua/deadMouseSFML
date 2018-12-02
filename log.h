#pragma once
#include <fstream>
#include <string>
#include <chrono>

/* ----------------------------------------------------------------------------
 * CLASS:
 *   log
 * DESCRIPTION:
 *   Class for logging
 * --------------------------------------------------------------------------*/
class log {
  public:
    log();
    void err(const std::string&);
  private:
    std::ofstream out;
    const std::string errorFile = "./logs/errors.log";
};

// Define extern
extern log logger;
