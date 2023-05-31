#include <limits.h>
#include "DES.h"
#include "gtest/gtest.h"
using namespace std;


/*============================
===========KEY TESTS==========
============================*/

TEST(KeyInitPermutationTest, TestOne) {
	
	// Test initial permutation
	 char key []= "C2345678ABCEDFF9";
	 char permutedKey[] = "11110001111011011001101011000111010101100110111110001110";

char *s=initKeyPermutation(key);
	for (int i = 0; i < 56; i++)
	{
			EXPECT_EQ(permutedKey[i], s[i]);

	}
	
}

TEST(KeyCircularShiftTest, TestOne) {
	
	// Test circular shifting of key
	 char leftHalfKey[] = "1111000111101101100110101100";
	 char rightHalfKey []= "0111010101100110111110001110";
	 char shiftedLeftHalf[] = "1110001111011011001101011001";
	 char shiftedRightHalf[] = "1110101011001101111100011100";
	char *s=halfCircularShift(leftHalfKey,1);
	for (int i = 0; i < 28; i++)
	{
			EXPECT_EQ(shiftedLeftHalf[i], s[i]);

	}
		char *r=halfCircularShift(rightHalfKey,1);
	for (int i = 0; i < 28; i++)
	{
			EXPECT_EQ(shiftedRightHalf[i], r[i]);

	}

}

TEST(KeySingleRoundPermutationTest, TestOne) {
	
	// Test round permutation of key
	 char key []= "11100011110110110011010110011110101011001101111100011100";
	 char permutedKey[] = "000110111001011001110111111110100111100001110010";
	
	char *r=roundPermutation(key);
	for (int i = 0; i < 48; i++)
	{
			EXPECT_EQ(permutedKey[i], r[i]);

	}}


/*============================
==========TEXT TESTS==========
============================*/

TEST(TextInitPermutationTest, TestOne) {
	
	// Test initial permutation
	 char text []= "C123456789CBCDEF";
	 char permutedText[] = "1110110100000000110011001111111111110001100010101111000010101010";
	char *r=initTextPermutation(text);
	for (int i = 0; i < 64; i++)
	{
			EXPECT_EQ(permutedText[i], r[i]);

	}
}

TEST(TextExpansionTableTest, TestOne) {
	
	// Test expansion table
	 char rightHalfText []= "11110001100010101111000010101010";
	 char expandedRightHalf[] = "011110100011110001010101011110100001010101010101";
		char *r=expandHalfText(rightHalfText);
	for (int i = 0; i < 48; i++)
	{
			EXPECT_EQ(expandedRightHalf[i], r[i]);

	}

}

TEST(TextXORTest, TestOne) {
	
	// Test text XOR key
	 char text    []= "011110100011110001010101011110100001010101010101";
	 char key     []= "000110111001011001110111111110100111100001110010";
	 char XORtext []= "011000011010101000100010100000000110110100100111";
	
	char *r=XOR(text,key);
	for (int i = 0; i < 48; i++)
	{
			EXPECT_EQ(XORtext[i], r[i]);

	}
}

TEST(TextSboxTest, TestOne) {
	
	// Test S Box calculation
	 char text []= "011000011010101000100010100000000110110100100111";
	 char output[] = "01010000100001100100111101100111";
	
char *r=calcSBox(text);
	for (int i = 0; i < 32; i++)
	{
			EXPECT_EQ(output[i], r[i]);

	}
	}