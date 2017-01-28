//
// Created by Lánczky, András on 2017. 01. 24..
//

#include "Perceptron.h"
#include <math.h>
#include <iostream>

using namespace std;

Perceptron::Perceptron(int size, float learningRate) {
    this->size = size + 1;

    this->w = new double[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->w[i] = 1;
    }

    this->learningRate = learningRate;
}

Perceptron::~Perceptron() {
    delete w;
}

short Perceptron::eval(double *x) {
    double res = w[0]; // the bias
    for (int i = 1; i < this->size; ++i) {
        res += this->w[i] * x[i-1];
    }
    return this->activation(res);
}

short Perceptron::activation(double res){
    return (res>0) ? (short)1 : (short)0;
}

void Perceptron::train(double **x, short *d, int trainingDataSize, int iterationCount) {
    int iter = 0;
    double se;
    double *w_ = new double[this->size];

    do {
        cout << "-------" << endl;
        cout << "Iteration " << iter << endl;
        se = mse(x, d, trainingDataSize);
        cout << "MSE: " << se << endl;
        this->print();

        double y = 0;
        for(int i=0; i<trainingDataSize; i++){
            y = (d[i] - this->eval(x[i]));
            delta(w_, y, x[i]);
            copy(w_, w_+this->size, this->w);
        }

        iter++;
    }while(iter < iterationCount && se>0);

}

void Perceptron::delta(double *w_, double y, double *x){
    w_[0] = this->w[0] + this->learningRate * y;
    for (int j = 1; j < this->size; ++j) {
        w_[j] = this->w[j] +  this->learningRate * y * x[j-1];
    }
}

double Perceptron::mse(double **x, short *d, int size){
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += pow(d[i] - eval(x[i]),2);
    }
    return result / (size * 2);
}

void Perceptron::print(){
    cout << "Perceptron: weights: ";
    for (int i = 0; i < this->size; ++i) {
        cout << "w[" << i << "]=" << this->w[i] << ", ";
    }
    cout << endl;
}