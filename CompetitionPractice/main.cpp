#include <iostream>
#include <vector>
#include "sortingcompetition.h"
#include <ctime>

int main()
{
    double diff;
    double mean = 0.0;
    clock_t start;
    SortingCompetition* s1 = new SortingCompetition("input.txt");
    s1 ->readData();
    for(int i=0; i<1; i++){
        s1->prepareData();
        start = clock();
        s1 ->sortData();
        diff = (std::clock() - start ) / (double)CLOCKS_PER_SEC;
        mean += diff;
    }
    std:: cout<<"printf: "<< mean/1 << std::endl;
    s1 -> outputData("output.txt");
    return 0;
}

//sorting algorithms tried
/*void mergePart(vector <char*>& result, vector <char*>& left, vector<char*>& right){
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < result.size(); i++){
        if (i2 >= right.size() || (i1 < left.size() && strcmp(left[i1], right[i2]) < 0)){
           result[i] = left[i1];
           i1++;
        }
        else{
            result[i] = right[i2];
            i2++;
        }
    }
}
void mergePart(vector <char*>& result, vector <char*>& left, vector<char*>& right){
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < result.size(); i++){
        if (i2 >= right.size() || (i1 < left.size() && strlen(left[i1]) < strlen(right[i2]))){
           result[i] = left[i1];
           i1++;
        }
        else{
            result[i] = right[i2];
            i2++;
        }
    }
}
void partitionSort(vector <char*> &words){
    if (words.size() >= 2){
        int mean = 0;
        for (int i = 0; i < words.size(); i++){
            mean += strlen(words[i]);
        }
        mean /= words.size();
        int index = 0;
        for (int i = 0; i < words.size(); i++){
            if (((strlen(words[i]) - mean)^2) < ((strlen(words[index]) - mean)^2)){
                 index = i;
                break;
            }
        }
        vector <char*> left;
        vector <char*> right;
        for (int i = 0; i < words.size(); i++){
            if (i == index){
                continue;
            }
            if (words[i][0] <= words[index][0]){
                left.push_back(words[i]);
            }
            if (words[i][0] > words[index][0]){
                right.push_back(words[i]);
            }
        }
        partitionSort(left);
        partitionSort(right);
        mergePart(words, left, right);
    }
}

void moveLargest(int** lengths, int size){
    int index = size-1;
    for (int i = index - 1; i >= 0; i--){
        if (lengths[i][0] >= lengths[index][0]){
            index = i;
        }
    }
    swap(lengths[index], lengths[size-1]);
}
void selectionSort(int** lengths, int size){
    if (size == 1){
        return;
    }
    else{
        moveLargest(lengths, size);
        selectionSort(lengths, size-1);
    }
}

//merge to alphabetize the words
void merge(vector <char*> &result, vector <char*> &left, vector <char*> &right){
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < result.size(); i++){
        if (i2 >= right.size() || (i1 < left.size() && strcmp(left[i1], right[i2]) < 0)){
           result[i] = left[i1];
           i1++;
        }
        else{
            result[i] = right[i2];
            i2++;
        }
    }
}

//merge for lengths of words
void merge(vector <char*> &result, vector <char*> &left, vector <char*> &right){
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < result.size(); i++){
        if (i2 >= right.size() || (i1 < left.size() && strlen(left[i1]) < strlen(right[i2]))){
           result[i] = left[i1];
           i1++;
        }
        else{
            result[i] = right[i2];
            i2++;
        }
    }
}
void mergeSort(vector <char*> &words){
    if (words.size() >= 2){
        vector <char*> left;
        vector <char*> right;
        int counter = words.size();
        for (int i = 0; i < counter/2; i++){
            right.push_back(words[i]);
        }
        for (int i = 0; i < counter - counter/2; i++){
            left.push_back(words[i+counter/2]);
        }
        mergeSort(right);
        mergeSort(left);
        merge(words, right, left);
    }
}

void findMedian(vector<char*> &words){
    int i = 0;
    int j = words.size() - 1;
    int index = 0;
    while (i < j){
        int x = i;
        int y = j;
        int mid = strlen(words[(x+y)/2]);

        while (x < y){
            if (strlen(words[x]) >= mid){
                swap(words[x], words[y]);
                y--;
            }
            else{
                x++;
            }
        }
        if (strlen(words[x]) > mid){
            x--;
        }
        if (words.size()/2 <= x){
            j = x;
        }
        else{
            i = x+1;
        }
    }
    return;
}
*/
/*void SortingCompetition :: resizeLengths(){
    int** newArray = new int*[lengthsCounter + 10];
    for (int i = 0; i < lengthsCounter; i++){
        newArray[i] = lengths[i];
    }
    delete [] lengths;
    lengths = newArray;
    return;
}*/

/*void SortingCompetition :: QuickSort(vector<char*>& words, int left, int right){
    int i = left;
    int j = right;
    //char* pivot =
    if ((strlen(words[left]) >= strlen(words[right]) && strlen(words[left]) <= strlen(words[(left+right)/2])) || (strlen(words[left]) >= strlen(words[(left+right)/2]) && strlen(words[left]) <= strlen(words[right])))
        pivot = strlen(words[left]);
    else if((strlen(words[right]) >= strlen(words[left]) && strlen(words[right]) <= strlen(words[(left+right)/2])) || (strlen(words[right]) >= strlen(words[(left+right)/2]) && strlen(words[right]) <= strlen(words[left])))
        pivot = strlen(words[right]);
    else
        pivot = strlen(words[(left+right)/2]);
    while (i <= j){
        while (strlen(words[i]) < pivot){
            i++;
        }
        while (strlen(words[j]) > pivot){
            j--;
        }
        if (i <= j){
            swap(words[i], words[j]);
            i++;
            j--;
        }
        if (left < j)
            QuickSort(words,left, j);
        if (i < right)
            QuickSort(words, i, right);
    }
    return;
}*/

