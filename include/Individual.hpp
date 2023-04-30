#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

class Individual {
public:
  Individual(string gene) {
    this->gene = gene;
    this->fit = calculateFitScore();
  }

  // ## GETTERS ##
  string getGene() {
    return gene;
  }

  int getFit() {
    return fit;
  }

  // ## SETTERS ##
  void setGene(string gene) {
    this->gene = gene;
  }

  void setFit(int fit) {
    this->fit = fit;
  }

  void updateFit() {
    this->fit = calculateFitScore();
  }

  int calculateFitScore() {
    /* How many pairs of queens are atacking each other or have 
     * the possibilityto atack other */ 
    int atackPairs = 0;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (i != j) {
          // Atack horizontally
          if (gene[i] == gene[j])
            atackPairs++;
            // Atack diagonally
          else if (
              (int) gene[i] == (int) gene[j] + abs(i - j) ||
              (int) gene[i] == (int) gene[j] - abs(i - j)
            )
            atackPairs++;
        }
      }
    }

    return atackPairs;
  }

  void mutate() {
    this->gene[rand() % 8] = to_string(rand() % 8)[0];
  }

  // To be able to sort then
  bool operator< (const Individual &other) const {
    return fit < other.fit;
  }

  string toString() {
    stringstream ss;
    ss << setw(8) << gene << setw(10) << fit;
    return ss.str();
  }

private:
  string gene;
  int fit;
};
