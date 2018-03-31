#include<iostream>
#include<string>
using namespace std;
void first(char c,string ch[], int n,char v)
{
        for(int i=0; i<n; i++)
        {
                if(ch[i][0]==c)
                {       
                        if( (ch[i][2]>='a' && ch[i][2]<='z') || ch[i][2]=='!' ||  ch[i][2]=='*' ||  ch[i][2]=='+'|| ch[i][2]=='('||ch[i][2]==')') //! -epsilon
                        {
                            cout<<" "<<ch[i][2]<<" ";
                            if(ch[i][2]=='!')
                            {
                                first(v,ch,n,v);
                            }
                        }    
                        else
                        {
                            v=ch[i][3];
                            first(ch[i][2],ch,n,v);
                        }
                        
                }
        }

}

int main()
{
        int n;
	char v=0;
        cout<<"Enter number of productions\n";
        cin>>n;
        string ch[n];
        cout<<"Enter the production\n";
        for(int i=0; i<n; i++)
        {
                cin>>ch[i];
        }
	while(1)
	{
        cout<<"Enter the production whose first you need\nPress z to exit\n";
        char c;
        cin>>c;
	if(c=='z')
	break;
	else
	{
        	cout<<"[";
        	first(c,ch,n,v);
        	cout<<"]"<<endl;
	}
	}
        return 0;
}

