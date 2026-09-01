#pragma once
#include "menu_item.h"
#include <string>
#include <vector>

class Restaurant {
private:
  static unsigned int restaurantId;
  std::string name;
  std::vector<MenuItem *> menu;

public:
  Restaurant(const std::string &name) : name(name) { restaurantId++; };

  // getters
  unsigned int getRestaurantId() const { return restaurantId; }

  std::string getName() const { return name; }

  std::vector<MenuItem *> getMenu() const { return menu; }

  // setters
  void setName(const std::string &name) { this->name = name; };

  void addMenuItem(MenuItem *item) { menu.push_back(item); };
};
