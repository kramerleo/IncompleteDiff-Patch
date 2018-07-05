#include <fstream> 
#include <string> 
#include <iostream>
#include <vector>
using namespace std; 

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
        //(through array)set maximum possible size of (SES) shortest edit script to the two strings in full added together
        int n = s.size();
        int m = s2.size();
        int max = n + m;
        //define some Ints for algorithm.
        int d; //depth, amount of 'moves' made in standard graph
        int k; //k=x-y
        int x; //Deletions to first string
        int y; //Additions to first string from second string
        //to build array that displays closest x in terms of k
        int Array[2 * max + 1];
        Array[0] = 0; 

        //If there are no files input.
        if (argc == 1) { cout << "Please input two files." << endl;}

        //If there is only one file input.
        else if (argc == 2) { cout << "Please input another file." << endl;}

        //If two files are input, plus a display of contents/name to check:
        else if (argc == 3) { cout << filename << " : " << s << endl; cout << filename2 << " : " << s2 << endl; 
            //To check about the shortest edit script using Myers Algorithim:
            if((d <= max) && (d >= 0)){ d++;
                cout << max << "D:" << d << endl;
                if((k < d) && (k > -d)){k+=2;
                    cout << "K:" << k << endl;
                    if ((k == -d)||((k != d) && (Array[k-1] < Array[k+1]))){
                        x = (Array[k+1]); cout << Array[k] << " x2:" << x << endl;
                        y = x-k;
                    } else {x = (Array[k-1]+1);}
                    while ((x < n) && (y < m) && (s[x] == s2[y])) {
                        x = x+1; cout << "x3:" << x << endl;
                        y = y+1; cout << "y3:" << y << endl;
                    } 
                    Array[k] = x;
                    if ((x>=n) && (y >= m)) {
                        cout << "D:" << d << " K:" << k << " X:" << x << " Y:" << y << endl;}
                } else { cout << "Problem with K" << endl;}
            } else {cout << "Problem with D" << endl;}   
//HAVING A PROBLEM HERE (I think its with the array)
        
        //A TRACE PROGRAM TO CREATE DIFF FILE:
            //store a copy of each ste
            //create new file with these stored values

        //PATCH PROGRAM:
            //input patch file, store values
            //subtract the negatives, add the positives

        }              

        //If more than 2 files are input.
        else if (argc >= 4) { cout << "Can only use two files." << endl;}

        //In case of Errors
        else {cout << "Error" << endl;}

return 0;
}