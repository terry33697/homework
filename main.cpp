#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int type_value = 0,value[4],divide = 1000;
	cout << "請輸入四位數：" << endl;
	cin >> type_value;
	
	
	while ( type_value > 9999 || type_value < 1000 ){
		cout << "此非四位數數字，請重新輸入：";
		cin >> type_value;
	}// avoid type_value variable not four digits.
	for (int i = 0;i < 4;i++){
		value[i] = type_value / divide;
		type_value = type_value % divide;
		divide /= 10;
	}
//encrypt formula
	short temp = 0;
	int encrypt[4]={0,0,0,0};
	for ( int j = 0;j<4;j++){
		encrypt[j] = (value[j] + 7) % 10;
	} 
	for ( int i = 0;i < 2;i++){
		temp = encrypt[i];
		encrypt[i] = encrypt[i+2];
		encrypt[i+2] = temp;
	}
	cout << "\n\n加密：" << endl; 
	for ( int i = 0;i<4;i++){
		cout << encrypt[i];
	}
	
//decrypt formula
	int decrypt[4]={0,0,0,0};
	for ( int j = 0;j<4;j++){
		decrypt[j] = (encrypt[j] + 3) % 10;
	}
	for ( int i = 0;i < 2;i++){
		temp = 0;
		temp = decrypt[i];
		decrypt[i] = decrypt[i+2];
		decrypt[i+2] = temp;
	}
	cout << "\n\n解密：" << endl; 
	for (int i = 0;i < 4;i++){
		cout << decrypt[i]; 
	}
	return 0;
}
