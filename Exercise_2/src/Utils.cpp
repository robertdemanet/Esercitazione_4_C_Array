#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int& S,
                   double*& w,
                   double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // prendo S
    string line;
    getline(file,line);
    line = line.substr(2);
    istringstream convertS;
    convertS.str(line);
    convertS >> S;

    // prendo n
    getline(file,line);
    line = line.substr(2);
    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    // salto la riga relativa a w e r
    getline(file,line);

    // salvo i valori dei vettori w e r
    w = new double[n];
    r = new double[n];
    int i = 0;
    char c;
    while (!file.eof())
    {
        getline(file,line);
        istringstream Convert;
        Convert.str(line);
        Convert>>w[i];
        Convert>>c;
        Convert>>r[i];
        i++;
    }

    file.close();
    return true;
}


double rateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double rateOfReturn = 0;
    for (unsigned int i = 0; i < n; ++i) {
        rateOfReturn += r[i] * w[i];
    }
    return rateOfReturn;
}


bool ExportResult(const string &outputFilePath,
                  const size_t &n,
                  const unsigned int &S,
                  const double * const &w,
                  const double * const &r,
                  const double &rateOfReturn)
{
    // apro il file
    ofstream file;
    file.open(outputFilePath);
    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file<< "S = " << S << ", n = " << n << endl;
    file<< "w = " << ArrayToString(n,w) << endl;
    file<< "r = " << ArrayToString(n,r) << endl;
    file<< "Rate of return of the portfolio: " << rateOfReturn << endl;
    file<< "V: " << S + rateOfReturn*S << endl;
    file.close();
    return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}


















