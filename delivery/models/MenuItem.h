#pragma once

#include <string>

class MenuItem {
private:
    std::string code;
    std::string name;
    double price;

public:
    MenuItem() : code(""), name(""), price(0.0) {}

    MenuItem(const std::string& code, const std::string& name, double price)
        : code(code), name(name), price(price) {}

    // Getters
    std::string getCode() const {
        return code;
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    // Setters
    void setCode(const std::string& c) {
        code = c;
    }

    void setName(const std::string& n) {
        name = n;
    }

    void setPrice(double p) {
        price = p;
    }
};
