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
    ~SortingCompetition();
    void resizeLengths();
    int partition (vector <char*>&, int, int);
    void QuickSort(vector<char*>&, int, int);
    void selectionSort(int**&, int);
    void moveLargest(int**&, int);
    void mergeAlpha(vector <char*>&, vector <char*>&, vector <char*>&);
    void mergeSortAlpha(vector <char*> &words);
    void mergeLength(vector <char*>&, vector <char*>&, vector <char*>&);
    void mergeSortLength(vector <char*>&);
    int** lengths;
    int** sortableLengths;
    vector <char*> wordArray;
    vector <char*> sortableArray;
    string fileName;
    int lengthsCounter;
};

#endif // SORTINGCOMPETITION_H
