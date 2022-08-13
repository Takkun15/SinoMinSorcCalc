#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include "Database.h"
#include "Multiplier.h"
#include "Weapon.h"
using namespace std;

//Default data sheet names
const char* data_csv = "data.csv";
const char* mult_csv = "mult.csv";

//Default weight values
const float atk_weight = 2.5;
const float sb1 = 1.4743, sb2 = 1.7817, sb3 = 2.1535;

//Overload < for comparing pair<float, Weapon> in pq
bool operator<(pair<float, Weapon> const& p1, pair<float, Weapon> const& p2) {
  return p1.first < p2.first;
}

int main(int argc, char** argv) {
  
  //Creating database from default file
  Database db(data_csv);
  cout << "Successfully built database from: " << data_csv << endl;
  
  //Creating multiplier database from default file
  Multiplier mult(mult_csv);

  //Reading in Grid (filename passed in from command line)
  vector<Weapon> grid;
  ifstream my_file(argv[1]);
  if(my_file.fail()) {
    throw invalid_argument("Specified txt files does not exist, please try again.\n");
  }
  string line;
  while(getline(my_file, line)) {
    if(db.info.find(line) != db.info.end()) {
      grid.push_back(db.search(line));
    }
    else {
      cout << line << " not found. ";
      throw invalid_argument("Weapon not found in database.\n");
    }
  }
  cout << "Obtained grid from: " << argv[1] << endl;

  //Prompt for which stat to optimize
  int choice;
  cout << "Which stat to optimize for?\n";
  cout << "1. Overall Attack\n" << "2. Overall Defense\n" << "3. Overall Average\n";
  cout << "4. Physical Attack\n" << "5. Magicial Attack\n" << "6. Physical Defense\n" << "7. Magicial Defense\n";
  cin >> choice;

  //Insert weapons into priority queue to sort from best to worst
  priority_queue<pair<float, Weapon>> pq;
  if(choice >= 1 && choice <= 7) {
    string c;
    switch(choice) {
      case 1:
        c = "overall attack";
        break;
      case 2:
        c = "overall defense";
        break;
      case 3:
        c = "overall average";
        break;
      case 4:
        c = "physical attack";
        break;
      case 5:
        c = "magicial attack";
        break;
      case 6:
        c = "physical defense";
        break;
      case 7:
        c = "magical attack";
        break;
    }
    cout << "You chose " << c << endl;
    for(auto w: grid) {
      string skill_tiered = w.main_skill.first + " " + to_string(w.main_skill.second);
      float w_val = mult.get_mult(skill_tiered, choice, atk_weight);
      cout << w.name << " mult: " << w_val << "supp skill: " << w.supp_skill.first << " " << w.supp_skill.second << endl;
      //Check for Support Boon skill and apply boost
      if(w.supp_skill.first == "Support Boon") {
        if(w.supp_skill.second == 1) {
          w_val *= sb1;
        }
        else if(w.supp_skill.second == 2) {
          w_val *= sb2;
        }
        else if(w.supp_skill.second == 3) {
          w_val *= sb3;
        }
      }
      pq.push(make_pair(w_val, w));
    }
  }
  else {
    throw invalid_argument("Not a valid choice, please try again\n");
  }

  //Print out recommended grid (best 20 weapons based on criteria)
  int i = 1;
  cout << "Suggested grid:\n";
  while(!pq.empty() && i <= 20) {
    cout << i << ":\t" << left << setw(35) << pq.top().second.name << " Weight: " << fixed << setprecision(2) << pq.top().first << endl;
    pq.pop();
    i++;
  }

  return 0;
}