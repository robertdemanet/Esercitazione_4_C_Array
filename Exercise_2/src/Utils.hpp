#pragma once
#include "iostream"


using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int &S,
                   double*& w,
                   double*& r);


double rateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int& S,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn);


string ArrayToString(const size_t& n,
                     const double * const &v);
