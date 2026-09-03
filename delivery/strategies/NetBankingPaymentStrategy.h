#pragma once

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

class NetBankingPaymentStrategy : public PaymentStrategy {
private:
    std::string bankName;
    std::string accountNumber;

public:
    NetBankingPaymentStrategy(const std::string& bank, const std::string& accNo)
        : bankName(bank), accountNumber(accNo) {}

    void pay(double amount) override {
        std::cout << "Paid Rs. " << std::fixed << std::setprecision(2) << amount
                  << " using NetBanking (" << bankName << ", A/C: " << accountNumber << ")" << std::endl;
    }
};
