/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream> 
#include<vector>
using namespace std;
int main(){
vector<int> t[3];  //three towers A,B,C represented as an array of 3 vectors
int n, candidate, to, from, move=0; 
cout<<"Please enter a integer of rings to move: ";
cin>>n; 
cout << endl;

//end program if 0 or less rings
if(n==0||n<0){ cout << "Invalid amount of rings.";
return 0;}

//initialize the 3 towers
for (int i=n+1;i>=1;i--)
t[0].push_back(i); 
t[1].push_back(n+1); 
t[2].push_back(n+1);

//initialize towers and candidate 
from=0;
to=2;
if((n%2)==1) to=1;
candidate=1;
while(t[1].size()<n+1){
cout<<"Move#"<<++move<<": Transfer ring "<<candidate<< " from tower "<< char(from+65)<<" to tower "<<char(to+65)<<endl;

//move the disks around
 t[to].push_back(t[from].back());
      t[from].pop_back();
      

//get next "from tower" It's not the most recent "to" so which is it?
if(n % 2 == 1){
    
//check statements
if(t[(to+1)%3].back() < t[(to + 2) %3].back()) from = (to+1)%3; 
else from = (to+2)%3; 
if(t[from].back() < t[(from+1)%3].back()) to = (from+1) %3; 
else to = (from+2)%3; 
candidate = t[from].back();
}

else {
if(t[(to+1)%3].back() < t[(to+ 2) %3].back()) from = (to+1)%3; 
else from=(to+2)%3; 
if(t[from].back() < t[(from+2)%3].back()) to = (from+2)%3; 
else to =(from+1)%3; 
}
	    	
candidate = t[from].back(); // it’s on the top of the current “from tower”
}

return 0;
}
