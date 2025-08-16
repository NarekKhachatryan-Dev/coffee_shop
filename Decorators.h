#include "Beverage.h"
#include <memory>

/* milk, sugar, whipped cream, caramel */

class BeverageDecorator : public Beverage {
    protected:
        std::shared_ptr<Beverage> beverage;
    public:
    virtual double cost() const override {
        return beverage->cost();
    }
    virtual std::string getDescription() const override {
        return beverage->getDescription();
    }

    BeverageDecorator(std::shared_ptr<Beverage> b) : beverage(b)  {}
    virtual ~BeverageDecorator() = default;
};

class Milk : public BeverageDecorator {
    public:
        Milk(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}
        double cost() const override {
            return beverage->cost() + 0.10;
        }
        std::string getDescription() const override {
            return beverage->getDescription() + ", Milk";
        }
};

class Sugar : public BeverageDecorator {
    public:
        Sugar(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}
        double cost() const override {
            return beverage->cost() + 0.05;
        }
        std::string getDescription() const override {
            return beverage->getDescription() + ", Sugar";
        }
};

class WhippedCream : public BeverageDecorator {
    public:
        WhippedCream(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}
        double cost() const override {
            return beverage->cost() + 0.15;
        }
        std::string getDescription() const override {
            return beverage->getDescription() + ", Whipped Cream";
        }
};

class Caramel : public BeverageDecorator {
    public:
        Caramel(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}
        double cost() const override {
            return beverage->cost() + 0.20;
        }
        std::string getDescription() const override {
            return beverage->getDescription() + ", Caramel";
        }
};

class Vanilla : public BeverageDecorator {
    public:
        Vanilla(std::shared_ptr<Beverage> b) : BeverageDecorator(b) {}
        double cost() const override {
            return beverage->cost() + 0.25;
        }
        std::string getDescription() const override {
            return beverage->getDescription() + ", Vanilla";
        }
};