#pragma once

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

class CreditCardPaymentStrategy : public PaymentStrategy {
private:
    std::string cardNumber;

public:
    explicit CreditCardPaymentStrategy(const std::string& card) : cardNumber(card) {}

    void pay(double amount) override {
        std::cout << "Paid Rs. " << std::fixed << std::setprecision(2) << amount
                  << " using Credit Card (" << cardNumber << ")" << std::endl;
    }
};
