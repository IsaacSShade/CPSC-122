#include <iostream>
#include <cstdlib>

using namespace std;

void generateTwoDimensions(int twoDimensional[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            twoDimensional[i][j] = rand() % 100 + 1;
        }
    }

}

void printTwoDimensions(int twoDimensional[5][5]) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << twoDimensional[i][j] << " ";
            }
            cout << endl;
        }
}

int main() {
    int oneDimension[5], twoDimensions[5][5];
    
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {



        oneDimension[i] = rand() % 100 + 1;

    }

    for (int i = 0; i < 5; i++) {
        cout << oneDimension[i] << " ";
    }

    // Solution 2

    generateTwoDimensions(twoDimensions);

    printTwoDimensions(twoDimensions);

    return 0;
}