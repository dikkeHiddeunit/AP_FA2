#include <iostream>
#include "../src/include/pallet.hpp"
#include "../src/include/warehouse.hpp"
#include "../src/include/shelf.hpp"
#include "../src/include/employee.hpp"
#include "../test/include/catch.hpp"
#define CATCH_CONFIG_MAIN

TEST_CASE("Employee Equality") {
    Employee employee1("Jaap Koops", true);  // maak een werknemer aan 
    Employee employee2("Jaap Koops", true);  // maak een andere werknemer (eigenlijk dezelfde)
    Employee employee3("Jane Smith", false); // maak totaal andere werknemer aan

    REQUIRE(employee1 == employee2);        // controleer of employee1 gelijk is aan employee2 (verwacht: true)
    REQUIRE_FALSE(employee1 == employee3);  // controleer of employee1 niet gelijk is aan employee3 (verwacht: false)
    REQUIRE_FALSE(employee2 == employee3);  // controleer of employee2 niet gelijk is aan employee3 (verwacht: false)
}

TEST_CASE("Get Employee Name") {
    Employee employee("John Doe", true);     // maak een werknemer aan 
    REQUIRE(employee.getName() == "John Doe");  // controleer of de naam van de werknemer overeenkomt met "John Doe"
}

TEST_CASE("Get Employee Busy Status") {
    Employee employee("John Doe", true);     // maak een werknemer aan 
    REQUIRE_FALSE(employee.getBusy());       // controleer of de werknemer niet bezet is

    employee.setBusy(true);                  // past de status van de werknemer aan naar bezet
    REQUIRE(employee.getBusy());             // controleer of de werknemer nu bezet is
}

TEST_CASE("Get Employee Forklift Certificate") {
    Employee employee("John Doe", true);     // maak een werknemer
    REQUIRE(employee.getForkliftCertificate());  // controleer of de werknemer een heftruckcertificaat heeft

    employee.setForkliftCertificate(false);   // stelt in dat de werknemer geen heftruckcertificaat heeft
    REQUIRE_FALSE(employee.getForkliftCertificate());  // controleer of de werknemer een heftruckcertificaat heeft
}