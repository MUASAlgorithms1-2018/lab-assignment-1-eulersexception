/**
 *  Algorithms and Data Structures - Lab 1
 *  Maximum Subsequence Sum - calculating the maximum sum of consecutive numbers within an array
 *
 *  @author Bahadir Suezer
 *  @version 2018-09-10
 */


#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


// to maintain readabilty of the code the algorithms have been outsourced of the main method


int maxSumCubic(vector<int> vec, int size) {
    int maxSumCubic = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            int thisSum = 0;
            for(int k = i; k <= j; k++) {
                thisSum += vec.at(k);
                if(thisSum > maxSumCubic)
                    maxSumCubic = thisSum;
            }
        }
    }
    return maxSumCubic;
}

int maxSumQuadratic(vector<int> vec, int size) {
    int maxSumQuadratic = 0;
    for(int i = 0; i < size; i++) {
        int thisSum = 0;
        for(int j = i; j < size; j++) {
            thisSum += vec.at(j);
            if(thisSum > maxSumQuadratic)
                maxSumQuadratic = thisSum;
        }
    }
    return maxSumQuadratic;
}

int maxSumLinear(vector<int> vec, int size) {
    int maxSumLinear = 0;
    int thisSumLinear = 0;
    for(int i = 0; i < size; i++) {
        thisSumLinear += vec.at(i);
        if(thisSumLinear > maxSumLinear)
            maxSumLinear = thisSumLinear;
        else if(thisSumLinear < 0)
            thisSumLinear = 0;
    }
    return maxSumLinear;
}


int main() {

    // creating first array and passing its values to a vector to make them accessible outside main method
    int array1[] = {5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    vector<int> vec1(array1, array1+length1);

    // creating second array
    int array2[] = {-2,1,-3,4,-1,2,1,-5,4};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    vector<int> vec2(array2, array2+length2);

    // creating third array
    int array3[] = {-2, 1};
    int length3 = sizeof(array3) / sizeof(array3[0]);
    vector<int> vec3(array3, array3+length3);

    // creating fourth array
    int array4[] = {4, -3, 1, 4, -2, -5,  3, 4};
    int length4 = sizeof(array4) / sizeof(array4[0]);
    vector<int> vec4(array4, array4+length4);

    // creating fifth array
    int array5[] = {2, -3, 1, 4, -2, -5,  3, 1};
    int length5 = sizeof(array5) / sizeof(array5[0]);
    vector<int> vec5(array5, array5+length5);

    // tests for cubic complexity
    assert(maxSumCubic(vec1, length1) == 25);
    assert(maxSumCubic(vec2, length2) == 6);
    assert(maxSumCubic(vec3, length3) == 1);
    assert(maxSumCubic(vec4, length4) == 7);
    assert(maxSumCubic(vec5, length5) == 5);
    cout << "Tests for cubic complexity succeeded!" << endl;

    // tests for quadratic complexity
    assert(maxSumQuadratic(vec1, length1) == 25);
    assert(maxSumQuadratic(vec2, length2) == 6);
    assert(maxSumQuadratic(vec3, length3) == 1);
    assert(maxSumQuadratic(vec4, length4) == 7);
    assert(maxSumQuadratic(vec5, length5) == 5);
    cout << "\nTests for quadratic complexity succeded!" << endl;


    // tests for linear complexity
    assert(maxSumLinear(vec1, length1) == 25);
    assert(maxSumLinear(vec5, length5) == 5);
    assert(maxSumLinear(vec2, length2) == 6);
    assert(maxSumLinear(vec3, length3) == 1);
    assert(maxSumLinear(vec4, length4) == 7);
    cout << "\nTests for linear complexity succeeded!" << endl;

    return 0;
}
