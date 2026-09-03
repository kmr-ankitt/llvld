#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"

class Order {
protected:
    inline static int nextOrderId = 0;
    int orderId;
    User* user;
    Restaurant* restaurant;
    std::vector<MenuItem> items;
    PaymentStrategy* paymentStrategy;
    double total;
    std::string scheduled;

public:
    Order()
        : orderId(++nextOrderId),
          user(nullptr),
          restaurant(nullptr),
          paymentStrategy(nullptr),
          total(0.0),
          scheduled("") {}

    virtual ~Order() {
        delete paymentStrategy;
    }

    bool processPayment() {
        if (paymentStrategy) {
            paymentStrategy->pay(total);
            return true;
        } else {
            std::cout << "Please choose a payment mode first" << std::endl;
            return false;
        }
    }

    virtual std::string getType() const = 0;

    // Getters and Setters
    int getOrderId() const {
        return orderId;
    }

    void setUser(User* u) {
        user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setItems(const std::vector<MenuItem>& its) {
        items = its;
        total = 0.0;
        for (const auto& i : items) {
            total += i.getPrice();
        }
    }

    const std::vector<MenuItem>& getItems() const {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p) {
        if (paymentStrategy != p) {
            delete paymentStrategy;
            paymentStrategy = p;
        }
    }

    PaymentStrategy* getPaymentStrategy() const {
        return paymentStrategy;
    }

    void setScheduled(const std::string& s) {
        scheduled = s;
    }

    std::string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(double t) {
        total = t;
    }
};
