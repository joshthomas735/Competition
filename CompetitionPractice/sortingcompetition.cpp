#include "sortingcompetition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdlib.h"

using namespace std;

SortingCompetition::SortingCompetition(const string& inputFileName){
    //lengths = new int*[20];
    fileName = inputFileName;
    //lengthsCounter = 0;
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
            switch (length){
            case 1:
                radixCharHelper[0][1]++;
                radixCharHelper[0][10]++;
                break;
            case 2:
                radixCharHelper[0][2]++;
                radixCharHelper[0][10]++;
                break;
            case 3:
                radixCharHelper[0][3]++;
                radixCharHelper[0][10]++;
                break;
            case 4:
                radixCharHelper[0][4]++;
                radixCharHelper[0][10]++;
                break;
            case 5:
                radixCharHelper[0][5]++;
                radixCharHelper[0][10]++;
                break;
            case 6:
                radixCharHelper[0][6]++;
                radixCharHelper[0][10]++;
                break;
            case 7:
                radixCharHelper[0][7]++;
                radixCharHelper[0][10]++;
                break;
            case 8:
                radixCharHelper[0][8]++;
                radixCharHelper[0][10]++;
                break;
            case 9:
                radixCharHelper[0][9]++;
                radixCharHelper[0][10]++;
                break;
            }
        }
        //This might be splitting hairs, but all these if statements could be swtich
        //statements if we wanted to. It already looks clean, but the switch statements
        //would be a little bit shorter
        else{
            int random = length;
            word[1] = '0' + random % 10;
            random/=10;
            word[0] = '0' + random; //can we combine these two lines into: word[0]=random/10; ?
            random = length;

            if (random/10 == 1){
                switch(random%10){
                case 0:
                    radixCharHelper[random/10][0]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 1:
                    radixCharHelper[random/10][1]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 2:
                    radixCharHelper[random/10][2]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 3:
                    radixCharHelper[random/10][3]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 4:
                    radixCharHelper[random/10][4]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 5:
                    radixCharHelper[random/10][5]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 6:
                    radixCharHelper[random/10][6]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 7:
                    radixCharHelper[random/10][7]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 8:
                    radixCharHelper[random/10][8]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 9:
                    radixCharHelper[random/10][9]++;
                    radixCharHelper[random/10][10]++;
                    break;
                }

            }
            if (random/10 == 2){
                switch(random % 10){
                case 0:
                    radixCharHelper[random/10][0]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 1:
                    radixCharHelper[random/10][1]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 2:
                    radixCharHelper[random/10][2]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 3:
                    radixCharHelper[random/10][3]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 4:
                    radixCharHelper[random/10][4]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 5:
                    radixCharHelper[random/10][5]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 6:
                    radixCharHelper[random/10][6]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 7:
                    radixCharHelper[random/10][7]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 8:
                    radixCharHelper[random/10][8]++;
                    radixCharHelper[random/10][10]++;
                    break;
                case 9:
                    radixCharHelper[random/10][9]++;
                    radixCharHelper[random/10][10]++;
                    break;
                }

            }
            if (random/10 == 3){
                switch(random % 10){
                case 0:
                    radixCharHelper[random][0]++;
                    radixCharHelper[random][10]++;
                    break;
                case 1:
                    radixCharHelper[random][1]++;
                    radixCharHelper[random][10]++;
                    break;
                case 2:
                    radixCharHelper[random][2]++;
                    radixCharHelper[random][10]++;
                    break;
                case 3:
                    radixCharHelper[random][3]++;
                    radixCharHelper[random][10]++;
                    break;
                case 4:
                    radixCharHelper[random][4]++;
                    radixCharHelper[random][10]++;
                    break;
                case 5:
                    radixCharHelper[random][5]++;
                    radixCharHelper[random][10]++;
                    break;
                case 6:
                    radixCharHelper[random][6]++;
                    radixCharHelper[random][10]++;
                    break;
                case 7:
                    radixCharHelper[random][7]++;
                    radixCharHelper[random][10]++;
                    break;
                case 8:
                    radixCharHelper[random][8]++;
                    radixCharHelper[random][10]++;
                    break;
                case 9:
                    radixCharHelper[random][9]++;
                    radixCharHelper[random][10]++;
                }

            }
            if (random/10 == 4){
                switch(random % 10){
                case 0:
                    radixCharHelper[random][0]++;
                    radixCharHelper[random][10]++;
                    break;
                case 1:
                    radixCharHelper[random][1]++;
                    radixCharHelper[random][10]++;
                    break;
                case 2:
                    radixCharHelper[random][2]++;
                    radixCharHelper[random][10]++;
                    break;
                case 3:
                    radixCharHelper[random][3]++;
                    radixCharHelper[random][10]++;
                    break;
                case 4:
                    radixCharHelper[random][4]++;
                    radixCharHelper[random][10]++;
                    break;
                case 5:
                    radixCharHelper[random][5]++;
                    radixCharHelper[random][10]++;
                    break;
                case 6:
                    radixCharHelper[random][6]++;
                    radixCharHelper[random][10]++;
                    break;
                case 7:
                    radixCharHelper[random][7]++;
                    radixCharHelper[random][10]++;
                    break;
                case 8:
                    radixCharHelper[random][8]++;
                    radixCharHelper[random][10]++;
                    break;
                case 9:
                    radixCharHelper[random][9]++;
                    radixCharHelper[random][10]++;
                    break;
                }

            }
            if (random/10 == 5){
                switch(random % 10){
                case 0:
                    radixCharHelper[random][0]++;
                    radixCharHelper[random][10]++;
                    break;
                case 1:
                    radixCharHelper[random][1]++;
                    radixCharHelper[random][10]++;
                    break;
                case 2:
                    radixCharHelper[random][2]++;
                    radixCharHelper[random][10]++;
                    break;
                case 3:
                    radixCharHelper[random][3]++;
                    radixCharHelper[random][10]++;
                    break;
                case 4:
                    radixCharHelper[random][4]++;
                    radixCharHelper[random][10]++;
                    break;
                case 5:
                    radixCharHelper[random][5]++;
                    radixCharHelper[random][10]++;
                    break;
                case 6:
                    radixCharHelper[random][6]++;
                    radixCharHelper[random][10]++;
                    break;
                case 7:
                    radixCharHelper[random][7]++;
                    radixCharHelper[random][10]++;
                    break;
                case 8:
                    radixCharHelper[random][8]++;
                    radixCharHelper[random][10]++;
                    break;
                case 9:
                    radixCharHelper[random][9]++;
                    radixCharHelper[random][10]++;
                    break;
                }

            }
        }
        for (int i = 0; i < length; i++){
            buff[i] = tolower(buff[i]);
        }
        strcat(word, buff);
        wordArray.push_back(word);
        /*if (lengthsCounter == 0){
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
        }*/
    }
    fin.close();
    //Do we need to delete word and buff? I think so
    return true;
}

