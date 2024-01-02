#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double data[], int n, double result[]) {
  double sum = 0;
  double squaredSum = 0;
  double mul = 1;
  double recipSum = 0;
  double minn = data[0];
  double maxx = data[0];
  for (int i = 0; i < n; i++) {
    double d = data[i];
    sum += d;
    squaredSum += d * d;
    mul *= d;
    recipSum += 1 / d;

    if (d < minn) minn = d;
    if (d > maxx) maxx = d;
  }

  double mean = sum / n;
  double squaredMean = squaredSum / n;

  result[0] = mean;
  result[1] = sqrt(squaredMean - mean*mean);
  result[2] = pow(mul, 1.0/n);
  result[3] = n / recipSum;
  result[4] = maxx;
  result[5] = minn;
}
