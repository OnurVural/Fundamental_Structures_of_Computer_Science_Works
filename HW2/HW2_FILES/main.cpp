#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int* sortAlgorithm1(const int* arr1, const int* arr2, const int N ){
    int* arr3 = new int[2*N];
    int counter = 0;
    int holder = N;

    for ( int i = 0; i < N; i++){
        arr3[i] = arr1[i];
    }

    for ( int i = 0; i < N; i++ ){
          if ( arr3[i] > arr2[counter])
          {
            for ( int k = holder; k > i; k--)
              arr3[k] = arr3[k-1];
            arr3[i] = arr2[counter];
            holder++;
            counter++;
          }
    }
    while (counter < N){
            arr3[holder++] = arr2[counter++];
    }
    return arr3;
}

int* sortAlgorithm2(const int* arr1, const int* arr2, const int N ){
  int count1 = 0, count2 = 0, index = 0;
  int* arr3 = new int[2*N];

  while ( count1 < N && count2 < N){
    if (arr1[count1]< arr2[count2]){
        arr3[index] = arr1[count1];
        index++;
        count1++;
    }
    else{
        arr3[index] = arr2[count2];
        index++;
        count2++;
    }
  }

  //Remaining items will be copied
  while ( count1 < N){
        arr3[index] = arr1[count1];
        index++;
        count1++;
  }

  while ( count2 < N){
        arr3[index] = arr2[count2];
        index++;
        count2++;
  }
  return arr3;
}

void init(int A[], int arrSize, const int lowerboundRange, const int upperboundRange){
  for( int i = 0; i < arrSize; i++ )
    A[i] = rand() % upperboundRange + lowerboundRange;
  sort(A,A+arrSize);
}

void print(const int A[], const int arrSize){
  for( int i = 0; i < arrSize; i++ )
    cout << A[i] << " ";
}

int main()
{
    cout << "Hello world!" << endl;

    const int arrSize1 = 100;
    const int arrSize2 = 1000;
    const int arrSize3 = 2000;
    const int arrSize4 = 4000;
    const int arrSize5 = 8000;
    const int arrSize6 = 10000;
    const int arrSize7 = 16000;
    const int arrSize8 = 32000;
    const int arrSize9 = 64000;
    const int arrSize10 = 100000;
    const int arrSize11 = 128000;

    const int arrSize12 = 100;
    const int arrSize13 = 1000;
    const int arrSize14 = 10000;
    const int arrSize15 = 100000;
    const int arrSize16 = 1000000;
    const int arrSize17 = 10000000;
    const int arrSize18 = 100000000;


    //-------------------------------------------------------------
    int* array1 = new int[arrSize1];
    init(array1,arrSize1,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    int* array2 = new int[arrSize1];
    init(array2,arrSize1,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    int* array3 = new int[arrSize1];
    init(array3,arrSize1,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    //-------------------------------------------------------------------
    cout << "N = " << arrSize1 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    int* arraySorted = sortAlgorithm1(array1,array3,arrSize1);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize1);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize1);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
//    -----------------------------------------------------------------------

    array1 = new int[arrSize2];
    init(array1,arrSize2,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize2];
    init(array2,arrSize2,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize2];
    init(array3,arrSize2,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize2 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize2);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize2);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize2);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
//------------*********************************************************
    array1 = new int[arrSize3];
    init(array1,arrSize3,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize3];
    init(array2,arrSize3,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize3];
    init(array3,arrSize3,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize3 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize3);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize3);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize3);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
//------------*********************************************************
    array1 = new int[arrSize4];
    init(array1,arrSize4,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize4];
    init(array2,arrSize4,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize4];
    init(array3,arrSize4,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize4 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize4);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize4);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize4);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;



    delete [] array1;
    delete [] array2;
    delete [] array3;
//------------*********************************************************
    array1 = new int[arrSize5];
    init(array1,arrSize5,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize5];
    init(array2,arrSize5,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize5];
    init(array3,arrSize5,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize5 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize5);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize5);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize5);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
//------------*********************************************************
    array1 = new int[arrSize6];
    init(array1,arrSize6,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize6];
    init(array2,arrSize6,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize6];
    init(array3,arrSize6,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize6 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize6);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize6);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize6);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
