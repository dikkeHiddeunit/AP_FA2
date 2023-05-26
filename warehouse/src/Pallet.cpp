#include <iostream>
#include "include/pallet.hpp"

// Pallet met alle waarden
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}

// Standaard contructor
Pallet::Pallet() {
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;
}

// Verkrijgt de naam van een item op de een pallet
const std::string Pallet::getItemName() {
    return itemName;
}

// kijkt hoeveel intems er op de pallet staan
const int Pallet::getItemCount() {
    return itemCount;
}

// Kijkt hoeveel plek er nog over is op de pallet
const int Pallet::getRemainingSpace() {
    return itemCapacity - itemCount;
}

// Zodra een pallet leeg is reset hij de waarden waardoor de pallet als nieuw is
bool Pallet::ReallocateEmptyPallet(std::string itemName, int itemCapacity, int itemCount) {
    if (itemCount == 0) {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
    return false;
}

// Pakt een item van de pallet
bool Pallet::takeOne() {
    if (itemCount > 0) {
        itemCount--;
        return true;
    }
    return false;
}

// Voegt een item toe aan de pallet
bool Pallet::putOne() {
    if (itemCount < itemCapacity) {
        itemCount++;
        return true;
    }
    return false;
}

// Maakt te pallet leeg
bool Pallet::isEmpty() {
    return (itemCount == 0);
}