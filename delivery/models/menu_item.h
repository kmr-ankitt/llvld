#pragma once
#include <string>

class MenuItem {
private:
  static unsigned int id;
  std::string name;
  double price;

public:
  MenuItem(const std::string &name, double price) : name(name), price(price) {
    id++;
  };

  // getters
  unsigned int getId() const { return id; }

  std::string getName() const { return name; }

  double getPrice() const;

  // setters
  void setName(const std::string &name);
  void setPrice(double price);
};
