#pragma once

#include <string>
#include "Cart.h"

class User {
private:
    int userId;
    std::string name;
    std::string address;
    Cart cart;

public:
    User(int userId, const std::string& name, const std::string& address)
        : userId(userId), name(name), address(address) {}

    // Getters and Setters
    int getUserId() const {
        return userId;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        name = n;
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(const std::string& a) {
        address = a;
    }

    Cart* getCart() {
        return &cart;
    }

    const Cart* getCart() const {
        return &cart;
    }
};
