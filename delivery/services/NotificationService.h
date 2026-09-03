#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "../models/Order.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"

class NotificationService {
private:
    Order* order;

public:
    NotificationService() : order(nullptr) {}
    explicit NotificationService(Order* ord) : order(ord) {}

    void setOrder(Order* ord) {
        order = ord;
    }

    void notifyUser() const {
        if (order) {
            notify(order);
        }
    }

    static void notify(const Order* ord) {
        if (!ord) return;

        std::cout << "\n---------------------------------------------" << std::endl;
        std::cout << "Notification: New " << ord->getType() << " order placed!" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Order ID:       #" << ord->getOrderId() << std::endl;
        std::cout << "Customer:       " << (ord->getUser() ? ord->getUser()->getName() : "N/A") << std::endl;
        std::cout << "Restaurant:     " << (ord->getRestaurant() ? ord->getRestaurant()->getName() : "N/A") << std::endl;

        if (auto delOrder = dynamic_cast<const DeliveryOrder*>(ord)) {
            std::cout << "Delivery To:    " << delOrder->getUserAddress() << std::endl;
        } else if (auto picOrder = dynamic_cast<const PickupOrder*>(ord)) {
            std::cout << "Pickup At:      " << picOrder->getRestaurantAddress() << std::endl;
        }

        std::cout << "Items Ordered:  " << std::endl;
        const auto& items = ord->getItems();
        for (const auto& item : items) {
            std::cout << "   - " << item.getName() << " (Rs. " << std::fixed << std::setprecision(2)
                      << item.getPrice() << ")" << std::endl;
        }

        std::cout << "Total:          Rs. " << std::fixed << std::setprecision(2) << ord->getTotal() << std::endl;
        std::cout << "Scheduled For:  " << ord->getScheduled() << std::endl;
        std::cout << "Payment Status: SUCCESS" << std::endl;
        std::cout << "---------------------------------------------\n" << std::endl;
    }
};
