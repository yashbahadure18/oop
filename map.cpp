#include <iostream>
 #include <map>
 #include <string>
 int main() {
 // Create a map to store state populations
 std::map<std::string, long long> statePopulation;
 // Initialize the map with some sample data
 statePopulation["California"] = 39538223;
 statePopulation["Texas"] = 29145505;
 statePopulation["Florida"] = 21538187;
 statePopulation["New York"] = 20201249;
 statePopulation["Pennsylvania"] = 13002700;
 std::string state;
 // Prompt the user for a state name
 std::cout << "Enter the name of a state: ";
 std::getline(std::cin, state);
 // Look up the state in the map
 auto it = statePopulation.find(state);
 // Check if the state was found and display the population
 if (it != statePopulation.end()) {
 std::cout << "The population of " << state << " is " << it->second << ".\n";
 } else {
 std::cout << "State not found in the map.\n";
 }
 return 0;
 }