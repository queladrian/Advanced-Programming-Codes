#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

#include "../libs/CLI11/CLI11.hpp"

int main(int argc, char** argv) {
    CLI::App app{"Retail Analytics"};

    std::string file = "data/OnlineRetail.csv";
    std::string country_filter;
    bool only_uk = false;

    app.add_option("-f,--file", file, "CSV file");
    app.add_option("-c,--country", country_filter, "Country filter");
    app.add_flag("--only-uk", only_uk, "Calculate only UK");

    CLI11_PARSE(app, argc, argv);

    std::ifstream fin(file);
    if (!fin.is_open()) {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    std::string line;
    std::getline(fin, line); // skip header

    std::unordered_map<std::string, int> tx_count;
    double total_amount = 0.0;

    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string token;
        std::string cols[8];
        int i = 0;
        while (std::getline(ss, token, ',') && i < 8) {
            cols[i++] = token;
        }

        std::string country = cols[7];
        int quantity = std::stoi(cols[3]);
        double price = std::stod(cols[5]);
        double amount = quantity * price;

        if (country_filter.empty() || country == country_filter) {
            tx_count[country]++;
        }
        if (!only_uk || country == "United Kingdom") {
            total_amount += amount;
        }
    }

    if (!country_filter.empty()) {
        std::cout << "Transactions in " << country_filter << ": " << tx_count[country_filter] << "\n";
    } else {
        std::cout << "Transactions per country:\n";
        for (auto& [c, n] : tx_count) {
            std::cout << c << ": " << n << "\n";
        }
    }

    std::cout << "Total amount" << (only_uk ? " (UK only)" : "") << ": " << total_amount << "\n";

    return 0;
}
