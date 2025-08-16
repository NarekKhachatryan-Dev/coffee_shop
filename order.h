#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

class Order {
private:
    std::vector<std::string> items;

public:
    Order();
    void addItem(const std::string& item) {
        items.push_back(item);
    }
    void clearOrder() {
        items.clear();
    }
    bool isEmpty() const {
        return items.empty();
    }
    void removeItem(const std::string& item) {
        auto it = std::remove(items.begin(), items.end(), std::string(item));
        if (it != items.end()) {
            items.erase(it, items.end());
        }
    }
    void displayOrder() const {
        if (items.empty()) {
            std::cout << "Order is empty." << std::endl;
        } else {
            std::cout << "Order items:" << std::endl;
            for (const auto& item : items) {
                std::cout << "- " << item << std::endl;
            }
        }
    }


};