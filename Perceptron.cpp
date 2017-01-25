//
// Created by Lánczky, András on 2017. 01. 24..
//

#include "Perceptron.h"
#include <math.h>

Perceptron::Perceptron(int size) {
    this->size = size;

    this->w = new double[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->w[i] = 10;
    }
    this->b = 1;
}

Perceptron::~Perceptron() {
    delete w;
}

double Perceptron::eval(double *x) {
    double res = b;
    for (int i = 0; i < this->size; ++i) {
        res += this->w[i] * x[i];
    }
    return res;
}

void Perceptron::learn(double *x) {

}

double Perceptron::mse(double **x, double *y, int size){
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += pow(y[i] - eval(x[i]),2);
    }
    return result / size;
}
