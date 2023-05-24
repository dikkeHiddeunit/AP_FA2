#include <iostream>
#include "src/include/pallet.hpp"

int testPallet(){
// Test Pallet met opgegeven parameters
    Pallet pallet1("Brabante worste broodjes", 25, 8);

    std::cout << "Product naam =  " << pallet1.getItemName() << std::endl;
    std::cout << "Hoeveelheid = " << pallet1.getItemCount() << std::endl;
    std::cout << "Overige plaatsen = " << pallet1.getRemainingSpace() << std::endl;

    pallet1.takeOne();
    std::cout << "Na het pakken afnemen van 1 broodje: hoeveelheid = " << pallet1.getItemCount() << std::endl;

    pallet1.putOne();
    std::cout << "Na het pakken toevoegen van 1 broodje: hoeveelheid = " << pallet1.getItemCount() << std::endl;

    // Test Pallet zonder opgegeven parameters
    Pallet pallet2;

    std::cout << "Product naam = " << pallet2.getItemName() << std::endl;
    std::cout << "Hoeveelheid = " << pallet2.getItemCount() << std::endl;
    std::cout << "Overige plaatsen = " << pallet2.getRemainingSpace() << std::endl;

    pallet2.ReallocateEmptyPallet("Limburgse vlaai", 8);
    std::cout << "Na het her lokaliseren: " << pallet2.getItemName() << ", overige plaatsen: " << pallet2.getRemainingSpace() << std::endl;
}





int main() {
    testPallet();

    return 0;
}