#include <iostream>
#include "../src/include/pallet.hpp"
#include "../src/include/warehouse.hpp"
#include "../src/include/shelf.hpp"
#include "../src/include/employee.hpp"
#include "../test/include/catch.hpp"
#define CATCH_CONFIG_MAIN


TEST_CASE("Get Item Name") {
    Pallet testPallet = Pallet("Limburgse vlaai", 50, 20); // aanmaken object "pallet" 
    REQUIRE(testPallet.getItemName() == "Limburgse vlaai"); // verkrijgt de naam van het item in pallet
}

TEST_CASE("Get Item Count") {
    Pallet testPallet = Pallet("Limburgse vlaai", 50, 20); // aanmaken object "pallet"
    REQUIRE(testPallet.getItemCount() == 20); //verkrijgt de hoeveelheid aanwezige items op pallet
}

TEST_CASE("Get Remaining Space") {
    Pallet testPallet = Pallet("Limburgse vlaai", 50, 20); // aanmaken object "pallet"
    REQUIRE(testPallet.getRemainingSpace() == 30); // verkrijgt het aantal overige plekken op pallet
}

TEST_CASE("Reallocate Empty Pallet") {
    Pallet testPallet = Pallet("Limburgse vlaai", 50, 1); // aanmaken object "pallet"
    REQUIRE(testPallet.ReallocateEmptyPallet("Limburgse vlaai", 50, 1) == false); // probeerd pallet te verplaatsen, kan niet want de pallet is niet leeg

    testPallet.takeOne(); // pakt het laatste item van de pallet
    REQUIRE(testPallet.ReallocateEmptyPallet("Brabants worstebroodje", 100, 0) == true); // verplaatst te pallet
    REQUIRE(testPallet.getRemainingSpace() == 100); // verkrijgt het aantal overige plekken (deze keer op een lege pallet)
}

TEST_CASE("Take Item off of a semi-full Pallet") {
    Pallet testPallet1 = Pallet("Limburgse vlaai", 50, 46); // aanmaken object "pallet1"
    Pallet testPallet2 = Pallet("Brabants worstebroodje", 50, 18); // aanmaken object "pallet1"

    REQUIRE(testPallet1.takeOne()); // neemt 1 item van pallet1
    REQUIRE(testPallet2.takeOne()); // neemt 1 item van pallet2
    REQUIRE(testPallet2.takeOne()); // neemt nogmaals een item van pallet2

    //checkt of de verwachte waardes overeenkomen
    REQUIRE(testPallet1.getItemCount() == 45);
    REQUIRE(testPallet2.getItemCount() == 16);
}

TEST_CASE("Put Item on a semi-empty Pallet") {
    Pallet testPallet1 = Pallet("Limburgse vlaai", 50, 2); // aanmaken object "pallet1"
    Pallet testPallet2 = Pallet("Brabants worstebroodje", 50, 5); // aanmaken object "pallet1"

    REQUIRE(testPallet1.putOne());// voegt 1 item toe aan pallet1
    REQUIRE(testPallet2.putOne());// voegt 1 item toe aan pallet1
    REQUIRE(testPallet2.putOne());// voegt nogmaals een item toe aan pallet2

    //checkt of de verwachte waardes overeenkomen
    REQUIRE(testPallet1.getItemCount() == 3);
    REQUIRE(testPallet2.getItemCount() == 7);
}