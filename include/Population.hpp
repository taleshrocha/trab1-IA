#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>
#include <cmath>

#include "Individual.hpp"

using namespace std;

class Population {

public:
  Population(size_t maxPopulation, size_t maxGeneration) {
    this->maxPopulation = maxPopulation;
    this->maxGeneration = maxGeneration;
    //this.individuals = Individual[maxPopulation];

    // Creates a initial individuals with random genes
    for (size_t i = 0; i < maxPopulation; i++) {
      individuals.push_back(Individual(
          to_string(rand() % 8) +
          to_string(rand() % 8) +
          to_string(rand() % 8) +
          to_string(rand() % 8) +
          to_string(rand() % 8) +
          to_string(rand() % 8) +
          to_string(rand() % 8) +
          to_string(rand() % 8)));
    }
  }

  int evolve() {
    size_t front, back;

    // Leave the 1/4 best individuals to live
    size_t oldGenPreserve;

    size_t selectionNumber = maxPopulation/2;
    string frontGenes[selectionNumber];
    string backGenes[selectionNumber]; 

    size_t crossoverRate = 0;

    for (size_t i = 0; i < maxGeneration; i++) {
      sort(individuals.begin(), individuals.end());
      cout << "(" << i << "," << averageFit() << ")";
      //cout << toString() << endl;

      // Perserve up to 1/4 of the old generation
      oldGenPreserve = (rand() % (int) maxPopulation/4);

      // Some number between 1 and 4;
      crossoverRate = 1 + (rand() % 4);

      for(size_t j = 0; j < selectionNumber; j++) {
        frontGenes[j] = (individuals[j].getGene()).substr(0,crossoverRate);
        backGenes[j] = (individuals[j].getGene()).substr(crossoverRate,8);
      }

      // Mating... Yeah!
      for(size_t j = oldGenPreserve; j <= maxPopulation; j++) {
        front = rand() % selectionNumber;
        back = rand() % selectionNumber;
        while(front == back) {
          back = rand() % selectionNumber;
        }
        individuals[j].setGene(frontGenes[front] + backGenes[back]);
        individuals[j].updateFit();
        if(individuals[j].getFit() == 0) {
          //cout << individuals[j].toString() << endl;
          cout << "(" << i << "," << averageFit() << ")";
          return j;
        }
      }

      for(size_t j = 0; j < maxPopulation/2; j++) {
        individuals[rand() % (maxPopulation+1)].mutate();
      }
    }
    return -1;
  }

  double averageFit() {
    double sum = 0;
    for(auto individual : individuals)
      sum += individual.getFit();

    return sum / maxPopulation;
  }

  string toString() {
    stringstream ss;

    ss << setw(8) << "Gene" << setw(10) << "FitScore" << endl;
    for (size_t i = 0; i < maxPopulation; i++)
      ss << individuals[i].toString() << endl;

    return ss.str();
  }

  template<typename T>
  std::vector<T> slice(std::vector<T> const &v, int m, int n)
  {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<T> vec(first, last);
    return vec;
  }

private:
  size_t maxPopulation;
  size_t maxGeneration;
  vector<Individual> individuals;
};
