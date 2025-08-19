#include<bits/stdc++.h>
using namespace std;
class Solution {

private:
    double epsilon = 0.000001; // tolerance for floating point comparison

    // Recursive helper function to check if we can form 24
    bool solve(vector<double>& card) {
        // Base case: if only one number remains, check if it's close to 24
        if (card.size() == 1)
            return abs(card[0] - 24) <= epsilon;

        // Try all pairs (i, j) of numbers from the list
        for (int i = 0; i < card.size(); i++) {
            for (int j = 0; j < card.size(); j++) {
                if (i == j) // skip same index
                    continue;

                // Create a temporary list without i and j
                vector<double> temp;
                for (int k = 0; k < card.size(); k++) {
                    if (k != i && k != j)
                        temp.push_back(card[k]);
                }

                double a = card[i];
                double b = card[j];

                // All possible results of applying an operation on a and b
                vector<double> opr = {a + b, a - b, b - a, a * b};

                // Division (avoid division by zero)
                if (abs(a) > 0.0) {
                    opr.push_back(b / a);
                }
                if (abs(b) > 0.0) {
                    opr.push_back(a / b);
                }

                // Try each possible result
                for (auto it : opr) {
                    temp.push_back(it);     // add new result
                    if (solve(temp))        // recursively solve
                        return true;
                    temp.pop_back();        // backtrack
                }
            }
        }

        return false; // no solution found
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        // Convert input integers to doubles
        for (int i = 0; i < cards.size(); i++) {
            nums.push_back(1.0 * cards[i]);
        }

        // Start recursive solving
        return solve(nums);
    }
};
