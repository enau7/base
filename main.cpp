#include <iostream>
#include <cmath>
#include <vector>
#include "headers.h"
using namespace std;

void print_statement(int max_per_value, int base, int max_per);

int main(){
    int base = 2;
    Base b(base);
    Persistance p(base);
    int max_per, max_per_value;
    int per_k;

    for (int j = 2; j <= 12; j++){

        base = j;
        b.set_working_base(base);
        p.set_working_base(base);
        max_per = 0;
        max_per_value = 0;

        for(int k = 1; k < 1000000; k++){
            if (!p.is_valid_int(k)) {continue;};
            int per_k = p.per(k,base);
            if (per_k > max_per){
                max_per = per_k;
                max_per_value = k;
            }
        }
        print_statement(max_per_value,base,max_per);
    }
}

void print_statement(int per_value, int base, int per){
    Base b(base);
    cout << "Persistance of " << b.to_base(per_value) << " (in base " << base << ", " << per_value << " in base 10) is " << per << endl;
}