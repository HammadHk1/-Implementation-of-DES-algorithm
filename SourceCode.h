#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
string HextoBin(string a) {//function for converting hexadecimal number into binary number
	int n = a.length();
	string* arr1 = new  string[n];
	for (int x = 0; x < n; x++) {
		if (a[x] == '0') {
			arr1[x] = "0000";
		}
		else if (a[x] == '1') {
			arr1[x] = "0001";
		}
		else if (a[x] == '2') {
			arr1[x] = "0010";
		}
		else if (a[x] == '3') {
			arr1[x] = "0011";
		}
		else if (a[x] == '4') {
			arr1[x] = "0100";
		}
		else if (a[x] == '5') {
			arr1[x] = "0101";
		}
		else if (a[x] == '6') {
			arr1[x] = "0110";
		}
		else if (a[x] == '7') {
			arr1[x] = "0111";
		}
		else if (a[x] == '8') {
			arr1[x] = "1000";
		}
		else if (a[x] == '9') {
			arr1[x] = "1001";
		}
		else if (a[x] == 'A' || a[x] == 'a') {
			arr1[x] = "1010";
		}
		else if (a[x] == 'B' || a[x] == 'b') {
			arr1[x] = "1011";
		}
		else if (a[x] == 'C' || a[x] == 'c') {
			arr1[x] = "1100";
		}
		else if (a[x] == 'D' || a[x] == 'd') {
			arr1[x] = "1101";
		}
		else if (a[x] == 'E' || a[x] == 'e') {
			arr1[x] = "1110";
		}
		else if (a[x] == 'F' || a[x] == 'f') {
			arr1[x] = "1111";
		}
	}
	string store;
	store.clear();
	for (int x = 0; x < n; x++) {
		store += arr1[x];
	}
	return store;
}
string initKeyPermutation(string key) { //one time function call
	string binary = HextoBin(key);
	string permuted = "";
	permuted.clear();
	int PC1[56] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,
	  23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	for (int x = 0; x < 56; x++) {//converting 64bit into 56bit number
		permuted += binary[PC1[x] - 1];
	}
	return permuted;
}
string halfCircularShift(string half_key, int index) { //shift 
	int x = 1;
	string shifted;
	for (int y = 0; y < index; y++) {
		for (int x = 1; x < 28; x++) {
			shifted += half_key[x];
			if (x == 27) {
				shifted += half_key[0];
			}
		}
	}
	return shifted;
}
string roundPermutation(string key) {//56 to 48 bit conversion
	string permuted = "";
	permuted.clear();
	int PC2[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,
	41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
	for (int x = 0; x < 48; x++) {
		permuted += key[PC2[x] - 1];
	}
	return permuted;
}

string initTextPermutation(string text) {
	int PC3[64] = { 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,
	24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };
	string binary = HextoBin(text);
	string permuted = "";
	permuted.clear();
	for (int x = 0; x < 64; x++) {
		permuted += binary[PC3[x] - 1];
	}
	return permuted;
}
string expandHalfText(string rightHalfText) {
	int PC4[48] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,
	16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
	string permuted = "";
	permuted.clear();
	for (int x = 0; x < 48; x++) {
		permuted += rightHalfText[PC4[x] - 1];
	}
	return permuted;
}
string XOR(string t1, string t2) {
	int size1 = 0, size2 = 0;
	for (int x = 0; t1[x] != '\0'; x++) {//loop for checking the lenght of both string T1 AND T2
		size1++;
	}
	for (int x = 0; t2[x] != '\0'; x++) {
		size2++;
	}
	string Xor;
	char *s1=new char[size1 + 1];
	strcpy(s1, t1.c_str());
	char *s2=new char[size2 + 1];
	strcpy(s2, t2.c_str());
	for (int x = 0; x < size1; x++) {// loop for comparing the both elements of the array to give XOR output 
		if ((s1[x] == '0' && s2[x] == '0') || (s1[x] == '1' && s2[x] == '1')) {
			Xor += '0';
		}
		else if ((s1[x] == '0' && s2[x] == '1') || (s1[x] == '1' && s2[x] == '0')) {
			Xor += '1';
		}
	}
	return Xor;// returning XOR GATE result
}
string calcSBox(string text) {//function no 7
	int Box1[4][16] = { {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
	{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13} };
	int Box2[4][16] = { {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
	{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9} };
	int Box3[4][16] = { {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
	{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12} };
	int Box4[4][16] = { {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
	{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14} };
	int Box5[4][16] = { {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
	{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3} };
	int Box6[4][16] = { {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
	{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13} };
	int Box7[4][16] = { {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
	{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12} };
	int Box8[4][16] = { {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
	{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };
	int binary[8][6]; int rows[8] = { 0 }, columns[8] = { 0 };
	int first = 0, last = 6; string sbox; sbox.clear(); int array[8][4] = { 0 };
	int temp = 0;
	for (int x = 0; x < 8; x++) {//loop for makng string into integer array
		for (int y = 0; y < 6; y++) {
			if (text[first] == '0') {
				binary[x][y] = 0;
			}
			else
				binary[x][y] = 1;
			first++;
		}
	}
	for (int loop = 0; loop < 8; loop++) {//loop for converting the number in decimal to find row
		int deci = 0, temp = 0;
		temp = binary[loop][0] * (2);
		deci = temp + binary[loop][5] * (1);
		rows[loop] = deci;
	}
	for (int x = 0; x < 8; x++) {//loop for converting the number in decimal to find columns
		int deci = 0, temp = 0, temp1 = 0;
		temp = binary[x][1] * pow(2, 3);
		temp1 = temp + binary[x][2] * pow(2, 2);
		deci = temp1 + binary[x][3] * pow(2, 1);
		columns[x] = deci + binary[x][4] * 1;
	}
	for (int n = 0; n < 8; n++) {//loop for using Sbox to get the index 
		if (n + 1 == 1) {
			temp = Box1[rows[n]][columns[n]];
		}
		else if (n + 1 == 2) {
			temp = Box2[rows[n]][columns[n]];
		}
		else if (n + 1 == 3) {
			temp = Box3[rows[n]][columns[n]];
		}
		else if (n + 1 == 4) {
			temp = Box4[rows[n]][columns[n]];
		}
		else if (n + 1 == 5) {
			temp = Box5[rows[n]][columns[n]];
		}
		else if (n + 1 == 6) {
			temp = Box6[rows[n]][columns[n]];
		}
		else if (n + 1 == 7) {
			temp = Box7[rows[n]][columns[n]];
		}
		else if (n + 1 == 8) {
			temp = Box8[rows[n]][columns[n]];
		}
		int i = 3;
		while (temp > 0) {//loop for converting the decimal back to binary
			array[n][i] = temp % 2;
			temp = temp / 2;
			i--;
		}
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 4; y++) {
			sbox += to_string(array[x][y]);
		}
	}
	return sbox;
}
//********************above this swapper and inverse permutation function all testcases runs on string*************//
//****************16 rounds which was give in the end*************************************//
string Swapper(string t1, string t2,string key){
  string rightside;
    for(int x=32;x<64;x++){
      rightside += key[x];
    }
  int size1 = 0, size2 = 0;
  for (int x = 0; t1[x] != '\0'; x++) {//loop for checking the lenght of both string T1 AND T2
    size1++;
  }
  for (int x = 0; t2[x] != '\0'; x++) {
    size2++;
  }
  string Xor,temp;
  char *s1=new char[size1 + 1];
  strcpy(s1, t1.c_str());
  char *s2=new char[size2 + 1];
  strcpy(s2, t2.c_str());
  for(int x=0;x<16;x++){
  for (int x = 0; x < size1; x++) {// loop for comparing the both elements of the array to give XOR output 
    if ((s1[x] == '0' && s2[x] == '0') || (s1[x] == '1' && s2[x] == '1')) {
      Xor += '0';
    }
    else if ((s1[x] == '0' && s2[x] == '1') || (s1[x] == '1' && s2[x] == '0')) {
      Xor += '1';
    }
   }
   temp=rightside;
   rightside=Xor;
   Xor=temp;
 }
return Xor+rightside;
}
string inversepermutation(string binary){
int IPC[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28, 
  35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
 string permuted = "";
  permuted.clear();
  for (int x = 0; x < 64; x++) {
    permuted += binary[IPC[x] - 1];
  }
  return permuted;
}
