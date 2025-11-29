#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int DiceSums[50000];
unsigned int SumDistribution[11];
unsigned int DiceAmount = 2;
unsigned int RollAmount = 50000;

void DiceRoll(int DiceAmount, int RollAmount) {
  for (int i = 0; i < RollAmount; i++) {
    int DiceSum = 0;
    for (int x = 0; x < DiceAmount; x++) {
      DiceSum = DiceSum + rand() % 6 + 1;
    }
    DiceSums[i] = DiceSum;
  }
};
void CheckSumDistribution(unsigned int arr[], int Arraysize) {
  for (int i = 0; i < Arraysize; i++) {
    switch (arr[i]) {
    case 2:
      SumDistribution[0]++;
      break;
    case 3:
      SumDistribution[1]++;
      break;
    case 4:
      SumDistribution[2]++;
      break;
    case 5:
      SumDistribution[3]++;
      break;
    case 6:
      SumDistribution[4]++;
      break;
    case 7:
      SumDistribution[5]++;
      break;
    case 8:
      SumDistribution[6]++;
      break;
    case 9:
      SumDistribution[7]++;
      break;
    case 10:
      SumDistribution[8]++;
      break;
    case 11:
      SumDistribution[9]++;
      break;
    case 12:
      SumDistribution[10]++;
      break;
    }
  }
}

void PrintArray(int arr[], int ArraySize) {
  for (int i = 0; i <= ArraySize; i++) {
    fprintf(stdout, "%d. %d \n", i + 2, arr[i]);
  }
}

int main() {
  srand(time(NULL));
  DiceRoll(DiceAmount, RollAmount);
  CheckSumDistribution(DiceSums, RollAmount);
  PrintArray(SumDistribution, 10);
}
