#include "include/shelf.hpp"
#include <algorithm>
#include "include/Warehouse.hpp"

Warehouse::Warehouse() : Employees(std::vector<Employee>{}), shelves(std::vector<Shelf>{}) {}

void Warehouse::addEmployee(Employee employee) {
    if (std::find(Employees.begin(), Employees.end(), employee) == Employees.end()) {
        Employees.push_back(employee);
    }
}

void Warehouse::addShelf(Shelf& shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    Employee* availableEmployee = nullptr;

    for (unsigned int x = 0; x < Employees.size(); x++) {
        if (Employees[x].getForkliftCertificate() && !Employees[x].getBusy()) {
            availableEmployee = &Employees[x];
            break;
        }
    }

    if (availableEmployee == nullptr) {
        return false;
    }

    availableEmployee->setBusy(true);

    while (true) {
        unsigned int count = 0;

        for (unsigned int x = 1; x < shelf.pallets.size(); x++) {
            if (shelf.pallets[x].getItemCount() < shelf.pallets[x - 1].getItemCount()) {
                shelf.swapPallet(x, x - 1);
                break;
            }
            count++;
        }

        if (count == shelf.pallets.size() - 1) {
            break;
        }
    }

    availableEmployee->setBusy(false);

    return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    std::vector<Pallet*> pallets;
    int availableItems = 0;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName && pallet.getItemCount() > 0) {
                pallets.push_back(&pallet);
                availableItems += pallet.getItemCount();
            }
        }
    }

    if (availableItems < itemCount) {
        return false;
    }

    int itemsRemaining = itemCount;

    for (Pallet* x : pallets) {
        while (itemsRemaining > 0 && x->getItemCount() > 0) {
            x->takeOne();
            itemsRemaining--;
        }
    }

    return true;
}