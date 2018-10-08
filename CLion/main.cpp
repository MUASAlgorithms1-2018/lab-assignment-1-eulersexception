#include <iostream>


using namespace std;

int main() {

    int array[] = {1, 2, -30, 4, 5};
    int maxSum = 0;

    int length = sizeof(array) / sizeof(array[0]);

    cout << "length of array " << length << endl;

    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            int thisSum = 0;
            for(int k = i; k <= j; k++) {
                thisSum += array[k];
                if(thisSum > maxSum)
                    maxSum = thisSum;
            }
        }
    }
    cout << maxSum << endl;

    return 0;

}