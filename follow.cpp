#include<iostream>
#include<string>
using namespace std;
void follow(char c, string ch[], int n, char v,int flag);
int flag;

void first(char c,int x,int y, string ch[], int n,char v)
{
	for(int i=0; i<n; i++)
        {
                if(ch[i][0]==c)
                {       
                        if( (ch[i][2]>='a' && ch[i][2]<='z') || ch[i][2]=='!' ||  ch[i][2]=='*' ||  ch[i][2]=='+'|| ch[i][2]=='('||ch[i][2]==')') //! -epsilon
                        {
                            if(ch[i][2]!='!')
                            cout<<" "<<ch[i][2]<<" ";
                            if(ch[i][2]=='!')
                            {
                                if(ch[x][y+1] < 'A' || ch[x][y+1] > 'B')        //If it is the last element of RHS
                                {
                                    follow(ch[x][0],ch,n,v,flag);
                                }
                                else
                                {
                                    first(ch[x][y+1],x,y+1,ch,n,v);
                                }
                            }
                        }    
                        else
                        {
                            v=ch[i][3];
                            first(ch[i][2],x,y+1,ch,n,v);
                        }
                        
                }
        }
}

void follow(char c, string ch[], int n, char v,int flag)
{
	for(int i=0; i<n; i++)
	{
		int len=ch[i].length();
		for(int j=2; j<len; j++)
		{
			if(c==ch[i][j])
			{
				if((j==(len-1)) && flag==0)						//If it is the last element in the grammar
				{	
					follow(ch[i][0],ch,n,v,flag);
                    flag=1; 
				}
                else if((ch[i][j+1]>='a' && ch[i][j+1]<='z') ||  ch[i][j+1]=='*' ||  ch[i][j+1]=='+'|| ch[i][j+1]=='(' || ch[i][j+1]==')')
                {
                    cout<<" "<<ch[i][j+1]<<" ";
                }
				else if(flag==0)
				{
					first(ch[i][j+1],i,j+1,ch,n,v);
                    flag=1;
				}
			}
		}	
	}	

}
int main()
{
        int n;
        char v=0;  					//v is for second non-terminal
        cout<<"Enter number of productions\n";
        cin>>n;						//n is no. of productions		
        string ch[n];
        cout<<"Enter the production\n";
        for(int i=0; i<n; i++)
        {
                cin>>ch[i];
        }
        while(1)
        {
        flag=0;
        cout<<"Enter the production whose follow you need \n Press z to exit\n";
        char c;
        cin>>c;
        if(c=='z')
		  break;
        else
        {
                cout<<"[";
                follow(c,ch,n,v,flag);
                cout<<"$ ]"<<endl;
        }
        }
        return 0;
}


