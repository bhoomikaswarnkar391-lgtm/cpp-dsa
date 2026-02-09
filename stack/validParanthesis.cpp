#include<iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParanthesis(string s){
    stack<char> st ;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if( ch == '{' || ch == '(' || ch == '['){
            st.push(ch);
        }else{
            if(st.empty()) return false;

            char top = st.top();
            if(( ch == '}' && top == '{') ||
            (ch == ']' && top == '[') || 
            (ch == ')' && top == '('))
            st.pop();
            else
            return false;
        }
    }
     
    return st.empty();
}



int main(){
    int c;
    cout<<"How many strings you want to insert ?:";
    cin>>c;

    while(c--){
    string s;
    cin>>s;
    bool isvalid = isValidParanthesis(s);
    if(isvalid)
    cout<<true;
    else
    cout<<false;
}
}
