//
// Created by Lánczky, András on 2017. 01. 24..
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#endif //PERCEPTRON_PERCEPTRON_H

class Perceptron {
    int size;
    double *w;
    float learningRate;

    short activation(double res);
    void delta(double *w_, double w, double *x);

public:
    Perceptron(int size, float learningRate);
    ~Perceptron();

    short eval(double *x);

    void train(double **x, short *y, int trainingDataSize, int iterationCount);

    double mse(double **x, short *y, int size);

    void print();
};