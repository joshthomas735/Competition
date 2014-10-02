
#include "sortingcompetition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

SortingCompetition::SortingCompetition(const string& inputFileName){
    lengths = new int*[20];
    fileName = inputFileName;
    lengthsCounter = 0;
    readData();
    return;
}

void SortingCompetition :: setFileName(const string& inputFileName){
    fileName = inputFileName;
    return;
}

bool SortingCompetition :: readData(){
    ifstream fin(fileName.c_str());
    if (!fin.is_open()){
        return false;
    }
    char* buff = new char[50];
    while (!fin.eof()){
        fin >> buff;
        int length = strlen(buff);
        char* word = new char[length+1];
        strcpy(word, buff);
        for (int i = 0; i < length; i++){
            word[i] = tolower(word[i]);
        }
        wordArray.push_back(word);
        if (lengthsCounter == 0){
            lengths[0] = new int[2];
            lengths[0][0] = length;
            lengths[0][1] = 1;
            lengthsCounter++;
        }
        else{
            bool duplicate = false;
            for (int i = 0; i < lengthsCounter; i++){
                if (length == lengths[i][0]){
                    lengths[i][1]++;
                    duplicate = true;
                    break;
                }
            }
            if (duplicate == false){
                if (lengthsCounter % 20 == 0){
                    resizeLengths();
                }
                lengths[lengthsCounter] = new int[2];
                lengths[lengthsCounter][0] = length;
                lengths[lengthsCounter][1] = 1;
                lengthsCounter++;
            }
        }
    }
    fin.close();
    return true;
}

void SortingCompetition :: resizeLengths(){
    int** newArray = new int*[lengthsCounter + 10];
    for (int i = 0; i < lengthsCounter; i++){
        newArray[i] = lengths[i];
    }
    delete [] lengths;
    lengths = newArray;
    return;
}


bool SortingCompetition :: prepareData(){
    for (int i = 0; i < wordArray.size(); i++){
        sortableArray.push_back(wordArray[i]);
    }
    sortableLengths = new int*[lengthsCounter];
    for (int i = 0; i < lengthsCounter; i++){
        sortableLengths[i] = new int[2];
        sortableLengths[i][0] = lengths[i][0];
        sortableLengths[i][1] = lengths[i][1];
    }
    return true;
}

void SortingCompetition :: sortData(){
    selectionSort(sortableLengths, lengthsCounter);
    //QuickSort(sortableArray, 0, (sortableArray.size()-1));
    mergeSortLength(sortableArray);
    int counter1 = 0;
    int counter = 0;
    vector<char*> tempWords;
    while (counter != lengthsCounter){
        if (sortableLengths[counter][1] == 1){
            counter1 += sortableLengths[counter][1];
            counter++;
            tempWords.clear();
            continue;
        }
        for (int i = counter1; i < counter1 + sortableLengths[counter][1]; i++){
            tempWords.push_back(sortableArray[i]);

        }
        mergeSortAlpha(tempWords);
        int tempCounter = 0;
        for (int i = counter1; i < counter1 + sortableLengths[counter][1]; i++){
            sortableArray[i] = tempWords[tempCounter];
            tempCounter++;
        }
        counter1 += sortableLengths[counter][1];
        counter++;
        tempWords.clear();
    }
}

void SortingCompetition :: QuickSort(vector<char*>& words, int left, int right){
    int i = left;
    int j = right;
    //char* pivot =
    /*if ((strlen(words[left]) >= strlen(words[right]) && strlen(words[left]) <= strlen(words[(left+right)/2])) || (strlen(words[left]) >= strlen(words[(left+right)/2]) && strlen(words[left]) <= strlen(words[right])))
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
    return;*/
}

int SortingCompetition :: partition (vector <char*>& words, int top, int bottom){
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
}

void SortingCompetition :: selectionSort(int** &sortArray, int size){
    if (size == 1){
        return;
    }
    else{
        moveLargest(sortArray, size);
        selectionSort(sortArray, size-1);
    }
}

void SortingCompetition :: moveLargest(int** &sortArray, int size){
    int index = size-1;
    for (int i = index - 1; i >= 0; i--){
        if (sortArray[i][0] >= sortArray[index][0]){
            index = i;
        }
    }
    swap(sortArray[index], sortArray[size-1]);
}

void SortingCompetition :: mergeAlpha(vector <char*> &result, vector <char*> &left, vector <char*> &right){
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

void SortingCompetition :: mergeSortAlpha(vector <char*> &words){
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
}

void SortingCompetition :: mergeLength(vector <char*> &result, vector <char*> &left, vector <char*> &right){
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

void SortingCompetition :: mergeSortLength(vector <char*> &words){
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
}

void SortingCompetition :: outputData(){
    cout << "Sorted Array: "<< sortableArray.size() << " words" << endl;
    for (int i = 0; i < sortableArray.size(); i++){
        cout << sortableArray[i] << endl;
    }
}

SortingCompetition :: ~SortingCompetition(){
    for (int i = 0; i < lengthsCounter; i++){
        delete [] lengths[i];
    }
    delete [] lengths;
    for (int i = 0; i < lengthsCounter; i++){
        delete [] sortableLengths[i];
    }
    delete [] sortableLengths;
    wordArray.clear();
    sortableArray.clear();
}
