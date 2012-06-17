/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/

#ifndef _MATH_H_
#define _MATH_H_
#include <math.h>

#ifndef FLT_MAX
#define FLT_MAX 3.402823466E+38F
#endif

namespace doubal
{
namespace core
{

	//! Rounding error constant often used when comparing float values.

	const int ROUNDING_ERROR_int = 0;
	const float ROUNDING_ERROR_float = 0.000001f;
	const double ROUNDING_ERROR_double = 0.00000001;

#ifdef PI // make sure we don't collide with a define
#undef PI
#endif
	//! Constant for PI.
	const float PI		= 3.14159265359f;

	//! Constant for reciprocal of PI.
	const float RECIPROCAL_PI	= 1.0f/PI;

	//! Constant for half of PI.
	const float HALF_PI	= PI/2.0f;

#ifdef PI64 // make sure we don't collide with a define
#undef PI64
#endif
	//! Constant for 64bit PI.
	const double PI64		= 3.1415926535897932384626433832795028841971693993751;

	//! Constant for 64bit reciprocal of PI.
	const double RECIPROCAL_PI64 = 1.0/PI64;

	//! 32bit Constant for converting from degrees to radians
	const float DEGTORAD = PI / 180.0f;

	//! 32bit constant for converting from radians to degrees (formally known as GRAD_PI)
	const float RADTODEG   = 180.0f / PI;

	//! 64bit constant for converting from degrees to radians (formally known as GRAD_PI2)
	const double DEGTORAD64 = PI64 / 180.0;

	//! 64bit constant for converting from radians to degrees
	const double RADTODEG64 = 180.0 / PI64;

	//! Utility function to convert a radian value to degrees
	/** Provided as it can be clearer to write radToDeg(X) than RADTODEG * X
	\param radians	The radians value to convert to degrees.
	*/
	inline float radToDeg(float radians)
	{
		return RADTODEG * radians;
	}

	//! Utility function to convert a radian value to degrees
	/** Provided as it can be clearer to write radToDeg(X) than RADTODEG * X
	\param radians	The radians value to convert to degrees.
	*/
	inline double radToDeg(double radians)
	{
		return RADTODEG64 * radians;
	}

	//! Utility function to convert a degrees value to radians
	/** Provided as it can be clearer to write degToRad(X) than DEGTORAD * X
	\param degrees	The degrees value to convert to radians.
	*/
	inline float degToRad(float degrees)
	{
		return DEGTORAD * degrees;
	}

	//! Utility function to convert a degrees value to radians
	/** Provided as it can be clearer to write degToRad(X) than DEGTORAD * X
	\param degrees	The degrees value to convert to radians.
	*/
	inline double degToRad(double degrees)
	{
		return DEGTORAD64 * degrees;
	}

	//! returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T& min_(const T& a, const T& b)
	{
		return a < b ? a : b;
	}

	//! returns minimum of three values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T& min_(const T& a, const T& b, const T& c)
	{
		return a < b ? min_(a, c) : min_(b, c);
	}

	//! returns maximum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T& max_(const T& a, const T& b)
	{
		return a < b ? b : a;
	}

	//! returns maximum of three values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T& max_(const T& a, const T& b, const T& c)
	{
		return a < b ? max_(b, c) : max_(a, c);
	}

	//! returns abs of two values. Own implementation to get rid of STL (VS6 problems)
	template<class T>
	inline T abs_(const T& a)
	{
		return a < (T)0 ? -a : a;
	}

	//! returns linear interpolation of a and b with ratio t
	//! \return: a if t==0, b if t==1, and the linear interpolation else
	template<class T>
	inline T lerp(const T& a, const T& b, const float t)
	{
		return (T)(a*(1.f-t)) + (b*t);
	}

	//! clamps a value between low and high
	template <class T>
	inline const T clamp (const T& value, const T& low, const T& high)
	{
		return min_ (max_(value,low), high);
	}

