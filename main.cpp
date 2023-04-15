#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
  size_t popSize = 5;
  vector<string> population;
  for (size_t i = 0; i < popSize; i++) {
    population.push_back(
        to_string(rand() % 8) +
        to_string(rand() % 8) +
        to_string(rand() % 8) +
        to_string(rand() % 8) +
        to_string(rand() % 8) +
        to_string(rand() % 8) +
        to_string(rand() % 8) +
        to_string(rand() % 8));
      cout << population[i] << endl;
  }
  return 0;
}
