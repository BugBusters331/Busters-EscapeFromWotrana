#pragma once

#include <map>
#include <string>

class InventoryManager {
private:
    std::map<std::string, int> items;

    static std::string normalizeName(std::string name);

public:
    bool addItem(const std::string& name, int quantity = 1);
    bool removeItem(const std::string& name, int quantity = 1);

    bool hasItem(const std::string& name, int quantity = 1) const;
    int getQuantity(const std::string& name) const;

    void displayInventory() const;
};