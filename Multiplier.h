#ifndef MULTIPLIER_H
#define MULTIPLIER_H
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

class Multiplier {
  public:
  string name;
    unordered_map<string, tuple<float, float, float, float, float>> info;

    Multiplier(const char* const & csv);

    float get_mult(string query, int opt, float atk_weight);
};
#endif