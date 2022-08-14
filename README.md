# Version 0.1.0

## Description
A C++ command line program to optimize SINoALICE grids for minstrels/sorcerers based on criteria of desired stat

*Minstrel support to be added soon*


## Requirements
No additional requirements beyond the included files


## Usage
Startup command: (replace *inventory.txt* with the name of your file)

```
./main <inventory.txt>
```

After that enter the integer (1-7) when prompted to choose a stat to optimize the grid around

```
1. Overall Attack
2. Overall Defense
3. Overall Average
4. Physical Attack
5. Magicial Attack
6. Physical Defense
7. Magicial Defense
```


## Troubleshooting & FAQ
- I'm getting an error that my file does not exit

  Make sure that the file name is spelled correctly with the under the proper casing

- The databases for either the weapons/skill multipliers are not found

  Make sure that the data and multiplier csv files are located in the same directory as the program

- A weapon/skill in my inventory file is not recognized

  Make sure that the weapons and skill names are spelled correctly with the matching case as the database/multiplier files
  
  If the weapon/skill cannot be found in the database please add them along with their correct parameters in manually
  
- Where do I find/modify the names of the default files and the values of the default multipliers

  They can be found listed as constant variables near the top of main.cpp
  
  Default weight of atk to def is 2.5 : 1
  
  SB1: 1.4743, SB2: 1.7817, SB3: 2.1535


## Planned Updates
- Support for minstrel weapons
- Weapon equipment cost and optimization under user's max available cost
- Weapons elements and weights during elemental bonuses
- Inventories with mixed weapon types and desired number of off-type weapons
- Larger databases to include more weapons/skills


## Maintainers
- Takkun15
