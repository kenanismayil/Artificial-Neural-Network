#include "perceptron.h"
#include <cmath>
#include "Process.h"


int perceptron(Samples sample, double* weights, double c)
{
	float bias = 1;
	int	net = 0;
	float output = 0.0;
	int desired = sample.id;

	// net = w[0]*x1 + w[1].x2 + w[2]*bias

	net += sample.x1 * weights[0];
	net += sample.x2 * weights[1];
	net += bias * weights[2];

	// output = f(net)

	output = sgn(net);

	// w(t + 1) = w(t) * delta_w

	if (output != desired)
	{
		weights[0] = weights[0] + c * (desired - output) * sample.x1;
		weights[1] = weights[1] + c * (desired - output) * sample.x2;
		weights[2] = weights[2] + c * (desired - output) * bias;
		return 0;
	}
	else {
		return 1;
	}
}
