#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <vector>

void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "\nCurrent Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> inventory;
    std::set<std::string> productCategories;
    std::queue<std::string> orders;
    std::stack<std::pair<std::string, int>> restocks;
    std::vector<std::string> customerCart;

    // Initialization of inventory
    inventory["Pencil HB"] = 50;
    inventory["Eraser Pelikan"] = 40;
    inventory["Paper A4"] = 100;
    inventory["Glue"] = 20;
    inventory["Rule 30cm"] = 35;
    inventory["Paper A3"] = 40;
    inventory["Color Pens"] = 120;
    inventory["Color Pencils"] = 25;
    inventory["Markers"] = 30;
    inventory["Calculator"] = 15;
    
    displayInventory(inventory);

    // Initialization of cathegories
    productCategories.insert("Drawing and Picturing Products");
    productCategories.insert("Geometric Accessories");
    productCategories.insert("All Size Papers");
    productCategories.insert("Computing Machines");
    productCategories.insert("Glues");

    std::cout << "Product Categories:\n";
    for (const auto& category : productCategories) {
        std::cout << "- " << category << "\n";
    }

    // Adding products from the inventory
    int numProducts;
    std::cout << "\nHow many products do you want to add? ";
    std::cin >> numProducts;
    std::cin.ignore(); // Clean buffer

    for (int i = 0; i < numProducts; ++i) {
        std::string productName;
        int quantity;
        std::cout << "Enter product name: ";
        std::getline(std::cin, productName);
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cin.ignore();
        inventory[productName] = quantity;
    }

    displayInventory(inventory);

    // Adding orders of the user
    int numOrders;
    std::cout << "\nHow many orders do you want to place? ";
    std::cin >> numOrders;
    std::cin.ignore();

    for (int i = 0; i < numOrders; ++i) {
        std::string order;
        std::cout << "Enter product to order: ";
        std::getline(std::cin, order);
        orders.push("Order: " + order);
    }

    // Processing orders
    while (!orders.empty()) {
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    }

    // Adding products to your cart
    int numCartItems;
    std::cout << "\nHow many items do you want to add to your cart? ";
    std::cin >> numCartItems;
    std::cin.ignore();

    for (int i = 0; i < numCartItems; ++i) {
        std::string item;
        std::cout << "Enter item to add to cart: ";
        std::getline(std::cin, item);
        customerCart.push_back(item);
    }

    std::cout << "\nItems in customer cart:\n";
    for (const auto& item : customerCart) {
        std::cout << "- " << item << "\n";
    }

    return 0;
}
