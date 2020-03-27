#include <iostream>
#include <bitset>
#include <string.h>
#include <sstream>
using namespace std;
int main() {
    string base64,basechars[50];
    int baseNum;
    char basechar;
    cout << "base64 encoded text: "<<endl;
    cin >> base64;
    int baseNums[base64.size()],binaryNums[base64.size()];

    for(int i=0;i<base64.size();i++){
        basechar = base64[i];
        baseNum = int(basechar);
        if(baseNum <= 57 && baseNum >=48){
            baseNum = baseNum - 48+52;
            baseNums[i] = baseNum;
        }
        else if(baseNum >= 65 && baseNum <= 90){
            baseNum = baseNum - 65;
            baseNums[i] = baseNum;
        }
        else if(baseNum >=97 && baseNum <=122){
            baseNum = baseNum -97+26;
            baseNums[i] = baseNum;
        }
    }

    bitset<6> bin_x;
    string bin_y;

    for(int i=0;i<sizeof(baseNums)/sizeof(baseNums[0]);i++){
        bin_x = baseNums[i];
        bin_y = bin_y + bin_x.to_string();

    }

    string binaryin8[bin_y.size()/8];
    int cha=0;
    for(int i=0;i<bin_y.size()/8;i++){
        while(binaryin8[i].size() < 8){
            binaryin8[i]+= bin_y[cha];
            cha++;
        }
    }
    int binayNums[sizeof(binaryin8)/sizeof(binaryin8[0])];
    for(int i=0;i<sizeof(binaryin8)/sizeof(binaryin8[0]);i++){
        binayNums[i] = stoi(binaryin8[i]);
        //cout << binaryin8[i];
    }

    for(int i=0;i<sizeof(binayNums)/sizeof(binayNums[0]);i++){
        int bin, dec = 0, rem, num, base = 1;
        num = binayNums[i];
        bin = num;
        while (num > 0){
            rem = num % 10;
            dec = dec + rem * base;
            base = base * 2;
            num = num / 10;
        }
        binayNums[i] = dec;

        dec=0;
    }
    cout << "Decoded text ---> ";
    for(int i=0;i<sizeof(binayNums)/sizeof(binayNums[0]);i++){
        cout << char(binayNums[i]);
    }
    return 0;
}
