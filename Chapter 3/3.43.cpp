#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <iterator>

using namespace std;

int main () {


int ia [3] [4] = {{0, 1, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

for (const int  (&row) [4] : ia) {
    for (int col : row)
        cout << col << "\t";
    cout << endl;
}
    
return 0; 
}
