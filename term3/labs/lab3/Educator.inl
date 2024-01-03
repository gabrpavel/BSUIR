Educator::Educator() {}

Educator::Educator(const String& name, int birthYear, const String& specialty)
    : Human(name, birthYear), specialty(specialty) {}

Educator::Educator(const char name[], int birthYear, const char specialty[])
    : Human(name, birthYear), specialty(specialty) {}

Educator::~Educator() {}

void Educator::setName(String name) {
    this->name = name;
}

void Educator::setBirthYear(int birthYear) {
    this->birthYear = birthYear;
}

String Educator::getSpecialty() const {
    return specialty;
}

void Educator::setSpecialty(const String& specialty) {
    this->specialty = specialty;
}

void Educator::setSpecialty(const char* specialty) {
    this->specialty = (String)specialty;
}

Educator& Educator::operator =(const Educator& other) {

    if (this != &other) {
        static_cast<Human&>(*this) = other;
        this->setSpecialty(other.getSpecialty());
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Educator& educator) {

    os << static_cast<const Human&>(educator);
    os << std::setw(20) << educator.specialty;
    return os;
}

std::istream& operator>>(std::istream& is, Educator& educator) {

    is >> static_cast<Human&>(educator);
    std::cout << "Enter specialty: ";
    educator.specialty = input_string(is);
    return is;
}

bool Educator::operator ==(const Educator& other) const {
    if (this->name != other.name) return false;
    else if (this->birthYear != other.birthYear) return false;
    else if (this->specialty != other.specialty) return false;
    else return true;
}

void Educator::classView() {

    std::cout << std::setw(25) << "Name"
        << std::setw(15) << "BirthYear"
        << std::setw(20) << "Specialty" << std::endl;

}