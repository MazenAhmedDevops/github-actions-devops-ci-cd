#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Hotel.h"

static const std::string APP_VERSION = "1.0.0";

enum ExitCode {
    OK = 0,
    INVALID_ARGUMENTS = 1,
    RUNTIME_ERROR = 2
};