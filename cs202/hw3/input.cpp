#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int k = 1;
    char fname[] = "inputk.txt";
    for (int k = 1; k <= 5; k++) {
        fname[5] = k + 48;
        ofstream out_file(fname);
        if (out_file.is_open() ) {
            // TO-DO: Print the sorted array, 
            //also print the number of key comparisons to the end.
            for (int i = 0; i < k * 1000; i++)
                out_file << rand() / 1000000 << endl;
            out_file.close();
        }
    }
}