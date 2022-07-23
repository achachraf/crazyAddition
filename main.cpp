#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>


using namespace std;

vector<vector<int>> getCombinations(int n, int r){

    vector<bool> v(n);
    vector<vector<int>> results;
    fill(v.begin(), v.begin() + r, true);
    do {
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
        if (v[i]) {
            temp.push_back(i+1);
        }
        }
        results.push_back(temp);
    } while (prev_permutation(v.begin(), v.end()));
    
    return results;
}

void generateCombinations(int chosen[], int arr[],
                    int index, int r, int start, int end, vector<vector<int>> &results)
{
  
    if (index == r)
    {
        vector<int> temp;
        for (int i = 0; i < r; i++){
            temp.push_back(arr[chosen[i]]);
        }
        results.push_back(temp);
        return;
    }
 
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        generateCombinations(chosen, arr, index + 1,
                                               r, i, end, results);
    }
    return;
}

int* generateRange(int left, int right){
    int* range = new int[right-left+1];
    for(int i=left,j=0;i<=right;i++,j++){
        range[j] = i;
    }
    return range;
}


string generateInputCode(int variables){
    string code = "vars = []\n";
    code += "for v in range("+to_string(variables)+"):\n";
    code += "\ttemp = int(input())\n";
    code += "\tvars.append(temp)\n";
    return code;
}

string generateDictCode(vector<vector<int>> combs){
    string code = "data = {";
    for(auto line : combs){
        string key;
        int sum = 0;
        for(int number : line){
            key += to_string(number);
            sum += number;
        }
        code += "\"" + key + "\": " + to_string(sum) + ",";
    }
    code += "}\n";
    return code;
}

string generateKeyCode(){
    string code = "vars.sort()\n";
    code += "mapped = map(str,vars)\n";
    code += "key = \"\".join(mapped)\n";
    return code;
}

string generateOutputCode(){
    string code = "output = data[key]\n";
    code += "print(output)\n";
    return code; 
}


int main(int argc, char* argv[]){
    
    if(argc != 4){
        cout<<"Illegale number of parameters, expected 4 found "<<argc-1<<"\n";
        return -1;
    }

    const int r = atoi(argv[1]);
    const int left = atoi(argv[2]);
    const int right = atoi(argv[3]);
    const int n = right - left + 1;
    
    vector<vector<int>> combs;
    int* chosen = new int[n+1];
    int* range = generateRange(left, right);
    generateCombinations(chosen, range, 0, r, 0, n-1, combs);
    string code = generateInputCode(r);
    code += generateDictCode(combs);
    code += generateKeyCode();
    code += generateOutputCode();
    
    ofstream file;
    file.open("crazyAdditionScript.py");
    file<<code;


}

