#pragma once

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(User* user, Cart* /*cart*/, Restaurant* restaurant,
                       const std::vector<MenuItem>& menuItems,
                       PaymentStrategy* paymentStrategy, double totalCost,
                       const std::string& orderType) override {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user ? user->getAddress() : "");
            order = deliveryOrder;
        } else {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant ? restaurant->getLocation() : "");
            order = pickupOrder;
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(TimeUtils::getCurrentTime());
        order->setTotal(totalCost);
        return order;
    }
};
