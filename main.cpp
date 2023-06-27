#include <bits/stdc++.h>
#include "ARMY_INFO.h"


int main() {

    MilitaryUnit militaryunit;
    militaryunit.squad = 1;
    militaryunit.battalion = 4;
    militaryunit.company = 10;
    militaryunit.platoon = 1;
    militaryunit.militaryDivision = std::pair<int, char>(30632, 'A');
    std::pair<MilitarySpecialization, Post>MOS = std::pair<MilitarySpecialization, Post>(driver, driver_mechanic);
    auto Me = new Private();
    std::cout << Me->rank << std::endl;
    Me->Promotion();
    std::cout << Me->rank << std::endl;

    auto You = new Private(Rank::junior_lieutenant, militaryunit, MOS);
    std::cout << (Me < You) << std::endl;

    auto He = new Officer(Rank::junior_lieutenant, militaryunit, MOS, "lieutenant");
    std::cout << He->GetManager() << std::endl;

    Managment(*He, "Major");
    std::cout << He->GetManager() << std::endl;

    Me->plan.push_back("Enemy 1");
    Me->plan.push_back("Alert 2");
    Me->plan.push_back("Enemy 2");

    std::cout << Me->plan << std::endl;

    CompositeUnit army;
    army.addUnit(Me);
    army.addUnit(He);
    army.addUnit(You);

    std::cout << army.getStrength() << std::endl;

    return 0;
}
