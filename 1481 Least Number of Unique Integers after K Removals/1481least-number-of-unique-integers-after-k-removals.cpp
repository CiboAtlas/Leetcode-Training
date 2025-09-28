// k 
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // create a hash map and keep track of unique numbers
        unordered_map<int ,int> mp;
        
        // fill in the hash map
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] += 1;
        }

        // create vector 
        vector<int> visited; // initialize vector with array

        for (auto& a : mp) {
            visited.push_back(a.second); // frequency count
        }

        sort(visited.begin(), visited.end());

        for(int i = 0; i < visited.size(); i++) {
            if(k > visited[i]) {
                k = k - visited[i];
                visited[i] = 0;
            } else {
                if(k != 0) { // check first to see if theres anymore k left
                visited[i] = visited[i] - k;
                }

                k = 0;
            }
        }

        //for (auto i : visited)
        //    cout << i << " ";

        int count = 0;
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] != 0) {
                count++;
            }
        }


        return count;
    }
};