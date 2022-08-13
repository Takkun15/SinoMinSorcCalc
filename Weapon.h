#ifndef WEAPON_H
#define WEAPON_H
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

class Weapon {
  public:
    string name;
    pair<string, int> main_skill, supp_skill;
    int atk_prio, def_prio, mix_prio;

    Weapon(string name, string ms_name, int ms_tier, string ss_name, int ss_tier);
};
#endif