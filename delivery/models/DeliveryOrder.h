#pragma once

#include "Order.h"
#include <string>

class DeliveryOrder : public Order {
private:
    std::string userAddress;

public:
    DeliveryOrder() : userAddress("") {}

    std::string getType() const override {
        return "Delivery";
    }

    // Getters and Setters
    void setUserAddress(const std::string& addr) {
        userAddress = addr;
    }

    std::string getUserAddress() const {
        return userAddress;
    }
};
