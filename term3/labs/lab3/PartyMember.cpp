#include "PartyMember.h"

PartyMember::PartyMember() {}

PartyMember::PartyMember(const String& name, int birthYear, const String& partyName)
    : Human(name, birthYear), partyName(partyName) {}

PartyMember::PartyMember(const char* name, int birthYear, const char* partyName)
    : Human(name, birthYear), partyName(partyName) {}

PartyMember::~PartyMember() {}

String PartyMember::getPartyName() const {
    return partyName;
}

void PartyMember::setPartyName(const String& partyName) {
    this->partyName = partyName;
}

void PartyMember::addBiographyEntry(const String& entry) {
    biography.push_back(entry);
}

std::vector<String> PartyMember::getBiography() const {
    return biography;
}

void PartyMember::viewBiography() {

    for (const auto& element : this->biography) // range-based for loop
        std::cout << element << std::endl;
    std::cout << std::endl;
}

PartyMember& PartyMember::operator =(PartyMember& other) {

    static_cast<Human&>(*this) = static_cast<Human&>(other);
    this->setPartyName(other.getPartyName());
    this->biography = other.getBiography();

    return *this;
}


std::ostream& operator<<(std::ostream& os, const PartyMember& partyMember) {

    os << static_cast<const Human&>(partyMember);
    os << std::setw(20) << partyMember.partyName;
    return os;
}

std::istream& operator>>(std::istream& is, PartyMember& partyMember) {

    is >> static_cast<Human&>(partyMember);
    std::cout << "Enter the name of party: ";
    partyMember.partyName = input_string(is);
    return is;
}

