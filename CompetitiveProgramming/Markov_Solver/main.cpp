// CPP program to find the probability of a state from any given destination and given a time in a stochastic process 
#include <iostream>
#include <vector>
#include <valarray>
using namespace std;
#define float_vec vector<float>
//multiply 2 given mats
vector<float_vec > multiply(vector<float_vec > A, vector<float_vec > B, int N) {
    vector<float_vec > C(N, vector<float>(N, 0));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
         for (int k = 0; k < N; ++k)
            C[i][j] += A[i][k] * B[k][j];
   return C; //res of matrix mult
}
//calc power of a matrix
vector<float_vec > power(vector<float_vec > M, int p, int n) {
    vector<float_vec > A(n, vector<float>(n, 0));
    for (int i = 0; i < n; ++i)
        A[i][i] = 1;
    while (p) {
      if (p % 2)
         A = multiply(A, M, n);
      M = multiply(M, M, n);
      p /= 2;
    }
    return A; //powered matrix
}
float get_probs(vector<float_vec > M, int States, int Final, int Source, int Time) {
    vector<float_vec > trans_mat = power(M, Time, States);
    return trans_mat[Final - 1][Source - 1];
}
void as_fraction(double number, int cycles = 10, double precision = 5e-4){
    int sign  = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number,whole_part;
    double decimal_part =  number - (int)number;
    int counter = 0;
    
    valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;
    
    while(decimal_part > precision & counter < cycles){
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;
        
        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;
        
        decimal_part = new_number - whole_part;
        counter += 1;
    }
    cout<<"p: "<< number <<"\tFraction: " << sign * vec_1[0]<<'/'<< vec_1[1]<<endl;
}
//DRIVER CODE IMPL
int main() {
    vector<float_vec > Trans{
      {0, 0.3333333, 0.33333333, 0.3333333},
      {0.3333333, 0, 0.3333333, 0.3333333},
      {0.3333333, 0.3333333, 0, 0.3333333},
      {0.3333333, 0.3333333, 0.3333333, 0}
   };
    

    //number of available states
    int States = 4;
    int S = 1, F = 1, T = 4;
    float res = get_probs(Trans, States, F, S, T);
    cout << "Probability of reaching: " << F << " within time " << T << " after starting from: " << S << " is: " << res;
    cout << "\nAs a fraction, this is:\n";
    as_fraction(res);
    return 0;
}
