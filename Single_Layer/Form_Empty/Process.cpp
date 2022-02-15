#include "Process.h"
#include "Resource.h"
#include <cmath>

int findY(int x, double* w, int Carpan) {
	return (int)((double)(-1 * w[2] * (double)Carpan - w[0] * x) / (double)(w[1]));
}

double sgn(double net) {

	return (net >= 0.0f) ? 1.0f : (0.0f);
}

double sgn_derivative(double net) {

	return 0.0f;
}

double sigmoid(double net) {

	return (1.0 / (1.0 + pow(euler, -net)));
}

double sigmoid_derivative(double net) {

	return sigmoid(net) * (1 - sigmoid(net));
}
