# Tomato - Food Delivery Application

A clean Low-Level Design (LLD) implementation of an online food delivery system.

---

## Architecture & Class Diagram

```mermaid
classDiagram
    direction TB
    class TomatoApp {
        +searchRestaurants(location)
        +selectRestaurant(user, restaurant)
        +addToCart(user, itemCode)
        +checkoutNow(user, orderType, paymentStrategy)
        +checkoutScheduled(user, orderType, paymentStrategy, scheduleTime)
        +payForOrder(user, order)
        +printUserCart(user)
    }

    class RestaurantManager {
        <<Singleton>>
        -vector~Restaurant*~ restaurants
        +getInstance() RestaurantManager*
        +addRestaurant(r)
        +searchByLocation(loc)
    }

    class OrderManager {
        <<Singleton>>
        -vector~Order*~ orders
        +getInstance() OrderManager*
        +addOrder(order)
        +listOrders()
    }

    class Order {
        <<Abstract>>
        #int orderId
        #User* user
        #Restaurant* restaurant
        #vector~MenuItem~ items
        #PaymentStrategy* paymentStrategy
        #double total
        #string scheduled
        +processPayment() bool
        +getType()* string
    }

    class DeliveryOrder {
        -string userAddress
        +getType() string
    }

    class PickupOrder {
        -string restaurantAddress
        +getType() string
    }

    class OrderFactory {
        <<Interface>>
        +createOrder()* Order*
    }

    class NowOrderFactory {
        +createOrder() Order*
    }

    class ScheduledOrderFactory {
        -string scheduleTime
        +createOrder() Order*
    }

    class PaymentStrategy {
        <<Interface>>
        +pay(amount)* void
    }

    class CreditCardPaymentStrategy {
        -string cardNumber
        +pay(amount) void
    }

    class UpiPaymentStrategy {
        -string mobile
        +pay(amount) void
    }

    class NetBankingPaymentStrategy {
        -string bankName
        -string accountNumber
        +pay(amount) void
    }

    TomatoApp --> RestaurantManager
    TomatoApp --> OrderManager
    TomatoApp --> OrderFactory
    Order <|-- DeliveryOrder
    Order <|-- PickupOrder
    OrderFactory <|-- NowOrderFactory
    OrderFactory <|-- ScheduledOrderFactory
    OrderFactory ..> Order : creates
    PaymentStrategy <|-- CreditCardPaymentStrategy
    PaymentStrategy <|-- UpiPaymentStrategy
    PaymentStrategy <|-- NetBankingPaymentStrategy
    Order o-- PaymentStrategy
```

---

## 📁 Directory Structure

```
delivery/
├── arch.png                           # Architecture reference diagram
├── README.md                          # Project documentation
├── main.cpp                           # Composition root & test scenarios
├── index.cpp                          # Delegating entry point
├── TomatoApp.h                        # Facade orchestrator
├── models/
│   ├── MenuItem.h                     # Menu item (code, name, price)
│   ├── Restaurant.h                   # Restaurant entity with menu
│   ├── User.h                         # User profile with address & cart
│   ├── Cart.h                         # Cart managing items & subtotal
│   ├── Order.h                        # Abstract order base class
│   ├── DeliveryOrder.h                # Order variant for delivery
│   └── PickupOrder.h                  # Order variant for pickup
├── managers/
│   ├── RestaurantManager.h            # Singleton: restaurant registry & search
│   └── OrderManager.h                 # Singleton: order history & logging
├── strategies/
│   ├── PaymentStrategy.h              # Payment interface
│   ├── CreditCardPaymentStrategy.h    # Credit Card payment
│   ├── UpiPaymentStrategy.h           # UPI payment
│   └── NetBankingPaymentStrategy.h    # NetBanking payment
├── factories/
│   ├── OrderFactory.h                 # Abstract order factory interface
│   ├── NowOrderFactory.h              # Factory for immediate orders
│   └── ScheduledOrderFactory.h        # Factory for scheduled orders
├── services/
│   └── NotificationService.h          # Order confirmation & receipt
└── utils/
    └── TimeUtils.h                    # Timestamp formatting utility
```

---

## Build & Run

```bash
# Compile
g++ -std=c++17 -Wall -Wextra main.cpp -o tomato.exe

# Run
.\tomato.exe
```

---

## 💻 Quick Usage

```cpp
#include "TomatoApp.h"

int main() {
    Tomato* tomato = new Tomato();
    User* user = new User(101, "Aditya", "42 Connaught Place, New Delhi");

    // Search and select restaurant
    auto restaurants = tomato->searchRestaurants("Delhi");
    tomato->selectRestaurant(user, restaurants[0]);

    // Add items to cart
    tomato->addToCart(user, "P1");
    tomato->addToCart(user, "P2");

    // Checkout immediate delivery via UPI
    Order* order = tomato->checkoutNow(user, "Delivery", new UpiPaymentStrategy("9876543210@upi"));

    // Pay and notify
    tomato->payForOrder(user, order);

    delete user;
    delete tomato;
    return 0;
}
```
