#include "include/shelf.hpp"
#include <iostream>

Shelf::Shelf() : pallets(std::array<Pallet, 4>{}) {}

bool Shelf::swapPallet(int slot, int slot2) {
    if (slot < 0 || slot >= 4 || slot2 < 0 || slot2 >= 4) {
        return false;  // Retourneer false zodra het slot ongeldig is
    }

    Pallet& pallet1 = pallets[slot];
    Pallet& pallet2 = pallets[slot2];

    std::swap(pallet1, pallet2);  // Wisseld de pallets van positie

    return true;  // Retourneer true om aan te geven dat de wisseling is gelukt
}

std::array<bool, 4> Shelf::getSlotStatus() {
    std::array<bool, 4> slotStatus;

    for (int i = 0; i < 4; i++) {
        slotStatus[i] = (pallets[i].getItemCount() > 0);  // Controleer of elk slot bezet
    }

    return slotStatus;  // Retourneer een array met de status van elk slot
}

bool Shelf::removePallet(int slot) {
    if (slot < 0 || slot >= 4) {
        return false;  // Retourneer false voor een ongeldig slot
    }

    if (pallets[slot].getItemCount() == 0) {
        return false;  // Retourneer false als het palletslot al leeg is
    }

    pallets[slot] = Pallet();  // Maak het slot leeg door een nieuwe lege pallet toe te wijzen

    return true;  // Retourneer true om aan te geven dat het pallet verwijderen is gelukt 
}

bool Shelf::insertPallet(int slot, Pallet pallet) {
    if (slot < 0 || slot >= 4) {
        return false;  // Retourneer false voor een ongeldig slot
    }

    if (pallets[slot].getItemCount() > 0) {
        return false;  // Retourneer false als het slot al bezet is
    }
    return true;  // Retourneer true om aan te geven dat de pallet invoegen is gelukt
}

