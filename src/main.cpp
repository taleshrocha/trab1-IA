#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#include "Population.hpp"

using namespace std;

int main (int argc, char *argv[]) {
  srand (time(NULL));

  Population population(100, 100);

  population.evolve();

  return 0;
}
