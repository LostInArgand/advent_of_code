#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>


typedef long long ll;

using namespace std;


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    std::ifstream inputFile("/Users/pradithaalwis/CLionProjects/csesPractice/input.txt");
    if (!inputFile){
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    std::string line, colour;
    ll ans = 0;
    int ID;
    ll num;
    ll r, g, b;
    char ch;
    while (inputFile >> line) {
        inputFile >> ID;
        inputFile >> ch;
        r = 0;
        g = 0;
        b = 0;
        while(true) {
            inputFile >> num;
            inputFile >> colour;
            if(*(colour.end() - 1) == ',' or *(colour.end() - 1) == ';'){
                colour.pop_back();
                if (colour == "blue") b = max(b, num);
                else if (colour == "red") r = max(r, num);
                else if (colour == "green") g = max(g, num);
            }
            else{
                if (colour == "blue") b = max(b, num);
                else if (colour == "red") r = max(r, num);
                else if (colour == "green") g = max(g, num);
                break;
            }
        }
        ans += r * g * b;
    }
    inputFile.close();
    cout << ans << endl;
    return 0;
}