	//! swaps the content of the passed parameters
	// Note: We use the same trick as boost and use two template arguments to
	// avoid ambiguity when swapping objects of an Irrlicht type that has not
	// it's own swap overload. Otherwise we get conflicts with some compilers
	// in combination with stl.
	template <class T1, class T2>
	inline void swap(T1& a, T2& b)
	{
		T1 c(a);
		a = b;
		b = c;
	}

	//! returns if a equals b, taking possible rounding errors into account
	inline bool equals(const double a, const double b, const double tolerance = ROUNDING_ERROR_double)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}

	//! returns if a equals b, taking possible rounding errors into account
	inline bool equals(const float a, const float b, const float tolerance = ROUNDING_ERROR_float)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}
#if 0
	//! returns if a equals b, not using any rounding tolerance
	inline bool equals(const int a, const int b)
	{
		return (a == b);
	}

	//! returns if a equals b, not using any rounding tolerance
	inline bool equals(const unsigned int a, const unsigned int b)
	{
		return (a == b);
	}
#endif
	//! returns if a equals b, taking an explicit rounding tolerance into account
	inline bool equals(const int a, const int b, const int tolerance = ROUNDING_ERROR_int)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}

	//! returns if a equals b, taking an explicit rounding tolerance into account
	inline bool equals(const unsigned int a, const unsigned int b, const int tolerance = ROUNDING_ERROR_int)
	{
		return (a + tolerance >= b) && (a - tolerance <= b);
	}


	//! returns if a equals zero, taking rounding errors into account
	inline bool iszero(const double a, const double tolerance = ROUNDING_ERROR_double)
	{
		return fabs(a) <= tolerance;
	}

	//! returns if a equals zero, taking rounding errors into account
	inline bool iszero(const float a, const float tolerance = ROUNDING_ERROR_float)
	{
		return fabsf(a) <= tolerance;
	}

	//! returns if a equals not zero, taking rounding errors into account
	inline bool isnotzero(const float a, const float tolerance = ROUNDING_ERROR_float)
	{
		return fabsf(a) > tolerance;
	}

	//! returns if a equals zero, taking rounding errors into account
	inline bool iszero(const int a, const int tolerance = 0)
	{
		return ( a & 0x7ffffff ) <= tolerance;
	}

	//! returns if a equals zero, taking rounding errors into account
	inline bool iszero(const unsigned int a, const unsigned int tolerance = 0)
	{
		return a <= tolerance;
	}

	inline int int_min(int a, int b)
	{
		const int mask = (a - b) >> 31;
		return (a & mask) | (b & ~mask);
	}

	inline int int_max(int a, int b)
	{
		const int mask = (a - b) >> 31;
		return (b & mask) | (a & ~mask);
	}

	inline int int_clamp (int value, int low, int high)
	{
		return int_min(int_max(value,low), high);
	}

	/*
		float IEEE-754 bit represenation

		0      0x00000000
		1.0    0x3f800000
		0.5    0x3f000000
		3      0x40400000
		+inf   0x7f800000
		-inf   0xff800000
		+NaN   0x7fc00000 or 0x7ff00000
		in general: number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)
	*/

	typedef union { unsigned int u; int s; float f; } inttofloat;

	#define float_AS_int(f)		(*((int *) &(f)))
	#define float_AS_unsigned int(f)		(*((unsigned int *) &(f)))

	#define float_VALUE_0		0x00000000
	#define float_VALUE_1		0x3f800000
	#define float_SIGN_BIT		0x80000000U
	#define float_EXPON_MANTISSA	0x7FFFFFFFU

	//! code is taken from IceFPU
	//! Integer representation of a floating-point value.
#ifdef IRRLICHT_FAST_MATH
	#define IR(x)                           ((unsigned int&)(x))
#else
	inline unsigned int IR(float x) {inttofloat tmp; tmp.f=x; return tmp.u;}
