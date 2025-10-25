#include<iostream>

using namespace std;

class Calculator{
    
    
    public :
       double add( double a,int b){
           return a+b;
           
       }
       double sub(double a,double b){
           return a-b;
       }
       double mul(double a,double b){
           return a*b;
           
       }
           
       double divis(double a,double b){
           if(b==0){
               cout<<"Error"<<endl;
               cout<<endl;
           
           return 0;
           }
       
       return a/b;
       }
};

int main(){
    Calculator Cal;
   int take;
    double a,b;
    
    
while(true){
    //while true means that the loop will run to infinite time in the  given posssibe conditoins
    //true is a boolean constant that means 1 which means true
    
    
    cout<<"Enter your operations:"<<endl;
    cout<<" + "<<"Type 1."<<endl;
    cout<<endl;
    cout<<" - "<<"Type 2."<<endl;
    cout<<endl;
    cout<<" * "<<"Type 3."<<endl;
    cout<<endl;
    cout<<" / "<<"Type 4."<<endl;
    cout<<endl;
    cin>>take;
    
    if(take>=5){
        cout<<"the operation is inavlid"<<endl;
        break;
    }
    
    cout<<"Enter the two numbers";
    cin>>a>>b;
    cout<<endl;
    
    
    switch(take){
        case 1:
        cout<<"Opeartion is :"<<Cal.add(a,b)<<endl;
        break;
        
        case 2:
        cout<<"Operation is:"<<Cal.sub(a,b)<<endl;
        break;
        
        
        case 3:
        cout<<"opeartion is:"<<Cal.mul(a,b)<<endl;
        
        
        case 4:
        cout<<"opeartion is:"<<Cal.divis(a,b)<<endl;
        
        break;
           
           default:
           cout<<"Error in the opeartion!!"<<endl;
    }
           
    }
    return 0;
    
}


