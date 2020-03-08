#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

string upper(string x){
    for(int i=0;i<x.size();i++){
        x[i]=toupper(x[i]);
    }
    return x;
}
int main(){
    ifstream file("name_score.txt");
    string text,grade;
    char name[100];
    int num1,num2,num3,sum;
    vector<string> v_name,v_grade;
    while(getline(file,text)){
        sscanf(text.c_str(),"%[^:]: %d %d %d",name,&num1,&num2,&num3);
        v_name.push_back(name);
        
        sum=0;
        sum=num1+num2+num3;
        if(sum>=80)grade="A";
        else if(sum>=70)grade="B";
        else if(sum>=60)grade="C";
        else if(sum>=50)grade="D";
        else grade="F";

        v_grade.push_back(grade);
    }

    while(1){
        cout<<"Please input your command: ";
        getline(cin,text);

        string s1,s2;
        int idx=text.find_first_of(" ");
        s1=upper(text.substr(0,idx));
        s2=upper(text.substr(idx+1,text.size()));

        if(s1=="NAME"){
            cout<<"---------------------------------"<<endl;
            int c=0;
            for(int i=0;i<v_name.size();i++){
                if(s2==upper(v_name[i])){
                c++;
                    cout<<v_name[i]<<"'s grade = "<<v_grade[i]<<endl;
                }
            }
            if(c==0)cout<<"Cannot found."<<endl;
            cout<<"---------------------------------"<<endl;
            
        }
        else if(s1=="GRADE"){
            cout<<"---------------------------------"<<endl;
            int c=0;
            for(int i=0;i<v_name.size();i++){
                if(s2==upper(v_grade[i])){
                c++;
                    cout<<v_name[i]<<endl;
                }
            }
            if(c==0)cout<<"Cannot found."<<endl;
            cout<<"---------------------------------"<<endl;
        }
        else if(s1=="EXIT")break;
        else cout<<"Invalid command"<<endl;
    }
}