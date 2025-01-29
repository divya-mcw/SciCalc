#include <iostream>
#include <cmath>

using namespace std;
template <typename T>

class ScientificCalculator {
public:
    T add(T a,T b){return a + b;}
    T subtract(T a,T b){return a - b;}
    T multiply(T a,T b){return a * b;}
    T divide(T a,T b){
        if(b==0) throw runtime_error("Error: Division by zero!");
        return a/b;
    }
    T power(T base,T exponent){return pow(base,exponent);}    
    T root(T num){
        if(num<0) throw runtime_error("Error: Root of negative number");
        return sqrt(num);
    }
    T sine(T angle){return sin(angle*(M_PI/180.0));}
    T cosine(T angle){return cos(angle*(M_PI/180.0));}
    T tangent(T angle){ 
        if(fmod(angle,90)==0 && fmod(angle,180)!=0) 
            throw runtime_error("Error: Tan  is undefined at 90° + k*180°");
        return tan(angle*(M_PI/180.0)); 
    }
    T logBaseE(T num){
        if(num<=0) throw runtime_error("Error: Logarithm of non-positive number");
        return log(num);
    }
    T exponential(T num){return exp(num);}
    T fraction(T num){
        if(num==0) throw runtime_error("Error: Reciprocal of zero");
        return 1.0/num;
    }
};

int main(){
    int choice;
    double num1, num2;
    ScientificCalculator<double> calc;
    while(true){
        cout << "\nScientific Calculator Menu:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Square Root\n7. Sine\n8. Cosine\n9. Tangent\n10. Log\n11. Exponential\n12. Fraction (1/x)\n13. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        try{
            switch(choice){
            case 1:
                cout<<"Enter two numbers: ";
                cin>>num1>>num2;
                cout<<"Result: "<<calc.add(num1,num2)<<endl;
                break;
            case 2:
                cout<<"Enter two numbers: ";
                cin>>num1>>num2;
                cout<<"Result: "<<calc.subtract(num1,num2)<<endl;
                break;
            case 3:
                cout<<"Enter two numbers: ";
                cin>>num1>>num2;
                cout<<"Result: "<<calc.multiply(num1,num2)<<endl;
                break;
            case 4:
                cout<<"Enter two numbers: ";
                cin>>num1>>num2;
                cout<<"Result: "<<calc.divide(num1,num2)<<endl;
                break;
            case 5:
                cout<<"Enter base and exponent: ";
                cin>>num1>>num2;
                cout<<"Result: "<< calc.power(num1,num2)<<endl;
                break;
            case 6:
                cout<<"Enter a number: ";
                cin>>num1;
                cout<<"Result: "<<calc.root(num1)<<endl;
                break;
            case 7:
                cout<<"Enter angle in degrees: ";
                cin>>num1;
                cout<<"Result: "<<calc.sine(num1)<<endl;
                break;
            case 8:
                cout<<"Enter angle in degrees: ";
                cin>>num1;
                cout<<"Result: "<<calc.cosine(num1)<<endl;
                break;
            case 9:
                cout<<"Enter angle in degrees: ";
                cin>>num1;
                cout<< "Result: "<<calc.tangent(num1)<<endl;
                break;
            case 10:
                cout<<"Enter a number: ";
                cin>>num1;
                cout<< "Result: "<<calc.logBaseE(num1)<<endl;
                break;
            case 11:
                cout<<"Enter a number: ";
                cin>>num1;
                cout<< "Result: "<<calc.exponential(num1)<<endl;
                break;
            case 12:
                cout<<"Enter a number: ";
                cin>>num1;
                cout<<"Result: "<<calc.fraction(num1)<<endl;
                break;
            case 13:
                cout<<"Exiting calculator"<<endl;
                return 0;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
            }
        } catch (const exception& e) {
            cerr<<e.what()<<endl;
        }
    }
}
