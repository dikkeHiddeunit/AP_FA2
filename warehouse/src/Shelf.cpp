#include "include/shelf.hpp"
#include <iostream>

// Standaard contructor
Shelf::Shelf() {
}

// Verwisseld twee pallets met elkaars positie
bool Shelf::swapPallet(int slot, int slot2) {
  if (slot < 0 && slot >= 4 && slot2 < 0 && slot2 >= 4) 
  {
    return false;
  }
  std::swap(pallets[slot], pallets[slot2]);
  return true;
}