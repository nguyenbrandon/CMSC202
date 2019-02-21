#include <iostream>
using namespace std;

const int NUM_STUDENTS = 25;  // maximum number of scores

// Function prototypes - do not change!

int max(int data[], int dataLen);
int min(int data[], int dataLen);
float average(int data[], int dataLen);

int main() {
  int scores[NUM_STUDENTS] = {0};
  int numScores = 0;
  int inputValue;
  int spot = 0;

  cout<<"Enter a score (-1 when done): ";
  cin>>inputValue;
  
  while (inputValue != -1){
    scores[spot] = inputValue;
    numScores++;
    spot++;
    cout<<"Enter a score (-1 when done): ";
    cin>>inputValue;

  }


  int maxVal = max(scores, numScores);  // compute maximum score
  int minVal = min(scores, numScores);
  float avgVal = average(scores, numScores);

  cout << "Max score is " << maxVal << endl;
  cout << "Min score is " << minVal << endl;
  cout << "Average is " << avgVal << endl;
    
  return 0;
}

int max(int data[], int dataLen) {
  int currentMax = data[0];
  for (int i = 1; i < dataLen; i++) {
    if (data[i] > currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

// max() - computes maximum value in an int array
// Assumes data[] contains at least one element

float average(int data[], int dataLen){
  float sum = 0;
  for(int i = 0; i < dataLen; i++){
    sum += data[i];
  }
  float avg; 
  avg =  sum / float(dataLen);
  return avg;
}


int min(int data[], int dataLen) {
  int currentMin = data[0];
  for (int i = 1; i < dataLen; i++) {
    if (data[i] < currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
} 
