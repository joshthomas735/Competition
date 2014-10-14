#include "sortingcompetition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdlib.h"

using std :: ifstream;
using std :: cout;
using std :: endl;

SortingCompetition::SortingCompetition(const string& inputFileName){
    fileName = inputFileName;
    radixCharHelper = new int*[6];
    for (int i = 0; i < 6; i++){
        radixCharHelper[i] = new int[11];
        for (int x = 0; x < 11; x++){
            radixCharHelper[i][x] = 0;
        }
    }
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
    char* buff = new char[51];
    while (!fin.eof()){
        fin >> buff;
        int length = strlen(buff);
        char* word = new char[length+3];
        if (length < 10){
            word[0] = '0';
            word[1] = '0' + length;
            radixCharHelper[0][length%10]++;
            radixCharHelper[0][10]++;
        }
        else{
            word[1] = '0' + length % 10;
            word[0] = '0' + length/10;
            radixCharHelper[length/10][length % 10]++;
            radixCharHelper[length/10][10]++;
        }
        for (int i = 0; i < length; i++){
            buff[i] = tolower(buff[i]);
        }
        strcat(word, buff);
        wordArray.push_back(word);
    }
    delete [] buff;
    fin.close();
    return true;
}

bool SortingCompetition :: prepareData(){
    sortableArray2 = new char*[wordArray.size()];
    sortableSize = wordArray.size();
    for (int i = 0; i < sortableSize; i++){
        sortableArray2[i] = wordArray[i];
    }
    return true;
}

int SortingCompetition :: StringCompare(const void* a, const void* b){
    char const* char_a = *(char const**)a;
    char const* char_b = *(char const**)b;
    return strcmp(char_a, char_b);
}

void SortingCompetition :: sortData(){
    radixSortChar(sortableArray2);
    qsort(sortableArray2, sortableSize, sizeof(char*), StringCompare);
}

void SortingCompetition :: radixSortChar(char**& words){
    char** zeros = new char*[radixCharHelper[0][10]];
    char** ones = new char*[radixCharHelper[1][10]];
    char** twos = new char*[radixCharHelper[2][10]];
    char** threes = new char*[radixCharHelper[3][10]];
    char** fours = new char*[radixCharHelper[4][10]];
    char** fives = new char*[radixCharHelper[5][10]];
    int zerosC = 0;
    int onesC = 0;
    int twosC = 0;
    int threesC = 0;
    int foursC = 0;
    int fivesC = 0;
    for (int i = 0; i < sortableSize; i++){
        switch(words[i][0] - '0'){
        case 0:
            zeros[zerosC] = words[i];
            zerosC++;
            break;
        case 1:
            ones[onesC] = words[i];
            onesC++;
            break;
        case 2:
            twos[twosC] = words[i];
            twosC++;
            break;
        case 3:
            threes[threesC] = words[i];
            threesC++;
            break;
        case 4:
            fours[foursC] = words[i];
            foursC++;
            break;
        case 5:
            fives[fivesC] = words[i];
            fivesC++;
            break;
        }
    }
    innerSortChar(zeros, zerosC, 0);
    innerSortChar(ones, onesC, 1);
    innerSortChar(twos, twosC, 2);
    innerSortChar(threes, threesC, 3);
    innerSortChar(fours, foursC, 4);
    innerSortChar(fives, fivesC, 5);
    int location = 0;
    radixMergeChar(words, zeros, location, zerosC);
    radixMergeChar(words, ones, location, onesC);
    radixMergeChar(words, twos, location, twosC);
    radixMergeChar(words, threes, location, threesC);
    radixMergeChar(words, fours, location, foursC);
    radixMergeChar(words, fives, location, fivesC);
    return;

}

void SortingCompetition :: innerSortChar(char**& words, int size, int biggerNum){
    char** zeros = new char*[radixCharHelper[biggerNum][0]];
    char** ones = new char*[radixCharHelper[biggerNum][1]];
    char** twos = new char*[radixCharHelper[biggerNum][2]];
    char** threes = new char*[radixCharHelper[biggerNum][3]];
    char** fours = new char*[radixCharHelper[biggerNum][4]];
    char** fives = new char*[radixCharHelper[biggerNum][5]];
    char** sixes = new char*[radixCharHelper[biggerNum][6]];
    char** sevens = new char*[radixCharHelper[biggerNum][7]];
    char** eights = new char*[radixCharHelper[biggerNum][8]];
    char** nines = new char*[radixCharHelper[biggerNum][9]];
    int zerosC = 0;
    int onesC = 0;
    int twosC = 0;
    int threesC = 0;
    int foursC = 0;
    int fivesC = 0;
    int sixesC = 0;
    int sevensC = 0;
    int eightsC = 0;
    int ninesC = 0;
    for (int i = 0; i < size; i++){
        switch(words[i][1] - '0'){
        case 0:
            zeros[zerosC] = words[i];
            zerosC++;
            break;
        case 1:
            ones[onesC] = words[i];
            onesC++;
            break;
        case 2:
            twos[twosC] = words[i];
            twosC++;
            break;
        case 3:
            threes[threesC] = words[i];
            threesC++;
            break;
        case 4:
            fours[foursC] = words[i];
            foursC++;
            break;
        case 5:
            fives[fivesC] = words[i];
            fivesC++;
            break;
        case 6:
            sixes[sixesC] = words[i];
            sixesC++;
            break;
        case 7:
            sevens[sevensC] = words[i];
            sevensC++;
            break;
        case 8:
            eights[eightsC] = words[i];
            eightsC++;
            break;
        case 9:
            nines[ninesC] = words[i];
            ninesC++;
            break;
        }
    }
    int location = 0;
    radixMergeChar(words, zeros, location, zerosC);
    radixMergeChar(words, ones, location, onesC);
    radixMergeChar(words, twos, location, twosC);
    radixMergeChar(words, threes, location,threesC);
    radixMergeChar(words, fours, location,foursC);
    radixMergeChar(words, fives, location,fivesC);
    radixMergeChar(words, sixes, location,sixesC);
    radixMergeChar(words, sevens, location,sevensC);
    radixMergeChar(words, eights, location,eightsC);
    radixMergeChar(words, nines, location,ninesC);
}
void SortingCompetition ::  radixMergeChar(char**& result, char**& number, int& startLocation, int size){
    int counter = 0;
    for (int i = startLocation; i < startLocation + size; i++){
        result[i] = number[counter];
        counter++;
    }
    startLocation += counter;
}

void SortingCompetition :: outputData(){
    cout << "Sorted Array: "<< wordArray.size() << " words" << endl;
    char* buff = new char[3];
    for (int i = 0; i < sortableSize; i++){
        buff[0] = sortableArray2[i][0];
        buff[1] = sortableArray2[i][1];
        for (int x = 2; x < atoi(buff) + 2; x++){
            cout << sortableArray2[i][x];
        }
        cout << endl;
    }
    delete [] buff;
}

SortingCompetition :: ~SortingCompetition(){
    for (int i = 0; i < sortableSize; i++){
        delete [] sortableArray2[i];
    }
    delete [] sortableArray2;
    wordArray.clear();
}
