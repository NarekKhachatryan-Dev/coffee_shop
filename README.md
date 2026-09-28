# Coffee Shop

A small C++ coffee shop order application demonstrating the Decorator design pattern.

## Features

- Espresso, Latte, and Green Tea beverages.
- Milk, Sugar, Whipped Cream, Caramel, and Vanilla decorators.
- Interactive order menu.
- Multiple add-ons can be applied to one beverage.
- Order description and total cost are calculated through the `Beverage` interface.
- Invalid numeric input is handled without terminating the program.

## Project Files

- `Beverage.h` - base beverage interface and concrete beverages.
- `Decorators.h` - beverage decorator interface and add-ons.
- `order.h` - interactive order management and total calculation.
- `main.cpp` - application entry point.
- `Makefile` - build and clean commands.

## Requirements

- A C++ compiler with C++20 support.
- GNU Make, if using the Makefile.

## Build

Using Make:

```bash
make
```

Or directly with `g++`:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o coffee_shop
```

## Run

```bash
./coffee_shop
```

## Menu

1. Espresso
2. Latte
3. Green Tea
4. Sugar
5. Milk
6. Whipped Cream
7. Caramel
8. Vanilla
9. Add current drink to order
10. Finish order

Choose a base beverage before selecting an add-on. For example:

```text
1 -> Espresso
5 -> Milk
7 -> Caramel
9 -> Add current drink to order
10 -> Finish order
```

The result is:

```text
Espresso, Milk, Caramel ($1.8)
Total: $1.8
```

## Clean Build Files

```bash
make clean
```

## Design Pattern

The project uses the Decorator pattern:

```text
Espresso
  + Milk
    + Caramel
```

Each decorator wraps a `std::shared_ptr<Beverage>`, adds its own price, and extends the beverage description.
