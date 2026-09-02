#pragma once

#include "../interfaces/location.h"
#include "menu_item.h"

#include <string>
#include <vector>

class Restaurant {
private:
  static unsigned int restaurantId;
  std::string name;
  Location location;
  std::vector<MenuItem *> menu;

public:
  Restaurant(const std::string &name, int latitude, int longitude,
             std::string &loc)
      : name(name) {
    restaurantId++;
    location.latitude = latitude;
    location.longitude = longitude;
    location.name = loc;
  };

  // getters
  unsigned int getRestaurantId() const { return restaurantId; }

  std::string getName() const { return name; }

  std::vector<MenuItem *> getMenu() const { return menu; }
  Location getLocation() const { return location; }

  // setters
  void setName(const std::string &name) { this->name = name; };

  void addMenuItem(MenuItem *item) { menu.push_back(item); };
};
