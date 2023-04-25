#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

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

tuple<size_t, size_t> SelectCouple(vector<Individual> population){

  size_t val;
  size_t ind[2];
  ind[0] = ind[1] = 0;

  do{
    for (size_t i = 0; i < 2; i++) {
      val = (rand() % 100) + 1;
      if(val <= 50) 
        ind[i] = 0;
      else if(val > 50 && val <= 75) 
        ind[i] = 1;
      else if(val > 75 && val <= 85)
        ind[i] = 2;
      else { // Some of the other individuals
        ind[i] = (rand() % population.size() - 3) + 3;
      }
    }
  } while(ind[0] == ind[1]);

  return  {ind[0], ind[1]};
}

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;
 
    std::vector<T> vec(first, last);
    return vec;
}


int main (int argc, char *argv[]) {
  srand (time(NULL));
  size_t popSize = 6;
  size_t crossoverRate = 4;
  size_t maxNumGeneration = 100;


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
    //cout << population[i].GetGene() << endl;
  }

  // Get the best individuals to be in the end of the vector
  sort(population.begin(), population.end());

  for (int i = 0; i < population.size(); i++) {
    //cout << i << " " << population[i].GetGene() << " " << population[i].GetFit() << endl;
  }

  size_t index = 0;

  size_t livingSlice = rand() % popSize/2; // In the maximun 50% of the old gen can live

  // Cria a nova população
  auto newPop = slice(population, 0, livingSlice);

  size_t ind1, ind2;

  do {
    tie(ind1, ind2) = SelectCouple(newPop);
    cout << ind1 << "--" << ind2 << endl;
  } while(ind1 != 3);
  //} while(newPop.size() != popSize) {


  return 0;
}
