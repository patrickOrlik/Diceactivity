#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DICE 100
#define MAX_ROLLS 50000

unsigned int DiceSums[50000];
unsigned int SumDistribution[601];
unsigned int DiceAmount;
unsigned int RollAmount;

/**
 * @brief a simple function that simulates X amount of Dice rolls with X amount
 * of dice
 *
 * @param DiceAmount  = amount of Dice wanted
 * @param RollAmount =  amount of rolls wanted
 */
void DiceRoll(int DiceAmount, int RollAmount) {
  for (int i = 0; i < RollAmount; i++) {
    int DiceSum = 0;
    for (int x = 0; x < DiceAmount; x++) {
      DiceSum = DiceSum + rand() % 6 + 1;
    }
    DiceSums[i] = DiceSum;
  }
};
/**
 * @brief a function that checks the sum distribution of sums of dice rolls
 * stored in an array works for N amount of Dice and rolls
 *
 * @param arr[] = Array storing sums
 * @param size of the array storing sums =Arraysize
 */
void CheckSumDistribution(unsigned int arr[], int Arraysize) {
  for (int i = 0; i < Arraysize; i++) {
    SumDistribution[arr[i]]++;
  }
}
/**
 * @brief Prints out a specified array storing sums of dicethrows
 *
 * @param the array that should be printed
 * @param size of the array that should be printed
 * @param amount of dice being rolled.
 */
void PrintArray(unsigned int arr[], int ArraySize, unsigned int DiceAmount) {
  for (int i = DiceAmount; i <= (DiceAmount * 6); i++) {
    fprintf(stdout, "%d. %d \n", i, arr[i]);
  }
}

int main() {

  srand(time(NULL));
  puts("how many Dice do you want? Max is 100 Dice");
  fscanf(stdin, "%d", &DiceAmount);
  if (DiceAmount > 0 && DiceAmount <= MAX_DICE) {
    puts("How many rolls do you want? Max 50000");
    fscanf(stdin, "%d", &RollAmount);
    if (RollAmount > 0 && RollAmount <= 50000) {
      DiceRoll(DiceAmount, RollAmount);
      CheckSumDistribution(DiceSums, RollAmount);
      PrintArray(SumDistribution, _countof(SumDistribution), DiceAmount);
    } else
      fprintf(stderr, "%s", "Error:Invalid user input");

  } else
    fprintf(stderr, "%s", "Error:Invalid user input");
}
