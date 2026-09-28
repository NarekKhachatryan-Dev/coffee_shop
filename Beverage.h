#pragma once
#include <string>

class Beverage {
    public:
        virtual std::string getDescription() const = 0;
        virtual double cost() const = 0;
        virtual ~Beverage() = default;
};

class Espresso : public Beverage {
public:
    std::string getDescription() const override {
        return "Espresso";
    }

    double cost() const override {
        return 1.50;
    }
};

class Latte : public Beverage {
public:
    std::string getDescription() const override {
        return "Latte";
    }

    double cost() const override {
        return 2.50;
    }
};

class GreenTea : public Beverage {
public:
    std::string getDescription() const override {
        return "Green Tea";
    }

    double cost() const override {
        return 1.00;
    }
};