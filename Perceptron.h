//
// Created by Lánczky, András on 2017. 01. 24..
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#endif //PERCEPTRON_PERCEPTRON_H

class Perceptron {
    int size;
    double b;
    double *w;

public:
    Perceptron(int size);
    ~Perceptron();

    double eval(double *x);

    void learn(double *x);

    double mse(double **x, double *y, int size);
};