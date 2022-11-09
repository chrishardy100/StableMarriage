
/*
 * This program provides a solution to the "Stable Marriage Problem"
 * of mapping one set of preferences onto another set of preferences such that
 * no elements from each set has a preference for each other over the elements 
 * they are already assigned.
 * 
 * @author Christopher Hardy
 * 
*/
This program provides a solution to the "Stable Marriage Problem"
of mapping one set of preferences onto another set of preferences such that
no elements from each set has a preference for each other over the elements 
they are already assigned.

/*
Notes before starting:
  0 is the most preferable, 2 is the least (for a 3 men and woman)
*/
#include <iostream>
using namespace std;
struct Solution {
    int n = 3;
    int matching[3] = {0}; // initialize all elements as 0.
                              //male prefference for woman
    int mp[3][3] = { {0,2,1},   //man 0 likes woman 0 the most and woman 1 the least.
                    {0,2,1},
                    {1,2,0}
    };

    int wp[3][3] = { {2,1,0},
                    {0,1,2},
                    {2,0,1}
    };
    void printMatching() {

        for (int i = 0; i < n; i++) {
            cout << "male: " << i << " and female: " << matching[i] << endl;
        }
        cout << endl;
    }
    bool isAlreadyTaken(int currMale) {

        for (int i = 0; i < currMale; ++i) {
            // matchingueens are on the same row

            if (matching[i] == matching[currMale]) {
                return true;
            }
        }
        return false;
    }

    bool isStable(int x) {
        for (int i = 0; i < x; i++) {
            if ((mp[i][matching[x]] < mp[i][matching[i]] && wp[matching[x]][i] < wp[matching[x]][x]) ||
                (mp[x][matching[i]] < mp[x][matching[x]] && wp[matching[i]][x] < wp[matching[i]][i]))  {
                return false;
            }

        }
        return true;
    }

    bool ok(int currMale){
        if (!isAlreadyTaken(currMale) && isStable(currMale)) {
            return true;
        }
        else {
            return false;
        }
    }


    void solve(int currMale)
    {

        if (currMale > 2) { // print                 
            printMatching();
            return;
        } // print

        for (int j = 0; j < 3; ++j) {
            matching[currMale] = j;
            if (ok(currMale)) {
                solve(currMale + 1);
            }
        }

    } // solve

}; // Solution
int main() {
    Solution s;
    s.solve(0);
    std::cout << "finished" << endl;
}