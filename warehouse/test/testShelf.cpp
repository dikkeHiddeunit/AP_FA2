#include <iostream>
#include "../src/include/pallet.hpp"
#include "../src/include/warehouse.hpp"
#include "../src/include/shelf.hpp"
#include "../src/include/employee.hpp"
#include "../test/include/catch.hpp"
#define CATCH_CONFIG_MAIN

TEST_CASE("Swap Pallets") {
    Shelf testShelf; // maakt een shelf aan voor de test
    Pallet pallet1("Item1", 50, 10); // maakt pallet1 aan
    Pallet pallet2("Item2", 50, 20); // maakt pallet2 aan
    Pallet pallet3("Item3", 50, 30); // maakt pallet3 aan

    // voegt de 3 pallets toe aan 'testShelf"
    testShelf.insertPallet(0, pallet1); 
    testShelf.insertPallet(1, pallet2);
    testShelf.insertPallet(2, pallet3);

    // kijkt of de waarden van swappallet overeen komt met de verwachte waarde
    REQUIRE(testShelf.swapPallet(0, 2) == true);
}

TEST_CASE("Remove Pallet") {
    Shelf testShelf; // maakt een testshelf aan
    Pallet pallet("Item", 50, 10); // maakt een testpallet aan
    testShelf.insertPallet(0, pallet); // voegt de testpallet toe aan de shelf op positie 0
    std::array<bool, 4> updatedSlotStatus = testShelf.getSlotStatus();
    // Controleer of de status van sleuf 0 overeenkomt met 'false'
    REQUIRE(updatedSlotStatus[0] == false);
}

TEST_CASE("Insert Pallet") {
    Shelf testShelf; // maakt een shelf aan voor de test
    Pallet pallet("Item", 50, 10); // maakt een pallet aan voor de test
    REQUIRE(testShelf.insertPallet(0, pallet) == true); //voegt de testpllate toe aan shelf op positie 0 en kijkt of dit is gelukt
}