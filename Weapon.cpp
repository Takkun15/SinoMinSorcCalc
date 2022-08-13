#include <stdio.h>
#include <cstring>
#include <string>
#include "Weapon.h"
using namespace std;

Weapon::Weapon(string name, string ms_name, int ms_tier, string ss_name, int ss_tier) {
  this->name = name;
  this->main_skill = make_pair(ms_name, ms_tier);
  this->supp_skill = make_pair(ss_name, ss_tier);
  this->atk_prio = 0;
  this->def_prio = 0;
  this->mix_prio = 0;
}