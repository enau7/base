#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "base.h"
using namespace std;

void Base::check_base(int base){
    /*
        Throws if a base is invalid. The base must be between 2 and the length of numerals.
        @base the given base.
    */

    if (base > numerals.length()){
        cerr << "Base too large. Must be an integer between 2 and " << numerals.length() << ".\n";
        exit(1);
    } else if (base < 2){
        cerr << "Base too small. Must be an integer between 2 and " << numerals.length() << ".\n";
        exit(1);
    }
}

int Base::number_of_digits(long n, int base){
    /*
        Returns the number of digits n has in the given base.
        @n the given integer.
        @base the given base.
    */

    if (n < 0 || base < 2){
        return 0;
    } else {
        int power = 1;
        while(true){
            if (n < pow(base,power)){
                break;
            } else {
                power++;
            }
        }
        return power;
    }
};

string Base::to_base(long n, int base){
    /*
        Returns n as a string in the given base.
        @n the given integer.
        @base the given base.
    */

    check_base(base);

    string output = "";
    int magnitude_of_index;

    for (int k = number_of_digits(n,base) - 1; k >= 0; k--){
        magnitude_of_index = n / pow(base,k);
        n -= magnitude_of_index*pow(base,k);
        output = output + numerals[magnitude_of_index];
    };

    return output;
}

long Base::from_base(string s, int base){
    /*
        Returns s in the given base as an integer.
        @s the integer as a string, written in the given base.
        @base the given base.
    */

    check_base(base);
    long value = 0;
    int magnitude;
    int length = s.length();
    string sub_numerals = numerals.substr(0,base);

    for(int k = 1; k <= length; k++){
        if ((magnitude = sub_numerals.find(s[k-1])) < 0){
            cerr << "Base and string do not match.\n";
            exit(1);
        } else {
            value += magnitude*pow(base,length-k);
        }
    }
    return value;
}

void Base::set_numerals(string s){
    /*
        Checks if s is a valid set of numerals, then sets the value of numerals to s;
        @s the given string.
    */

    if (s.length() < 2){
        cerr << "Bad string. There must be at least 2 numerals in the string.\n";
        exit(1);
    } else if (s.length() < working_base){
        cerr << "Bad string. Change the working_base (" << 
            working_base << ") or increase the size of the string.\n";
        exit(1);
    };
    for (char k : s){
        if (s.find(k) != s.rfind(k)){
            cerr << "Bad string. Repeating numerals.\n";
            exit(1);
        }
    }
    numerals = s;
    return;
}