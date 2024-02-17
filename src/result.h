
#include <cstdlib>
#include <optional>
#include <string>
#include <functional>

namespace filewatcher {

    void panic(const std::string& msg = "");

    template<typename T, typename U>
    class Result {
        std::optional<T> value;
        std::optional<U> error;

    public:
        bool is_err() const {
            return error.has_value();
        }

        bool is_ok() const {
            return value.has_value();
        }

        T unwrap() {
            if(value.has_value()) {
                return std::move(value.value());
            } else {
                panic("called `Result::unwrap()` on an `Err` value");
                exit(1);
            }
        }

        U unwrap_err() {
            if(error.has_value()) {
                return std::move(error.value());
            } else {
                panic("called `Result::unwrap_err()` on an `Ok` value");
                exit(1);
            }
        }

        T unwrap_or(T&& def) {
            if(value.has_value()) {
                return std::move(value.value());
            } else {
                return std::move(def);
            }
        }

        T unwrap_or_else(std::function<T(U&&)> f) {
            if(value.has_value()) {
                return std::move(value.value());
            } else {
                return f(std::move(error.value()));
            }
        }

        U unwrap_err_or(U&& def) {
            if(error.has_value()) {
                return std::move(error.value());
            } else {
                return std::move(def);
            }
        }

        U unwrap_err_or_else(std::function<U(T&&)> f) {
            if(error.has_value()) {
                return std::move(error.value());
            } else {
                return f(std::move(value.value()));
            }
        }

        T expect(const std::string& msg) {
            if(value.has_value()) {
                return std::move(value.value());
            } else {
                panic(msg);
                exit(1);
            }
        }

        U expect_err(const std::string& msg) {
            if(error.has_value()) {
                return std::move(error.value());
            } else {
                panic(msg);
                exit(1);
            }
        }

        std::optional<T> ok() {
            return value;
        }

        std::optional<U> err() {
            return error;
        }
    public:

        static Result<T, U> Ok(T&& value) {
            Result<T, U> result;
            result.error = std::nullopt;
            result.value = std::move(value);
            return result;
        }

        static Result<T, U> Err(U&& error) {
            Result<T, U> result;
            result.value = std::nullopt;
            result.error = std::move(error);
            return result;
        }
    };
}



