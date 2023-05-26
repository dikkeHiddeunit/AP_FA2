#include "include/shelf.hpp"
#include <iostream>

Shelf::Shelf() : pallets(std::array<Pallet, 4>{}) {}

bool Shelf::swapPallet(int slot, int slot2) {
    if (slot < 0 || slot >= 4 || slot2 < 0 || slot2 >= 4) {
        return false;  // Ongeldige slots
    }

    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;

    return true;
}

std::array<bool, 4> Shelf::getSlotStatus() {
    std::array<bool, 4> slotStatus;

    for (int i = 0; i < 4; i++) {
        slotStatus[i] = (pallets[i].getItemCount() > 0);
    }

    return slotStatus;
}

bool Shelf::removePallet(int slot) {
    if (slot < 0 || slot >= 4) {
        return false;  // Ongeldig slot
    }

    if (pallets[slot].getItemCount() == 0) {
        return false;  // Pallet is al leeg
    }

    // Optioneel: Voer hier aanvullende logica uit om de pallet te verwijderen

    return true;
}

bool Shelf::insertPallet(int slot, Pallet pallet) {
    if (slot < 0 || slot >= 4) {
        return false;  // Ongeldig slot
    }

    if (pallets[slot].getItemCount() > 0) {
        return false;  // Slot is al bezet
    }

    // Optioneel: Voer hier aanvullende logica uit om de pallet in te voegen

    return true;
}

