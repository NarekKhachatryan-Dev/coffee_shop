#include <string>
#include <iostream>

class Beverage {
    public:
        virtual std::string getDescription() const = 0;
        virtual double cost() const = 0;
        virtual ~Beverage() = default;
};

class Espresso : public Beverage {
    std::string getDescription() const override {
        return "Espresso";
    }

    double cost() const override {
        return 1.50;
    }
};

class Latte : public Beverage {
    std::string getDescription() const override {
        return "Latte";
    }

    double cost() const override {
        return 2.50;
    }
};

class greenTea : public Beverage {
    std::string getDescription() const override {
        return "Green Tea";
    }

    double cost() const override {
        return 1.00;
    }
};