#endif

	//! Absolute integer representation of a floating-point value
	#define AIR(x)				(IR(x)&0x7fffffff)

	//! Floating-point representation of an integer value.
#ifdef IRRLICHT_FAST_MATH
	#define FR(x)                           ((float&)(x))
#else
	inline float FR(unsigned int x) {inttofloat tmp; tmp.u=x; return tmp.f;}
	inline float FR(int x) {inttofloat tmp; tmp.s=x; return tmp.f;}
#endif

	//! integer representation of 1.0
	#define IEEE_1_0			0x3f800000
	//! integer representation of 255.0
	#define IEEE_255_0			0x437f0000

#ifdef IRRLICHT_FAST_MATH
	#define	float_LOWER_0(f)		(float_AS_unsigned int(f) >  float_SIGN_BIT)
	#define	float_LOWER_EQUAL_0(f)	(float_AS_int(f) <= float_VALUE_0)
	#define	float_GREATER_0(f)	(float_AS_int(f) >  float_VALUE_0)
	#define	float_GREATER_EQUAL_0(f)	(float_AS_unsigned int(f) <= float_SIGN_BIT)
	#define	float_EQUAL_1(f)		(float_AS_unsigned int(f) == float_VALUE_1)
	#define	float_EQUAL_0(f)		( (float_AS_unsigned int(f) & float_EXPON_MANTISSA ) == float_VALUE_0)

	// only same sign
	#define	float_A_GREATER_B(a,b)	(float_AS_int((a)) > float_AS_int((b)))

#else

	#define	float_LOWER_0(n)		((n) <  0.0f)
	#define	float_LOWER_EQUAL_0(n)	((n) <= 0.0f)
	#define	float_GREATER_0(n)	((n) >  0.0f)
	#define	float_GREATER_EQUAL_0(n)	((n) >= 0.0f)
	#define	float_EQUAL_1(n)		((n) == 1.0f)
	#define	float_EQUAL_0(n)		((n) == 0.0f)
	#define	float_A_GREATER_B(a,b)	((a) > (b))
#endif


#ifndef REALINLINE
	#ifdef _MSC_VER
		#define REALINLINE __forceinline
	#else
		#define REALINLINE inline
	#endif
#endif

#if defined(__BORLANDC__) || defined (__BCPLUSPLUS__)

	// 8-bit bools in borland builder

	//! conditional set based on mask and arithmetic shift
	REALINLINE unsigned int if_c_a_else_b ( const char condition, const unsigned int a, const unsigned int b )
	{
		return ( ( -condition >> 7 ) & ( a ^ b ) ) ^ b;
	}

	//! conditional set based on mask and arithmetic shift
	REALINLINE unsigned int if_c_a_else_0 ( const char condition, const unsigned int a )
	{
		return ( -condition >> 31 ) & a;
	}
#else

	//! conditional set based on mask and arithmetic shift
	REALINLINE unsigned int if_c_a_else_b ( const int condition, const unsigned int a, const unsigned int b )
	{
		return ( ( -condition >> 31 ) & ( a ^ b ) ) ^ b;
	}

	//! conditional set based on mask and arithmetic shift
	REALINLINE unsigned short if_c_a_else_b ( const short condition, const unsigned short a, const unsigned short b )
	{
		return ( ( -condition >> 15 ) & ( a ^ b ) ) ^ b;
	}

	//! conditional set based on mask and arithmetic shift
	REALINLINE unsigned int if_c_a_else_0 ( const int condition, const unsigned int a )
	{
		return ( -condition >> 31 ) & a;
	}
