#pragma once

#include "Decorators.h"

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

class Order {
private:
    std::vector<std::shared_ptr<Beverage>> items;

    void saveCurrentDrink(std::shared_ptr<Beverage>& currentDrink) {
        if (currentDrink) {
            items.push_back(std::move(currentDrink));
            currentDrink.reset();
        }
    }

    void displayCurrentDrink(const std::shared_ptr<Beverage>& currentDrink) const {
        if (currentDrink) {
            std::cout << "Current drink: " << currentDrink->getDescription()
                      << " ($" << currentDrink->cost() << ")\n";
        } else {
            std::cout << "Choose a base beverage first.\n";
        }
    }

public:
    void start() {
        std::shared_ptr<Beverage> currentDrink;

        while (true) {
            std::cout << "\n1. Espresso\n"
                      << "2. Latte\n"
                      << "3. Green Tea\n"
                      << "4. Sugar\n"
                      << "5. Milk\n"
                      << "6. Whipped Cream\n"
                      << "7. Caramel\n"
                      << "8. Vanilla\n"
                      << "9. Add current drink to order\n"
                      << "10. Finish order\n"
                      << "Choice: ";

            int input = 0;
            if (!(std::cin >> input)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a number.\n";
                continue;
            }

            switch (input) {
            case 1:
                currentDrink = std::make_shared<Espresso>();
                displayCurrentDrink(currentDrink);
                break;
            case 2:
                currentDrink = std::make_shared<Latte>();
                displayCurrentDrink(currentDrink);
                break;
            case 3:
                currentDrink = std::make_shared<GreenTea>();
                displayCurrentDrink(currentDrink);
                break;
            case 4:
                if (currentDrink) {
                    currentDrink = std::make_shared<Sugar>(std::move(currentDrink));
                }
                displayCurrentDrink(currentDrink);
                break;
            case 5:
                if (currentDrink) {
                    currentDrink = std::make_shared<Milk>(std::move(currentDrink));
                }
                displayCurrentDrink(currentDrink);
                break;
            case 6:
                if (currentDrink) {
                    currentDrink = std::make_shared<WhippedCream>(std::move(currentDrink));
                }
                displayCurrentDrink(currentDrink);
                break;
            case 7:
                if (currentDrink) {
                    currentDrink = std::make_shared<Caramel>(std::move(currentDrink));
                }
                displayCurrentDrink(currentDrink);
                break;
            case 8:
                if (currentDrink) {
                    currentDrink = std::make_shared<Vanilla>(std::move(currentDrink));
                }
                displayCurrentDrink(currentDrink);
                break;
            case 9:
                saveCurrentDrink(currentDrink);
                displayOrder();
                break;
            case 10:
                saveCurrentDrink(currentDrink);
                return;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        }
    }

    double getTotalCost() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item->cost();
        }
        return total;
    }

    void clearOrder() {
        items.clear();
    }

    bool isEmpty() const {
        return items.empty();
    }

    void removeItem(std::size_t index) {
        if (index < items.size()) {
            items.erase(items.begin() + static_cast<std::ptrdiff_t>(index));
        }
    }

    void displayOrder() const {
        if (items.empty()) {
            std::cout << "Order is empty.\n";
            return;
        }

        std::cout << "Order items:\n";
        for (const auto& item : items) {
            std::cout << "- " << item->getDescription()
                      << " ($" << item->cost() << ")\n";
        }
        std::cout << "Total: $" << getTotalCost() << '\n';
    }
};
