#include <bits/stdc++.h>
#ifndef MAIN_CPP_ARMY_INFO_H
#define MAIN_CPP_ARMY_INFO_H

#include "FORWARD_LIST.h"

enum Rank{
    //Солдатский и сержантский состав
    privat = 1, corporal = 2, junior_sergeant = 3, sergeant = 4, senior_sergeant = 5, chief = 6,
    //Прапорщики
    warrant_officer = 7, senior_warrant_officer,
    //Младший офицерский состав
    junior_lieutenant, lieutenant, senoir_lieutenant, captain,
    //Старший офицерский состав
    major, lieutenant_colonel, colonel,
    //Высший командный состав
    general_major, general_lieutenant, general_colonel, general_of_army
};//Звания

const Rank operator++(Rank& rank, int);

enum Post{without_any_position = 0,
    driver_mechanic = 1,
    operator_transmitter = 1,
    squad_commander,
    deputy_platoon_commander,
    platoon_commander,
    company_chief,
    company_commander,
    deputy_platoon_commander_for_MPW,
    battalion_chief_of_staff,
    battalion_commander};//Должность в боевом расчёте

struct MilitaryUnit {
public:

    std::pair<int, char> militaryDivision;
    int battalion;
    int company;
    int platoon;
    int squad;

    MilitaryUnit(int militaryDivisionNumber,
                 char militaryDivisionLettter,
                 int battalion,
                 int company,
                 int platoon,
                 int squad);

    MilitaryUnit();

};

enum MilitarySpecialization{driver = 121}; //Военная специализация


enum Alert{
    WarDanger = 1,
    FireDanger = 2,
    SpyDanger = 3
};

class Soldier {
public:

    Rank rank;
    MilitaryUnit militaryunit;
    std::pair<MilitarySpecialization, Post> MOS; //Военнно-учётная специальность
    Container::forward_list<std::string> plan;

    virtual void Promotion();
    Soldier();

    Soldier(Rank ranks, MilitaryUnit militaryunits, std::pair<MilitarySpecialization, Post> MOSes);

    virtual bool operator==(Soldier* a);
    virtual bool operator<(Soldier* a);
    virtual bool operator>(Soldier* a);

    virtual ~Soldier() = default;
};
class Private: public Soldier{
public:

    bool operator==(Soldier* a) override;
    bool operator<(Soldier* a) override;
    bool operator>(Soldier* a) override;

    Private() : Soldier() {};
    Private(Rank ranks, MilitaryUnit militaryunits, std::pair<MilitarySpecialization, Post> MOSes);
};

class Officer: public Soldier {
    friend void Managment(Officer&, std::string);
private:
    std::string manager;
public:
    std::string GetManager();

    Officer();
    Officer(Rank ranks, MilitaryUnit militaryunits, std::pair<MilitarySpecialization, Post> MOSes, std::string manager);
};

void Managment(Officer& a, std::string);

class Sergant: public Soldier{};
class WarrantOfficer: public Soldier{};

typedef std::string ARRAYFORSUBJECTS[][5][1];
typedef std::string ARRAYFORRULES[][4];

class CompositeUnit: public Soldier
{
public:
    int getStrength() {
        int total = 0;
        for(auto i : army)
            total += i->rank;
        return total;
    }
    void addUnit(Soldier* p) {
        army.push_front( p);
    }
    ~CompositeUnit() {
        for(auto i : army)
            delete i;
    }
private:
    Container::forward_list<Soldier*> army;
};

#endif //MAIN_CPP_ARMY_INFO_H
