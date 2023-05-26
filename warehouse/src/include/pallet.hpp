#include <iostream>
#include <string>
#pragma once

class Pallet{
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;

    public:
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
        const std::string getItemName();
        const int getItemCount();
        const int getRemainingSpace();
        bool ReallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();
        bool isEmpty();     
};
