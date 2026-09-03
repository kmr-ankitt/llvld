#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "MenuItem.h"

class Restaurant {
private:
    inline static int nextRestaurantId = 0;
    int restaurantId;
    std::string name;
    std::string location;
    std::vector<MenuItem> menu;

public:
    Restaurant(const std::string& name, const std::string& location)
        : restaurantId(++nextRestaurantId), name(name), location(location) {}

    // Getters
    int getRestaurantId() const {
        return restaurantId;
    }

    std::string getName() const {
        return name;
    }

    std::string getLocation() const {
        return location;
    }

    const std::vector<MenuItem>& getMenu() const {
        return menu;
    }

    // Setters
    void setName(const std::string& n) {
        name = n;
    }

    void setLocation(const std::string& loc) {
        location = loc;
    }

    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }
};
