#include <limits.h>
#include <string>
#include "DES.h"
#include "gtest/gtest.h"
using namespace std;


/*============================
===========KEY TESTS==========
============================*/

TEST(KeyInitPermutationTest, TestOne) {
	
	// Test initial permutation
	const string key = "1234567890ABCDEF";
	const string permutedKey = "11110000110011001010101000011010010111000110111010001111";

	EXPECT_EQ(permutedKey, initKeyPermutation(key));
}

TEST(KeyCircularShiftTest, TestOne) {
	
	// Test circular shifting of key
	const string leftHalfKey = "1111000011001100101010100001";
	const string rightHalfKey = "1010010111000110111010001111";
	const string shiftedLeftHalf = "1110000110011001010101000011";
	const string shiftedRightHalf = "0100101110001101110100011111";
	
	EXPECT_EQ(shiftedLeftHalf, halfCircularShift(leftHalfKey, 1));
	EXPECT_EQ(shiftedRightHalf, halfCircularShift(rightHalfKey, 1));
}

TEST(KeySingleRoundPermutationTest, TestOne) {
	
	// Test round permutation of key
	const string key = "11100001100110010101010000110100101110001101110100011111";
	const string permutedKey = "000010110000001001101111110101100111100101110100";
	
	EXPECT_EQ(permutedKey, roundPermutation(key));
}


/*============================
==========TEXT TESTS==========
============================*/

TEST(TextInitPermutationTest, TestOne) {
	
	// Test initial permutation
	const string text = "0123456789ABCDEF";
	const string permutedText = "1100110000000000110011001111111111110000101010101111000010101010";

	EXPECT_EQ(permutedText, initTextPermutation(text));
}

TEST(TextExpansionTableTest, TestOne) {
	
	// Test expansion table
	const string rightHalfText = "11110000101010101111000010101010";
	const string expandedRightHalf = "011110100001010101010101011110100001010101010101";
	
	EXPECT_EQ(expandedRightHalf, expandHalfText(rightHalfText));
}

TEST(TextXORTest, TestOne) {
	
	// Test text XOR key
	const string text    = "011110100001010101010101011110100001010101010101";
	const string key     = "000010110000001001101111110101100111100101110100";
	const string XORtext = "011100010001011100111010101011000110110000100001";
	
	EXPECT_EQ(XORtext, XOR(text, key));
}

TEST(TextSboxTest, TestOne) {
	
	// Test S Box calculation
	const string text = "011100010001011100111010101011000110110000100001";
	const string output = "00001100001000101110111110100010";
	
	EXPECT_EQ(output, calcSBox(text));
}