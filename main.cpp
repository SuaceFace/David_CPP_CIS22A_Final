//  main.cpp
//  FA24_Final
//  Created by David Dang on 12/11/24.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void rotate_string(string& st, int k, bool right){
    // rotates string st by k times
    // to the right if right = true; to the left if right is false
    if(right){
        //right rotation
        size_t n = st.size();
        for (int i = 0; i < k; i++) {
            char last = st[n-1];
            for (int j = n-1; j > 0; j--){
                st[j] = st[j - 1];
            }
            st[0] = last;
        }
    }
    else{
        //left rotation
        size_t n = st.size();
        for (int i = 0; i < k; i++) {
            char first = st[0];
            for (int j = 0; j < n - 1; j++){
                st[j] = st[j + 1];
            }
            st[n - 1] = first;
        }
    }
    return;
}

int main(){
    //Q1
    cout << "Q1" << endl;
    cout << "Welcome to string rotation!" << endl;
    string name, id, phone, nameid;
    cout << "Enter first name: " << endl;
    cin >> name;
    cout << "Enter student id: " << endl;
    cin >> id;
    cout << "Enter phone number (in any format): " << endl;
    cin >> phone;
    nameid = name + id;
    cout << "nameid before rotation = " << nameid << endl;
    cout << "Rotate right for even digits and left for odd digits: " << endl;
    for(int i = 0; i<phone.size(); i++){
        int digit = phone.at(i)-'0';
        bool r;
        if(digit % 2 == 1){
            r = false;
        }
        else{
            r = true;
        }
        rotate_string(nameid, digit, r);
        cout << "digit = " << digit << ", nameid = " << nameid << endl;
    }
    cout << "Rotated nameid = " << nameid << endl;
    
    cout << "Rotate left for even digit and right for odd digit: " << endl;
    for(int i = 0; i<phone.size(); i++){
        int digit = phone.at(i)-'0';
        bool r;
        if(digit % 2 == 1){
            r = true;
        }
        else{
            r = false;
        }
        rotate_string(nameid, digit, r);
        cout << "digit = " << digit << ", nameid = " << nameid << endl;
    }
    cout << "Unrotated nameid = " << nameid << endl << endl;
    
    
    //Q2
    string f1name;
    string f2name;
    ifstream f1;
    ofstream f2;
    cout << "Q2" << endl;
    cout << "Enter input file name: " << endl;
    cin.ignore();
    //fin.txt address: /Users/daviddang/Documents/FA24_DavidDang_Final_Q1/FA24_Final/fin.txt
    getline(cin, f1name);
    cout << "Enter output file name: " << endl;
    getline(cin, f2name);
    //out.txt address: /Users/daviddang/Documents/FA24_DavidDang_Final_Q1/FA24_Final/out.txt
    f1.open(f1name);
    f2.open(f2name);
    if(f1.fail()){
        cout << "Failed to open input file: " << f1name << endl;
        return 1;
    }
    if(f2.fail()){
        cout << "Failed to open output file: " << f2name << endl;
        return 1;
    }
    string line;
    //Count each letter in my name d, a, v, i
    int dCount = 0;
    int aCount = 0;
    int vCount = 0;
    int iCount = 0;
    int lines = 0; //number of lines
    int digitCount = 0;
    while (getline(f1, line)) {
        dCount += count(line.begin(), line.end(), 'd');
        aCount += count(line.begin(), line.end(), 'a');
        vCount += count(line.begin(), line.end(), 'v');
        iCount += count(line.begin(), line.end(), 'i');
        for(int i = 0; i<10; i++){
            char digit = char(i) + '0';
            digitCount += count(line.begin(), line.end(), digit);
        }
        lines++;
    }
    cout << "Number of times d appears: " << dCount << endl;
    f2 << dCount << endl;
    cout << "Number of times a appears: " << aCount << endl;
    f2 << aCount << endl;
    cout << "Number of times v appears: " << vCount << endl;
    f2 << vCount << endl;
    cout << "Number of times i appears: " << dCount << endl;
    f2 << iCount << endl;
    cout << "Number of lines in file: " << lines << endl;
    f2 << lines << endl;
    cout << "Number of digits 0-9 in file: " << digitCount << endl;
    f2 << digitCount << endl;
    f1.close();
    f2.close();
    
    return 0;
}
