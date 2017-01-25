#include <iostream>
#include "Perceptron.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Perceptron *p = new Perceptron(2);

    double x[2] = {1,2};
    cout << "eval: " << p->eval(x) << endl;

    delete p;
    return 0;
}