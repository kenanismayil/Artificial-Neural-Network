#include "Delta.h"
#include <cmath>
#include "Process.h"
#include "Resource.h"


int delta(Samples sample, double* weights, double c)
{
	float bias = 1;
	float net = 0;
	float output = 0.0;
	float desired = sample.id;

	net = sample.x1 * weights[0] + sample.x2 * weights[1] + bias * weights[2];

	output = sigmoid(net);

	if (!IS_EQUAL(output, desired))
	{
		weights[0] = weights[0] + c * (desired - output) * sigmoid_derivative(net) * sample.x1;
		weights[1] = weights[1] + c * (desired - output) * sigmoid_derivative(net) * sample.x2;
		weights[2] = weights[2] + c * (desired - output) * sigmoid_derivative(net) * bias;
		return 0;
	}
	else
	{
		return 1;
	}
}

