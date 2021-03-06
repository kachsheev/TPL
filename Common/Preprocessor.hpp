/*
 * file:       Preprocessor.cpp
 *
 * created:    26.08.2016
 * author:     Anton Kashcheev
 */
#ifndef COMMON_PREPROCESSOR_HPP
#define COMMON_PREPROCESSOR_HPP


#ifndef OVERLOADING
#define OVERLOADING(SUBJ) \
	SUBJ *create##SUBJ();
#endif

#define CONC(X,Y) X##Y

#define COUNT_ARGS(...) \
	_COUNT_ARGS_(__VA_ARGS__,SEARCH_NUMBER())

#define _COUNT_ARGS_(...) \
	_ARG_NUMBER_(__VA_ARGS__)

#define _ARG_NUMBER_( \
		 _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
		_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
		_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
		_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
		_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
		_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
		_61,_62,_63,N,...) \
	N

#define SEARCH_NUMBER() \
         63,62,61,60,                   \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

#define NEED_MACRO() \
	MACROFUNC_63,MACROFUNC_62,MACROFUNC_61,MACROFUNC_60, \
	MACROFUNC_59,MACROFUNC_58,MACROFUNC_57,MACROFUNC_56, \
	MACROFUNC_55,MACROFUNC_54,MACROFUNC_53,MACROFUNC_52, \
	MACROFUNC_51,MACROFUNC_50,MACROFUNC_49,MACROFUNC_48, \
	MACROFUNC_47,MACROFUNC_46,MACROFUNC_45,MACROFUNC_44, \
	MACROFUNC_43,MACROFUNC_42,MACROFUNC_41,MACROFUNC_40, \
	MACROFUNC_39,MACROFUNC_38,MACROFUNC_37,MACROFUNC_36, \
	MACROFUNC_35,MACROFUNC_34,MACROFUNC_33,MACROFUNC_32, \
	MACROFUNC_31,MACROFUNC_30,MACROFUNC_29,MACROFUNC_28, \
	MACROFUNC_27,MACROFUNC_26,MACROFUNC_25,MACROFUNC_24, \
	MACROFUNC_23,MACROFUNC_22,MACROFUNC_21,MACROFUNC_20, \
	MACROFUNC_19,MACROFUNC_18,MACROFUNC_17,MACROFUNC_16, \
	MACROFUNC_15,MACROFUNC_14,MACROFUNC_13,MACROFUNC_12, \
	MACROFUNC_11,MACROFUNC_10,MACROFUNC_9, MACROFUNC_8 , \
	MACROFUNC_7, MACROFUNC_6, MACROFUNC_5, MACROFUNC_4, \
	MACROFUNC_3, MACROFUNC_2,MACROFUNC_1,0


#define MACROFUNC_1(SUBJ1) OVERLOADING(SUBJ1)
#define MACROFUNC_2(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_1(__VA_ARGS__)
#define MACROFUNC_3(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_2(__VA_ARGS__)
#define MACROFUNC_4(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_3(__VA_ARGS__)
#define MACROFUNC_5(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_4(__VA_ARGS__)
#define MACROFUNC_6(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_5(__VA_ARGS__)
#define MACROFUNC_7(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_6(__VA_ARGS__)
#define MACROFUNC_8(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_7(__VA_ARGS__)
#define MACROFUNC_9(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_8(__VA_ARGS__)
#define MACROFUNC_10(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_9(__VA_ARGS__)
#define MACROFUNC_11(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_10(__VA_ARGS__)
#define MACROFUNC_12(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_11(__VA_ARGS__)
#define MACROFUNC_13(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_12(__VA_ARGS__)
#define MACROFUNC_14(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_13(__VA_ARGS__)
#define MACROFUNC_15(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_14(__VA_ARGS__)
#define MACROFUNC_16(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_15(__VA_ARGS__)
#define MACROFUNC_17(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_16(__VA_ARGS__)
#define MACROFUNC_18(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_17(__VA_ARGS__)
#define MACROFUNC_19(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_18(__VA_ARGS__)
#define MACROFUNC_20(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_19(__VA_ARGS__)
#define MACROFUNC_21(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_20(__VA_ARGS__)
#define MACROFUNC_22(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_21(__VA_ARGS__)
#define MACROFUNC_23(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_22(__VA_ARGS__)
#define MACROFUNC_24(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_23(__VA_ARGS__)
#define MACROFUNC_25(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_24(__VA_ARGS__)
#define MACROFUNC_26(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_25(__VA_ARGS__)
#define MACROFUNC_27(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_26(__VA_ARGS__)
#define MACROFUNC_28(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_27(__VA_ARGS__)
#define MACROFUNC_29(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_28(__VA_ARGS__)
#define MACROFUNC_30(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_29(__VA_ARGS__)
#define MACROFUNC_31(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_30(__VA_ARGS__)
#define MACROFUNC_32(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_31(__VA_ARGS__)
#define MACROFUNC_33(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_32(__VA_ARGS__)
#define MACROFUNC_34(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_33(__VA_ARGS__)
#define MACROFUNC_35(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_34(__VA_ARGS__)
#define MACROFUNC_36(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_35(__VA_ARGS__)
#define MACROFUNC_37(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_36(__VA_ARGS__)
#define MACROFUNC_38(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_37(__VA_ARGS__)
#define MACROFUNC_39(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_38(__VA_ARGS__)
#define MACROFUNC_40(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_39(__VA_ARGS__)
#define MACROFUNC_41(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_40(__VA_ARGS__)
#define MACROFUNC_42(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_41(__VA_ARGS__)
#define MACROFUNC_43(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_42(__VA_ARGS__)
#define MACROFUNC_44(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_43(__VA_ARGS__)
#define MACROFUNC_45(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_44(__VA_ARGS__)
#define MACROFUNC_46(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_45(__VA_ARGS__)
#define MACROFUNC_47(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_46(__VA_ARGS__)
#define MACROFUNC_48(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_47(__VA_ARGS__)
#define MACROFUNC_49(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_48(__VA_ARGS__)
#define MACROFUNC_50(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_49(__VA_ARGS__)
#define MACROFUNC_51(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_50(__VA_ARGS__)
#define MACROFUNC_52(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_51(__VA_ARGS__)
#define MACROFUNC_53(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_52(__VA_ARGS__)
#define MACROFUNC_54(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_53(__VA_ARGS__)
#define MACROFUNC_55(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_54(__VA_ARGS__)
#define MACROFUNC_56(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_55(__VA_ARGS__)
#define MACROFUNC_57(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_56(__VA_ARGS__)
#define MACROFUNC_58(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_57(__VA_ARGS__)
#define MACROFUNC_59(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_58(__VA_ARGS__)
#define MACROFUNC_60(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_59(__VA_ARGS__)
#define MACROFUNC_61(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_60(__VA_ARGS__)
#define MACROFUNC_62(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_61(__VA_ARGS__)
#define MACROFUNC_63(SUBJ1, ...) OVERLOADING(SUBJ1) MACROFUNC_62(__VA_ARGS__)

#define tplGenerator(...) \
	_COUNT_ARGS_(__VA_ARGS__,NEED_MACRO())(__VA_ARGS__)

// work
//tplGenerator(Cat, Dog, Mouse, Tiger)

#endif // COMMON_PREPROCESSOR_HPP
