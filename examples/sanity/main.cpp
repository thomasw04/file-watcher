#include <filewatcher.h>

#include <iostream>

using namespace filewatcher;

int main() {
    std::cout << "Hello World" << std::endl;

    auto res = Result<std::string, std::string>::Ok("Among");

    auto str = res.unwrap_err();
}