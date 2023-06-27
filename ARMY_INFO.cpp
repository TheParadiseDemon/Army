#include "ARMY_INFO.h"

 const Rank operator++(Rank& rank, int){
    Rank prev = rank;
    rank = static_cast<Rank>(rank + 1);
    return prev;
}

MilitaryUnit::MilitaryUnit(int militaryDivisionNumber,
                           char militaryDivisionLettter,
                           int battalion,
                           int company,
                           int platoon,
                           int squad) {
    this->militaryDivision.second = militaryDivisionLettter;
    this->militaryDivision.first = (militaryDivisionNumber);
    this->battalion = (battalion);
    this->platoon = (platoon);
    this->company = (company);
    this->squad = (squad);
}

MilitaryUnit::MilitaryUnit(){
        this->militaryDivision.second = 'A';
        this->militaryDivision.first = 1;
        this->battalion = 1;
        this->platoon = 1;
        this->company = 1;
        this->squad = 1;
}

    bool Soldier::operator==(Soldier* a){
        return this->MOS.second == a->MOS.second;
    }

    bool Private::operator==(Soldier* a){
        return this->rank == a->rank;
    }

    bool Soldier::operator<(Soldier* a) {
        return this->MOS.second < a->MOS.second;
    }

    bool Private::operator<(Soldier* a){
        return this->rank < a->rank;
    }

    bool Soldier::operator>(Soldier* a) {
        return this->MOS.second > a->MOS.second;
    }

    bool Private::operator>(Soldier* a){
        return this->rank > a->rank;
    }

    void Soldier::Promotion(){
        this->rank++;
    }

    Soldier::Soldier(){
    this->rank = Rank::privat;
    this->MOS.first = MilitarySpecialization::driver;
    this->MOS.second = Post::without_any_position;
    this->militaryunit = MilitaryUnit();
    }

    Soldier::Soldier(Rank ranks, MilitaryUnit militaryunits, std::pair<MilitarySpecialization, Post> MOSes){
        rank = ranks;
        militaryunit = militaryunits;
        MOS = MOSes;
    }


void Managment(Officer &a, std::string newManager){
    a.manager = std::move(newManager);
};

Private::Private(Rank ranks, MilitaryUnit militaryunits, std::pair<MilitarySpecialization, Post> MOSes){
    rank = ranks;
    militaryunit = militaryunits;
    MOS = MOSes;
}

Officer::Officer(){
    this->rank = Rank::privat;
    this->MOS.first = MilitarySpecialization::driver;
    this->MOS.second = Post::without_any_position;
    this->militaryunit = MilitaryUnit();
}

Officer::Officer(Rank ranks, MilitaryUnit militaryunits, std::pair<MilitarySpecialization, Post> MOSes, std::string newManager){
    rank = ranks;
    militaryunit = militaryunits;
    MOS = MOSes;
    manager = std::move(newManager);
}

std::string Officer::GetManager() {
    return manager;
}