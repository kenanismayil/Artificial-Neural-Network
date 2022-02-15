#include "Perceptron.h"
#include <cmath>
#include "Process.h"


bool perceptron(Samples sample, double* weights, double c)
{
	float bias = 1;
	float net = 0;
	float output = 0.0;
	float desired = sample.id;

	net = sample.x1 * weights[0] + sample.x2 * weights[1] + bias * weights[2];

	output = sgn(net);

	if (output != desired)
	{
		weights[0] = weights[0] + c * (desired - output) * sample.x1;
		weights[1] = weights[1] + c * (desired - output) * sample.x2;
		weights[2] = weights[2] + c * (desired - output) * bias;
		return false;
	}
	else
	{
		return true;
	}
}
