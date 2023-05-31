#include <limits.h>
#include "DES.h"
#include "gtest/gtest.h"
using namespace std;


/*============================
===========KEY TESTS==========
============================*/

TEST(KeyInitPermutationTest, TestOne) {
	
	// Test initial permutation
	  char key[] = "1234567890ABCDEF";
	 char permutedKey[] = "11110000110011001010101000011010010111000110111010001111";
	char *s=initKeyPermutation(key);
	for (int i = 0; i < 56; i++)
	{
			EXPECT_EQ(permutedKey[i], s[i]);

	}
	

}

TEST(KeyCircularShiftTest, TestOne) {
	
	// Test circular shifting of key
	 char leftHalfKey []= "1111000011001100101010100001";
	 char rightHalfKey []= "1010010111000110111010001111";
	 char shiftedLeftHalf[] = "1110000110011001010101000011";
	 char shiftedRightHalf []= "0100101110001101110100011111";
	
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
	 char key []= "11100001100110010101010000110100101110001101110100011111";
	 char permutedKey []= "000010110000001001101111110101100111100101110100";
		char *r=roundPermutation(key);
	for (int i = 0; i < 48; i++)
	{
			EXPECT_EQ(permutedKey[i], r[i]);

	}
}


/*============================
==========TEXT TESTS==========
============================*/

TEST(TextInitPermutationTest, TestOne) {
	
	// Test initial permutation
	 char text []= "0123456789ABCDEF";
	 char permutedText[] = "1100110000000000110011001111111111110000101010101111000010101010";
		char *r=initTextPermutation(text);
	for (int i = 0; i < 64; i++)
	{
			EXPECT_EQ(permutedText[i], r[i]);

	}
}

TEST(TextExpansionTableTest, TestOne) {
	
	// Test expansion table
	 char rightHalfText []= "11110000101010101111000010101010";
	 char expandedRightHalf[] = "011110100001010101010101011110100001010101010101";
		char *r=expandHalfText(rightHalfText);
	for (int i = 0; i < 48; i++)
	{
			EXPECT_EQ(expandedRightHalf[i], r[i]);

	}
	//EXPECT_EQ(expandedRightHalf, expandHalfText(rightHalfText));
}

TEST(TextXORTest, TestOne) {
	
	// Test text XOR key
	 char text[]= "011110100001010101010101011110100001010101010101";
	 char key[]     = "000010110000001001101111110101100111100101110100";
	 char XORtext[] = "011100010001011100111010101011000110110000100001";
	char *r=XOR(text,key);
	for (int i = 0; i < 48; i++)
	{
			EXPECT_EQ(XORtext[i], r[i]);

	}
}

TEST(TextSboxTest, TestOne) {
	
	// Test S Box calculation
	 char text[] = "011100010001011100111010101011000110110000100001";
	 char output[] = "00001100001000101110111110100010";
	char *r=calcSBox(text);
	for (int i = 0; i < 32; i++)
	{
			EXPECT_EQ(output[i], r[i]);

	}
	// EXPECT_EQ(output, calcSBox(text));
}