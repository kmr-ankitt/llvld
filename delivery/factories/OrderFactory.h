#pragma once

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../strategies/PaymentStrategy.h"
#include <vector>
#include <string>

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant,
                               const std::vector<MenuItem>& menuItems,
                               PaymentStrategy* paymentStrategy, double totalCost,
                               const std::string& orderType) = 0;
    virtual ~OrderFactory() = default;
};
