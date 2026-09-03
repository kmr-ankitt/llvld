#pragma once

#include "Order.h"
#include <string>

class PickupOrder : public Order {
private:
    std::string restaurantAddress;

public:
    PickupOrder() : restaurantAddress("") {}

    std::string getType() const override {
        return "Pickup";
    }

    // Getters and Setters
    void setRestaurantAddress(const std::string& addr) {
        restaurantAddress = addr;
    }

    std::string getRestaurantAddress() const {
        return restaurantAddress;
    }
};
