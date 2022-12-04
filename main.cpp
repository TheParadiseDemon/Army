#include <bits/stdc++.h>
#include "ARMYINFO.h"

class Soldier;
class Private;
class Officer;
class Sergant;
class WarrantOfficer;

typedef std::string ARRAYFORSUBJECTS[][1];
typedef std::string ARRAYFORRULES[][4];

class Soldier{

public:

    Rank rank;
    MilitaryUnit militaryunit;
    std::pair<MilitarySpecialization, Post> MOS; //Военнно-учётная специальность

    virtual bool operator==(const Soldier a) const{
        return this->MOS.second == a.MOS.second;
    }

    virtual bool operator<(const Soldier a) const{
        return this->MOS.second < a.MOS.second;
    }

    virtual bool operator>(const Soldier a) const{
        return this->MOS.second > a.MOS.second;
    }

};

class Officer: public Soldier{

};

class Sergant: public Soldier{

};

class Privat: public Soldier{

};

class WarrantOfficer: public Soldier{

};

int main() {

    return 0;
}
