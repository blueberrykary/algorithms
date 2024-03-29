/*Karen Salinas
CSC 501- Design and Analysis*/

/*
ALGORITHM ChangeMaking(D[1..m], n)
//Applies dynamic programming to find the minimum number of coins
//of denominations d1< d2 < . . . < dm where d1 = 1 that add up to a
//given amount n
//Input: Positive integer n and array D[1..m] of increasing positive
// integers indicating the coin denominations where D[1]= 1
//Output: The minimum number of coins that add up to n

F[0]←0
for i ←1 to n do
temp←∞; j ←1
while j ≤ m and i ≥ D[j ] do
temp ←min(F [i − D[j ]], temp)
j ←j + 1
F[i]←temp + 1
return F[n]

*/

// The code I created similarly follows the Change_Making algorithm, with
//a few adjustments. There was an error in my code when I tried having j = 1,
// and therefore decided to leave it to j = 0.
#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

int Change_Making(int input[], int m, int change_amount)
{
  //this is set to store the number of coins
  int F[change_amount + 1];

  //in the change_amount is 0 base case
  F[0] = 0;

  for(int i = 1; i <= change_amount; i ++) {
    F[i] = INT_MAX; //initialized F[] with an infinity value
    int temp = INT_MAX; // likewise with temp as an infinity value
    int j = 0;      //set to 0

    //this will check all values(change_amount) smaller than i
    while (j <= m &&  i >= input[j]) {
      temp = min(F[i - input[j]], temp);
      j = j + 1;
    }
    F[i] = temp + 1;
  }
  return F[change_amount];
}

//Driver code
int main()
{
  int input[] = {1,2,3,4};
  int m = sizeof(input)/sizeof(input[0]);
  int change_amount = 15;
  size_t n = sizeof(input)/sizeof(input[0]);
  cout << "Change Denominations: [ "  ;

  for(size_t i=0; i < n; i++) {
    cout << input[i] << ' ';
  }

  cout << "]";

  cout << "\nAmount of: " << change_amount << "\n";
  cout << "The minimum number of coins required to get desired change:  " << Change_Making(input, m, change_amount) << "\n";

  return 0;
}
