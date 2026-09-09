// Objective 1: Trace variables, control flow, scope and lifetime by hand
// Objective 2: Explain call stack behaviour for recursive calls
// Objective 3: Distinguish value vs reference semantics
#include <vector>
#include <iostream>
using namespace std ; 




void modififunc(int val , int *ref){
  val = 99 ; 
  *ref = 99 ; 
}

int sumRecursive(int n, std::vector<int>& ExecutionLog) {
    // Static Variable: Lifetime lasts until the program ends. Scope is local to this function.
    static int callCount = 0; 
    callCount++;
    
    // Local Automatic Variable: Created when execution reaches this line, destroyed at block end.
    int currentId = callCount; 
    
    ExecutionLog.push_back(currentId); // Log entry into this stack frame

    // Base Case
    if (n <= 0) {
        return 0; 
    }
    
    // Recursive Case
    int result = n + sumRecursive(n - 1, ExecutionLog);
    return result;
}

int main(){
  cout<<"hellow world"<<endl ;
  int num1,num2 = 1 ; 
  modififunc(num1,&num2) ;
  cout<<num1 <<  endl ; 
  cout<<num2 ;       

  std::vector<int> log;
    int totalSum = sumRecursive(3, log);

}

