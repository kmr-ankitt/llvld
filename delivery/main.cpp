#include <iostream>
#include <vector>
#include "TomatoApp.h"

int main() {
    std::cout << "========================================================" << std::endl;
    std::cout << "        WELCOME TO TOMATO FOOD ORDERING SYSTEM          " << std::endl;
    std::cout << "========================================================" << std::endl;

    // Create the Tomato Facade instance
    Tomato* tomato = new Tomato();

    // ==========================================================
    // SCENARIO 1: Immediate Delivery Order via UPI (Aditya - Delhi)
    // ==========================================================
    std::cout << "\n>>> [Scenario 1] Immediate Delivery Order with UPI" << std::endl;
    User* user1 = new User(101, "Aditya", "42 Connaught Place, New Delhi");
    std::cout << "Active User: " << user1->getName() << " (" << user1->getAddress() << ")" << std::endl;

    // Search restaurants by location
    std::string searchLoc = "Delhi";
    std::cout << "Searching for restaurants in: " << searchLoc << std::endl;
    std::vector<Restaurant*> delhiRestaurants = tomato->searchRestaurants(searchLoc);

    if (delhiRestaurants.empty()) {
        std::cout << "No restaurants found in " << searchLoc << "!" << std::endl;
    } else {
        std::cout << "Found " << delhiRestaurants.size() << " restaurant(s):" << std::endl;
        for (const auto& r : delhiRestaurants) {
            std::cout << " - " << r->getName() << " (Location: " << r->getLocation() << ")" << std::endl;
        }

        // Select the first restaurant
        Restaurant* selectedRes = delhiRestaurants[0];
        tomato->selectRestaurant(user1, selectedRes);
        std::cout << "Selected: " << selectedRes->getName() << std::endl;

        // Add items to cart
        tomato->addToCart(user1, "P1"); // Chole Bhature
        tomato->addToCart(user1, "P2"); // Samosa

        // Print cart
        tomato->printUserCart(user1);

        // Checkout Now for Delivery using UPI
        std::cout << "Checking out: Delivery (Now) via UPI..." << std::endl;
        Order* order1 = tomato->checkoutNow(user1, "Delivery", new UpiPaymentStrategy("9876543210@upi"));

        // Pay for order
        if (order1) {
            tomato->payForOrder(user1, order1);
        }
    }

    // ==========================================================
    // SCENARIO 2: Scheduled Pickup Order via Credit Card (Priya - Chennai)
    // ==========================================================
    std::cout << "\n>>> [Scenario 2] Scheduled Pickup Order with Credit Card" << std::endl;
    User* user2 = new User(102, "Priya", "15 T. Nagar, Chennai");
    std::cout << "Active User: " << user2->getName() << " (" << user2->getAddress() << ")" << std::endl;

    std::vector<Restaurant*> chennaiRestaurants = tomato->searchRestaurants("chennai");
    if (!chennaiRestaurants.empty()) {
        Restaurant* selectedRes = chennaiRestaurants[0];
        tomato->selectRestaurant(user2, selectedRes);
        std::cout << "Selected: " << selectedRes->getName() << std::endl;

        tomato->addToCart(user2, "P1"); // Masala Dosa
        tomato->addToCart(user2, "P3"); // Filter Coffee

        tomato->printUserCart(user2);

        std::string pickupTime = "2026-09-04 19:30:00";
        std::cout << "Checking out: Pickup (Scheduled for " << pickupTime << ") via Credit Card..." << std::endl;
        Order* order2 = tomato->checkoutScheduled(user2, "Pickup",
                                                  new CreditCardPaymentStrategy("4111-XXXX-XXXX-1111"),
                                                  pickupTime);
        if (order2) {
            tomato->payForOrder(user2, order2);
        }
    }

    // ==========================================================
    // SCENARIO 3: Scheduled Delivery Order via NetBanking (Rahul - Kolkata)
    // ==========================================================
    std::cout << "\n>>> [Scenario 3] Scheduled Delivery Order with NetBanking" << std::endl;
    User* user3 = new User(103, "Rahul", "7 Park Street, Kolkata");
    std::cout << "Active User: " << user3->getName() << " (" << user3->getAddress() << ")" << std::endl;

    std::vector<Restaurant*> kolkataRestaurants = tomato->searchRestaurants("Kolkata");
    if (!kolkataRestaurants.empty()) {
        Restaurant* selectedRes = kolkataRestaurants[0];
        tomato->selectRestaurant(user3, selectedRes);
        std::cout << "Selected: " << selectedRes->getName() << std::endl;

        tomato->addToCart(user3, "P1"); // Raj Kachori
        tomato->addToCart(user3, "P2"); // Pav Bhaji
        tomato->addToCart(user3, "P3"); // Dhokla

        tomato->printUserCart(user3);

        std::string deliveryTime = "2026-09-04 20:45:00";
        std::cout << "Checking out: Delivery (Scheduled for " << deliveryTime << ") via NetBanking..." << std::endl;
        Order* order3 = tomato->checkoutScheduled(user3, "Delivery",
                                                  new NetBankingPaymentStrategy("HDFC Bank", "987654321098"),
                                                  deliveryTime);
        if (order3) {
            tomato->payForOrder(user3, order3);
        }
    }

    // ==========================================================
    // OrderManager Global Summary
    // ==========================================================
    OrderManager::getInstance()->listOrders();

    // Clean up allocated user and facade instances
    delete user1;
    delete user2;
    delete user3;
    delete tomato;

    std::cout << "All resources successfully cleaned up. Tomato App terminated gracefully." << std::endl;
    return 0;
}
