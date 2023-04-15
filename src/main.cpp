#include <string>  
#include <iostream>
#include <vector>

using namespace std;

// Fitness function

int main () {
	srand((unsigned) time(NULL));

  int popSize = 5;
  vector<string> population;

  // Generate random individuals
  for (int i = 0; i < popSize; i++) {
    population.push_back(to_string(rand() % 8) +
      to_string(rand() % 8) +
      to_string(rand() % 8) +
      to_string(rand() % 8) +
      to_string(rand() % 8) +
      to_string(rand() % 8) +
      to_string(rand() % 8) +
      to_string(rand() % 8));
    cout << population[i] << endl;
  }

  // Do
  // FOR size of population
  // Select the individuals
  // Crossover them
  // Mutate the children
  // Change old population for the children
  // WHILE some individual is fit enough or max number of generations
  return 0;
}