/*int SortingCompetition :: partition (vector <char*>& words, int top, int bottom){
    int pivot = strlen(words[top]);
    int i = top;
    int j = bottom + 1;
    while(top < bottom){
        while(strlen(words[top]) <= pivot && i <= bottom){
            i++;
        }
        while(strlen(words[j]) > pivot){
            j--;
        }
        if (i >= j){
            break;
        }
        swap(words[i], words[j]);
    }
    return j;
}*/

/*void SortingCompetition :: selectionSort(int** &sortArray, int size){
    if (size == 1){
        return;
    }
    else{
        moveLargest(sortArray, size);
        selectionSort(sortArray, size-1);
    }
}*/

/*void SortingCompetition :: moveLargest(int** &sortArray, int size){
    int index = size-1;
    for (int i = index - 1; i >= 0; i--){
        if (sortArray[i][0] >= sortArray[index][0]){
            index = i;
        }
    }
    swap(sortArray[index], sortArray[size-1]);
}*/

/*void SortingCompetition :: mergeAlpha(vector <char*> &result, vector <char*> &left, vector <char*> &right){
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < result.size(); i++){
        if (i2 >= right.size() || (i1 < left.size() && strcmp(left[i1], right[i2]) < 0)){
           result[i] = left[i1];
           i1++;
        }
        else{
            result[i] = right[i2];
            i2++;
        }
    }
}*/

/*void SortingCompetition :: mergeSortAlpha(vector <char*> &words){
    vector <char*> left;
    vector <char*> right;
    if (words.size() >= 2){
        int counter = words.size();
        for (int i = 0; i < counter/2; i++){
            right.push_back(words[i]);
        }
        for (int i = 0; i < counter - counter/2; i++){
            left.push_back(words[i+counter/2]);
        }
        mergeSortAlpha(right);
        mergeSortAlpha(left);
        mergeAlpha(words, right, left);
    }
}*/

/*void SortingCompetition :: mergeLength(vector <char*> &result, vector <char*> &left, vector <char*> &right){
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < result.size(); i++){
        if (i2 >= right.size() || (i1 < left.size() && strlen(left[i1]) < strlen(right[i2]))){
           result[i] = left[i1];
           i1++;
        }
        else{
            result[i] = right[i2];
            i2++;
        }
    }
}*/

/*void SortingCompetition :: mergeSortLength(vector <char*> &words){
    if (words.size() >= 2){
        vector <char*> left;
        vector <char*> right;
        int counter = words.size();
        for (int i = 0; i < counter/2; i++){
            right.push_back(words[i]);
        }
        for (int i = 0; i < counter - counter/2; i++){
            left.push_back(words[i+counter/2]);
        }
        mergeSortLength(right);
        mergeSortLength(left);
        mergeLength(words, right, left);
    }
}*/

/*void SortingCompetition ::  radixMerge(vector <char*>& result, vector <char*>& number, int& startLocation){
    int counter = 0;
    for (int i = startLocation; i < startLocation + number.size(); i++){
        result[i] = number[counter];
        counter++;
    }
    startLocation += counter;
}*/

/*void SortingCompetition :: innerSort(vector <char*>& words){
    vector <char*> zeros;
    vector <char*> ones;
    vector <char*> twos;
    vector <char*> threes;
    vector <char*> fours;
    vector <char*> fives;
    vector <char*> sixes;
    vector <char*> sevens;
    vector <char*> eights;
    vector <char*> nines;
    for (int i = 0; i < words.size(); i++){
        if (words[i][1] - '0' == 0){
            zeros.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 1){
            ones.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 2){
            twos.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 3){
            threes.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 4){
            fours.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 5){
            fives.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 6){
            sixes.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 7){
            sevens.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 8){
            eights.push_back(words[i]);
            continue;
        }
        if (words[i][1] - '0' == 9){
            nines.push_back(words[i]);
            continue;
        }
    }
    int location = 0;
    radixMerge(words, zeros, location);
    radixMerge(words, ones, location);
    radixMerge(words, twos, location);
    radixMerge(words, threes, location);
    radixMerge(words, fours, location);
    radixMerge(words, fives, location);
    radixMerge(words, sixes, location);
    radixMerge(words, sevens, location);
    radixMerge(words, eights, location);
    radixMerge(words, nines, location);
}*/

/*void SortingCompetition :: radixSort(vector <char*>& words){
    vector <char*> zeros;
    vector <char*> ones;
    vector <char*> twos;
    vector <char*> threes;
    vector <char*> fours;
    vector <char*> fives;
    for (int i = 0; i < words.size(); i++){
        if (words[i][0] - '0' == 0){
            zeros.push_back(words[i]);
            continue;
        }
        if (words[i][0] - '0' == 1){
            ones.push_back(words[i]);
            continue;
        }
        if (words[i][0] - '0' == 2){
            twos.push_back(words[i]);
            continue;
        }
        if (words[i][0] - '0' == 3){
            threes.push_back(words[i]);
            continue;
        }
        if (words[i][0] - '0' == 4){
            fours.push_back(words[i]);
            continue;
        }
        if (words[i][0] - '0' == 5){
            fives.push_back(words[i]);
            continue;
        }
    }
    innerSort(zeros);
    innerSort(ones);
    innerSort(twos);
    innerSort(threes);
    innerSort(fours);
    innerSort(fives);
    int location = 0;
    radixMerge(words, zeros, location);
    radixMerge(words, ones, location);
    radixMerge(words, twos, location);
    radixMerge(words, threes, location);
    radixMerge(words, fours, location);
    radixMerge(words, fives, location);
    return;

}*/
