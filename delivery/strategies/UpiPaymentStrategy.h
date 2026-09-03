#pragma once

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

class UpiPaymentStrategy : public PaymentStrategy {
private:
    std::string mobile;

public:
    explicit UpiPaymentStrategy(const std::string& mob) : mobile(mob) {}

    void pay(double amount) override {
        std::cout << "Paid Rs. " << std::fixed << std::setprecision(2) << amount
                  << " using UPI (" << mobile << ")" << std::endl;
    }
};
