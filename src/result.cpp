#include "result.h"

#include <sstream>
#include <thread>
#include <iostream>

namespace filewatcher {

    void panic(const std::string& msg) {
        std::stringstream ss;
        ss << "thread '" << std::this_thread::get_id() << "' panicked at '" << msg << "'" << std::endl;
        ss << "note: run with RUST_BACKTRACE=1 environment variable to display a backtrace" << std::endl;
        std::cout << ss.str();
        std::abort();
    }
}