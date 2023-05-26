#include <iostream>
#include <array>
#include "pallet.hpp"
#pragma once

class Shelf{
    public:
        std::array<Pallet, 4> pallets;
        Shelf();
        bool swapPallet(int slot, int slot2);
        std::array<bool, 4> getSlotStatus();
        bool removePallet(int slot);
        bool insertPallet(int slot, Pallet pallet);
        bool isEmpty();
};
