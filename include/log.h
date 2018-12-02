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
    void session(const std::string&);
  private:
    std::ofstream out;
    const std::string errorFile = "./logs/errors.log";
    const std::string sessionFile = "./logs/sessions.log";
};

/* ----------------------------------------------------------------------------
 * Define externs here.
 * --------------------------------------------------------------------------*/
extern log logger;
