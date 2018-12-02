#include "log.h"

/* ----------------------------------------------------------------------------
 * Define externs here
 * --------------------------------------------------------------------------*/
log logger;

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   log()
 * DESCRIPTION:
 *   Default ctor
 * --------------------------------------------------------------------------*/
log::log() {
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   err(const std::string&)
 * DESCRIPTION:
 *   Logs a message to the error log.
 * --------------------------------------------------------------------------*/
void log::err(const std::string& msg) {
  out.open(errorFile, std::ios::app);
  // Get the system time
  auto time
    = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // Log time and error message
  out << std::ctime(&time) << msg << "\n\n";
  out.close();
}
