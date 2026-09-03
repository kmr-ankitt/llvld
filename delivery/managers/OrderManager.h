#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include "../models/Order.h"

class OrderManager {
private:
    std::vector<Order*> orders;

    OrderManager() = default;

    ~OrderManager() {
        for (auto order : orders) {
            delete order;
        }
        orders.clear();
    }

    OrderManager(const OrderManager&) = delete;
    OrderManager& operator=(const OrderManager&) = delete;

public:
    static OrderManager* getInstance() {
        static OrderManager instance;
        return &instance;
    }

    void addOrder(Order* order) {
        if (order) {
            orders.push_back(order);
        }
    }

    void listOrders() const {
        std::cout << "\n=============================================" << std::endl;
        std::cout << "                 ALL ORDERS                  " << std::endl;
        std::cout << "=============================================" << std::endl;
        if (orders.empty()) {
            std::cout << "No orders placed yet." << std::endl;
            return;
        }

        for (const auto& order : orders) {
            if (!order) continue;
            std::cout << "#" << order->getOrderId() << " | "
                      << "[" << order->getType() << "]"
                      << " Customer: " << (order->getUser() ? order->getUser()->getName() : "N/A")
                      << " | Restaurant: " << (order->getRestaurant() ? order->getRestaurant()->getName() : "N/A")
                      << " | Total: Rs. " << std::fixed << std::setprecision(2) << order->getTotal()
                      << " | Scheduled: " << order->getScheduled()
                      << std::endl;
        }
        std::cout << "=============================================\n" << std::endl;
    }

    const std::vector<Order*>& getOrders() const {
        return orders;
    }
};