//------------*********************************************************
    array1 = new int[arrSize7];
    init(array1,arrSize7,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize7];
    init(array2,arrSize7,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize7];
    init(array3,arrSize7,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize7 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize7);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize7);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize7);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //------------*********************************************************
    array1 = new int[arrSize8];
    init(array1,arrSize8,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize8];
    init(array2,arrSize8,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize8];
    init(array3,arrSize8,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize8 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize8);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize8);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize8);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //------------*********************************************************
    array1 = new int[arrSize9];
    init(array1,arrSize9,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize9];
    init(array2,arrSize9,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize9];
    init(array3,arrSize9,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize9 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize9);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize9);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize9);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //------------*********************************************************
    array1 = new int[arrSize10];
    init(array1,arrSize10,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize10];
    init(array2,arrSize10,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize10];
    init(array3,arrSize10,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize10 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize10);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize10);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize10);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //------------*********************************************************
    array1 = new int[arrSize11];
    init(array1,arrSize11,1,50); //numbers will be between 1 and 50
    //print(array1,arrSize2);
    cout << endl;

    array2 = new int[arrSize11];
    init(array2,arrSize11,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize2);
    cout << endl;

    array3 = new int[arrSize11];
    init(array3,arrSize11,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize2);
    cout << endl;

    cout << "N = " << arrSize11 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;

    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array3,arrSize11);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array3,array1,arrSize11);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize11);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;

    //---------------------------------------------------------------------------------------------------------
    cout << "N = " << arrSize16 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;
    array1 = new int[arrSize16];
    init(array1,arrSize16,1,50); //numbers will be between 1 and 50

    array2 = new int[arrSize16];
    init(array2,arrSize16,60,100); //numbers will be between 1 and 50


    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize16);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : Takes so much time at that point compared with O(N)" << endl;
    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : Takes so much time at that point compared with O(N)" << endl;
    //---------------------------------------------------------------------------------------------------------
    cout << "N = " << arrSize17 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;
    array1 = new int[arrSize17];
    init(array1,arrSize17,1,50); //numbers will be between 1 and 50

    array2 = new int[arrSize17];
    init(array2,arrSize17,60,100); //numbers will be between 1 and 50

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize17);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : Takes so much time at that point compared with O(N)" << endl;
    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : Takes so much time at that point compared with O(N)" << endl;
    //---------------------------------------------------------------------------------------------------------
    cout << "N = " << arrSize18 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (best)" << endl;
    cout << "FOR ALG1 : " ;
    array1 = new int[arrSize18];
    init(array1,arrSize18,1,50); //numbers will be between 1 and 50

    array2 = new int[arrSize18];
    init(array2,arrSize18,60,100); //numbers will be between 1 and 50

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm1(array1,array2,arrSize18);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (worst)" << endl;
    cout << "FOR ALG1 : Takes so much time at that point compared with O(N)" << endl;
    cout << "(iii) there is no such ordering between these arrays (average)" << endl;
    cout << "FOR ALG1 : Takes so much time at that point compared with O(N)" << endl;





    cout << endl;
    cout << "ALGORITHM 2 TEST STARTS..." << endl;
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//-------------------------------------------------------------
    array1 = new int[arrSize12];
    init(array1,arrSize12,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize12];
    init(array2,arrSize12,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize12];
    init(array3,arrSize12,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize12 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize12);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize12);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize12);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //-------------------------------------------------------------
    array1 = new int[arrSize13];
    init(array1,arrSize13,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize13];
    init(array2,arrSize13,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize13];
    init(array3,arrSize13,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize13 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize13);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize13);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

   cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize13);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //-------------------------------------------------------------
    array1 = new int[arrSize14];
    init(array1,arrSize14,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize14];
    init(array2,arrSize14,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize14];
    init(array3,arrSize14,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize14 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize14);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize14);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize14);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //-------------------------------------------------------------
    array1 = new int[arrSize15];
    init(array1,arrSize15,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize15];
    init(array2,arrSize15,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize15];
    init(array3,arrSize15,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize15 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize15);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize15);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize15);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //-------------------------------------------------------------
    array1 = new int[arrSize16];
    init(array1,arrSize16,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize16];
    init(array2,arrSize16,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize16];
    init(array3,arrSize16,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize16 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize16);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize16);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize16);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //-------------------------------------------------------------
    array1 = new int[arrSize17];
    init(array1,arrSize17,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize17];
    init(array2,arrSize17,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize17];
    init(array3,arrSize17,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize17 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize17);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize17);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize17);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //-------------------------------------------------------------
    array1 = new int[arrSize18];
    init(array1,arrSize18,1,50); //numbers will be between 1 and 50

    //print(array1,arrSize1);
    cout << endl;

    array2 = new int[arrSize18];
    init(array2,arrSize18,1,50); //numbers will be between 1 and 50
    //print(array2,arrSize1);
    cout << endl;

    array3 = new int[arrSize18];
    init(array3,arrSize18,60,100); //numbers will be between 60 and 100
    //print(array3,arrSize1);
    cout << endl;

    cout << "N = " << arrSize18 << endl;
    // Cases:
    cout << "(i) all numbers in arr1 are smaller than arr2 (average)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    duration;
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array3,arrSize18);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(ii) all numbers in arr2 are smaller than arr1 (best)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time
    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array3,array1,arrSize18);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    cout << "(iii) there is no such ordering between these arrays (worst)" << endl;
    cout << "FOR ALG2 : " ;
    //Store the starting time

    startTime = clock();
    //Code block
    arraySorted = sortAlgorithm2(array1,array2,arrSize18);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    delete [] arraySorted;

    delete [] array1;
    delete [] array2;
    delete [] array3;
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    return 0;
}
