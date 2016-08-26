/*
 * file:       Preprocessor.cpp
 *
 * created:    26.08.2016
 * author:     Anton Kashcheev
 */
#ifndef COMMON_PREPROCESSOR_HPP
#define COMMON_PREPROCESSOR_HPP

/*

#define select( selector, ... ) impl ## _ ## selector( __VA_ARGS__ )
#define impl_1() meh
#define impl_2( abc, xyz ) # abc "wizza" xyz()
//etc

// usage: select( 1 ) => impl_1() => meh
//        select( 2, huz, bar ) => impl_2( huzza, bar ) => "huz" "wizza" bar()

#define CAT( A, B ) A ## B
#define SELECT( NAME, NUM ) CAT( NAME ## _, NUM )

#define GET_COUNT( _1, _2, _3, _4, _5, _6, COUNT, ... ) COUNT
#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1 )




#define CAT( A, B ) A ## B
#define SELECT( NAME, NUM ) CAT( NAME ## _, NUM )

#define GET_COUNT( _1, _2, _3, _4, _5, _6 , COUNT, ... ) COUNT
#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1 )

#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)


#define MY_OVERLOADED( ... ) VA_SELECT( MY_IMPL, __VA_ARGS__ )
#define MY_IMPL_1( X ) foo< X >
#define MY_IMPL_2( X, Y ) bar< X >( Y )
#define MY_IMPL_3( X, Y, Z ) bang_ ## X< Y >.Z()

*/


#define OVERLOADING_MACRO(SUBJECT) \
		hello##SUBJECT

#define CONC(A, B) A ## B

#define GET_COUNT ( \
		_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) \
	N

#define NARGS(...) GET_COUNT(__VA_ARGS__, \
		10, 9, 8, 7, 6, 5, 4, 3, 2, 1 )

#define GENERATE_ARG1(OBJECT1) \
		OVERLOADING_MACRO(OBJECT1)

#define GENERATE_ARG2(OBJECT1, OBJECT2) \
		GENERATE_ARG1(OBJECT1) \
		GENERATE_ARG1(OBJECT2)

#define GENERATE_ARG3(OBJECT1, OBJECT2, OBJECT3) \
		GENERATE_ARG2(OBJECT1, OBJECT2) \
		GENERATE_ARG1(OBJECT3)

#define GENERATE(NAME, ... ) CONC(NAME ## _, NARGS(__VA_ARGS__) )


//#define GENERATE_ARG4(OBJECT1) tplPrototypeClone(OBJECT1)

GENERATE(GENERATE_ARG, Cat, Mouse, Dolphin)

#endif // COMMON_PREPROCESSOR_HPP