bool SortingCompetition :: prepareData(){
    sortableArray2 = new char*[wordArray.size()];
    /*for (int i = 0; i < wordArray.size(); i++){
        sortableArray.push_back(wordArray[i]);
    }*/
    for (int i = 0; i < wordArray.size(); i++){
        sortableArray2[i] = wordArray[i];
    }
    /*sortableLengths = new int*[lengthsCounter];
    for (int i = 0; i < lengthsCounter; i++){
        sortableLengths[i] = new int[2];
        sortableLengths[i][0] = lengths[i][0];
        sortableLengths[i][1] = lengths[i][1];
    }*/
    return true;
}

int SortingCompetition :: StringCompare( const void* a, const void* b)
{
char const *char_a = *(char const **)a;
char const *char_b = *(char const **)b;

return strcmp(char_a, char_b);
}

void SortingCompetition :: sortData(){
    radixSortChar(sortableArray2);
    qsort(sortableArray2, wordArray.size(), sizeof(char*), StringCompare);
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

    for (int i = 0; i < wordArray.size(); i++){
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
//need to find a way to put the radixSortHelper in here
void SortingCompetition :: innerSortChar(char**& words, int size, int biggerNum){
    char** zeros;
    char** ones;
    char** twos;
    char** threes;
    char** fours;
    char** fives;
    char** sixes;
    char** sevens;
    char** eights;
    char** nines;
    switch(biggerNum){
    case 0:
        ones = new char*[radixCharHelper[0][1]];
        twos = new char*[radixCharHelper[0][2]];
        threes = new char*[radixCharHelper[0][3]];
        fours = new char*[radixCharHelper[0][4]];
        fives = new char*[radixCharHelper[0][5]];
        sixes = new char*[radixCharHelper[0][6]];
        sevens = new char*[radixCharHelper[0][7]];
        eights = new char*[radixCharHelper[0][8]];
        nines = new char*[radixCharHelper[0][9]];
        break;
    case 1:
        zeros = new char*[radixCharHelper[1][0]];
        ones = new char*[radixCharHelper[1][1]];
        twos = new char*[radixCharHelper[1][2]];
        threes = new char*[radixCharHelper[1][3]];
        fours = new char*[radixCharHelper[1][4]];
        fives = new char*[radixCharHelper[1][5]];
        sixes = new char*[radixCharHelper[1][6]];
        sevens = new char*[radixCharHelper[1][7]];
        eights = new char*[radixCharHelper[1][8]];
        nines = new char*[radixCharHelper[1][9]];
        break;
    case 2:
        zeros = new char*[radixCharHelper[2][0]];
        ones = new char*[radixCharHelper[2][1]];
        twos = new char*[radixCharHelper[2][2]];
        threes = new char*[radixCharHelper[2][3]];
        fours = new char*[radixCharHelper[2][4]];
        fives = new char*[radixCharHelper[2][5]];
        sixes = new char*[radixCharHelper[2][6]];
        sevens = new char*[radixCharHelper[2][7]];
        eights = new char*[radixCharHelper[2][8]];
        nines = new char*[radixCharHelper[2][9]];
        break;
    case 3:
        zeros = new char*[radixCharHelper[3][0]];
        ones = new char*[radixCharHelper[3][1]];
        twos = new char*[radixCharHelper[3][2]];
        threes = new char*[radixCharHelper[3][3]];
        fours = new char*[radixCharHelper[3][4]];
        fives = new char*[radixCharHelper[3][5]];
        sixes = new char*[radixCharHelper[3][6]];
        sevens = new char*[radixCharHelper[3][7]];
        eights = new char*[radixCharHelper[3][8]];
        nines = new char*[radixCharHelper[3][9]];
        break;
    case 4:
        zeros = new char*[radixCharHelper[4][0]];
        ones = new char*[radixCharHelper[4][1]];
        twos = new char*[radixCharHelper[4][2]];
        threes = new char*[radixCharHelper[4][3]];
        fours = new char*[radixCharHelper[4][4]];
        fives = new char*[radixCharHelper[4][5]];
        sixes = new char*[radixCharHelper[4][6]];
        sevens = new char*[radixCharHelper[4][7]];
        eights = new char*[radixCharHelper[4][8]];
        nines = new char*[radixCharHelper[4][9]];
        break;
    case 5:
        zeros = new char*[radixCharHelper[5][0]];
        ones = new char*[radixCharHelper[5][1]];
        twos = new char*[radixCharHelper[5][2]];
        threes = new char*[radixCharHelper[5][3]];
        fours = new char*[radixCharHelper[5][4]];
        fives = new char*[radixCharHelper[5][5]];
        sixes = new char*[radixCharHelper[5][6]];
        sevens = new char*[radixCharHelper[5][7]];
        eights = new char*[radixCharHelper[5][8]];
        nines = new char*[radixCharHelper[5][9]];
        break;
    }
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
    for (int i = 0; i < wordArray.size(); i++){
        buff[0] = sortableArray2[i][0];
        buff[1] = sortableArray2[i][1];
        for (int x = 2; x < atoi(buff) + 2; x++){
            cout << sortableArray2[i][x];
        }
        cout << endl;
    }
}

SortingCompetition :: ~SortingCompetition(){
    /*for (int i = 0; i < lengthsCounter; i++){
        delete [] lengths[i];
    }
    delete [] lengths;
    for (int i = 0; i < lengthsCounter; i++){
        delete [] sortableLengths[i];
    }
    delete [] sortableLengths;*/
    for (int i = 0; i < wordArray.size(); i++){
        delete [] sortableArray2[i];
    }
    delete [] sortableArray2;
    wordArray.clear();
}

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
