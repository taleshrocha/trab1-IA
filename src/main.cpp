#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#include "Population.hpp"

using namespace std;

int main (int argc, char *argv[]) {
  srand (time(NULL));

  cout << "ITERATION 1 -- 25, 0.8, 0.05" << endl;
  Population *population = new Population(200, 25, 0, 5);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 2 -- 25, 0.7, 0.05" << endl;
  population = new Population(200, 25, 1, 5);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 3 -- 25, 0.7, 0.15" << endl;
  population = new Population(200, 25, 1, 15);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 4 -- 75, 0.7, 0.15" << endl;
  population = new Population(200, 75, 1, 15);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 5 -- 75, 0.6, 0.15" << endl;
  population = new Population(200, 25, 2, 15);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 6 -- 75, 0.6, 0.10" << endl;
  population = new Population(200, 25, 2, 10);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 7 -- 150, 0.6, 0.10" << endl;
  population = new Population(200, 150, 2, 10);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 8 -- 150, 0.6, 0.20" << endl;
  population = new Population(200, 150, 2, 20);
  population->evolve();
  cout << "\n\n";
  delete population;

  cout << "ITERATION 9 -- 150, 0.5, 0.20" << endl;
  population = new Population(200, 150, 0, 20);
  population->evolve();
  cout << "\n\n";
  delete population;

  return 0;
}
