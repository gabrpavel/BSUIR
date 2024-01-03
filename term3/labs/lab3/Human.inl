Human::Human() : name(), birthYear(0) {}

Human::Human(const String& name, int birthYear) : name(name), birthYear(birthYear) {}

Human::Human(const char name[], int birthYear) : name(name), birthYear(birthYear) {}

Human::~Human() {}

String Human::getName() const {
    return name;
}

int Human::getBirthYear() const {
    return birthYear;
}

void Human::setName(const String& name) {
    this->name = name;
}

void Human::setName(const char* name) {
    this->name = (String)name;
}

void Human::setBirthYear(int birthYear) {
    this->birthYear = birthYear;
}

Human& Human::operator =(const Human& other) {

    if (this != &other) {
        this->birthYear = other.birthYear;
        this->name = other.name;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Human& human) {

    os << std::setw(25) << human.name << std::setw(15) << human.birthYear;
    return os;
}

std::istream& operator>>(std::istream& is, Human& human) {

    std::cout << "Enter name: ";
    human.name = input_string(is);
    std::cout << "Enter birth year: ";
    human.birthYear = input_int(is);
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка входного буфера (is) от лишних символов после считывания данных в переменные human.name и human.birthYear
    return is;
}

void Human::classView() {

    std::cout << std::setw(25) << "Name" << std::setw(10) << "birthYear" << std::endl;

}