EducatorPartyMember::EducatorPartyMember() {}
EducatorPartyMember::EducatorPartyMember(const String& name, int birthYear, const String& specialty,
    const String& partyName, const String& partyRole)
    : Educator(name, birthYear, specialty), PartyMember(name, birthYear, partyName), partyRole(partyRole) {}

EducatorPartyMember::EducatorPartyMember(const char* name, int birthYear, const char* specialty,
    const char* partyName, const char* partyRole)
    : Educator(name, birthYear, specialty), PartyMember(name, birthYear, partyName), partyRole(partyRole) {}

EducatorPartyMember::~EducatorPartyMember() {}

String EducatorPartyMember::getPartyRole() const {
    return partyRole;
}

void EducatorPartyMember::setPartyRole(const String& partyRole) {
    this->partyRole = partyRole;
}

void EducatorPartyMember::setName(const String& name) {
    Educator::setName(name);
}

void EducatorPartyMember::setBirthYear(int birthYear) {
    Educator::setBirthYear(birthYear);
}

std::ostream& operator<<(std::ostream& os, const EducatorPartyMember& educatorPartyMember) {

    os << static_cast<const Educator&>(educatorPartyMember);
    os << std::setw(20) << educatorPartyMember.getPartyName();
    os << std::setw(15) << educatorPartyMember.partyRole;
    return os;
}

std::istream& operator>>(std::istream& is, EducatorPartyMember& educatorPartyMember) {

    is >> static_cast<Educator&>(educatorPartyMember);
    std::cout << "Enter the name of party: ";
    String partyName;
    partyName = input_string(is);
    educatorPartyMember.setPartyName(partyName);
    std::cout << "Enter party role: ";
    educatorPartyMember.partyRole = input_string(is);
    return is;
}

void EducatorPartyMember::classView() {

    std::cout << std::setw(25) << "Name"
        << std::setw(15) << "BirthYear"
        << std::setw(20) << "Specialty"
        << std::setw(20) << "PartyName"
        << std::setw(15) << "PartyRole"
        << std::endl;

}

