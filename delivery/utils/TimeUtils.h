#pragma once

#include <ctime>
#include <string>

class TimeUtils {
public:
    static std::string getCurrentTime() {
        std::time_t now = std::time(nullptr);
        std::tm ltm{};
#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&ltm, &now);
#else
        localtime_r(&now, &ltm);
#endif
        char buffer[64];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &ltm);
        return std::string(buffer);
    }
};
