#include "include/shelf.hpp"
#include <algorithm>
#include "include/Warehouse.hpp"

Warehouse::Warehouse() : Employees(std::vector<Employee>{}), shelves(std::vector<Shelf>{}) {}

void Warehouse::addEmployee(Employee employee) {
    if (std::find(Employees.begin(), Employees.end(), employee) == Employees.end()) {
        Employees.push_back(employee);  // Voeg de werknemer toe aan de lijst van werknemers als deze nog niet bestaat
    }
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);  // Voeg de plank toe aan de lijst van shelves
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    auto it = std::find_if(Employees.begin(), Employees.end(), [](const Employee& employee) {
        return employee.getForkliftCertificate() && !employee.getBusy();
    });  // Zoek naar een beschikbare werknemer met een heftruckcertificaat

    if (it == Employees.end()) {
        return false;
        }

    Employee& availableEmployee = *it;
    availableEmployee.setBusy(true);  // Markeer de werknemer als bezet

    bool changesMade = true;
    while (changesMade) {
        changesMade = false;

        for (size_t i = 1; i < shelf.pallets.size(); i++) {
            if (shelf.pallets[i].getItemCount() < shelf.pallets[i - 1].getItemCount()) {
                shelf.swapPallet(i, i - 1);
                changesMade = true;  // Wissel van plaats als het aantal items op een pallet kleiner is dan de voorgaande pallet
            }
        }
    }

    availableEmployee.setBusy(false);  // Geef de werknemer de status 'niet bezet'

    return true;  // Retourneer true om aan te geven dat de verandering is gelukt
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    std::vector<Pallet*> pallets;
    int availableItems = 0;
    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName && pallet.getItemCount() > 0) {
                pallets.push_back(&pallet);  // Voeg de pallet toe aan de lijst van pallets als deze overeenkomt met het item en items heeft
                availableItems += pallet.getItemCount();  // Telt het aantal beschikbare items 
            }
        }
    }
    if (availableItems < itemCount) {
        return false;  // Niet genoeg beschikbare items om op te halen, retourneer false
    }
    int itemsRemaining = itemCount;
    for (Pallet* x : pallets) {
        while (itemsRemaining > 0 && x->getItemCount() > 0) {
            x->takeOne();  // Haal 1 item van de pallet af
            itemsRemaining--;  // Verlaag het aantal nog op de pallet aanwezige items
        }
    }
    return true;  // Alle items zijn succesvol opgehaald, retourneer true
}