#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;


int main()
{
    string inputFileName = "./data.csv";
    size_t n = 0;
    unsigned int S = 0;
    double* r = nullptr;
    double* w = nullptr;
    if (!ImportVectors(inputFileName, n, S, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout<< "Import successful: n = "<< n << ", r = "<< ArrayToString(n, r) << ", w = "<< ArrayToString(n, w)<< endl;

    double rateOfReturn_ = rateOfReturn(n,w,r);
    cout << "Rate of return: " << rateOfReturn_ << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, S, w, r, rateOfReturn_))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;

}




