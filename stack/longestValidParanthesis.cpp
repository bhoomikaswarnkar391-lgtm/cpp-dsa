#include<iostream>
#include<stack>
#include<string>
using namespace std;

int longestValidParaenthesis(string s){
    stack<char> st;
    int count;
    for(int i=0; i<s.length(); i++){
        int count =0; 
        char ch = s[i];

        if( ch == '(' )
        st.push(ch);
        else{
            if(st.empty()) return 0;

            char top = st.top();
            if((ch == ')' && top == '(')) 
             
            st.pop();
            count += 2;
        }
    }
     return count;
}

int main(){
    int c;
    cin>>c;

    while(c--){
        string s;
        cin>>s;
        cout<<longestValidParaenthesis(s);
    }

}