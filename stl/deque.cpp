//
// Created by Jesson on 2021/2/25.
//

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    deque<string> strDeq;

    strDeq.assign(4,string("CHINA"));
    strDeq.emplace_back("first_string");
    strDeq.push_front("last_string");

    copy(strDeq.begin(),strDeq.end(),
         ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;

    for(int i = 0;i < strDeq.size();++i)
        cout << "strDeq[" << i << "] : " << strDeq[i] << endl;
    cout << endl;

    for(int i = 0;i < strDeq.size();++i)
        cout << "strDeq.at(" << i << ") : " << strDeq.at(i) << endl;
    cout << endl;

    strDeq.pop_front();
    strDeq.pop_back();

    copy(strDeq.begin(),strDeq.end(),
         ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;

    for(int i = 1;i < strDeq.size();++i)
        strDeq[i] = "pre" + strDeq[i];
    copy(strDeq.begin(),strDeq.end(),
         ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;

    strDeq.resize(4,"resized string");

    copy(strDeq.begin(),strDeq.end(),
         ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;
}
