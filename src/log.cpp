#include "../include/log.h"

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

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   session(const std::string&)
 * DESCRIPTION:
 *   Logs the current session when the SMFL window is closed. These are
 *   basically stats of the mouse.
 * --------------------------------------------------------------------------*/
void log::session(const std::string& msg) {
  // Open the file in append mode
  out.open(sessionFile, std::ios::app);

  // Log the time, then the message.
  auto time =
    std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  out << std::ctime(&time) << msg << "\n\n";
}
