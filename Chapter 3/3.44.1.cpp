#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <iterator>

using namespace std;

int main () {

int ia [3] [4] = {{0, 1, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

using size = size_t;

for (size i = 0; i < 3; ++i) {
    for (size j = 0; j < 4; ++j)
        cout << ia [i] [j] << "\t";
    cout << endl;
}

return 0; 
}
