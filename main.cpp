#include "Decorators.h"
#include "order.h"

#include <iostream>

int main() {
	std::cout << "Welcome to the Coffee Shop!\n";
	std::cout << "Please select your drinks and add-ons.\n";

	Order order;
	order.start();
	order.displayOrder();
	std::cout << "Total cost: $" << order.getTotalCost() << '\n';
}
