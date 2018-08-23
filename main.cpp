#include <iostream>
#include <boost/spirit/home/support/detail/hold_any.hpp>
#include <armadillo>
#include <dlib/matrix.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace arma;

void test_arma(){
    //multinucleo
    mat m1(5000, 5000, fill::randn);
    mat m2(5000, 5000, fill::randn);
    mat m3 = m1*m2;
    //cout<<m3<<endl;
    //cout<<m3.n_rows<<" "<<m3.n_cols<<endl;
    //cout<<"----------------\n";
}

void test_dlib(){
    //mononucleo
    dlib::matrix<double> dm1 = dlib::randm(1000, 1000);
    dlib::matrix<double> dm2 = dlib::randm(1000, 1000);
    dlib::matrix<double> dm3 = dm1*dm2;
    //cout<<dm3<<endl;
    //cout<<dm3.nr()<<" "<<dm3.nc()<<endl;
    //cout<<"----------------\n";
}

int main() {
    high_resolution_clock::time_point t1_arma = high_resolution_clock::now();
    test_arma();
    high_resolution_clock::time_point t2_arma = high_resolution_clock::now();
    auto duration_arma = duration_cast<std::chrono::milliseconds>( t2_arma - t1_arma ).count();
    cout<<"arma: "<<duration_arma<<" milisegundos"<<endl;

    high_resolution_clock::time_point t1_dlib = high_resolution_clock::now();
    test_dlib();
    high_resolution_clock::time_point t2_dlib = high_resolution_clock::now();
    auto duration_dlib = duration_cast<std::chrono::milliseconds>( t2_dlib - t1_dlib ).count();
    cout<<"dlib: "<<duration_dlib<<" milisegundos"<<endl;

    return 0;
}