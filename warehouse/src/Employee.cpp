#include <string>
#include <iostream>
#include "include/employee.hpp"


Employee::Employee(std::string name, bool forkliftCertificate) : name(name), forkliftCertificate(forkliftCertificate) {
    busy = false;  // Stel de standaardwaarde voor busy in op false
}

std::string Employee::getName() const {
    return name;  // Retourneer de naam van de werknemer
}

bool Employee::getBusy() const {
    return busy;  // Retourneer de huidige status van buys
}

void Employee::setBusy(bool busy) {
    this->busy = busy;  // Stel de status van busy in op de opgegeven waarde
}

bool Employee::getForkliftCertificate() const {
    return forkliftCertificate;  // Retourneer de waarde van forliftcertificate
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;  // Stel de waarde van forkliftCertificate in
}

bool operator==(const Employee& lhs, const Employee& rhs) {
    return (lhs.getName() == rhs.getName()) && (lhs.getForkliftCertificate() == rhs.getForkliftCertificate());  // Vergelijk de namen en forkliftcertificaten van beide werknemers
}