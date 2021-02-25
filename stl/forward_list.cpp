//
// Created by Jesson on 2021/2/25.
//

#include<forward_list>
#include<iostream>
using namespace std;

int main()
{
    forward_list<int> list = {1,2,4,5,6};

    auto pre = list.before_begin();
    for(auto pos=list.begin();pos!=list.end();++pos,++pre) {
        if(*pos%4==0)
            break;
    }

    list.insert_after(pre,6);

    for(auto pos=list.begin();pos!=list.end();++pos)
        cout<<*pos<<" ";
    cout<<endl;
    return 0;
}

