#include "persistance.h"
#include "base.h"
#include <iostream>
#include <string>
using namespace std;

string Persistance::step(string s, int base){
    /*
        Multiplies all of the digits of a string together.
    */

    Base b(base);
    int product = 1;
    for (char k : s){
        product *= b.from_base(k);
    };
    return b.to_base(product);
}

int Persistance::per(string s, int base, bool print){

    if (print){
        cout << s << endl;
    };

    if (s.length() <= 1){
        return 0;
    };

    s = Persistance::step(s,base);
    
    return 1 + per(s, base, print);

}

bool Persistance::is_valid_int(string s, int base){
    Base b(base);
    int last_element = 0;
    for (char k : s){
        int from_base_k = b.from_base(k);
        if (from_base_k < last_element){
            return false;
        } else {
            last_element = from_base_k;
        }
    }
    return true;
}