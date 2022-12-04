//
// Created by user on 05.12.2022.
//

#ifndef MAIN_CPP_ARMYINFO_H
#define MAIN_CPP_ARMYINFO_H

enum Rank{
    //Солдатский и сержантский состав
    privat = 1, corporal, junior_sergeant, sergeant, senior_sergeant, chief,
    //Прапорщики
    warrant_officer, senior_warrant_officer,
    //Младший офицерский состав
    junior_lieutenant, lieutenant, senoir_lieutenant, captain,
    //Старший офицерский состав
    major, lieutenant_colonel, colonel,
    //Высший командный состав
    general_major, general_lieutenant, general_colonel, general_of_army
};//Звания

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

enum MilitarySpecialization{}; //Военная специализация

enum Alert{};

struct MilitaryUnit{
    std::pair<int, char> militarydivision;
    int battalion;
    int company;
    int platoon;
    int squad;
};

#endif //MAIN_CPP_ARMYINFO_H
