#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "MenuItem.h"
#include "Restaurant.h"

class Cart {
private:
    Restaurant* restaurant;
    std::vector<MenuItem> items;

public:
    Cart() : restaurant(nullptr) {}

    void addItem(const MenuItem& item) {
        if (!restaurant) {
            std::cerr << "Cart Error: Please select a restaurant before adding items." << std::endl;
            return;
        }
        items.push_back(item);
    }

    double getTotalCost() const {
        double sum = 0.0;
        for (const auto& item : items) {
            sum += item.getPrice();
        }
        return sum;
    }

    bool isEmpty() const {
        return (restaurant == nullptr || items.empty());
    }

    void clear() {
        items.clear();
        restaurant = nullptr;
    }

    // Getters and Setters
    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    const std::vector<MenuItem>& getItems() const {
        return items;
    }
};
