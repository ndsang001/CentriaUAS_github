#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <array>
#include <iomanip>
using namespace std;

const unsigned int rollTime{36000000};
const size_t frequencySize{13};

void roll(){ 
  int dice1, dice2;
  int sum = 0;
  double a = 0;

  array<unsigned int, frequencySize> frequency{};
  array<double, 11> theoryPer{1/.36, 2/.36, 3/.36, 4/.36, 5/.36, 6/.36, 5/.36, 4/.36, 3/.36, 2/.36, 1/.36};
  array<double, 11> practicalPer{};

  for(size_t i{0}; i < rollTime; ++i){
    dice1 = 1 + rand()%6;
    dice2 = 1 + rand()%6;
    sum = dice1 + dice2;
    ++frequency[sum];
  }
  
  for(size_t j{0}; j < 11; ++j){
    a = frequency[j+2];
    practicalPer[j] = (a / rollTime) * 100;
  }
  
  cout << "Sum" << setw(12) << "Frequency" 
  << setw(23) << "Theorical percentage" 
  << setw(23) << "Practical percentage" << endl;

  for (size_t sumDot{2}; sumDot < frequency.size(); ++sumDot) {
    cout << setw(3) << sumDot 
    << setw(12) << frequency[sumDot] 
    << setw(22) << setprecision(5) << theoryPer[sumDot-2] << "%" 
    << setw(22) << setprecision(5) << practicalPer[sumDot-2] << "%" << endl;
  }
}

int main(){
unsigned int seed{0};
  
cout << "Please enter seed: ";
cin >> seed;
srand(seed);

roll();

return 0;
}
