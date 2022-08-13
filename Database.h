#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <unordered_map>
#include "Weapon.h"
using namespace std;

class Database {
  public:
    string name;
    unordered_map<string, Weapon> info;
    
    Database(const char* const & csv);

    Weapon search(string nm);

    void add(string name, string ms, int mslv, string ss, int sslv);
};
#endif