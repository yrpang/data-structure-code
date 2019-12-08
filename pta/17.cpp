#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<iostream>


int main()
{
    using namespace std;

    vector<char> input;
    stack<float> num;

    char c;
    while(cin>>c)
    {
        input.push_back(c);
    }

    int i;
    float a,b;
    for(i=input.size()-1;i>=0;i--)
    {   
        if(input[i]=='+'||input[i]=='-'||input[i]=='/'||input[i]=='*')
        {
            a=num.top();
            num.pop();
            b=num.top();
            num.pop();
            
            switch(input[i]){
                case '+':
                    a = a+b;
                    num.push(a);
                    break;
                case '-':
                    a = a-b;
                    num.push(a);
                    break;
                case '*':
                    a = a*b;
                    num.push(a);
                    break;
                case '/':
                    if(b==0){
                        printf("ERROR\n");
                        return 0;
                    };
                    a = a/b;
                    num.push(a);
                    break;
            }

        }
        else
        {
            num.push(input[i]-'0');
        }
    }

    printf("%.1f",num.top());

    return 0;
}