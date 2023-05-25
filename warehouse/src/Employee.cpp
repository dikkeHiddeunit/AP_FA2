#include <iostream>
#include <string>
#include "include/employee.hpp"

Employee::Employee(std::string name, bool forkliftCertificate) : name(name), forkliftCertificate(forkliftCertificate) {
    busy = false;
}

std::string Employee::getName() {
    return name;
}

bool Employee::getBusy() {
    return busy;
}

void Employee::setBusy(bool busy) {
    this->busy = busy;
}

bool Employee::getForkliftCertificate() {
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}