#include "Human.h"


class Educator : public Human {

    String specialty;

public:

    Educator();
    Educator(const String& name, int birthYear, const String& specialty);
    Educator(const char name[], int birthYear, const char specialty[]);
    virtual ~Educator();

    void setName(String name);
    void setBirthYear(int birthYear);
 
    String getSpecialty() const;
    void setSpecialty(const String& specialty);
    void setSpecialty(const char* specialty);

    Educator& operator=(const Educator& other);
    friend std::ostream& operator<<(std::ostream& os, const Educator& human);
    friend std::istream& operator>>(std::istream& is, Educator& educator);
    bool operator ==(const Educator& other) const;

    static void classView();
};

#include "../lab3/Educator.inl"