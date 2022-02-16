#pragma once

#include <string>
using namespace std;

class Base {
    /* 
        c++11 base.h
        Purpose: Converts integers into strings of different bases.

        @author Colton Rowe
        @version 0.1 8/29/2021
    */

    private:

        string numerals = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$#";
        int working_base = 2;
        void check_base(int base);
        int number_of_digits(long n, int base);

    public:

        string to_base(long n, int base);
        string to_base(long n) {return to_base(n, working_base);};
        string to_base(string s, int base) {return to_base(stoi(s),base);};
        string to_base(string s) {return to_base(s, working_base);};

        long from_base(string s, int base);
        long from_base(string s) {return from_base(s,working_base);};
        long from_base(char c, int base) {return from_base(string(1,c),base);};
        long from_base(char c) {return from_base(string(1,c));};

        void set_numerals(string s);
        void set_working_base(int base) {check_base(base); working_base = base;};

        int get_working_base(){return working_base;};
        string get_numerals(){return numerals;};

        Base(int base, string s) {set_working_base(base); set_numerals(s);}
        Base(int base) {set_working_base(base);}
        Base(string s) {set_numerals(s);};
        Base(){};
};