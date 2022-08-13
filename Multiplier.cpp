#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "Multiplier.h"
using namespace std;

Multiplier::Multiplier(const char* const & csv) {
  this->name = csv;
  ifstream my_file(csv);
  if(my_file.fail()) {
    throw invalid_argument("Specified csv files does not exist, please try again.\n");
  }
  string line;
  while(getline(my_file, line)) {
    istringstream ss(line);
    string first, second, third, fourth, fifth, sixth;
    getline(ss, first, ',');
    getline(ss, second, ',');
    getline(ss, third, ',');
    getline(ss, fourth, ',');
    getline(ss, fifth, ',');
    getline(ss, sixth, ',');

    tuple<float, float, float, float, float> vals = make_tuple(stof(second), stof(third), stof(fourth), stof(fifth), stof(sixth));

    if(info.find(first) == info.end()) {
      info.insert({first, vals});
    }
  }
  my_file.close();
}

float Multiplier::get_mult(string query, int opt, float atk_weight) {
  tuple<float, float, float, float, float> vals = info.find(query)->second;
  if(opt == 1) {
    return atk_weight * (get<1>(vals) + get<2>(vals)) * get<0>(vals) / 2;
  }
  else if(opt == 2) {
    return (get<3>(vals) + get<4>(vals)) * get<0>(vals) / 2;
  }
  else if(opt == 3) {
    return (atk_weight * (get<1>(vals) + get<2>(vals)) + get<3>(vals) + get<4>(vals)) * get<0>(vals) / 4;
  }
  else if(opt == 4) {
    return atk_weight * get<1>(vals) * get<0>(vals);
  }
  else if(opt == 5) {
    return atk_weight * get<2>(vals) * get<0>(vals);
  }
  else if(opt == 6) {
    return get<3>(vals) * get<0>(vals);
  }
  else if(opt == 7) {
    return get<4>(vals) * get<0>(vals);
  }
  else {
    return 0;
  }
}