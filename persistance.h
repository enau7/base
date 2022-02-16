#pragma once

#include <iostream>
#include "base.h"
using namespace std;

class Persistance {
    /*
        c++11 persistance.h
        Purpose: finds the multiplicative persistance of numbers in different bases.

        @author Colton Rowe
        version 0.1 8/30/2021
    */

    private:

        int working_base = 10;

    public:

        static string step(string s, int base);
        static string step(long n, int base) {Base b(base); return step(b.to_base(n),base);};
               string step(string s) {return step(s,working_base);};
               string step(long n) {return step(n,working_base);};

        static int per(string s, int base, bool print);
        static int per(string s, int base) {return per(s,base,false);};
               int per(string s) {return per(s,working_base);};
        static int per(long n, int base, bool print) {Base b(base); return per(b.to_base(n),base,print);};
        static int per(long n, int base) {return per(n,base,false);};
               int per(long n) {return per(n,working_base);};

        static bool is_valid_int(string s, int base);
        static bool is_valid_int(int n, int base) {Base b(base); return is_valid_int(b.to_base(n), base);};
               bool is_valid_int(string s) {return is_valid_int(s,working_base);};
               bool is_valid_int(int n) {return is_valid_int(n,working_base);};

        void set_working_base(int base){working_base = base;};
        int get_working_base() {return working_base;};

        Persistance(int base){set_working_base(base);};
        Persistance(){};

};