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
    int sortableSize;
    int** radixCharHelper;
    char** sortableArray2;
    vector <char*> wordArray;
    string fileName;
};

#endif // SORTINGCOMPETITION_H
