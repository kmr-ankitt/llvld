#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "../models/Restaurant.h"

class RestaurantManager {
private:
    std::vector<Restaurant*> restaurants;

    RestaurantManager() = default;

    ~RestaurantManager() {
        for (auto r : restaurants) {
            delete r;
        }
        restaurants.clear();
    }

    RestaurantManager(const RestaurantManager&) = delete;
    RestaurantManager& operator=(const RestaurantManager&) = delete;

public:
    static RestaurantManager* getInstance() {
        static RestaurantManager instance;
        return &instance;
    }

    void addRestaurant(Restaurant* r) {
        if (r) {
            restaurants.push_back(r);
        }
    }

    std::vector<Restaurant*> searchByLocation(std::string loc) const {
        std::vector<Restaurant*> result;
        std::transform(loc.begin(), loc.end(), loc.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });

        for (auto r : restaurants) {
            if (!r) continue;
            std::string rl = r->getLocation();
            std::transform(rl.begin(), rl.end(), rl.begin(), [](unsigned char c) {
                return static_cast<char>(std::tolower(c));
            });
            if (rl == loc) {
                result.push_back(r);
            }
        }
        return result;
    }

    const std::vector<Restaurant*>& getAllRestaurants() const {
        return restaurants;
    }
};
