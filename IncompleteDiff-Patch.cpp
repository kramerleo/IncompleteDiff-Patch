//Written by Leo Kramer, 20018

//The Program has a major error, so most of the cout and display is for developing, and trying to figure out the error, (it wouldn't be in the final version).
//In addition, I was unable to implement the trace and patch additions as there were errors with this base algorithim, and you can't build the program on a shakey base.

#include <fstream> 
#include <string> 
#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>

using namespace std; 

void diff(string s, string s2){
        //(through array)set maximum possible size of (SES) shortest edit script to the two strings in full added together
        int n = s.size();
        int m = s2.size();
        int max = n + m;

        //convert strings to arrays for efficency
        char char_array1[n+1];
        strcpy(char_array1, s.c_str());
        char char_array2[n+1];
        strcpy(char_array2, s2.c_str());

        //define some Ints for algorithm.
        int x=0; //Deletions to first string
        int y=0; //Additions to first string from second string

        //build array that displays closest x in terms of k
        int Array[(2 * max + 1)];
        Array[1]=0;
        int * p = &Array[0];

        cout << "___________START______________" << endl;
           //To check 'difference contours' of the shortest edit script using Myers Algorithim (each 'move'):
            for(int d = 0; ((d <= max) && (d >= 0)); d++ ){
                //to check different k lines, and how far they reach (to find the one that reaches the end first)
                //Incremented K to every other line because when d is even, K is even, and when it is odd, it is odd
                for(int k = -d ; (k <= d); k+=2){
                    cout << "For K  = " << k << "---------" << endl;
                    if ((k == -d)||((k != d) && (Array[k-1] < Array[k+1]))){cout << "K-1 Array: " << Array[k-1] << " <-> K+1 Array: " << Array[k+1] << endl;
                        x = (Array[k+1]); cout << "[Past Function: X=Arrayk+1] X= " << x << endl;
                    } else {
                        x = (Array[k-1]+1); cout << "[Past Function: X=Array[k+1]+1] X=" << x << endl;}
                    y = x-k;
                    //for when both chars are the same (can skip)
                    if ((x < n) && (y < m) && (char_array1[x+1] == char_array2[y+1])) {cout << "Snake" << endl;
                        x = x+1;cout << "[Past Function: X=x+1] X=" << x << endl; 
                        y = y+1;cout << "[Past Function: y=y+1] Y=" << y << endl;
                    } 
                    Array[k] = x;
                    //For Solution:
                    if ((x>=n) && (y >= m)) {cout << "Found D! For N: " << n << ", M: " << m << ", X: " << x << ", and Y: " << y << endl;
                        } 
                }
                cout << "________End of D:" << d << "__________" << endl;
                //Wait for Input to move to next D Contour
                cin.get();
            
        //Suspect main error to be accessing negative index of arrays, but im not sure how to solve.

         //MISSING: A TRACE PROGRAM TO CREATE DIFF FILE:
            //store a copy of each ste
            //create new file with these stored values

        //MISSING: PATCH PROGRAM:
            //input patch file, store values
            //subtract the negatives, add the positives
            
            } 
}
        
int main(int argc, char** argv) {
        //convert file 1 into a string
        const char* filename = argv[1];
        ifstream text(filename);
        string s;
        text >> s;
        //convert file 2 into a string
        const char* filename2 = argv[2];
        ifstream text2(filename2);
        string s2;
        text2 >> s2;
        
        //If there are no files input.
        if (argc == 1) { cout << "Please input two files." << endl;}

        //If there is only one file input.
        else if (argc == 2) { cout << "Please input another file." << endl;}

        //If two files are input, plus a display of contents/name to check:
        else if (argc == 3) { cout << filename << " : " << s << endl; cout << filename2 << " : " << s2 << endl; 
        diff(s,s2); }

        //If more than 2 files are input.
        else if (argc >= 4) { cout << "Can only use two files." << endl;}

        //In case of Errors
        else {cout << "Error" << endl;}

return 0;
}