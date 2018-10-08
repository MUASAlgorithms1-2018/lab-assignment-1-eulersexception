#include <iostream>
#include <vector>

using namespace std;

int main() {

    int array[] = {5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1};
    std::vector<int> vec1


    int length = sizeof(array) / sizeof(array[0]);

    // cubic complexity
    int maxSumCubic = 0;
    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            int thisSum = 0;
            for(int k = i; k <= j; k++) {
                thisSum += array[k];
                if(thisSum > maxSumCubic)
                    maxSumCubic = thisSum;
            }
        }
    }

    // quadratic complexity
    int maxSumQuadratic = 0;
    for(int i = 0; i < length; i++) {
        int thisSum = 0;
        for(int j = i; j < length; j++) {
            thisSum += array[j];
            if(thisSum > maxSumQuadratic)
                maxSumQuadratic = thisSum;
        }
    }

    // linear complexity
    int maxSumLinear = 0;
    int thisSumLinear = 0;
    for(int i = 0; i < length; i++) {
        thisSumLinear += array[i];
        if(thisSumLinear > maxSumLinear)
            maxSumLinear = thisSumLinear;
        else if(thisSumLinear < 0)
            thisSumLinear = 0;
    }

    return 0;

}