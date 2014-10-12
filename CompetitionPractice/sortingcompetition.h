#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H
#include <string>
#include <vector>

using std :: string;
using std :: vector;

class SortingCompetition
{
public:
    SortingCompetition(const string&);
    void setFileName(const string&);
    bool readData();
    bool prepareData();
    void sortData();
    void outputData();
private:
    static int StringCompare(const void*, const void*);
    void radixSortChar(char**&);
    void innerSortChar(char**&, int, int);
    void radixMergeChar(char**&, char**&, int&, int);
    ~SortingCompetition();
    int** radixCharHelper;
    char** sortableArray2;
    vector <char*> wordArray;
    string fileName;
    //void resizeLengths();
    //int partition (vector <char*>&, int, int);
    //void QuickSort(vector<char*>&, int, int);
    //void selectionSort(int**&, int);
    //void moveLargest(int**&, int);
    //void mergeAlpha(vector <char*>&, vector <char*>&, vector <char*>&);
    //void mergeSortAlpha(vector <char*> &words);
    //void mergeLength(vector <char*>&, vector <char*>&, vector <char*>&);
    //void mergeSortLength(vector <char*>&);
    //void radixSort(vector<char*>&);
    //void innerSort(vector <char*>&);
    //void radixMerge(vector <char*>&, vector <char*>&, int&);
    //int** lengths;
    //vector <char*> sortableArray;
    //int lengthsCounter;
};

#endif // SORTINGCOMPETITION_H
