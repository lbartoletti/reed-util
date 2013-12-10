#pragma once
#include <cmath>
#include <float.h>

// Compile-time array size
template <typename T, int N> char(&dim_helper(T(&)[N]))[N];
#define dim(x) (sizeof(dim_helper(x)))
#define dim_field(S, m) dim(((S*)0)->m)

// Compile-time assert
#define cassert(x) static_assert(x, #x)

namespace util
{
	// "uint" is a lot shorter than "unsigned int"
	typedef unsigned int uint;

	// Delicious pi
	const float pi = 3.141592654f;

	// Convenient float constants
	const float epsilon = 1e-6f;		// A reasonable general-purpose epsilon
	extern const float infty;
	extern const float NaN;

	// Generic min/max/abs/clamp/saturate
	template <typename T>
	T min(T a, T b) { return (a < b) ? a : b; }
	template <typename T>
	T max(T a, T b) { return (a < b) ? b : a; }
	template <typename T>
	T abs(T a) { return (a < T(0)) ? -a : a; }
	template <typename T>
	T clamp(T value, T lower, T upper) { return min(max(value, lower), upper); }
	template <typename T>
	T saturate(T value) { return clamp(value, T(0), T(1)); }

	// Generic lerp
	template <typename T>
	T lerp(T a, T b, float u) { return a + (b - a) * u; }

	// Test for finiteness
	bool isfinite(float f);
	inline bool isfinite(double d)
		{ return (_finite(d) != 0); }

	// Print error message and exit
	void __declspec(noreturn) exit(const char * fmt, ...);
}

// Random number library
#include "util-rng.h"

// Vector/matrix math library
#include "util-vector.h"
#include "util-matrix.h"