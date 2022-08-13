#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "Database.h"
#include "Weapon.h"
using namespace std;

Database::Database(const char* const & csv) {
  this->name = csv;
  ifstream my_file(csv);
  if(my_file.fail()) {
    throw invalid_argument("Specified csv file does not exist, please try again.\n");
  }
  string line;
  while(getline(my_file, line)) {
    istringstream ss(line);
    string first, second, third, fourth, fifth;
    getline(ss, first, ',');
    getline(ss, second, ',');
    getline(ss, third, ',');
    getline(ss, fourth, ',');
    getline(ss, fifth, ',');

    if(info.find(first) == info.end()) {
      info.insert({first, Weapon(first, second, stoi(third), fourth, stoi(fifth))});
    }
  }
  my_file.close();
}

Weapon Database::search(string query) {
  if(info.find(query) == info.end()) {
    throw invalid_argument("No such weapon entry exists, please try something else\n");
  }
  return info.find(query)->second;
}

void Database::add(string name, string ms, int mslv, string ss, int sslv) {
  info.insert({name, Weapon(name, ms, mslv, ss, sslv)});
}