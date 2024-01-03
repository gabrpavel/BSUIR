#include "Educator.h"
#include "PartyMember.h"

class EducatorPartyMember : public Educator, public PartyMember {

    String partyRole;

public:

    EducatorPartyMember();
    EducatorPartyMember(const String& name, int birthYear, const String& specialty,
                        const String& partyName, const String& partyRole);
    EducatorPartyMember(const char* name, int birthYear, const char* specialty,
                        const char* partyName, const char* partyRole);
    virtual ~EducatorPartyMember();

    String getPartyRole() const;
    void setPartyRole(const String& partyRole);
    void setName(const String& name);
    void setBirthYear(int birthYear);

    friend std::ostream& operator<<(std::ostream& os, const EducatorPartyMember& educatorPartyMember);
    friend std::istream& operator>>(std::istream& is, EducatorPartyMember& educatorPartyMember);

    static void classView();
};

#include "../lab3/EducatorPartyMember.inl"