#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

const double DOUBLE_PRECISION = 1e-10;

const int INF_ROOTS = -1;

const size_t COEFFICIENT_NUM = 3;
const size_t ROOT_NUM = 2;

int d_equal(double roots, double y) {
	return fabs(roots - y) < DOUBLE_PRECISION;
} 

int find_roots(const double* a, double* roots) {
	roots[0] = 0;
	roots[1] = 0;
	if (d_equal(a[0], 0)) {
		if (d_equal(a[1], 0)) {
			if (d_equal(a[2], 0)) {
				return INF_ROOTS;
			} else {
				return 0;
			}
		} else {
			roots[0] = -a[2] / a[1];
			roots[1] = roots[0];
			return 1;
		}
	} else {
		double b_sq = a[1] * a[1];
		double discriminant =  - 4 * a[0] * a[2];
		roots[0] = (-a[1] - sqrt(discriminant)) / (2 * a[0]);
		roots[1] = (-a[1] + sqrt(discriminant)) / (2 * a[0]); 
		if (d_equal(discriminant, 0)) {
			return 1;
		} else {
			return 2;
		}
	}
}

void input_array(double* a, size_t sz) {
	for (size_t i = 0; i < sz; ++i) {
		scanf("%lf", &a[i]);
	}
}

void print_roots(int roots_num, double* roots) {
	switch (roots_num) {
	case 0:
		printf("No roots.");
		break;
	case 1:
		printf("One root: %f", roots[0]);
		break;
	case 2:
		printf("Two roots: %f, %f", roots[1], roots[2]);
		break;
	case INF_ROOTS:
		printf("Each number is root.");
		break;
	}
}

int main() {
	double a[COEFFICIENT_NUM];
	double roots[ROOT_NUM];
	input_array(a, COEFFICIENT_NUM);
	int roots_num = find_roots(a, roots);
	print_roots(roots_num, roots);
}