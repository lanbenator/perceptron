#include <iostream>
#include "Perceptron.h"
#include "Iris.h"

using namespace std;

int main() {
    const int trainingDataSize = 100,
                perceptronDim = 2;

    Iris *iris = new Iris();

    double **x = new double*[trainingDataSize];
    short d[trainingDataSize];
    for (int i = 0; i < trainingDataSize; ++i) {
        x[i] = new double[perceptronDim];
        x[i][0] = iris->data[i][0];
        x[i][1] = iris->data[i][1];
        d[i] = (i<50) ? (short)1 : (short)0;
    }

    Perceptron *p = new Perceptron(perceptronDim, 0.01);

    p->train(x, d, trainingDataSize, 1000);

    delete p;
    delete [] x;
    return 0;
}