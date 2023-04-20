#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Individual
  {
  public:
    Individual();
    Individual(string gene) {
      this->gene = gene;
      this->SetFit(FitScore());
    }
    void SetGene(string gene) {
      this->gene = gene;
    }
    string GetGene() {
      return gene;
    }
    void SetFit(int fit) {
      this->fit = fit;
    }
    int GetFit() {
      return fit;
    }
    int FitScore() {
      // How many pairs of queens are atacking each other or have the possibility
      // to atack other
      int atackPairs = 0;

      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          if (i != j) {
            // Atack horizontally
            if(gene[i] == gene[j])
              atackPairs++;
              // Atack diagonally
            else if(
                (int) gene[i] == (int) gene[j] + abs(i - j) ||
                (int) gene[i] == (int) gene[j] - abs(i - j))
              atackPairs++;
          }
        }
      }

      return atackPairs;
    }
    bool operator< (const Individual &other) const {
      return fit < other.fit;
    }

  private:
    string gene;
    int fit;
  };


int main (int argc, char *argv[]) {
  srand (time(NULL));
  size_t popSize = 6;
  float crossoverRate = 0.5;


  vector<Individual> population;

  // Creates popSize new random individuals
  for (size_t i = 0; i < popSize; i++) {
    population.push_back(Individual(
                           to_string(rand() % 8) +
                           to_string(rand() % 8) +
                           to_string(rand() % 8) +
                           to_string(rand() % 8) +
                           to_string(rand() % 8) +
                           to_string(rand() % 8) +
                           to_string(rand() % 8) +
                           to_string(rand() % 8)));
    cout << population[i].GetGene() << endl;
  }

  // Get the best individuals to be in the end of the vector
  sort(population.begin(), population.end());

  //for (int i = 0; i < population.size(); i++) {
  //  cout << population[i].GetFit() << endl;
  //}



  return 0;
}
