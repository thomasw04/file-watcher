#pragma once

#include <string>
#include <memory>

#include "result.h"

namespace filewatcher {

    struct Watcher {
        using Ref = std::shared_ptr<Watcher>;

        ~Watcher();

        static Result<Ref, std::string> watch(const std::string& path);
    private:
        //Create a watcher for the specific file or directory. The String must be UTF-8 encoded.
        Watcher(const std::string& path);
    };

}


