#include <iostream>
#include <vector>
#include "sortingcompetition.h"
//#include <chrono>
#include <ctime>


int main()
{
    double diff;
    clock_t start;
    //std::chrono::time_point<std::chrono::system_clock> start, end;
    SortingCompetition* s1 = new SortingCompetition("input.txt");
    s1->prepareData();
    //start = std::chrono::system_clock::now();
    start = clock();
    s1 ->sortData();
    diff = ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
    std:: cout<<"printf: "<< diff <<'\n';
    //end = std::chrono::system_clock::now();
    //std::chrono::duration<double> elapsed_seconds = end-start;
    //std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    //std::cout << "finished computation at " << std:: ctime(&end_time) << " elapsed time: " << elapsed_seconds.count() << "s\n";
    //cout << endl;
    s1 -> outputData();

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
