/*
  * =======================================
  *           C++ cheat sheet
  * =======================================
  * 01- string
  * 02- vector
  * 03- pair
  * 04- set
  * 05- map
  *
  *
  * 10- general
  *
  * =======================================
*/

/*---------------------------
    01- string
---------------------------*/
// --- transform char using #include <string.h>
toupper(s[i], locale());
tolower(s[i], locale());

// --- initialize a sequence using #include <algorithm>
fill_n(nums, sizeof(nums), true);

// --- transform string using #include <algorithm>
transform(word.begin(), word.end(), word.begin(), ::tolower);   
transform(word.begin(), word.end(), word.begin(), ::toupper);

// --- use ignore after using cin
cin.ignore();   // Extracts chars from the input sequence and discards them.
getline(cin, line);     

// --- use #include <sstream>
getline(cin, line);
stringstream stream(line);
stream >> word;


// --- find using #include <string>
// 2nd param: Position of the 1st char in the string to be searched.
// 3rd param: Length of sequence of chars to match.

string haystack = "There are two needles in this haystack with needles.";
string needle = "needle";

size_t found = haystack.find(needle);
if (found != ::npos) cout << "first needle at: " << found << '\n';

found = haystack.find("needles are small", found+1, 6);
if (found != ::npos) cout << "second needle at: " << found << '\n';


// --- replace using #include <string>
string str1 = "donkey ate the milk";
string str2 = "cat";
str1.replace(str1.begin(), str1.begin()+6, str2); // (from, to, replace)

string str1 = "donkey ate the milk";
string str2 = "012cat";
str1.replace(str1.begin(), str1.begin()+6, str2.begin()+3, str2.end()); // (from, to, from, to)

str.replace(9,5,"hello");       // (from, len, replace) - string
str.replace(9,6,"hello",7,6);   // (from, len, replace, subFrom, subLen) - substring
str.replace(22,1,3,'!');        // (from, len, n, char c)   - fill

// replace the first needle:
str.replace(str.find(needle), needle.length(), "replace");

/*---------------------------
    02- vector
---------------------------*/
#include <vector>;
vector<int> v;              // declaration
vector<int>::iterator it;   // pointer to the vector<int>

v.push_back(4);             // adding to the vector
v.push_back(5);
v.size();

for (it=v.begin(); it!=v.end(); it++) {
    cout << *it << endl;    // print the vector elements
}

cout << v.front() << endl;  // access the first element
cout << v.back() << endl;   // access the last element

v.resize(5);                // 5 is the new container size
v.resize(5, 0);             // 0 copied to the added elements if 5 > the current container size

v.erase(v.begin());         // erase the first element
v.erase(v.begin() + 3);     // erase the 4th element
v.erase(v.begin(), v.begin() + 3);      // erase the 1, 2, 3 elements
v.pop_back();               // erase the last element
v.clear();                    // remember to clear the vector each loop

// use #include <algorithm>
reverse(v.begin(),v.end()); 
is_sorted(v.begin(),v.end());

int sum = 0;
while(!v.empty()) {         // return true if the container size = 0
    sum += v.back();
    v.pop_back();
}

// --- sort vector of nodes
bool vsort(const Node &left, const Node &right) {
    if (left.length == right.length) {
        return left.order < right.order;
    }
    return left.length > right.length;
}
struct Node {
    string word;
    int length;
    int order;
};
while (cin >> word) {
    Node *temp = new Node;
    temp->length = word.length();
    temp->order = count;
    temp->word = word;
    v.push_back(*temp);
}
sort(v.begin(), v.end(), vsort);


/*---------------------------
    03- pair
---------------------------*/
pair<int, int> p0;          // declaration
p0.first = 2;
p0.second = 5;
pair<int, int> p1 = make_pair(2, 5);
pair<int, int> p2(2, 5);
pair<int, int> p3(p2);

pair<int, int> arr[10];     // array of pairs
arr[0].first = 2;
arr[0].second = 5;
arr[1] = make_pair(2, 5);

bool pSort(const pair<int,int> &left, const pair<int,int> &right) {
    if (left.second == right.second) {
        return left.first < right.second;
    }
    return left.second < right.second;
}
sort(arr, arr+10, pSort);   // sort the array of pairs according to pSort/\

vector< pair<int, int> > v0;    // vector of pairs
vector< pair<int, int> >::iterator it0;
v0.push_back( make_pair(2, 4) );
for (it0=v0.begin(); it0!=v0.end(); it0++) {
    cout << (*it0).first << " | " << it0->second << endl;    // print the vector elements
}


/*---------------------------
    04- set
---------------------------*/
#include <set>
set<int> s; // declaration - used to store unique elements
set<int>::iterator it1;

s.insert(4);
for (it1=s.begin(); it1!=s.end(); it1++) {
    cout << *it << endl;  // print the set elements
}
cout << s.size() << endl;
cout << s.count(5); // return 1 if set contains 5 | otherwise return 0
it0 = s.find(5);    // if found return an iterator to the element, otherwise return set.end()
s.erase(s.end());   // erase the last element
s.clear();
s.empty();  // true || false


/*---------------------------
    05- map
---------------------------*/
#include <map>
map<char, int> m;
map<char, int>::iterator it2;

m['c'] = 3;
for(it2=m.begin(); it2!=m.end; it2++) {
    cout << it2->first << " => " << it2->second << endl;
}

it2 = m.find('c');
cout << it2->second << endl; // output => 3

cout << m.size() << endl;

m.erase('c');
m.erase(it2, m.end());  // erase from it2 to the end
m.clear();

m.empty();  // true || false

/*---------------------------
    10- general
---------------------------*/
// --- generating a prime list in the first 1000 number
bool nums[1001];
fill_n(nums, sizeof(nums), true);
nums[0] = nums[1] = false;

for (int i=2; i<100; i++) {
    if (nums[i] == false) continue;
    int tmp;
    for (int j=2; tmp=i*j, tmp <=sizeof(nums); j++) {
        nums[tmp] = false;
    }
}

// --- get the greatest common devisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
