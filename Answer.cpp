//# Internshala

#include <bits/stdc++.h>
using namespace std;

map <int, int> m;

// Function to calculate a day.

int dayofweek(int d, int m, int y, int val){
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; y -= m < 3; int x = ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7; return x; }

int main(){

// I have taken a input in vector v as {DD, MM, YYYY, val, ....}.

vector < int > v = {20, 12, 2020, 2, 21, 12, 2000, -12, 20, 1, 2020, 26, 1, 12, 2020, 10, 9, 12, 1980, -32, 20, 1, 1970, 442, 2, 6, 2050, -222};

int day=0;

// Here I have calculated values corresponding to a particular day.

for ( int i = 0; i < v.size() ; i=i+4 ){

    day = dayofweek(v[i], v[i+1], v[i+2], v[i+3]);
    m[day] += v[i+3];

}

string arr[7] = {"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};

for ( int i = 0; i < 7; i++ ){

    if ( m[i] ){
        cout<<arr[i]<<":"<<m[i];
    }  else  {
        // Else part is for a mean thing.
        cout<<arr[i]<<":"<<(m[(i-1+7)%7]+m[(i+1)%7])/2;
    }
    if ( i < 6 )  cout<<", ";

}

return 0;  
}