#endif

	/*
		if (condition) state |= m; else state &= ~m;
	*/
	REALINLINE void setbit_cond ( unsigned int &state, int condition, unsigned int mask )
	{
		// 0, or any postive to mask
		//int conmask = -condition >> 31;
		state ^= ( ( -condition >> 31 ) ^ state ) & mask;
	}

	inline float round_( float x )
	{
		return floorf( x + 0.5f );
	}

	REALINLINE void clearFPUException ()
	{
#ifdef IRRLICHT_FAST_MATH
		return;
#ifdef feclearexcept
		feclearexcept(FE_ALL_EXCEPT);
#elif defined(_MSC_VER)
		__asm fnclex;
#elif defined(__GNUC__) && defined(__x86__)
		__asm__ __volatile__ ("fclex \n\t");
#else
#  warn clearFPUException not supported.
#endif
#endif
	}

	// calculate: sqrt ( x )
	REALINLINE float squareroot(const float f)
	{
		return sqrtf(f);
	}

	// calculate: sqrt ( x )
	REALINLINE double squareroot(const double f)
	{
		return sqrt(f);
	}

	// calculate: sqrt ( x )
	REALINLINE int squareroot(const int f)
	{
		return static_cast<int>(squareroot(static_cast<float>(f)));
	}

	// calculate: 1 / sqrt ( x )
	REALINLINE double reciprocal_squareroot(const double x)
	{
		return 1.0 / sqrt(x);
	}

	// calculate: 1 / sqrtf ( x )
	REALINLINE float reciprocal_squareroot(const float f)
	{
#if defined ( IRRLICHT_FAST_MATH )
	#if defined(_MSC_VER)
		// SSE reciprocal square root estimate, accurate to 12 significant
		// bits of the mantissa
		float recsqrt;
		__asm rsqrtss xmm0, f           // xmm0 = rsqrtss(f)
		__asm movss recsqrt, xmm0       // return xmm0
		return recsqrt;

/*
		// comes from Nvidia
		unsigned int tmp = (unsigned int(IEEE_1_0 << 1) + IEEE_1_0 - *(unsigned int*)&x) >> 1;
		float y = *(float*)&tmp;
		return y * (1.47f - 0.47f * x * y * y);
*/
	#else
		return 1.f / sqrtf(f);
	#endif
#else // no fast math
		return 1.f / sqrtf(f);
#endif
	}

	// calculate: 1 / sqrtf( x )
	REALINLINE int reciprocal_squareroot(const int x)
	{
		return static_cast<int>(reciprocal_squareroot(static_cast<float>(x)));
	}

	// calculate: 1 / x
	REALINLINE float reciprocal( const float f )
	{
#if defined (IRRLICHT_FAST_MATH)

		// SSE Newton-Raphson reciprocal estimate, accurate to 23 significant
		// bi ts of the mantissa
		// One Newtown-Raphson Iteration:
		// f(i+1) = 2 * rcpss(f) - f * rcpss(f) * rcpss(f)
		float rec;
		__asm rcpss xmm0, f               // xmm0 = rcpss(f)
		__asm movss xmm1, f               // xmm1 = f
		__asm mulss xmm1, xmm0            // xmm1 = f * rcpss(f)
		__asm mulss xmm1, xmm0            // xmm2 = f * rcpss(f) * rcpss(f)
		__asm addss xmm0, xmm0            // xmm0 = 2 * rcpss(f)
		__asm subss xmm0, xmm1            // xmm0 = 2 * rcpss(f)
										  //        - f * rcpss(f) * rcpss(f)
		__asm movss rec, xmm0             // return xmm0
		return rec;


		//! i do not divide through 0.. (fpu expection)
		// instead set f to a high value to get a return value near zero..
		// -1000000000000.f.. is use minus to stay negative..
		// must test's here (plane.normal dot anything ) checks on <= 0.f
		//unsigned int x = (-(AIR(f) != 0 ) >> 31 ) & ( IR(f) ^ 0xd368d4a5 ) ^ 0xd368d4a5;
		//return 1.f / FR ( x );

#else // no fast math
		return 1.f / f;
#endif
	}

	// calculate: 1 / x
	REALINLINE double reciprocal ( const double f )
	{
		return 1.0 / f;
	}


	// calculate: 1 / x, low precision allowed
	REALINLINE float reciprocal_approxim ( const float f )
	{
#if defined( IRRLICHT_FAST_MATH)

		// SSE Newton-Raphson reciprocal estimate, accurate to 23 significant
		// bi ts of the mantissa
		// One Newtown-Raphson Iteration:
		// f(i+1) = 2 * rcpss(f) - f * rcpss(f) * rcpss(f)
		float rec;
		__asm rcpss xmm0, f               // xmm0 = rcpss(f)
		__asm movss xmm1, f               // xmm1 = f
		__asm mulss xmm1, xmm0            // xmm1 = f * rcpss(f)
		__asm mulss xmm1, xmm0            // xmm2 = f * rcpss(f) * rcpss(f)
		__asm addss xmm0, xmm0            // xmm0 = 2 * rcpss(f)
		__asm subss xmm0, xmm1            // xmm0 = 2 * rcpss(f)
										  //        - f * rcpss(f) * rcpss(f)
		__asm movss rec, xmm0             // return xmm0
		return rec;


/*
		// SSE reciprocal estimate, accurate to 12 significant bits of
		float rec;
		__asm rcpss xmm0, f             // xmm0 = rcpss(f)
		__asm movss rec , xmm0          // return xmm0
		return rec;
*/
/*
		register unsigned int x = 0x7F000000 - IR ( p );
		const float r = FR ( x );
		return r * (2.0f - p * r);
*/
#else // no fast math
		return 1.f / f;
#endif
	}


	REALINLINE int floor32(float x)
	{
#ifdef IRRLICHT_FAST_MATH
		const float h = 0.5f;

		int t;

#if defined(_MSC_VER)
		__asm
		{
			fld	x
			fsub	h
			fistp	t
		}
#elif defined(__GNUC__)
		__asm__ __volatile__ (
			"fsub %2 \n\t"
			"fistpl %0"
			: "=m" (t)
			: "t" (x), "f" (h)
			: "st"
			);
#else
#  warn IRRLICHT_FAST_MATH not supported.
		return (int) floorf ( x );
#endif
		return t;
#else // no fast math
		return (int) floorf ( x );
#endif
	}


	REALINLINE int ceil32 ( float x )
	{
#ifdef IRRLICHT_FAST_MATH
		const float h = 0.5f;

		int t;

#if defined(_MSC_VER)
		__asm
		{
			fld	x
			fadd	h
			fistp	t
		}
#elif defined(__GNUC__)
		__asm__ __volatile__ (
			"fadd %2 \n\t"
			"fistpl %0 \n\t"
			: "=m"(t)
			: "t"(x), "f"(h)
			: "st"
			);
#else
#  warn IRRLICHT_FAST_MATH not supported.
		return (int) ceilf ( x );
#endif
		return t;
#else // not fast math
		return (int) ceilf ( x );
#endif
	}



	REALINLINE int round32(float x)
	{
#if defined(IRRLICHT_FAST_MATH)
		int t;

#if defined(_MSC_VER)
		__asm
		{
			fld   x
			fistp t
		}
#elif defined(__GNUC__)
		__asm__ __volatile__ (
			"fistpl %0 \n\t"
			: "=m"(t)
			: "t"(x)
			: "st"
			);
#else
#  warn IRRLICHT_FAST_MATH not supported.
		return (int) round_(x);
#endif
		return t;
#else // no fast math
		return (int) round_(x);
#endif
	}

	inline float float_max3(const float a, const float b, const float c)
	{
		return a > b ? (a > c ? a : c) : (b > c ? b : c);
	}

	inline float float_min3(const float a, const float b, const float c)
	{
		return a < b ? (a < c ? a : c) : (b < c ? b : c);
	}

	inline float fract ( float x )
	{
		return x - floorf ( x );
	}

} // end namespace core
} // end namespace doubal

#ifndef IRRLICHT_FAST_MATH
	using doubal::core::IR;
	using doubal::core::FR;
#endif

#endif

