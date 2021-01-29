#include <iostream>
#include <cmath>

//euler declaration
const double EulerConstant = std::exp(1.0);

//function declarations
long double function(long double x);
void secant(long double p0, long double p1, long double tol, long double max_iter);


//newton's method implementation
void secant(long double p0, long double p1, long double tol, long double max_iter){
    int i = 1;
    static long double p_0 = p0;
    static long double p_1 = p1;
    
    while (i < max_iter){
        long double p_i = p_1-function(p_1)*(p_1-p_0)/(function(p_1)-function(p_0));
        
        std::cout << 'P' << i << " = " << p_i << std::endl;
        
        long double absolute = abs(p_i-p_1);
        if (absolute < tol){
            std::cout << "Finished in " << i << " iterations" << std::endl;
            return;
        }
        i++;
        p_0 = p_1;
        p_1 = p_i;
        
    }
    std::cout << "Method Failed" << std::endl;
}

//function
long double function(long double  x){
    
  //double efun = pow(EulerConstant, x);
  //double xpow = pow(2, -x);
  //double cosin = 2*cos(x);
  //double constant = -6;
  //long double square = pow(x, 2);
  //double squareRoot = sqrt(x);
  //double double variable = 4*x;
  //double double cosin = cos(x);
  //double result = efun + xpow + cosin + constant; //e^x + 2^-x + 2cosx - 6
  //std::cout << result << std::endl;
    
    double cube = pow(x, 3);
    long double result = -1*cube-cos(x);
    
    return result;
    
}


int main(int argc, const char * argv[]) {
    //startin p0, p1
    long double p0 = -1.0;
    long double p1 = 0.0;
    
    //tolerance
    long double tol = pow(10.0, -5.0);
    
    //iterations
    long double max_iter = 100.0;
    
    //function call
    secant(p0, p1, tol, max_iter);

}
