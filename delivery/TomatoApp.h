#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "models/Order.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "strategies/CreditCardPaymentStrategy.h"
#include "strategies/NetBankingPaymentStrategy.h"
#include "factories/OrderFactory.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"

class TomatoApp {
public:
    TomatoApp() {
        initializeRestaurants();
    }

    void initializeRestaurants() {
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120.0));
        restaurant1->addMenuItem(MenuItem("P2", "Samosa", 15.0));

        Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80.0));
        restaurant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100.0));
        restaurant2->addMenuItem(MenuItem("P3", "Dhokla", 50.0));

        Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90.0));
        restaurant3->addMenuItem(MenuItem("P2", "Idli Vada", 60.0));
        restaurant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30.0));

        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);
    }

    std::vector<Restaurant*> searchRestaurants(const std::string& location) const {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(User* user, Restaurant* restaurant) {
        if (!user) return;
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    bool addToCart(User* user, const std::string& itemCode) {
        if (!user) return false;
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if (!restaurant) {
            std::cout << "Please select a restaurant first." << std::endl;
            return false;
        }
        for (const auto& item : restaurant->getMenu()) {
            if (item.getCode() == itemCode) {
                user->getCart()->addItem(item);
                std::cout << "Added '" << item.getName() << "' to " << user->getName() << "'s cart." << std::endl;
                return true;
            }
        }
        std::cout << "Item with code '" << itemCode << "' not found in " << restaurant->getName() << "'s menu." << std::endl;
        return false;
    }

    Order* checkoutNow(User* user, const std::string& orderType, PaymentStrategy* paymentStrategy) {
        NowOrderFactory factory;
        return checkout(user, orderType, paymentStrategy, &factory);
    }

    Order* checkoutScheduled(User* user, const std::string& orderType, PaymentStrategy* paymentStrategy, const std::string& scheduleTime) {
        ScheduledOrderFactory factory(scheduleTime);
        return checkout(user, orderType, paymentStrategy, &factory);
    }

    Order* checkout(User* user, const std::string& orderType,
                    PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (!user || user->getCart()->isEmpty()) {
            std::cout << "Cannot checkout: Cart is empty or invalid user." << std::endl;
            delete paymentStrategy; // Clean up unused payment strategy if checkout aborted
            return nullptr;
        }

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        std::vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    void payForOrder(User* user, Order* order) {
        if (!order) {
            std::cout << "No order provided for payment." << std::endl;
            return;
        }

        bool isPaymentSuccess = order->processPayment();

        // Clear user cart if payment is successful
        if (isPaymentSuccess) {
            NotificationService::notify(order);
            if (user && user->getCart()) {
                user->getCart()->clear();
            }
        }
    }

    void printUserCart(User* user) const {
        if (!user) return;
        std::cout << "\nItems in cart for " << user->getName() << ":" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        for (const auto& item : user->getCart()->getItems()) {
            std::cout << item.getCode() << " : " << item.getName() << " : Rs. "
                      << std::fixed << std::setprecision(2) << item.getPrice() << std::endl;
        }
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Grand total : Rs. " << std::fixed << std::setprecision(2)
                  << user->getCart()->getTotalCost() << "\n" << std::endl;
    }
};

// Alias matching Tomato from architecture diagram
using Tomato = TomatoApp;
