#include "log.h"

// Define externs
log logger;

log::log() {
  // New log every run
  if(std::filesystem::exists("./logs/errors.log"))
    std::filesystem::remove("./logs/errors.log");
}

void log::err(const std::string& msg) {
  out.open(errorFile, std::ios::app);
  // Get the system time
  auto time
    = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // Log time and error message
  out << std::ctime(&time) << ": " << msg << std::endl;
  out.close();
}
