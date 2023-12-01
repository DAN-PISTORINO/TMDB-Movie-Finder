#include <iostream>
#include <sstream>

template <typename T>
class JSSerializer {
public:
    std::string serialize(const T& obj) {
        std::stringstream ss;
        ss << "{";

        for (const auto& [key, value] : obj) {
            ss << "\"" << key << "\":" << convertValue(value) << ", ";
        }

        ss.seekp(-2, std::ios::end);
        ss << "}";

        return ss.str();
    }

private:
    std::string convertValue(const T& value) {
        if (std::is_integral<T>::value) {
            return std::to_string(value);
        }
        else if (std::is_floating_point<T>::value) {
            return std::to_string(value);
        }
        else if (std::is_same<T, std::string>::value) {
            return "\"" + value + "\"";
        }
        else {
            throw std::runtime_error("Unsupported data type");
        }
    }
};